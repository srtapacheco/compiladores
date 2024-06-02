%{

extern "C" int yylex();  


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

int contador = 0, linha = 0, coluna = 1, locais = 0, declaracaoAntecedente = 0;

string declaracao = "";

int token(int tk);

void exibir_codigo_processado(string codigo);
void exibir_erro(string codigo);

int yyparse();
void yyerror(const char *);

void set_var(string var);
void check_var(string var);


string enderecoPraFrente(string nome);
string enderecoResolvido(string nome);
string declarar(string var);
string declarar_arg(vector<string> args);
string acessar_campo(string nome_objeto, string campo);
string acessar_objeto(string nome_var);
string jumpComandos(string label_endereco_final, string label_endereco_corpo);
void ReplaceStringInPlace(std::string& subject, const std::string& search,const std::string& replace);
string asm_trim(string asm_command);
string declara_funcao(string nome, string parametros, string corpo);
string acessar_variavel(string nome_var);

#define YYSTYPE Atributos

map<string,int> variaveis_globais;
map<string, map<string,int>> variaveis_locais;

string undefined = "undefined";
string retorno_padrao = undefined + " @" + " '&retorno'" + " @" + " ~";

string funcoes = "";
map<string, string> retornos;

bool escopo_local = false;

string funcao = "";
string id = "";
int args = 0;

struct Atributos {
    string codigo;
    string retorno;
    int parametros;
    vector<string> argumentos;
    
    Atributos() : codigo(""), retorno(""), parametros(0) {}

    void adicionar_codigo(const string& cod) {
        codigo += cod + " ";
    }

    void adicionar_argumento(const string& arg) {
        argumentos.push_back(arg);
    }

    string obter_retorno() const {
        return retorno.empty() ? "" : retorno;
    }
};



%}

%token _INT _FLOAT _STRING _STRING2
%token _ID _FOR _IF _ELSE _LET  _PRINT  
%token _MAISMAIS _MA_IG _IGUAL _DIF _ME_IG
%token  _COMENTARIO  _CONST _VAR _CONCAT  _NOVO_OBJETO _WHILE _FUNCTION _BOLEANO _RETURN _ASM _ARRAY

%start S

%%

Atribuicao_Objeto2      : Objeto '=' Atribuicao_Objeto2  {$$.codigo = $1.codigo + $3.codigo + " " + $1.codigo + "[@] [=] ^ ";}
                        | Conta                          {$$.codigo = $1.codigo + "[=] ^ ";}
                        ;

Atribuicao_Objeto       : '=' Atribuicao_Objeto2    {$$.codigo = $2.codigo;}   
                        |                           {$$.codigo = "[@] ";}
                        ;

Atribuicao_MIGUAL       : '=' Conta      {$$.codigo = $2.codigo + " + = ^ ";}
                        ;

AtribuicaoObj_MIGUAL    : '=' Conta      {$$.codigo = $2.codigo + " + [=] ^ ";}
                        ;

Atribuicao_ID2 : _ID '=' Atribuicao_ID2  {$$.codigo = $1.codigo + $3.codigo + acessar_variavel($1.codigo) + "= ^ ";}
               | Conta                   {$$.codigo = $1.codigo + "= ^ ";}
               ;

Atribuicao_ID   : '=' Atribuicao_ID2      {$$.codigo = " " + $2.codigo;}
                |                         {string space = " ";$$.codigo = " @" + space;}
                ;

Conta_Simples :   '-' Termo Conta_Simples               {$$.codigo = $2.codigo + "- " + $3.codigo;} 
              |   '+' Termo Conta_Simples               {$$.codigo = $2.codigo + "+ " + $3.codigo;} 
              |   '>' Termo Conta_Simples               {$$.codigo = $2.codigo + $3.codigo + "> ";}
              |   '<' Termo Conta_Simples               {$$.codigo = $2.codigo + $3.codigo + "< ";}
              |   _IGUAL Termo Conta_Simples               {$$.codigo = $2.codigo + $3.codigo + "== ";}
              |                                         {$$.codigo = "";}
              ;

Conta_Complexa2   :   '^' Termo {$$.codigo = " " + $2.codigo + " ^";} 
                  |   '!' Termo {$$.codigo = " fat #" + $2.codigo;}
                  |             {$$.codigo = "";}  
                  ;

Conta_Complexa    :   '*' Membro Conta_Complexa2 Conta_Complexa {$$.codigo = $2.codigo + $3.codigo + "* " + $4.codigo;}
                  |   '/' Termo                                 {$$.codigo = $2.codigo + "/ ";}
                  |   '%' Membro Conta_Complexa2 Conta_Complexa {$$.codigo = $2.codigo + $3.codigo + "% " + $4.codigo;}
                  |   Conta_Complexa2                           {$$.codigo = $1.codigo;}
                  |                                             {$$.codigo = "";}
                  ;

Declaracao_Complexa     :  Declaracao_Simples                   {$$.codigo = $1.codigo; $$.argumentos = $1.argumentos;}
                        | ',' _ID '=' Conta Declaracao_Complexa {$$.codigo = declarar($2.codigo) + $2.codigo + " " + $4.codigo + "= ^ "+ $5.codigo;}
                        |                                       {$$.codigo = "";}
                        ;

Declaracao_Simples  : ',' _ID Declaracao_Simples  {$$.codigo = declarar($2.codigo) + $3.codigo; $3.argumentos.push_back($2.codigo); $$.argumentos = $3.argumentos;}
                    |                             {$$.codigo = ""; }
                    ;

Expressao_Declaracao  : _ID  '=' Conta Declaracao_Complexa    {$$.codigo = declarar($1.codigo) + $1.codigo + " " + $3.codigo + "= ^ " + $4.codigo;}
                      | _ID  Declaracao_Complexa              {$$.codigo = declarar($1.codigo) + $2.codigo; $2.argumentos.push_back($1.codigo); $$.argumentos = $2.argumentos;}
                      ;

Declaracao  : _LET   {declaracao = $1.codigo;} Expressao_Declaracao    {$$.codigo = $3.codigo;}
            | _CONST {declaracao = $1.codigo;} Expressao_Declaracao    {$$.codigo = $3.codigo;}
            | _VAR   {declaracao = $1.codigo;} Expressao_Declaracao    {$$.codigo = $3.codigo;}
            |                                 {$$.codigo = "";}
            ;

Membro_Simples  :   _STRING        {$$.codigo = $1.codigo + " ";}
                |   _INT           {$$.codigo = $1.codigo + " ";}
                |   _FLOAT         {$$.codigo = $1.codigo + " ";}
                |  _NOVO_OBJETO    {$$.codigo = "{} ";}
                |  _ARRAY          {$$.codigo = "[] ";}
                ;

Dimensoes       :   '[' Conta ']' Dimensoes {$$.adicionar_codigo("[@] " + $2.codigo + $2.obter_retorno() + $4.codigo);}
                |                           {$$.codigo = "";}
                ;


Array   :       _ID  '[' Conta ']'                         {$$.codigo = acessar_objeto($1.codigo) + $3.codigo;}  
        |       _ID  '[' Conta ']'  Dimensoes              {$$.codigo = acessar_campo($1.codigo, $3.codigo) + $3.obter_retorno() + $5.codigo;}
        |       '(' _ID ')'  '[' Conta ']'  Dimensoes      {$$.codigo = acessar_campo($2.codigo, $5.codigo) + $5.obter_retorno() + $7.codigo;}
        ;

Campo_Objeto    :  Array                             {$$.codigo = $1.codigo;}
                |  _ID                               {$$.codigo = $1.codigo + " ";}
                ;

Continuacao_Objeto      :   Campo_Objeto  Continuacao_Objeto          {$$.codigo = $1.codigo + $2.codigo;}
                        |   Array                                     {$$.codigo = $1.codigo;}
                        |   '.'  Campo_Objeto Continuacao_Objeto      {string space = " ";$$.codigo = " [@]" + space + $2.codigo + $3.codigo;}
                        |                                             {$$.codigo = "";}
                        ;

Objeto  :   _ID  '.' Continuacao_Objeto                        {$$.codigo = acessar_campo($1.codigo, $3.codigo);}
        |   '(' _ID  ')' '.' Continuacao_Objeto                {$$.codigo = acessar_campo($2.codigo, $5.codigo);}
        |   Array                                              {$$.codigo = $1.codigo;}
        |   '(' Objeto ')' Dimensoes                           {$$.codigo = $2.codigo + $4.codigo;}
        ;

Casos_ID        : _ID _CONCAT          Atribuicao_MIGUAL   {$$.codigo = $1.codigo + acessar_variavel($1.codigo) + $3.codigo;}
                | _ID _MAISMAIS      Conta_Simples       {$$.codigo = $1.codigo + " @" + $3.codigo + " " + $1.codigo + " " + acessar_variavel($1.codigo) + "1 + = ^ ";}
                | _ID Funcao                             {$$.codigo = $2.codigo + acessar_variavel($1.codigo) + "$ ";}
                | '(' _ID ')' Funcao                     {$$.codigo = $4.codigo + acessar_variavel($2.codigo) + "$ ";}
                | _ID Atribuicao_ID                      {check_var($1.codigo);$$.codigo = $1.codigo + $2.codigo; $$.retorno = $2.codigo == " @ "? "" : acessar_variavel($1.codigo);}
                ;

Casos_Objeto    : Objeto    Atribuicao_Objeto                       {$$.codigo = $1.codigo + $2.codigo;}
                | Objeto   _CONCAT               AtribuicaoObj_MIGUAL {$$.codigo = $1.codigo + " " + acessar_objeto($1.codigo) + $3.codigo;}
                | Objeto   _MAISMAIS                                {$$.codigo = $1.codigo + acessar_variavel($1.codigo) + "1 + [=] ^ " + acessar_variavel($1.codigo);}
                | Objeto   Funcao                                   {$$.codigo = $2.codigo + $1.codigo + "[@] $ ";}
                ;

Membro  :   Membro_Simples                        {$$.codigo = $1.codigo;}      
        |   Casos_Objeto                          {$$.codigo = $1.codigo;}
        |   Casos_ID                              {$$.codigo = $1.codigo; $$.retorno=$1.retorno;}
        |   Funcao                                {$$.codigo = $1.codigo;}
        |   '+'    Conta                          {$$.codigo = $2.codigo;}
        |   '-'    Termo                          {$$.codigo = "0 " + $2.codigo + "- ";}  
        |   '('    Conta ')' Membro               {$$.codigo = $2.codigo;}
        |   _BOLEANO                              {$$.codigo = $1.codigo + " ";}
        ;

Termo :   Membro  Conta_Complexa  {$$.codigo = $1.codigo + $2.codigo;$$.retorno=$1.retorno;}
      ;

Conta   :   Termo   Conta_Simples {$$.codigo = $1.codigo + $2.codigo;$$.retorno=$1.retorno;}          
        ;

Argumentos  : Conta Argumentos    {$$.codigo = $1.codigo + $1.obter_retorno() + $2.codigo; $$.parametros = 1 + $2.parametros;}
            | ','  Argumentos     {$$.codigo = $2.codigo; $$.parametros = $2.parametros;}
            |                     {$$.codigo = ""; $$.parametros = 0;}
            ;

Parametros : Expressao_Declaracao {$$.codigo = declarar_arg($1.argumentos);}
           |                      {$$.codigo = "";}
           ;

Bloco_Funcao : '{' Continuacao Retorno '}' {$$.codigo = $2.codigo + $3.codigo;}
             ;

Retorno : _RETURN Conta {$$.codigo = $2.codigo + acessar_variavel("'&retorno'") + "~ " + retorno_padrao;}
        |               {$$.codigo = retorno_padrao;}
        ;

Funcao  : _FUNCTION _ID {funcao = $2.codigo; escopo_local = true;} '(' Parametros ')' Bloco_Funcao {$$.codigo = declara_funcao($2.codigo, $5.codigo, $7.codigo);}
        | '(' Argumentos ')'                      {$$.codigo = $2.codigo + to_string($2.parametros) + " ";}
        ;

Jump_IF    : Expressao ';' SENAO           {contador++;$$.codigo = $3.codigo + jumpComandos("end_if", "then_") + $1.codigo + enderecoResolvido("end_if") + " ";}
           | Bloco SENAO                   {contador++;$$.codigo = $2.codigo + jumpComandos("end_if", "then_") + $1.codigo + enderecoResolvido("end_if") + " ";}
           ;

Jump_While      : Expressao ';'            {contador++;$$.codigo = jumpComandos("end_while", "whilec_") + $1.codigo + " " + jumpComandos("while_", "end_while");}
                | Bloco                    {contador++;$$.codigo = jumpComandos("end_while", "whilec_") + $1.codigo + " " + jumpComandos("while_", "end_while");}
                ;

Jump_For        : Expressao ';'            {contador++;$$.codigo = jumpComandos("end_for", "forc_") + $1.codigo;}
                | Bloco                    {contador++;$$.codigo = jumpComandos("end_for", "forc_") + $1.codigo;}
                | 
                ;       

SENAO   :  _ELSE Continuacao  {$$.codigo = $2.codigo;}
        |                     {$$.codigo = "";}
        ;

Comando :  _IF   '(' Expressao ')'  Jump_IF                              {$$.codigo = $3.codigo + enderecoPraFrente("then_") + " ?" + $5.codigo;}
        |  _FOR  '(' Expressao ';'  Expressao ';' Expressao ')' Jump_For {$$.codigo = $3.codigo + " " + enderecoResolvido("for_") + " " + $5.codigo + " " + enderecoPraFrente("forc_") + " ?" + $9.codigo + " " + $7.codigo + " " + enderecoPraFrente("for_") + " # " + enderecoResolvido("end_for");}
        | _WHILE '(' Expressao ')'  Jump_While                           {$$.codigo = enderecoResolvido("while_") + " " + $3.codigo + " " + enderecoPraFrente("whilec_") + " ?" + $5.codigo;}
        ;

Retorno_Comandos : _RETURN Conta {$$.codigo = $2.codigo + acessar_variavel("'&retorno'") + "~ ";}
                 |               {$$.codigo = "";}
                 ;

Bloco : '{' {escopo_local = true; funcao = "local" + to_string(locais++);} Continuacao Retorno_Comandos'}' {escopo_local=false;$$.codigo = "<{ " +  $3.codigo + $4.codigo + "}> ";}
      | Retorno_Comandos                    {$$.codigo = $1.codigo;}
      ;

Expressao       :   Declaracao                     {$$.codigo = $1.codigo;}
                |   _ID      Funcao      Expressao          {$$.codigo = $2.codigo + acessar_variavel($1.codigo) + "$ ^ " + $3.codigo;}
                | '(' _ID ')' Funcao     Expressao          {$$.codigo = $4.codigo + acessar_variavel($2.codigo) + "$ ^ " + $5.codigo;}
                |   Objeto   Funcao      Expressao          {$$.codigo = $2.codigo + $1.codigo + "[@] $ ^ " + $3.codigo;}
                |   Conta   Expressao              {$$.codigo = $1.codigo + $2.codigo;}
                |   Bloco   Expressao              {$$.codigo = $1.codigo + $2.codigo;}
                |   _ASM                           {$$.codigo = asm_trim($1.codigo);}
                ;

Continuacao  : Expressao ';' Continuacao         {$$.codigo = $1.codigo + $3.codigo;}
             | Comando    Continuacao            {$$.codigo = $1.codigo + $2.codigo;}
             | ';'   Continuacao                 {$$.codigo = $2.codigo;}         
             |                                   {$$.codigo = "";}
             ;

S :   Expressao ';' Continuacao         {exibir_codigo_processado($1.codigo + $3.codigo + "." + funcoes);}
        |   Comando       Continuacao         {exibir_codigo_processado($1.codigo + $2.codigo + "." + funcoes);}
        ;  
%%

#include "lex.yy.c"

string declara_funcao(string nome, string parametros, string corpo){
        contador++; 
        escopo_local = false; 
        funcao = "";
        string label = enderecoPraFrente(nome);
        funcoes = funcoes + " " + enderecoResolvido(nome) + " " + parametros + corpo;
        set_var(nome);
        return nome + " & " + nome + " {} = '&funcao' " + label + " [=] ^ ";

}

string asm_trim(string asm_command){
        ReplaceStringInPlace(asm_command, "asm{", "");
        ReplaceStringInPlace(asm_command, "}", "");
        return asm_command + " ^ ";
}

string acessar_objeto(string nome_var){
        return nome_var + "[@]" + " ";
}

string acessar_variavel(string nome_var){
        return nome_var + " @" + " ";
}

string acessar_campo(string nome_objeto, string campo){
        campo = " " + campo;
        return nome_objeto + " @" + campo;
}


string declarar(string var){
        set_var(var);
        if(declaracao == "var" && declaracaoAntecedente){
                declaracaoAntecedente = 0;
                return "";
        }
        return var + " & ";
}

string declarar_arg(vector<string> args){
        int count = args.size() - 1;
        string result = "";
        string space = "";

        for(string var : args){
                result = var + " & " + var + " " + acessar_variavel("arguments") +  to_string(count) + " [@] = ^" + space + result; 
                space = " ";
                count--;
        }

        return result + " ";
}


string enderecoPraFrente(string nome){
        return ":" + nome + to_string(contador);
}

string enderecoResolvido(string nome){
        return ";" + nome + to_string(contador);
}

string jumpComandos(string label_endereco_final, string label_endereco_corpo){
        return enderecoPraFrente(label_endereco_final) + " # " + enderecoResolvido(label_endereco_corpo) + " ";
}

void set_var(string var){
        map<string,int>::iterator it;

        int linhaAtual = linha + 1;
        if(escopo_local){
                map<string, int> vars = variaveis_locais[funcao];
                
                for (it = vars.begin(); it != vars.end(); ++it){
                        if(var == it->first && declaracao != "var") exibir_erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) +".");
                }
                variaveis_locais[funcao][var] = linhaAtual;
        }else{
                for (it = variaveis_globais.begin(); it != variaveis_globais.end(); ++it){
                        if(var == it->first & !escopo_local && declaracao != "var") exibir_erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) + ".");
                        if(var == it->first & !escopo_local && declaracao == "var") declaracaoAntecedente = 1;
                }
                variaveis_globais[var] = linhaAtual;
        }        

}

void check_var(string var){
        map<string,int>::iterator it;
        if(escopo_local){
                map<string, int> vars = variaveis_locais[funcao];
                for (it = vars.begin(); it != vars.end(); ++it){
                        if(var == it->first) return;
                } 
        }else{
                for (it = variaveis_globais.begin(); it != variaveis_globais.end(); ++it){
                        if(var == it->first) return;
                }
                exibir_erro("a variável '" + var + "' não foi declarada.");
        }  
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

void exibir_codigo_processado(string codigo){
        
   int pc_nolabel = 0;
   bool palavra = false;
   bool palavra2 = false;
   bool palavra3 = false;
   bool label = false;
   map<string,int> instPC;
   string label_in_process = "";
   string tk = "";

   for(int pc = 0; pc != codigo.size() ; pc++) {
     
        if(codigo[pc] == ';'){
                label = true;
                tk += codigo[pc];
                continue;
        }

        if(codigo[pc] == '"' || codigo[pc] == '\''){
                palavra = !palavra;
        }

        if(label){
                if(codigo[pc] == ' '){
                        label = false;
                        instPC[label_in_process] = pc_nolabel;
                        
                        label_in_process = "";
                        tk = printToken(pc_nolabel, tk);
                        pc_nolabel++;
                }else{
                        label_in_process += codigo[pc];
                        tk += codigo[pc];
                }

                continue;       
        }
        
        if(codigo[pc] == ' ' && !palavra && tk != "println" && tk != "println #") {
                tk = printToken(pc_nolabel, tk);
                pc_nolabel++;
                continue;
        }

        tk += codigo[pc];

   }

   map<string,int>::iterator it;
   for(it=instPC.begin(); it!=instPC.end(); ++it){
      ReplaceStringInPlace(codigo, ":" + it->first, to_string(it->second)); 
      ReplaceStringInPlace(codigo, ";" + it->first + " ", ""); 
   }
        
   cout << codigo;

}

void exibir_erro( string msg ) {
  cout << "Erro: " << msg;
  exit(0); 
}


int token( int tk ) {  
  yylval.codigo = yytext; 

  return tk;
}

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Proximo a: %s\nCoord: %d-%d\n", yytext, linha, coluna);
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}