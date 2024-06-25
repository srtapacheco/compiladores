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

int contador = 0, linha = 0, coluna = 1, args = 0, locais = 0, declaracaoAntecedente = 0;

string declaracao = "";

int token(int tk);

void exibir_codigo_processado(string valor);
void exibir_erro(string valor);

int yyparse();
void yyerror(const char *);

void setVar(string var);
void checkVar(string var);
string enderecoPraFrente(string nome);
string enderecoResolvido(string nome);
string declarar(string var);
string declarar_arg(vector<string> args);
string acessar_campo(string nome_objeto, string campo);
string acessar_objeto(string nome_var);
string jumpComandos(string label_endereco_final, string label_endereco_corpo);
void ReplaceStringInPlace(std::string& subject, const std::string& search, const std::string& replace);
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

struct Atributos {
    string valor;
    string retorno;
    int parametros;
    vector<string> args_value;

    Atributos() : valor(""), retorno(""), parametros(0) {}

    string getRetorno() const {
        return (retorno == " " + valor) ? "" : retorno;
    }
};
%}

%token _INT _FLOAT _STRING _STRING2
%token _ID _FOR _IF _ELSE _LET  _PRINT  
%token _MAISMAIS _MA_IG _IGUAL _DIF _ME_IG
%token  _COMENTARIO  _CONST _VAR _CONCAT  _NOVO_OBJETO _WHILE _FUNCTION _BOLEANO _RETURN _ASM _ARRAY

%start S

%%

Atribuicao_Objeto2      : Objeto '=' Atribuicao_Objeto2  {$$.valor = $1.valor + $3.valor + " " + $1.valor + "[@] [=] ^ ";}
                        | Conta                          {$$.valor = $1.valor + "[=] ^ ";}
                        ;

Atribuicao_Objeto       : '=' Atribuicao_Objeto2    {$$.valor = $2.valor;}   
                        |                           {$$.valor = "[@] ";}
                        ;

Atribuicao_MIGUAL       : '=' Conta      {$$.valor = $2.valor + " + = ^ ";}
                        ;

AtribuicaoObj_MIGUAL    : '=' Conta      {$$.valor = $2.valor + " + [=] ^ ";}
                        ;

Atribuicao_ID2 : _ID '=' Atribuicao_ID2  {$$.valor = $1.valor + $3.valor + acessar_variavel($1.valor) + "= ^ ";}
               | Conta                   {$$.valor = $1.valor + "= ^ ";}
               ;

Atribuicao_ID   : '=' Atribuicao_ID2      {$$.valor = " " + $2.valor;}
                |                         {string space = " ";$$.valor = " @" + space;}
                ;

Conta_Simples :   '-' Termo Conta_Simples               {$$.valor = $2.valor + "- " + $3.valor;} 
              |   '+' Termo Conta_Simples               {$$.valor = $2.valor + "+ " + $3.valor;} 
              |   '>' Termo Conta_Simples               {$$.valor = $2.valor + $3.valor + "> ";}
              |   '<' Termo Conta_Simples               {$$.valor = $2.valor + $3.valor + "< ";}
              |   _IGUAL Termo Conta_Simples               {$$.valor = $2.valor + $3.valor + "== ";}
              |                                         {$$.valor = "";}
              ;

Conta_Complexa2   :   '^' Termo {$$.valor = " " + $2.valor + " ^";} 
                  |   '!' Termo {$$.valor = " fat #" + $2.valor;}
                  |             {$$.valor = "";}  
                  ;

Conta_Complexa    :   '*' Membro Conta_Complexa2 Conta_Complexa {$$.valor = $2.valor + $3.valor + "* " + $4.valor;}
                  |   '/' Termo                                 {$$.valor = $2.valor + "/ ";}
                  |   '%' Membro Conta_Complexa2 Conta_Complexa {$$.valor = $2.valor + $3.valor + "% " + $4.valor;}
                  |   Conta_Complexa2                           {$$.valor = $1.valor;}
                  |                                             {$$.valor = "";}
                  ;

Declaracao_Complexa     :  Declaracao_Simples                   {$$.valor = $1.valor; $$.args_value = $1.args_value;}
                        | ',' _ID '=' Conta Declaracao_Complexa {$$.valor = declarar($2.valor) + $2.valor + " " + $4.valor + "= ^ "+ $5.valor;}
                        |                                       {$$.valor = "";}
                        ;

Declaracao_Simples  : ',' _ID Declaracao_Simples  {$$.valor = declarar($2.valor) + $3.valor; $3.args_value.push_back($2.valor); $$.args_value = $3.args_value;}
                    |                             {$$.valor = ""; }
                    ;

Expressao_Declaracao  : _ID  '=' Conta Declaracao_Complexa    {$$.valor = declarar($1.valor) + $1.valor + " " + $3.valor + "= ^ " + $4.valor;}
                      | _ID  Declaracao_Complexa              {$$.valor = declarar($1.valor) + $2.valor; $2.args_value.push_back($1.valor); $$.args_value = $2.args_value;}
                      ;

Declaracao  : _LET   {declaracao = $1.valor;} Expressao_Declaracao    {$$.valor = $3.valor;}
            | _CONST {declaracao = $1.valor;} Expressao_Declaracao    {$$.valor = $3.valor;}
            | _VAR   {declaracao = $1.valor;} Expressao_Declaracao    {$$.valor = $3.valor;}
            |                                 {$$.valor = "";}
            ;

Membro_Simples  :   _STRING        {$$.valor = $1.valor + " ";}
                |   _INT           {$$.valor = $1.valor + " ";}
                |   _FLOAT         {$$.valor = $1.valor + " ";}
                |  _NOVO_OBJETO      {$$.valor = "{} ";}
                |  _ARRAY          {$$.valor = "[] ";}
                ;

Dimensoes       :   '[' Conta ']' Dimensoes {$$.valor ="[@] " + $2.valor + $2.getRetorno() + $4.valor;}
                |                           {$$.valor = "";}
                ;


Array   :       _ID  '[' Conta ']'                         {$$.valor = acessar_objeto($1.valor) + $3.valor;}  
        |       _ID  '[' Conta ']'  Dimensoes              {$$.valor = acessar_campo($1.valor, $3.valor) + $3.getRetorno() + $5.valor;}
        |       '(' _ID ')'  '[' Conta ']'  Dimensoes      {$$.valor = acessar_campo($2.valor, $5.valor) + $5.getRetorno() + $7.valor;}
        ;

Campo_Objeto    :  Array                             {$$.valor = $1.valor;}
                |  _ID                               {$$.valor = $1.valor + " ";}
                ;

Continuacao_Objeto      :   Campo_Objeto  Continuacao_Objeto          {$$.valor = $1.valor + $2.valor;}
                        |   Array                                     {$$.valor = $1.valor;}
                        |   '.'  Campo_Objeto Continuacao_Objeto      {string space = " ";$$.valor = " [@]" + space + $2.valor + $3.valor;}
                        |                                             {$$.valor = "";}
                        ;

Objeto  :   _ID  '.' Continuacao_Objeto                        {$$.valor = acessar_campo($1.valor, $3.valor);}
        |   '(' _ID  ')' '.' Continuacao_Objeto                {$$.valor = acessar_campo($2.valor, $5.valor);}
        |   Array                                              {$$.valor = $1.valor;}
        |   '(' Objeto ')' Dimensoes                           {$$.valor = $2.valor + $4.valor;}
        ;

Casos_ID        : _ID _CONCAT          Atribuicao_MIGUAL   {$$.valor = $1.valor + acessar_variavel($1.valor) + $3.valor;}
                | _ID _MAISMAIS      Conta_Simples       {$$.valor = $1.valor + " @" + $3.valor + " " + $1.valor + " " + acessar_variavel($1.valor) + "1 + = ^ ";}
                | _ID Funcao                             {$$.valor = $2.valor + acessar_variavel($1.valor) + "$ ";}
                | '(' _ID ')' Funcao                     {$$.valor = $4.valor + acessar_variavel($2.valor) + "$ ";}
                | _ID Atribuicao_ID                      {checkVar($1.valor);$$.valor = $1.valor + $2.valor; $$.retorno = $2.valor == " @ "? "" : acessar_variavel($1.valor);}
                ;

Casos_Objeto    : Objeto    Atribuicao_Objeto                       {$$.valor = $1.valor + $2.valor;}
                | Objeto   _CONCAT               AtribuicaoObj_MIGUAL {$$.valor = $1.valor + " " + acessar_objeto($1.valor) + $3.valor;}
                | Objeto   _MAISMAIS                                {$$.valor = $1.valor + acessar_variavel($1.valor) + "1 + [=] ^ " + acessar_variavel($1.valor);}
                | Objeto   Funcao                                   {$$.valor = $2.valor + $1.valor + "[@] $ ";}
                ;

Membro  :   Membro_Simples                        {$$.valor = $1.valor;}      
        |   Casos_Objeto                          {$$.valor = $1.valor;}
        |   Casos_ID                              {$$.valor = $1.valor; $$.retorno=$1.retorno;}
        |   Funcao                                {$$.valor = $1.valor;}
        |   '+'    Conta                          {$$.valor = $2.valor;}
        |   '-'    Termo                          {$$.valor = "0 " + $2.valor + "- ";}  
        |   '('    Conta ')' Membro               {$$.valor = $2.valor;}
        |   _BOLEANO                              {$$.valor = $1.valor + " ";}
        ;

Termo :   Membro  Conta_Complexa  {$$.valor = $1.valor + $2.valor;$$.retorno=$1.retorno;}
      ;

Conta   :   Termo   Conta_Simples {$$.valor = $1.valor + $2.valor;$$.retorno=$1.retorno;}          
        ;

Argumentos  : Conta Argumentos    {$$.valor = $1.valor + $1.getRetorno() + $2.valor; $$.parametros = 1 + $2.parametros;}
            | ','  Argumentos     {$$.valor = $2.valor; $$.parametros = $2.parametros;}
            |                     {$$.valor = ""; $$.parametros = 0;}
            ;

Parametros : Expressao_Declaracao {$$.valor = declarar_arg($1.args_value);}
           |                      {$$.valor = "";}
           ;

Bloco_Funcao : '{' Continuacao Retorno '}' {$$.valor = $2.valor + $3.valor;}
             ;

Retorno : _RETURN Conta {$$.valor = $2.valor + acessar_variavel("'&retorno'") + "~ " + retorno_padrao;}
        |               {$$.valor = retorno_padrao;}
        ;

Funcao  : _FUNCTION _ID {funcao = $2.valor; escopo_local = true;} '(' Parametros ')' Bloco_Funcao {$$.valor = declara_funcao($2.valor, $5.valor, $7.valor);}
        | '(' Argumentos ')'                      {$$.valor = $2.valor + to_string($2.parametros) + " ";}
        ;

Jump_IF    : Expressao ';' SENAO           {contador++;$$.valor = $3.valor + jumpComandos("end_if", "then_") + $1.valor + enderecoResolvido("end_if") + " ";}
           | Bloco SENAO                   {contador++;$$.valor = $2.valor + jumpComandos("end_if", "then_") + $1.valor + enderecoResolvido("end_if") + " ";}
           ;

Jump_While      : Expressao ';'            {contador++;$$.valor = jumpComandos("end_while", "whilec_") + $1.valor + " " + jumpComandos("while_", "end_while");}
                | Bloco                    {contador++;$$.valor = jumpComandos("end_while", "whilec_") + $1.valor + " " + jumpComandos("while_", "end_while");}
                ;

Jump_For        : Expressao ';'            {contador++;$$.valor = jumpComandos("end_for", "forc_") + $1.valor;}
                | Bloco                    {contador++;$$.valor = jumpComandos("end_for", "forc_") + $1.valor;}
                | 
                ;       

SENAO   :  _ELSE Continuacao  {$$.valor = $2.valor;}
        |                     {$$.valor = "";}
        ;

Comando :  _IF   '(' Expressao ')'  Jump_IF                              {$$.valor = $3.valor + enderecoPraFrente("then_") + " ?" + $5.valor;}
        |  _FOR  '(' Expressao ';'  Expressao ';' Expressao ')' Jump_For {$$.valor = $3.valor + " " + enderecoResolvido("for_") + " " + $5.valor + " " + enderecoPraFrente("forc_") + " ?" + $9.valor + " " + $7.valor + " " + enderecoPraFrente("for_") + " # " + enderecoResolvido("end_for");}
        | _WHILE '(' Expressao ')'  Jump_While                           {$$.valor = enderecoResolvido("while_") + " " + $3.valor + " " + enderecoPraFrente("whilec_") + " ?" + $5.valor;}
        ;

Retorno_Comandos : _RETURN Conta {$$.valor = $2.valor + acessar_variavel("'&retorno'") + "~ ";}
                 |               {$$.valor = "";}
                 ;

Bloco : '{' {escopo_local = true; funcao = "local" + to_string(locais++);} Continuacao Retorno_Comandos'}' {escopo_local=false;$$.valor = "<{ " +  $3.valor + $4.valor + "}> ";}
      | Retorno_Comandos                    {$$.valor = $1.valor;}
      ;

Expressao       :   Declaracao                     {$$.valor = $1.valor;}
                |   _ID      Funcao      Expressao          {$$.valor = $2.valor + acessar_variavel($1.valor) + "$ ^ " + $3.valor;}
                | '(' _ID ')' Funcao     Expressao          {$$.valor = $4.valor + acessar_variavel($2.valor) + "$ ^ " + $5.valor;}
                |   Objeto   Funcao      Expressao          {$$.valor = $2.valor + $1.valor + "[@] $ ^ " + $3.valor;}
                |   Conta   Expressao              {$$.valor = $1.valor + $2.valor;}
                |   Bloco   Expressao              {$$.valor = $1.valor + $2.valor;}
                |   _ASM                           {$$.valor = asm_trim($1.valor);}
                ;

Continuacao  : Expressao ';' Continuacao         {$$.valor = $1.valor + $3.valor;}
             | Comando    Continuacao            {$$.valor = $1.valor + $2.valor;}
             | ';'   Continuacao                 {$$.valor = $2.valor;}         
             |                                   {$$.valor = "";}
             ;

S :   Expressao ';' Continuacao         {exibir_codigo_processado($1.valor + $3.valor + "." + funcoes);}
        |   Comando       Continuacao         {exibir_codigo_processado($1.valor + $2.valor + "." + funcoes);}
        ;  
%%

#include "lex.yy.c"

string declara_funcao(string nome, string parametros, string corpo){
        contador++; 
        escopo_local = false; 
        funcao = "";
        string label = enderecoPraFrente(nome);
        funcoes = funcoes + " " + enderecoResolvido(nome) + " " + parametros + corpo;
        setVar(nome);
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
        setVar(var);
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

void setVar(string var){
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

void checkVar(string var){
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

void exibir_codigo_processado(string valor){
    int pc_nolabel = 0;
    bool palavra = false;
    bool label = false;
    map<string,int> instPC;
    string label_in_process = "";
    string tk = "";

    for(int pc = 0; pc != valor.size(); pc++) {
        if(valor[pc] == ';'){
            label = true;
            tk += valor[pc];
            continue;
        }

        if(valor[pc] == '"' || valor[pc] == '\''){
            palavra = !palavra;
        }

        if(label){
            if(valor[pc] == ' '){
                label = false;
                instPC[label_in_process] = pc_nolabel;
                label_in_process = "";
                tk = printToken(pc_nolabel, tk);
                pc_nolabel++;
            }else{
                label_in_process += valor[pc];
                tk += valor[pc];
            }
            continue;       
        }
        
        if(valor[pc] == ' ' && !palavra && tk != "println" && tk != "println #") {
            tk = printToken(pc_nolabel, tk);
            pc_nolabel++;
            continue;
        }
        tk += valor[pc];
    }

    for(auto it=instPC.begin(); it!=instPC.end(); ++it){
        ReplaceStringInPlace(valor, ":" + it->first, to_string(it->second)); 
        ReplaceStringInPlace(valor, ";" + it->first + " ", ""); 
    }
    
    cout << valor;
}

void exibir_erro(string msg) {
    cerr << "Erro: " << msg << endl;
    exit(1); 
}


int token( int tk ) {  
  yylval.valor = yytext; 

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
