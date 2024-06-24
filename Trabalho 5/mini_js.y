%{

extern "C" int yylex();

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int yyparse();
void yyerror(const char *);


typedef vector<string> lista_strings;

struct Atributos {
  lista_strings c; 
  int l; 
};


#define YYSTYPE Atributos

lista_strings concatena(lista_strings a, lista_strings b);
lista_strings operator+(lista_strings a, lista_strings b);
lista_strings operator+(lista_strings a, string b);
lista_strings operator+(string a, lista_strings b);

string gera_label(string prefixo);

void print(lista_strings source);
lista_strings resolve_enderecos(lista_strings entrada);

lista_strings novo;
int linha = 1, coluna = 1;
int token(int tk);

void generate_var(Atributos var);
void check_var(Atributos var);
map<string, int> vars;

bool is_function_scope = false;
int argCallCounter = 0;
int argCounter = 0;
lista_strings argList = {};
lista_strings funcSource = {};

string trim(string str, string charsToRemove);
lista_strings token(string asmLine);

int literalArrayCounter = 0;

%}

%token _IF _ELSE _ASM _BOLEANO
%token _NUM _ID _LET _WHILE _FOR TK_STR _ARRAY
%token _MA_IG _FUNCTION _RETURN _SETA_ESQUERDA
%token _MAIS _MENOS _MULT _DIV _MODULO
%token _MAIOR _MENOR _ME_IG _MA_IG _IGUAL _DIF _AND _OR
%token _OBJETO _ABRE_CHAVE _FECHA_CHAVE

%nonassoc _MAIOR _MENOR _ME_IG _MA_IG _IGUAL _DIF
%nonassoc _IF _ELSE _WHILE _FOR
%left _AND _OR
%left _MAIS _MENOS
%left _MULT _DIV _MODULO

%start S 

%%

S : CMDs  { $$.c = $1.c + "." + funcSource; print( resolve_enderecos($$.c) ); }
  ;

CMDs : CMD ';' CMDs    { $$.c = $1.c + $3.c; }
	 | FLOW_CMD CMDs   { $$.c = $1.c + $2.c; }
	 | FUNC_DECL CMDs  { $$.c = $1.c + $2.c; }
     |                 { $$.c = novo; }
     ;
	 
ARGS : R ',' ARGS { $$.c = $1.c + $3.c; argCounter++; is_function_scope = true;
					if($1.c.size() >= 2) argList.push_back($1.c.rbegin()[1]); }
					
	 | R          { $$ = $1; argCounter++; is_function_scope = true;
					if($1.c.size() >= 2) argList.push_back($1.c.rbegin()[1]); }
					
	 |            { $$.c = novo; is_function_scope = true; }
	 ;
	 
ARGS_CALL : R ',' ARGS_CALL   { $$.c = $1.c + $3.c; argCallCounter++; }
          | R                 { $$ = $1; argCallCounter++; }
		  |                   { $$.c = novo; }
		  ;

CMD : A                        { $$.c = $1.c + "^"; }
    | _LET DECLVARS          { $$ = $2; }
	| _RETURN R              { $$.c = $2.c + "'&retorno'" + "@" + "~"; }
	| E _ASM                 { $$.c = $1.c + $2.c + "^"; }
    ;
	
FLOW_CMD : _IF '(' R ')' BODY OPT_ELSE
			{
				string endif = gera_label("end_if");
				string dps_else = gera_label("dps_else");
				$$.c = $3.c + "!" + endif + "?" + $5.c + dps_else + "#" + (":" + endif) + $6.c + (":" + dps_else) ;
			}
			
		 | _WHILE '(' R ')' BODY
			{
				string endwhile = gera_label("end_while");
				string beginwhile = gera_label("begin_while");
				$$.c = (":" + beginwhile) + $3.c + "!" + endwhile + "?" + $5.c + beginwhile + "#" + (":" + endwhile);
			}
			
		 | _FOR '(' CMD ';' R ';' A ')' BODY
		  {
		   string endfor = gera_label("end_for");
		   string beginfor = gera_label("begin_for");
		   $$.c = $3.c + (":" + beginfor) + $5.c + "!" + endfor + "?" + $9.c + $7.c + "^" + beginfor + "#" + (":" + endfor);
		  }
		 ;
		   
OPT_ELSE : _ELSE BODY  { $$ = $2; }
		 |               { $$.c = novo; }
		 ;
	
BODY : CMD ';'     { $$ = $1; }
	 | BLOCK
	 | FLOW_CMD
	 ;
	 
FUNC_CALL : LVALUE '(' ARGS_CALL ')'
			{
				$$.c = $3.c + to_string(argCallCounter) + $1.c + "@" + "$";
				argCallCounter = 0;
			}
		  | LVALUEPROP '(' ARGS_CALL ')'
			{
				$$.c = $3.c + to_string(argCallCounter) + $1.c + "[@]" + "$";
				argCallCounter = 0;
			}
	      ;
		  
FUNC_DECL : _FUNCTION LVALUE '(' ARGS ')' BLOCK
			{
				string beginfunc = gera_label("begin_func");
				$$.c = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + beginfunc + "[=]" + "^";
				
				funcSource.push_back(":"+beginfunc);
				for(int i = 0; i < argCounter; i++){
					lista_strings tmp = {argList.at(argCounter-i-1), "&", argList.at(argCounter-i-1), "arguments", "@", to_string(i), "[@]", "=", "^"};
					funcSource.insert(funcSource.end(), tmp.begin(), tmp.end());
				}
				funcSource.insert(funcSource.end(), $6.c.begin(), $6.c.end());
				
				lista_strings finalReturn = {"undefined", "@", "'&retorno'", "@", "~"};
				funcSource.insert(funcSource.end(), finalReturn.begin(), finalReturn.end());
				
				argCounter = 0; argList.clear(); is_function_scope = false;
			}
		  ;
			
BLOCK : _ABRE_CHAVE CMDs _FECHA_CHAVE { $$ = $2; }
	  ;

DECLVARS : DECLVAR ',' DECLVARS  { $$.c = $1.c + $3.c; }
         | DECLVAR               { $$ = $1; }
         ;

DECLVAR : LVALUE '=' R  { generate_var($1); $$.c = $1.c + "&" + $1.c + $3.c + "=" + "^"; }
        | LVALUE        { generate_var($1); $$.c = $1.c + "&"; }
		
		| LVALUE '=' LVALUE _MA_IG E
			{
				generate_var($1);
				string beginfunc = gera_label("begin_func");
				$$.c = $1.c + "&" + $1.c + "{}" + "'&funcao'" + beginfunc + "[<=]" + "=" + "^";
						  
				funcSource.push_back(":"+beginfunc);
				lista_strings lambdaArgs = {$3.c.back(), "&", $3.c.back(), "arguments", "0", "[@]", "=", "^"};
				funcSource.insert(funcSource.end(), lambdaArgs.begin(), lambdaArgs.end());
				
				funcSource.insert(funcSource.end(), $5.c.begin(), $5.c.end());
				lista_strings finalReturn = {"'&retorno'", "@", "~"};
				funcSource.insert(funcSource.end(), finalReturn.begin(), finalReturn.end());
			}
		
		| LVALUE '=' _FUNCTION '(' ARGS ')' BLOCK
			{
				string beginfunc = gera_label("begin_func");
				$$.c = $1.c + "&" + $1.c + "{}" + "'&funcao'" + beginfunc + "[<=]" + "=" + "^";
				
				funcSource.push_back(":"+beginfunc);
				
				for(int i = 0; i < argCounter; i++){
					lista_strings tmp = {argList.at(argCounter-i-1), "&", argList.at(argCounter-i-1), "arguments", "@", to_string(i), "[@]", "=", "^"};
					funcSource.insert(funcSource.end(), tmp.begin(), tmp.end());
				}
				
				funcSource.insert(funcSource.end(), $7.c.begin(), $7.c.end());
				
				lista_strings finalReturn = {"undefined", "@", "'&retorno'", "@", "~"};
				funcSource.insert(funcSource.end(), finalReturn.begin(), finalReturn.end());
				
				argCounter = 0; argList.clear(); is_function_scope = false;
			}
        ;

A : LVALUE '=' A                   { if(!is_function_scope) check_var($1); $$.c = $1.c + $3.c + "="; }
  | LVALUEPROP '=' A               { $$.c = $1.c + $3.c + "[=]"; }
  | R                              { $$ = $1; }
  ;

R : E _ME_IG E        { $$.c = $1.c + $3.c + "<="; }
  | E _MA_IG E        { $$.c = $1.c + $3.c + ">="; }
  |	E _MENOR E       { $$.c = $1.c + $3.c + "<"; }
  | E _MAIOR E       { $$.c = $1.c + $3.c + ">"; }
  | E _IGUAL E       { $$.c = $1.c + $3.c + "=="; }
  | E _DIF E        { $$.c = $1.c + $3.c + "!="; }
  | E                  { $$ = $1; }
  ;

E : LVALUE '=' E       { $$.c = $1.c + $3.c + "=" ; }
  | LVALUEPROP '=' E   { $$.c = $1.c + $3.c + "[=]"; }
  | E _MAIS E        { $$.c = $1.c + $3.c + "+"; }
  | E _MENOS E       { $$.c = $1.c + $3.c + "-"; }
  | E _MULT E        { $$.c = $1.c + $3.c + "*"; }
  | E _DIV E         { $$.c = $1.c + $3.c + "/"; }
  | E _MODULO E      { $$.c = $1.c + $3.c + "%"; }
  | _MENOS E         { $$.c = "0" + $2.c + "-"; }
  | LVALUE             { $$.c = $1.c + "@"; }
  | LVALUEPROP         { $$.c = $1.c + "[@]"; }
  | F                  { $$ = $1; }
  ;
  
LVALUE : _ID
	   ;
	   
LVALUEPROP : E '[' E ']'    { $$.c = $1.c + $3.c; }
		   | E '.' LVALUE   { $$.c = $1.c + $3.c; }
		   ;

		   
OBJ_MEMBERS : LVALUE ':' E ',' OBJ_MEMBERS   { $$.c = $1.c + $3.c + "[<=]" + $5.c; }
			| LVALUE ':' E                   { $$.c = $1.c + $3.c + "[<=]"; }
			|                                { $$.c = novo; }
			;
			
ARRAY_MEMBERS : E ',' ARRAY_MEMBERS { $$.c = "TAG_NUM" + $1.c + "[<=]" + $3.c; }
			  | E { $$.c = "TAG_NUM" + $1.c + "[<=]"; }
			  ;
		   
F : _NUM                                   { $$.c = $1.c; }
  | TK_STR                                   { $$.c = $1.c; }
  | _BOLEANO                               { $$.c = $1.c; }
  | '(' E ')'                                { $$ = $2; }
  | _ARRAY                                 { $$.c = novo + $1.c; }
  | '[' ARRAY_MEMBERS ']'                    {
												for(int i = 0; i < $2.c.size(); i++){
													if($2.c[i] == "TAG_NUM")
														$2.c[i] = to_string(literalArrayCounter++);
												}
												$$.c = "[]" + $2.c;
												literalArrayCounter = 0;
											 }
  | _ABRE_CHAVE OBJ_MEMBERS _FECHA_CHAVE   { $$.c = "{}" + $2.c; }
  | _OBJETO                                { $$.c = novo + $1.c; }
  | FUNC_CALL                                { $$ = $1; }
  ;

%%

#include "lex.yy.c"

lista_strings concatena(lista_strings a, lista_strings b) {
  for(int i(0); i < b.size(); i++ ) a.push_back( b[i] );
  return a;
}

lista_strings operator+(lista_strings a, lista_strings b) {
  return concatena(a, b);
}

lista_strings operator+(lista_strings a, string b) {
  a.push_back(b);
  return a;
}

lista_strings operator+(string a, lista_strings b) {
  lista_strings c;
  c.push_back(a);
  return c + b;
}

void generate_var(Atributos var){
  if(vars.count(var.c.back()) == 0){
	vars[var.c.back()] = var.l;
  }
  else {
	cout << "Erro: a variável '" << var.c.back() << "' já foi declarada na linha " << vars[var.c.back()] << "." << endl;
	exit(1);
  }
}

void check_var(Atributos var){
	
	if(vars.count(var.c.back()) == 0){
		cout << "Erro: a variável '" << var.c.back() << "' não foi declarada." << endl;
		exit(1);
	}
}

string gera_label(string prefixo){
  static int n = 0;
  return prefixo + "_" + to_string(++n) + ":";
}

void print(lista_strings source){
  for(int i(0); i < source.size(); i++) cout << source[i] << endl;
}

lista_strings resolve_enderecos(lista_strings entrada) {
  map<string,int> label;
  vector<string> saida;
  for( int i = 0; i < entrada.size(); i++ ) 
    if( entrada[i][0] == ':' ) 
        label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );
  
  for( int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Proximo a: %s, linha: %d, coluna: %d\n", yytext, linha, coluna);
   exit( 1 );
}

int token(int tk) {
    yylval.c = novo + yytext;
    yylval.l = linha;
    coluna += strlen(yytext);
    return tk;
}

string trim(string str, string charsToRemove){
	for(auto c : charsToRemove){
		str.erase(remove(str.begin(), str.end(), c), str.end());
	}
	return str;
}

lista_strings token(string asmLine){
	lista_strings instructions;
	string word = "";
	for(auto c : asmLine){
		if(c != ' ')
			word = word + c;
		else {
			instructions.push_back(word);
			word = "";
		}
	}
	instructions.push_back(word);
	return instructions;
}

int main( int argc, char** argv ) {
  yyparse();
  return 0;
}