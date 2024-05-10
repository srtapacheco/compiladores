 %{
// Includes em C/C++ e outras definições.
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Atributos {
  string v;
};

// Tipo dos atributos: YYSTYPE é o tipo usado para os atributos.
#define YYSTYPE Atributos

void erro( string msg );
void print( string st );

// protótipo para o analisador léxico (gerado pelo lex)
extern "C" int yylex();
void yyerror( const char* );

%}

// Tokens
%token	 ID NUM PRINT STRING

%%

CMDs : A { cout << endl; } CMDs   
     |  // Vazio, epsilon
     ;
     
// Lendo da esquerda para direita:
// $$ é símbolo do lado esquerdo
// $1 é o primeiro símbolo do lado direito
// $2 é o segundo símbolo do lado direito
// e assim por diante.

A : ID { print( $1.v ); } '=' E { print( "= ^"); } ';' 
  | PRINT E ';' { print(" print #" ); }
  | PRINT E     { print(" print #" ); }
  ;

E : E '+' T { print( "+" ); }
  | E '-' T { print( "-" ); }
  | T
  ;
   
T : T '*' F { print( "*" ); }
  | T '/' F { print( "/" ); }
  | F
  ;
   
F : ID  	{ print( $1.v + " @ " ); }
  | NUM 	{ print( $1.v ); }
  | STRING 	{ print( $1.v ); }
  | '-' { print("0");} F { print("-");}
  | '(' E ')'
  ;

%%

#include "lex.yy.c"

void yyerror( const char* msg ) {
  cout << endl << "Erro: " << msg << endl
       << "Perto de : '" << yylval.v << "'" <<endl;
  exit( 1 );
}

void print( string st ) {
  cout << st << " ";
}

int main() {
  yyparse();
  cout << endl;
}