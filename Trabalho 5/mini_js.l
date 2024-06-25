WS      [ \t\n]*

DIGITO  [0-9]
LETRA   [A-Za-z_$]
INT     {DIGITO}+
FLOAT  {INT}("."{INT})?([Ee]("-"|"+")?{INT})?
ID      {LETRA}({LETRA}|{DIGITO})*

STRING  ([\"]([^\"\n]*(\"\")*(\\\")*)*[\"])|([\']([^\'\n]*(\'\')*(\\\')*)*[\'])

FOR     "for"|"For"|"fOr"|"foR"|"FOr"|"FoR"|"fOR"|"FOR"
WHILE   "while"|"While"|"wHile"|"whIle"|"whiLe"|"whilE"|"WHile"|"WhIle"|"WhiLe"|"WhilE"|"wHIle"|"wHiLe"|"wHilE"|"whILe"|"wHIlE"|"WHILe"|"WHilE"|"WhIlE"|"WHiLe"|"WhIL"|"WHiLe"|"WHIL"
IF      "if"|"If"|"iF"|"IF"z
ELSE    "else"|"Else"|"eLse"|"elSe"|"elsE"|"ELse"|"ElSe"|"ElsE"|"eLSe"|"elSE"|"eLSE"|"ELSE"

ARGS    {WS}*{ID}{WS}*(","{WS}*{ID}{WS}*)*")"{WS}"=>"

BOLEANO       ("true"|"false")

%%

{WS}        { }

"\n"        { linha++; }

{FLOAT}   {return token(_FLOAT);}
{BOLEANO}    {return token(_BOLEANO);} 

"("/{ARGS}  {   return APS; }

{IF}         {return token(_IF);}
{ELSE}       {return token(_ELSE);}
{FOR}        {return token(_FOR);}
{WHILE}      {return token(_WHILE);}


"let"    {return token(_LET);}
"const"  {return token(_CONST);}
"var"    {return token(_VAR);}


"asm{".*"}" {   yylval.c = divide_string( remove_espacos( yytext + 4 ) ); return ASM; }
     
"function"   {return token(_FUNCTION);}
"function("   {return token(FUNC_ANON);}
"return"     {return token(_RETURN);} 

"<="         {return token(_ME_IG);}
">="         {return token(_MA_IG);}
"=="         {return token(_IGUAL);}
"=>"         {return token(_ARROW);}


{ID}     {return token(_ID);}
{STRING}            {return token(_STRING);}

.       {return token(yytext[0]);}

%%