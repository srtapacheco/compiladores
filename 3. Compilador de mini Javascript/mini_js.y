%{

extern "C" int yylex(); 

#include <iostream>  
#include <stdio.h>   
#include <stdlib.h>  
#include <string>    
#include <map>     
#include <list>       

using namespace std;

int contador_rotulo = 0, linha_atual = 1;
int obter_valor_token(int tk);

map<string, int> variaveis_declaradas;


void processar_e_exibir_codigo(string valor);
void exibir_erro(string valor);
 
int yyparse();
void yyerror(const char *);
void declarar_variavel(string var, int linha_atual);
void verificar_variavel(string var);

  
struct atributos_token {
    string valor;
    string retorno;
    atributos_token(const string& val = "", const string& ret = "") : valor(val), retorno(ret) {}
    string obterRetorno() const {
        return (valor.empty() || retorno != " " + valor) ? retorno : "";
    }
};


#define YYSTYPE atributos_token

%}

%token _ID _FOR _IF _ELSE _INT _FLOAT _MAIG _MEIG _IG _DIF _STRING _STRING2 _COMENTARIO _PRINT _LET _CONST _VAR _CONC _MAISMAIS _NOVO_OBJETO _WHILE

%start Entrada

%%

Argumentos  : Conta               {$$.valor = $1.valor;}
            | Conta ',' Conta     {$$.valor = $1.valor + " " + $3.valor;}
            |                     {$$.valor = "";}
            ;

Atribuicao_Objeto2      : Objeto '=' Atribuicao_Objeto2  {$$.valor = " " +$1.valor + $3.valor + " " + $1.valor + "[@]" + " [=] ^";}
                        | Conta                          {$$.valor = " " + $1.valor + " [=] ^";}
                        ;

Atribuicao_Objeto       : '=' Atribuicao_Objeto2    {$$.valor = $2.valor;}   
                        |                           {$$.valor = "[@]";}
                        ;

Atribuicao_MIGUAL       : '=' Conta      {$$.valor = $2.valor + " + = ^";}
                        ;

AtribuicaoObj_MIGUAL    : '=' Conta      {$$.valor = $2.valor + " + [=] ^";}
                        ;

Atribuicao_ID2 : _ID '=' Atribuicao_ID2  {$$.valor = " " +$1.valor + $3.valor + " " + $1.valor + "@" + " = ^";}
               | Conta                   {$$.valor = " " + $1.valor + " = ^";}
               ;

Atribuicao_ID   : '=' Atribuicao_ID2      {$$.valor = $2.valor;}
                |                         {$$.valor = "@";}
                ;

Conta_Simples :   '-' Termo Conta_Simples               {$$.valor = " " + $2.valor + " -" + $3.valor;} 
              |   '+' Termo Conta_Simples               {$$.valor = " " + $2.valor + " +" + $3.valor;} 
              |   '>' Termo Conta_Simples               {$$.valor = " " + $2.valor + $3.valor + " >";}
              |   '<' Termo Conta_Simples               {$$.valor = " " + $2.valor + $3.valor + " <";}
              |   _IG Termo Conta_Simples               {$$.valor = " " + $2.valor + $3.valor + " ==";}
              |                                         {$$.valor = "";}
              ;

Conta_Complexa2   :   '^' Termo {$$.valor = " " + $2.valor + " ^";} 
                  |   '!' Termo {$$.valor = " fat #" + $2.valor;}
                  |             {$$.valor = "";}  
                  ;

Conta_Complexa    :   '*' Membro Conta_Complexa2 Conta_Complexa {$$.valor = " " + $2.valor + $3.valor + " *" + $4.valor;}
                  |   '/' Termo                                 {$$.valor = " " + $2.valor + " /";}
                  |   Conta_Complexa2                           {$$.valor = $1.valor;}
                  |                                             {$$.valor = "";}
                  ;

Funcao  : _ID '(' Argumentos ')'  {$$.valor = $3.valor + " " + $1.valor + " #";}
        | _PRINT  Argumentos      {$$.valor = $2.valor + " print #";}
        ;
        
Declaracao_Complexa     :  Declaracao_Simples                   {$$.valor = $1.valor;}
                        | ',' _ID '=' Conta Declaracao_Complexa {declarar_variavel($2.valor, linha_atual);$$.valor = " " + $2.valor + "& " + $2.valor + " " + $4.valor + " = ^"+ $5.valor;}
                        |                                       {$$.valor = "";}
                        ;

Declaracao_Simples  : ',' _ID Declaracao_Simples  {declarar_variavel($2.valor, linha_atual);$$.valor = " " + $2.valor + "&" + $3.valor;}
                    |                             {$$.valor = "";}
                    ;

Expressao_Declaracao  : _ID  '=' Conta Declaracao_Complexa    {declarar_variavel($1.valor, linha_atual); $$.valor = $1.valor + "& " + $1.valor + " " + $3.valor + " = ^" + $4.valor;}
                      | _ID  Declaracao_Complexa              {declarar_variavel($1.valor, linha_atual); $$.valor = $1.valor + "&" + $2.valor;}
                      ;

Declaracao  : _LET    Expressao_Declaracao    {$$.valor = $2.valor;}
            | _CONST  Expressao_Declaracao    {$$.valor = $2.valor;}
            | _VAR    Expressao_Declaracao    {$$.valor = $2.valor;}
            |                                 {$$.valor = "";}
            ;

Membro_Simples  :   _STRING        {$$.valor = $1.valor;}
                |   _INT           {$$.valor = $1.valor;}
                |   _FLOAT         {$$.valor = $1.valor;}
                |  _NOVO_OBJETO '}'  {$$.valor = "{}";}
                |  '[' ']'         {$$.valor = "[]";}
                ;

Dimensoes       :   '[' Conta ']' Dimensoes {$$.valor ="[@] " + $2.valor + $2.obterRetorno() + $4.valor;}
                |                           {$$.valor = "";}
                ;

Objeto  :   _ID '.' _ID                  {$$.valor = $1.valor + "@ " + $3.valor;}
        |   _ID '.' _ID '[' Conta ']'    {$$.valor = $1.valor + "@ " + $3.valor + "[@] " + $5.valor;}
        |   _ID '[' Conta ']'  Dimensoes {$$.valor = $1.valor + "@ " + $3.valor + $3.obterRetorno() + $5.valor;}
        ;

Casos_ID        : _ID           Atribuicao_ID       {verificar_variavel($1.valor);$$.valor = $1.valor + $2.valor; $$.retorno = " " + $1.valor + "@";}
                | _ID _CONC     Atribuicao_MIGUAL   {$$.valor = $1.valor + " " + $1.valor + "@ " + $3.valor;}
                | _ID _MAISMAIS '+' Conta_Simples   {$$.valor = $1.valor + "@" + $4.valor + " " + $1.valor + " " + $1.valor + "@ 1 + = ^";}
                ;

Casos_Objeto    : Objeto           Atribuicao_Objeto    {$$.valor = $1.valor + $2.valor;}
                | Objeto _CONC     AtribuicaoObj_MIGUAL {$$.valor = $1.valor + " " + $1.valor + "[@] " + $3.valor;}
                | Objeto _MAISMAIS '+'                  {$$.valor = $1.valor + " " + $1.valor + "@ 1 + [=] ^ " + $1.valor + "@";}
                ;


Membro  :   Membro_Simples                        {$$.valor = $1.valor;}      
        |   Funcao                                {$$.valor = $1.valor;}
        |   Casos_Objeto                          {$$.valor = $1.valor;}
        |   Casos_ID                              {$$.valor = $1.valor;$$.retorno=$1.retorno;}
        |   '+'    Conta                          {$$.valor = $2.valor;}
        |   '-'    Termo                          {$$.valor = "0 " + $2.valor + " -";}  
        |   '('    Conta ')'                      {$$.valor = $2.valor;}
        |                                         {$$.valor = "";}
        ;

Termo :   Membro  Conta_Complexa  {$$.valor = $1.valor + $2.valor;$$.retorno=$1.retorno;}
      ;

Conta   :   Termo   Conta_Simples {$$.valor = $1.valor + $2.valor;$$.retorno=$1.retorno;}          
        ;

Jump_IF    : Expressao ';' SENAO            {contador_rotulo++; $$.valor = $3.valor + " " + ":end_if" + to_string(contador_rotulo) + " # " + ";then_" + to_string(contador_rotulo) + " " + $1.valor + " " + ";end_if" + to_string(contador_rotulo);}
           | '{' Continuacao '}' SENAO      {contador_rotulo++; $$.valor = $4.valor + " " + ":end_if" + to_string(contador_rotulo) + " # " + ";then_" + to_string(contador_rotulo) + $2.valor + " "+ ";end_if" + to_string(contador_rotulo);}
           ;

Jump_While      : Expressao ';'            {contador_rotulo++; $$.valor = ":end_while" + to_string(contador_rotulo) + " # " + ";whilec_" + to_string(contador_rotulo) + " " + $1.valor + " " + ":while_" + to_string(contador_rotulo) + " # " + ";end_while" + to_string(contador_rotulo);}
                | '{' Continuacao '}'      {contador_rotulo++; $$.valor = ":end_while" + to_string(contador_rotulo) + " # " + ";whilec_" + to_string(contador_rotulo) + $2.valor + " " + ":while_" + to_string(contador_rotulo) + " # " + ";end_while" + to_string(contador_rotulo);}
                ;

Jump_For        : Expressao ';'            {contador_rotulo++; $$.valor = ":end_for" + to_string(contador_rotulo) + " # " + ";forc_" + to_string(contador_rotulo) + " " + $1.valor;}
                | '{' Continuacao '}'      {contador_rotulo++; $$.valor = ":end_for" + to_string(contador_rotulo) + " # " + ";forc_" + to_string(contador_rotulo) + $2.valor;}
                | 
                ;



SENAO   :  _ELSE Continuacao  {$$.valor = $2.valor;}
        |                     {$$.valor = "";}
        ;

Comando :  _IF   '(' Expressao ')' Jump_IF                              {$$.valor = $3.valor + " " + ":then_" + to_string(contador_rotulo) + " ?" + $5.valor;}
        |  _FOR  '(' Expressao ';'  Expressao ';' Expressao ')' Jump_For{$$.valor = $3.valor + " " + ";for_" + to_string(contador_rotulo) + " " + $5.valor + " " + ":forc_" + to_string(contador_rotulo) + " ? " + $9.valor + " " + $7.valor + " " + ":for_" + to_string(contador_rotulo) + " # " + ";end_for" + to_string(contador_rotulo);}
        | _WHILE '(' Expressao ')' Jump_While                           {$$.valor = ";while_" + to_string(contador_rotulo) + " " + $3.valor + " " + ":whilec_" + to_string(contador_rotulo) + " ? " + $5.valor;}
        ;

Expressao       :   Declaracao              {$$.valor = $1.valor;}
                |   Conta   Expressao       {$$.valor = $1.valor + $2.valor;}   
                ;

Continuacao  : Expressao ';' Continuacao         {$$.valor = " " + $1.valor + $3.valor;}
             | Comando       Continuacao         {$$.valor = " " + $1.valor + $2.valor;}
             | ';'   Continuacao                 {$$.valor = $2.valor;}
             |                                   {$$.valor = "";}
             ;

Entrada :   Expressao ';' Continuacao         {processar_e_exibir_codigo($1.valor + $3.valor + " .");}
        |   Comando       Continuacao         {processar_e_exibir_codigo($1.valor + $2.valor + " .");}
        ;  
%%

#include "lex.yy.c"

string imprimir_token(int numToken, string token){
        return "";
}

void declarar_variavel(string var, int linha) {
    auto it = variaveis_declaradas.find(var);
    if (it != variaveis_declaradas.end()) {
        exibir_erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) + ".");
    }
    variaveis_declaradas[var] = linha;
}

void verificar_variavel(string var) {
    if (variaveis_declaradas.find(var) == variaveis_declaradas.end()) {
        exibir_erro("a variável '" + var + "' não foi declarada.");
    }
}

void substituir_string(std::string& subject, const std::string& search, const std::string& replace) {
    if (search.empty()) {
        return;
    }
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
        subject.replace(pos, search.length(), replace);
        pos += replace.length();
    }
}

void processar_e_exibir_codigo(string codigo) {
    int pc_sem_rotulo = 0;
    bool dentro_cadeia = false, dentro_rotulo = false, dentro_rotulo_codigo = false;
    map<string, int> mapa_rotulos;
    string rotulo_em_processo = "";
    string token = "";

    for (int pc = 0; pc < codigo.size(); pc++) {
        char caractere = codigo[pc];
        
        if (caractere == ';') {
            dentro_rotulo = true;
            token += caractere;
            continue;
        }

        if (dentro_rotulo) {
            if (caractere == ' ') {
                dentro_rotulo = false;
                mapa_rotulos[rotulo_em_processo] = pc_sem_rotulo;
                rotulo_em_processo = "";
            } else {
                rotulo_em_processo += caractere;
                token += caractere;
            }
            continue;
        }

        if (caractere == '"') {
            dentro_cadeia = !dentro_cadeia;
            continue;
        }

        if (dentro_cadeia) {
            token += caractere;
            continue;
        }

        if (caractere == ':') {
            dentro_rotulo_codigo = !dentro_rotulo_codigo;
            token += caractere;
            continue;
        }
        
        if (dentro_rotulo_codigo) {
            if (caractere == ' ') {
                dentro_rotulo_codigo = false;
                token = imprimir_token(pc_sem_rotulo, token);
                pc_sem_rotulo++;
            } else {
                token += caractere;
            }
            continue;
        }
        
        if (caractere == ' ') {
            token = imprimir_token(pc_sem_rotulo, token);
            pc_sem_rotulo++;
            continue;
        } else {
            if (caractere == '&' || caractere == '@') {
                token = imprimir_token(pc_sem_rotulo, token);
                pc_sem_rotulo++;
                token = caractere;
                continue;
            }
        }

        token += caractere;
    }

    for (auto it = mapa_rotulos.begin(); it != mapa_rotulos.end(); ++it) {
        substituir_string(codigo, ":" + it->first, to_string(it->second));
        substituir_string(codigo, ";" + it->first + " ", "");
    }
        
    cout << codigo;
}


void exibir_erro(string mensagem) {
    cout << "Erro: " << mensagem << endl;
    exit(0); 
}


int obter_valor_token( int token ) {  
  yylval.valor = yytext; 
  return token;
}

void yyerror(const char* mensagem) {
    puts(mensagem); 
    printf("Proximo a: %s\n", yytext);
    exit(0);
}

int main( int argc, char* argv[] ) {
  yyparse();
  return 0;
}