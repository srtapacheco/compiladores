%{

extern "C" int yylex();

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int token(int tk);

struct Atributos {
    vector<string> c;
};

#define YYSTYPE Atributos

int yyparse();
void yyerror(const char*);

vector<string> operator+(const vector<string>& a, const vector<string>& b);
vector<string> operator+(const vector<string>& a, const string& b);

string gera_label(const string& prefixo);

vector<string> resolve_enderecos(const vector<string>& entrada);
void imprime_vetor(const vector<string>& v);
string remove_espacos(const char* c);
vector<string> divide_string(const string& str);

vector<string> auxiliar;
map<string, int> vars;
vector<string> funcs;
int linha = 1, quantidade_parametros = 0;

vector<vector<string>> elements;
vector<vector<string>> pars;
%}

%token _FLOAT _STRING
%token _ID _IF _ELSE _FOR _WHILE 
%token _IGUAL _MA_IG _ME_IG
%token _BOLEANO _LET _VAR _CONST _FUNCTION FUNC_ANON _RETURN ASM APS _ARROW

%right '='
%right _ARROW

%nonassoc '<' '>' _IGUAL _MA_IG _ME_IG

%left '+' '-'
%left '*' '/' '%'

%start S

%%

S : Comandos { imprime_vetor(resolve_enderecos($1.c + "." + funcs)); }
  ;

Comandos : Comando Comandos { $$.c = $1.c + $2.c; }
     | Comando { $$.c = $1.c; }
     ;

Comando : Expressao ';' { $$.c = $1.c + "^"; }
    | _ID ASM ';' { $$.c = $1.c + "@" + $2.c + "^"; }
    | _LET Declaracao_Simples ';' { $$.c = $2.c; }
    | _VAR Declaracao_Simples ';' { $$.c = $2.c; }
    | _CONST Declaracao_Simples ';' { $$.c = $2.c; }
    | _RETURN Expressao ';' { $$.c = auxiliar + $2.c + "'&retorno'" + "@" + "~"; }
    | _IF '(' Expressao ')' Bloco _ELSE Bloco { 
        string r = gera_label("IF_ELSE"); 
        string s = gera_label("IF_CONTINUE"); 
        $$.c = $3.c + "!" + r + "?" + $5.c + s + "#" + (":" + r) + $7.c + (":" + s); 
    }
    | _IF '(' Expressao ')' Bloco { 
        string r = gera_label("ENDIF"); 
        $$.c = $3.c + "!" + r + "?" + $5.c + (":" + r); 
    }
    | _WHILE '(' Expressao ')' Bloco { 
        string r = gera_label("_WHILE"); 
        string s = gera_label("ENDWHILE"); 
        $$.c = auxiliar + (":" + r) + $3.c + "!" + s + "?" + $5.c + r + "#" + (":" + s); 
    }
    | _FOR '(' Comando Expressao ';' Expressao ')' Bloco { 
        string r = gera_label("TESTFOR");
        string s = gera_label("ENDFOR"); 
        $$.c = $3.c + (":" + r) + $4.c + "!" + s + "?" + $8.c + $6.c + "^" + r + "#" + (":" + s); 
    }
    | _FUNCTION _ID '(' ')' Bloco { 
        string r = gera_label($2.c[0]); 
        vector<string> retorna = auxiliar + "undefined" + "@" + "'&retorno'" + "@" + "~"; 
        funcs = funcs + (":" + r) + $5.c + retorna;
        vector<string> end_decl = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^";
        $$.c = end_decl; 
        quantidade_parametros = 0; 
    }
    | _FUNCTION _ID '(' D_LINHA ')' Bloco { 
        string r = gera_label($2.c[0]);
        vector<string> retorna = auxiliar + "undefined" + "@" + "'&retorno'" + "@" + "~";
        funcs = funcs + (":" + r) + $4.c + $6.c + retorna;
        $$.c = $2.c + "&" + $2.c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^"; 
    }
    ;

Expressao : Expressao '<' Expressao { $$.c = $1.c + $3.c + "<"; }
  | Expressao '>' Expressao { $$.c = $1.c + $3.c + ">"; }
  | Expressao _MA_IG Expressao { $$.c = $1.c + $3.c + ">="; }
  | Expressao _ME_IG Expressao { $$.c = $1.c + $3.c + "<="; }
  | Expressao _IGUAL Expressao { $$.c = $1.c + $3.c + "=="; }
  | Expressao '*' Expressao { $$.c = $1.c + $3.c + "*"; }
  | Expressao '+' Expressao { $$.c = $1.c + $3.c + "+"; }
  | Expressao '-' Expressao { $$.c = $1.c + $3.c + "-"; }
  | Expressao '/' Expressao { $$.c = $1.c + $3.c + "/"; }
  | Expressao '%' Expressao { $$.c = $1.c + $3.c + "%"; }
  | LV_ '=' Expressao { $$.c = $1.c + $3.c + "[=]"; }
  | LVALUE '=' Expressao { $$.c = $1.c + $3.c + "="; }
  | LV_ { $$.c = $1.c + "[@]"; }
  | LVALUE { $$.c = $1.c + "@"; }
  | O { $$ = $1; }
  | F { $$ = $1; }
  ;

Declaracao_Simples : Declaracao_Complexa ',' Declaracao_Simples { $$.c = $1.c + $3.c; }
  | Declaracao_Complexa { $$.c = $1.c; }
  ;

Declaracao_Complexa : LVALUE '=' Expressao { 
        $$.c = $1.c + "&" + $1.c + $3.c + "=" + "^";
        vars[$1.c[0]] = linha;
    }
  | LVALUE { 
        $$.c = $1.c + "&";
        vars[$1.c[0]] = linha;
    }
  ;

Bloco : '{' Comandos '}' { $$.c = $2.c; }
  | Comando { $$.c = $1.c; }
  | B_ { $$.c = auxiliar; }
  ;

B_ : '{' '}' { $$.c = auxiliar; }
   ;

D_LINHA : D_LINHA_ { 
        vector<string> decl_par;
        int tam = pars.size() / 2;
        for (int i = 0; i < tam; i++) {
            vector<string> defaultValue = pars.back();
            pars.pop_back();
            vector<string> id = pars.back();
            pars.pop_back();
            if (defaultValue.empty()) {
                decl_par = decl_par + id + "&" + id + "arguments" + "@" + to_string(i) + "[@]" + "=" + "^";
            } else {
                string r = gera_label("IF_ELSE");
                string s = gera_label("IF_CONTINUE");
                vector<string> def = auxiliar + "arguments" + "@" + to_string(i) + "[@]" + "undefined" + "@" + "==" + "!" + r + "?" + id + "&" + id + defaultValue + "=" + "^";
                vector<string> notDef = auxiliar + s + "#" + (":" + r) + id + "&" + id + "arguments" + "@" + to_string(i) + "[@]" + "=" + "^" + (":" + s);
                decl_par = decl_par + def + notDef;
            }
        }
        pars.clear();
        $$.c = decl_par; 
    }
    ;

D_LINHA_ : _ID '=' Expressao ',' D_LINHA_ { 
        pars.push_back($1.c);
        pars.push_back($3.c);
        $$.c = $1.c + $3.c + $5.c; 
    }
  | _ID ',' D_LINHA_ { 
        pars.push_back($1.c);
        pars.push_back(auxiliar);
        $$.c = $1.c + $3.c; 
    }
  | _ID '=' Expressao { 
        pars.push_back($1.c);
        pars.push_back($3.c);
        $$.c = $1.c + $3.c; 
    }
  | _ID { 
        pars.push_back($1.c);
        pars.push_back(auxiliar);
        $$.c = $1.c; 
    }
    ;

LV_ : LVALUE P { $$.c = $1.c + "@" + $2.c; }
    ;

LVALUE : _ID { $$.c = $1.c; }
       ;

P : '[' Expressao ']' P { $$.c = $2.c + "[@]" + $4.c; }
  | '.' _ID P { $$.c = $2.c + "[@]" + $3.c; }
  | '[' Expressao ']' { $$.c = $2.c; }
  | '.' _ID { $$.c = $2.c; }
  ;

O : '{' Atribuicao '}' { $$.c = auxiliar + "{}" + $2.c; }
  | B_ { $$.c = auxiliar + "{}"; }
  ;

Atribuicao : _ID ':' Expressao ',' Atribuicao { $$.c = $1.c + $3.c + "[<=]" + $5.c; }
      | _ID ':' Expressao { $$.c = $1.c + $3.c + "[<=]"; }
      ;

F : _FLOAT { $$.c = $1.c; }
  | _STRING { $$.c = $1.c; }
  | _BOLEANO { $$.c = $1.c; }
  | '(' Expressao ')' { $$ = $2; }
  | CF { $$ = $1; }
  | ARRAY { $$ = $1; }
  | FA { $$ = $1; }
  | Funcao_Seta { $$ = $1; }
  ;

CF : _ID '(' P_ ')' { $$.c = $3.c + to_string(quantidade_parametros) + $1.c + "@" + "$"; quantidade_parametros = 0; }
   | _ID '(' ')' { $$.c = auxiliar + "0" + $1.c + "@" + "$"; }
   | LV_ '(' P_ ')' { $$.c = $3.c + to_string(quantidade_parametros) + $1.c + "[@]" + "$"; quantidade_parametros = 0; }
   | LV_ '(' ')' { $$.c = auxiliar + "0" + $1.c + "[@]" + "$"; }
   ;

ARRAY : '[' ELS ']' { 
        $$.c = auxiliar + "[]";
        int tam = elements.size();
        for (int i = 0; i < tam; i++) {
            $$.c = $$.c + to_string(i) + elements.back() + "[<=]";
            elements.pop_back();
        }
    }
  | '[' ']' { $$.c = auxiliar + "[]"; }
  ;

FA : FUNC_ANON ')' Bloco { 
        string r = gera_label("FUNCANON"); 
        vector<string> retorna = auxiliar + "undefined" + "@" + "'&retorno'" + "@" + "~";
        funcs = funcs + (":" + r) + $3.c + retorna;
        $$.c = auxiliar + "{}" + "'&funcao'" + r + "[<=]"; 
    }
  | FUNC_ANON D_LINHA ')' Bloco { 
        string r = gera_label("FUNCANON");
        vector<string> retorna = auxiliar + "undefined" + "@" + "'&retorno'" + "@" + "~";
        funcs = funcs + (":" + r) + $2.c + $4.c + retorna;
        $$.c = auxiliar + "{}" + "'&funcao'" + r + "[<=]"; 
    }
    ;

Funcao_Seta : H _ARROW Expressao { 
        string r = gera_label("FUNCANON"); 
        vector<string> retorna = auxiliar + $3.c + "'&retorno'" + "@" + "~";
        funcs = funcs + (":" + r) + $1.c + retorna;
        $$.c = auxiliar + "{}" + "'&funcao'" + r + "[<=]"; 
    }
    ;

P_ : Expressao ',' P_ { $$.c = $1.c + $3.c; quantidade_parametros++; }
   | Expressao { $$.c = $1.c; quantidade_parametros++; }
   ;

ELS : Expressao ',' ELS { elements.push_back($1.c); }
    | Expressao { elements.push_back($1.c); }
    ;

H : _ID { $$.c = $1.c + "&" + $1.c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; }
  | '(' ')' { $$.c = auxiliar; }
  | APS D_LINHA ')' { $$.c = $2.c; }
  ;

%%

#include "lex.yy.c"

vector<string> operator+(const vector<string>& a, const vector<string>& b) {
    vector<string> result(a);
    result.insert(result.end(), b.begin(), b.end());
    return result;
}

vector<string> operator+(const vector<string>& a, const string& b) {
    vector<string> result(a);
    result.push_back(b);
    return result;
}

string gera_label(const string& prefixo) {
    static int n = 0;
    return prefixo + "_" + to_string(++n) + ":";
}

vector<string> resolve_enderecos(const vector<string>& entrada) {
    map<string, int> label;
    vector<string> saida;

    for (const auto& item : entrada) {
        if (item[0] == ':') {
            label[item.substr(1)] = saida.size();
        } else {
            saida.push_back(item);
        }
    }

    for (auto& item : saida) {
        if (label.count(item) > 0) {
            item = to_string(label[item]);
        }
    }

    return saida;
}

void imprime_vetor(const vector<string>& v) {
    for (const auto& item : v) {
        cout << item << " ";
    }
}

string remove_espacos(const char* c) {
    string temp(c);
    return temp.erase(temp.size() - 1);
}

vector<string> divide_string(const string& str) {
    vector<string> tokens;
    istringstream iss(str);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int token(int tk) {
    yylval.c = auxiliar + yytext;
    return tk;
}

void yyerror(const char* st) {
    puts(st);
    printf("Proximo a: %s\n", yytext);
    exit(1);
}

int main(int argc, char* argv[]) {
    yyparse();
    return 0;
}
