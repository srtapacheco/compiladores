%{

string lexema;

%}

WS	[ \t\n]

DIGITO           [0-9]

_INT             {DIGITO}+

_FLOAT           [0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)?

LETRA            [A-Za-z_]

_ID            [_a-zA-Z$][_a-zA-Z0-9_]*

ID_INVALIDO     [_a-zA-Z$]+\$+[_a-zA-Z0-9]*|\$\$+|_\$


COMENTARIO_BLOCO  "/*"([^*]|"*"+[^*/])*"*"+"/"
COMENTARIO_LINHA "//"[^\n]*



_STRING    \"([^"\\]|\\.)*\"

_STRING2   `([^`\\]|\\.|`{2})*`


%%

{WS}	{ /* ignora espaços, tabs e '\n' */ }


">="    { lexema = yytext; return _MAIG; }
"<="    { lexema = yytext; return _MEIG; }
"=="    { lexema = yytext; return _IG; }
"!="    { lexema = yytext; return  _DIF; }


"for"|"For"|"fOr"|"FOR"   { lexema = yytext; return _FOR; }
"if"|"IF"   { lexema = yytext; return  _IF; }

{ID_INVALIDO}   {
    printf("Erro: Identificador invalido: %s\n", yytext);
}


{_ID}                 { lexema = yytext; return _ID; }
{_INT}                { lexema = yytext; return _INT; }
{_FLOAT}              { lexema = yytext; return _FLOAT; }


{COMENTARIO_BLOCO} { lexema = yytext; return _COMENTARIO; }
{COMENTARIO_LINHA} { lexema = yytext; return _COMENTARIO; }

{_STRING} {
    lexema = string(yytext).substr(1, yyleng - 2);  
    return _STRING;
}

{_STRING2} {
    lexema = string(yytext).substr(1, yyleng - 2); 
    size_t pos = 0;
    while ((pos = lexema.find("''", pos)) != string::npos) {
        lexema.replace(pos, 2, "'");
        pos += 1;
    }
    return _STRING2;
}

.       { 
        lexema = yytext;
        return *yytext; 
          /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ 
        }

%%

/* Não coloque nada aqui - a função main é automaticamente incluída na hora de avaliar e dar a nota. */