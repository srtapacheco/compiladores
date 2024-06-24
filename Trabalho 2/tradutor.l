%{

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>

using namespace std;

enum TOKEN { _ID = 256, _INT, _FLOAT, _STR, _PRINT};

map<int,string> mapaNomesTokens = {
  { _INT, "int" },
  { _FLOAT, "float" },
  { _STR, "string" },
  { _PRINT, "print" },
  { _ID, "id" },
};

int token;
void casa(int);

void A();
void E();
void E_linha();
void T();
void T_linha();
void H();
void H_linha();
void F();

%}

WS	[ \n\t]
DIGITO	[0-9]
LETRA	[A-Za-z_]
INT	{DIGITO}+
FLOAT {INT}("."{INT})?([Ee]("+"|"-")?{INT})?
ID	{LETRA}({LETRA}|{DIGITO})*


STR \"(\"\"|\\\"|[^\"])*\"

%%

{WS}    {/* ignora espaços, tabs e '\n' */}
{INT}   {return _INT;}
{FLOAT} {return _FLOAT;}
{STR}   {return _STR;}
"print" {return _PRINT;}
{ID}    {return _ID;}
.	    {return yytext[0];}

%%

void casa(int tokenEsperado){
    if(token == tokenEsperado){
        token = yylex();
    } else{
        exit(1);
    }
}

void exibirMensagem(string str){
	cout << str << " ";
}



void A(){
    switch(token){
        case _PRINT:
            casa(_PRINT);
            E();
            exibirMensagem("print #");
    		    break;
        
        case _ID:
          exibirMensagem(yytext);
          casa(_ID);
          casa('=');
          E();
          exibirMensagem("= ^");
          break;
    }
}

void E(){
    T();
    E_linha();
}


void E_linha(){
    switch(token){
        case '+':
          casa('+');T();exibirMensagem("+"); E_linha();break;

        case '-':
          casa('-');T();exibirMensagem("-"); E_linha();break;
    }
}

void T(){
    H();
    T_linha();
}


void T_linha(){
    switch(token){
        case '*':
          casa('*');H(); exibirMensagem("*"); T_linha();
			break;

        case '/':
          casa('/');H(); exibirMensagem("/"); T_linha();
			break;
    }
}

void H(){
    F();
    H_linha();
}


void H_linha(){
    switch(token){

        case '^':
            casa('^');F();H_linha();exibirMensagem("power #"); H_linha();
			break;

        case '!':
          casa('!');exibirMensagem("fat #"); H_linha();
			break;
    }
}


void F(){
    switch(token){
        case _ID:{
            string tempID = (string)yytext;
            casa(_ID);
            if (token == '(') {
                casa('(');
                if (token != ')') {
                    E();
                    while (token == ',') {
                        casa(',');
                        E();
                    }
                }
                casa(')');
                exibirMensagem(tempID + " # ");
            } else {
                exibirMensagem(tempID + " @ ");
            }
            break;
        }
        case _INT:
            exibirMensagem(yytext);
            casa(_INT);
			      break;
        case _FLOAT:
            exibirMensagem(yytext);
            casa(token);
            break;
        case _STR:
            exibirMensagem(yytext);
            casa(_STR);
            break;
        case '(':
            casa('(');
            E();
            casa(')');
            break;
        case '-': 
            casa('-');
            exibirMensagem("0");
            H();
            exibirMensagem("-");
            break;
        case '+': 
            casa('+');
            H();
            break;
    }
}

int main(){
  
  while((token = yylex()) != 0)
  {	A();}
  
  return 0;
}

