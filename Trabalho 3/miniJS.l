WS	[ \s\t\n]*

DIGITO  [0-9]
LETRA   [A-Za-z]
INT     {DIGITO}+
FLOAT   {INT}("."{INT})?([Ee]("-"|"+")?{INT})?
ID ("$"|{LETRA}|_)+({LETRA}|{DIGITO})*

STR     ["]([^\"]|"\\"[\"]|[\"][\"])*["]

LINHA   [^\n]*

FOR     "for"|"For"|"fOr"|"foR"|"FOr"|"FoR"|"fOR"|"FOR"
WHILE   "while"|"While"|"wHile"|"whIle"|"whiLe"|"whilE"|"WHile"|"WhIle"|"WhiLe"|"WhilE"|"wHIle"|"wHiLe"|"wHilE"|"whILe"|"wHIlE"|"WHILe"|"WHilE"|"WhIlE"|"WHiLe"|"WhIL"|"WHiLe"|"WHIL"
IF      "if"|"If"|"iF"|"IF"
ELSE    "else"|"Else"|"eLse"|"elSe"|"elsE"|"ELse"|"ElSe"|"ElsE"|"eLSe"|"elSE"|"eLSE"|"ELSE"


COMENTARIO_BLOCO    "/*"([^\*]|"*"[^/])*"*/"
COMENTARIO_LINHA    "//"(.)*[\n]

STRING_1  [']([^\']|"\\'"|[\'][\'])*[']
STRING_2  [`]({WS}|.)*[`]

%%

{WS}	{ /* ignora espaços, tabs e '\n' */ }

"\n" { linha++;}


{INT}     { yylval.c = yytext; return CINT; }
{FLOAT}   { yylval.c = yytext; return CDOUBLE; }

{FOR}     { yylval.c = yytext; return FOR; }
{WHILE}   { yylval.c = yytext; return WHILE; }
{IF}      { yylval.c = yytext; return IF; }
{ELSE}    { yylval.c = yytext; return ELSE; }

"print"   { yylval.c = yytext; return PRINT; }

"let"     { yylval.c = yytext; return LET; }
"const"   { yylval.c = yytext; return CONST; }
"var"     { yylval.c = yytext; return VAR; }

"+"       { return '+'; }

">="      { return MA_IG; }
"<="      { return ME_IG; }
"=="      { return IGUAL; }
"!="      { return DIF; }


"{"/"}"     {yylval.c = yytext; return ABRE_FECHA_CHAVE;}
"+"/"+"     {return _MAISMAIS;}
"+"/"="     {return _CONC;}


{ID}              { yylval.c = yytext; return ID; }
{COMENTARIO_BLOCO}  { return _COMENTARIO; }
{COMENTARIO_LINHA}  { return _COMENTARIO; }
{STR}             { yylval.c = yytext; return CSTRING; }
{STRING_1}        { yylval.c = yytext; return CSTRING; }
{STRING_2}        { yylval.c = yytext; return CSTRING2; }

.	    {return yytext[0];}

%%