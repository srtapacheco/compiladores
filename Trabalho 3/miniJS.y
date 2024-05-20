%{

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

int contador = 0, linha = 1;

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

void motrar_erro(string c);
void mostrar(string c);

void setVar(string var, int linha);
void checkVar(string var);

map<string,int> var_declaradas;

  
struct Atributos {
  string c;
  string retorno = "";
  string getRetorno(){
        if(" " + c == retorno){
                return "";
        } 
        else return retorno;
  }
};

#define YYSTYPE Atributos
#define LABEL_IF ":then_"
#define LABEL_ENDIF ":end_if"
#define LABEL_WHILE ":while_"
#define LABEL_CORPO_WHILE ":whilec_"
#define LABEL_ENDWHILE ":end_while"
#define LABEL_FOR ":for_"
#define LABEL_CORPO_FOR ":forc_"
#define LABEL_ENDFOR ":end_for"

#define LABEL_RIF ";then_"
#define LABEL_RENDIF ";end_if"
#define LABEL_RWHILE ";while_"
#define LABEL_RCORPO_WHILE ";whilec_"
#define LABEL_RENDWHILE ";end_while"
#define LABEL_RFOR ";for_"
#define LABEL_RCORPO_FOR ";forc_"
#define LABEL_RENDFOR ";end_for"

%}

%token ID IF ELSE LET PRINT FOR WHILE
%token CINT CSTRING CSTRING2 CDOUBLE
%token  MA_IG ME_IG IGUAL DIF  _COMENTARIO  CONST VAR _CONC _MAISMAIS ABRE_FECHA_CHAVE 

%%

S :   Expressao ';' Continuacao         {mostrar($1.c + $3.c + " .");}
        |   CMD       Continuacao         {mostrar($1.c + $2.c + " .");}
        ;  


Argumentos  : Conta               {$$.c = $1.c;}
            | Conta ',' Conta     {$$.c = $1.c + " " + $3.c;}
            |                     {$$.c = "";}
            ;

Atribuicao_Objeto2      : Objeto '=' Atribuicao_Objeto2  {$$.c = " " +$1.c + $3.c + " " + $1.c + "[@]" + " [=] ^";}
                        | Conta                          {$$.c = " " + $1.c + " [=] ^";}
                        ;

Atribuicao_Objeto       : '=' Atribuicao_Objeto2    {$$.c = $2.c;}   
                        |                           {$$.c = "[@]";}
                        ;

Atribuicao_MIGUAL       : '=' Conta      {$$.c = $2.c + " + = ^";}
                        ;

AtribuicaoObj_MIGUAL    : '=' Conta      {$$.c = $2.c + " + [=] ^";}
                        ;

Atribuicao_ID2 : ID '=' Atribuicao_ID2  {$$.c = " " +$1.c + $3.c + " " + $1.c + "@" + " = ^";}
               | Conta                   {$$.c = " " + $1.c + " = ^";}
               ;

Atribuicao_ID   : '=' Atribuicao_ID2      {$$.c = $2.c;}
                |                         {$$.c = "@";}
                ;

Conta_Simples :   '-' Termo Conta_Simples               {$$.c = " " + $2.c + " -" + $3.c;} 
              |   '+' Termo Conta_Simples               {$$.c = " " + $2.c + " +" + $3.c;} 
              |   '>' Termo Conta_Simples               {$$.c = " " + $2.c + $3.c + " >";}
              |   '<' Termo Conta_Simples               {$$.c = " " + $2.c + $3.c + " <";}
              |   IGUAL Termo Conta_Simples               {$$.c = " " + $2.c + $3.c + " ==";}
              |                                         {$$.c = "";}
              ;

Conta_Complexa2   :   '^' Termo {$$.c = " " + $2.c + " ^";} 
                  |   '!' Termo {$$.c = " fat #" + $2.c;}
                  |             {$$.c = "";}  
                  ;

Conta_Complexa    :   '*' Membro Conta_Complexa2 Conta_Complexa {$$.c = " " + $2.c + $3.c + " *" + $4.c;}
                  |   '/' Termo                                 {$$.c = " " + $2.c + " /";}
                  |   Conta_Complexa2                           {$$.c = $1.c;}
                  |                                             {$$.c = "";}
                  ;

Funcao  : ID '(' Argumentos ')'  {$$.c = $3.c + " " + $1.c + " #";}
        | PRINT  Argumentos      {$$.c = $2.c + " print #";}
        ;
        
Declaracao_Complexa     :  Declaracao_Simples                   {$$.c = $1.c;}
                        | ',' ID '=' Conta Declaracao_Complexa {setVar($2.c, linha);$$.c = " " + $2.c + "& " + $2.c + " " + $4.c + " = ^"+ $5.c;}
                        |                                       {$$.c = "";}
                        ;

Declaracao_Simples  : ',' ID Declaracao_Simples  {setVar($2.c, linha);$$.c = " " + $2.c + "&" + $3.c;}
                    |                             {$$.c = "";}
                    ;

Expressao_Declaracao  : ID  '=' Conta Declaracao_Complexa    {setVar($1.c, linha); $$.c = $1.c + "& " + $1.c + " " + $3.c + " = ^" + $4.c;}
                      | ID  Declaracao_Complexa              {setVar($1.c, linha); $$.c = $1.c + "&" + $2.c;}
                      ;

Declaracao  : LET    Expressao_Declaracao    {$$.c = $2.c;}
            | CONST  Expressao_Declaracao    {$$.c = $2.c;}
            | VAR    Expressao_Declaracao    {$$.c = $2.c;}
            |                                 {$$.c = "";}
            ;

Membro_Simples  :   CSTRING        {$$.c = $1.c;}
                |   CINT           {$$.c = $1.c;}
                |   CDOUBLE         {$$.c = $1.c;}
                |  ABRE_FECHA_CHAVE '}'  {$$.c = "{}";}
                |  '[' ']'         {$$.c = "[]";}
                ;

Dimensoes       :   '[' Conta ']' Dimensoes {$$.c ="[@] " + $2.c + $2.getRetorno() + $4.c;}
                |                           {$$.c = "";}
                ;

Objeto  :   ID '.' ID                  {$$.c = $1.c + "@ " + $3.c;}
        |   ID '.' ID '[' Conta ']'    {$$.c = $1.c + "@ " + $3.c + "[@] " + $5.c;}
        |   ID '[' Conta ']'  Dimensoes {$$.c = $1.c + "@ " + $3.c + $3.getRetorno() + $5.c;}
        ;

Casos_ID        : ID           Atribuicao_ID       {checkVar($1.c);$$.c = $1.c + $2.c; $$.retorno = " " + $1.c + "@";}
                | ID _CONC     Atribuicao_MIGUAL   {$$.c = $1.c + " " + $1.c + "@ " + $3.c;}
                | ID _MAISMAIS '+' Conta_Simples   {$$.c = $1.c + "@" + $4.c + " " + $1.c + " " + $1.c + "@ 1 + = ^";}
                ;

Casos_Objeto    : Objeto           Atribuicao_Objeto    {$$.c = $1.c + $2.c;}
                | Objeto _CONC     AtribuicaoObj_MIGUAL {$$.c = $1.c + " " + $1.c + "[@] " + $3.c;}
                | Objeto _MAISMAIS '+'                  {$$.c = $1.c + " " + $1.c + "@ 1 + [=] ^ " + $1.c + "@";}
                ;


Membro  :   Membro_Simples                        {$$.c = $1.c;}      
        |   Funcao                                {$$.c = $1.c;}
        |   Casos_Objeto                          {$$.c = $1.c;}
        |   Casos_ID                              {$$.c = $1.c;$$.retorno=$1.retorno;}
        |   '+'    Conta                          {$$.c = $2.c;}
        |   '-'    Termo                          {$$.c = "0 " + $2.c + " -";}  
        |   '('    Conta ')'                      {$$.c = $2.c;}
        |                                         {$$.c = "";}
        ;

Termo :   Membro  Conta_Complexa  {$$.c = $1.c + $2.c;$$.retorno=$1.retorno;}
      ;

Conta   :   Termo   Conta_Simples {$$.c = $1.c + $2.c;$$.retorno=$1.retorno;}          
        ;

Jump_IF    : Expressao ';' SENAO            {contador++; $$.c = $3.c + " " + LABEL_ENDIF + to_string(contador) + " # " + LABEL_RIF + to_string(contador) + " " + $1.c + " " + LABEL_RENDIF + to_string(contador);}
           | '{' Continuacao '}' SENAO      {contador++; $$.c = $4.c + " " + LABEL_ENDIF + to_string(contador) + " # " + LABEL_RIF + to_string(contador) + $2.c + " "+ LABEL_RENDIF + to_string(contador);}
           ;

Jump_While      : Expressao ';'            {contador++; $$.c = LABEL_ENDWHILE + to_string(contador) + " # " + LABEL_RCORPO_WHILE + to_string(contador) + " " + $1.c + " " + LABEL_WHILE + to_string(contador) + " # " + LABEL_RENDWHILE + to_string(contador);}
                | '{' Continuacao '}'      {contador++; $$.c = LABEL_ENDWHILE + to_string(contador) + " # " + LABEL_RCORPO_WHILE + to_string(contador) + $2.c + " " + LABEL_WHILE + to_string(contador) + " # " + LABEL_RENDWHILE + to_string(contador);}
                ;

Jump_For        : Expressao ';'            {contador++; $$.c = LABEL_ENDFOR + to_string(contador) + " # " + LABEL_RCORPO_FOR + to_string(contador) + " " + $1.c;}
                | '{' Continuacao '}'      {contador++; $$.c = LABEL_ENDFOR + to_string(contador) + " # " + LABEL_RCORPO_FOR + to_string(contador) + $2.c;}
                | 
                ;



SENAO   :  ELSE Continuacao  {$$.c = $2.c;}
        |                     {$$.c = "";}
        ;

CMD :  IF   '(' Expressao ')' Jump_IF                              {$$.c = $3.c + " " + LABEL_IF + to_string(contador) + " ?" + $5.c;}
        |  FOR  '(' Expressao ';'  Expressao ';' Expressao ')' Jump_For{$$.c = $3.c + " " + LABEL_RFOR + to_string(contador) + " " + $5.c + " " + LABEL_CORPO_FOR + to_string(contador) + " ? " + $9.c + " " + $7.c + " " + LABEL_FOR + to_string(contador) + " # " + LABEL_RENDFOR + to_string(contador);}
        | WHILE '(' Expressao ')' Jump_While                           {$$.c = LABEL_RWHILE + to_string(contador) + " " + $3.c + " " + LABEL_CORPO_WHILE + to_string(contador) + " ? " + $5.c;}
        ;

Expressao       :   Declaracao              {$$.c = $1.c;}
                |   Conta   Expressao       {$$.c = $1.c + $2.c;}   
                ;

Continuacao  : Expressao ';' Continuacao         {$$.c = " " + $1.c + $3.c;}
             | CMD       Continuacao         {$$.c = " " + $1.c + $2.c;}
             | ';'   Continuacao                 {$$.c = $2.c;}
             |                                   {$$.c = "";}
             ;


%%

#include "lex.yy.c"

void setVar(string var, int linha){
        map<string,int>::iterator it;
        for (it = var_declaradas.begin(); it != var_declaradas.end(); ++it){
                if(var == it->first) motrar_erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) +".");
        }
        var_declaradas[var] = linha;
}

void checkVar(string var){
        map<string,int>::iterator it;
        for (it = var_declaradas.begin(); it != var_declaradas.end(); ++it){
                if(var == it->first) return;
        }
        motrar_erro("a variável '" + var + "' não foi declarada.");
}

void ReplaceStringInPlace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

string printToken(int numToken, string tk){
        return "";
}

void mostrar(string c){
   int pc_nolabel = 0;
   bool palavra = false;
   bool palavra2 = false;
   bool palavra3 = false;
   bool label = false;
   map<string,int> instPC;
   string label_in_process = "";
   string tk = "";

   for(int pc = 0; pc != c.size() ; pc++) {
     
        if(c[pc] == ';'){
                label = true;
                tk += c[pc];
                continue;
        }

        if(label){
                if(c[pc] == ' '){
                        label = false;
                        instPC[label_in_process] = pc_nolabel;
                        label_in_process = "";
                }else{
                        label_in_process += c[pc];
                        tk += c[pc];
                }

                continue;       
        }

        if(c[pc] == '"'){
                if(!palavra){
                        palavra = true;
                }else{
                        palavra = false;
                }
                continue;
        }

        if(palavra){
                tk += c[pc];
                continue;
        }

        if(c[pc] == '\''){
                if(!palavra3 && !palavra){
                        palavra3 = true;
                }else{
                        if(!palavra){
                                palavra3 = false;
                        }
                }
                continue;
        }

        

        if(c[pc] == ':'){
                if(!palavra2){
                        palavra2 = true;
                        tk += c[pc];
                }

                continue;
        }
        
        
        if(palavra2){
                if(c[pc] == ' '){
                        palavra2 = false;
                        tk = printToken(pc_nolabel,tk);
                        pc_nolabel++;
                } else{
                        tk += c[pc];
                }
                continue;
        }
        
        if(c[pc] == ' ') {
                tk = printToken(pc_nolabel, tk);
                pc_nolabel++;
                continue;
        }else{
                if(c[pc] == '&' || c[pc] == '@') {
                        tk = printToken(pc_nolabel, tk);
                        pc_nolabel++;
                        tk = c[pc];
                        continue;
                }
        }

        tk += c[pc];
   }

   map<string,int>::iterator it;
   for(it=instPC.begin(); it!=instPC.end(); ++it){
      ReplaceStringInPlace(c, ":" + it->first, to_string(it->second)); 
      ReplaceStringInPlace(c, ";" + it->first + " ", ""); 
   }
        
   cout << c;

}

void motrar_erro( string msg ) {
  cout << "Erro: " << msg << endl;
  exit(0); 

}


void yyerror( const char* st ) {
   cerr << st << endl; 
   cerr << "Proximo a: " << yytext << endl;
   exit( 1 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  return 0;
}