WS      [ \t\n]*

DIGITO  [0-9]
LETRA   [A-Za-z]
INT     {DIGITO}+
FLOAT   {INT}("."{INT})?([Ee]("-"|"+")?{INT})?
ID ("$"|{LETRA}|_)+({LETRA}|{DIGITO})*

STRING     ["]([^\"]|"\\"[\"]|[\"][\"])*["]

LINHA   [^\n]*

FOR     "for"|"For"|"fOr"|"foR"|"FOr"|"FoR"|"fOR"|"FOR"
WHILE   "while"|"While"|"wHile"|"whIle"|"whiLe"|"whilE"|"WHile"|"WhIle"|"WhiLe"|"WhilE"|"wHIle"|"wHiLe"|"wHilE"|"whILe"|"wHIlE"|"WHILe"|"WHilE"|"WhIlE"|"WHiLe"|"WhIL"|"WHiLe"|"WHIL"
IF      "if"|"If"|"iF"|"IF"
ELSE    "else"|"Else"|"eLse"|"elSe"|"elsE"|"ELse"|"ElSe"|"ElsE"|"eLSe"|"elSE"|"eLSE"|"ELSE"


COMENTARIO_BLOCO    "/*"([^\*]|"*"[^/])*"*/"
COMENTARIO_LINHA    "//"(.)*[\n]

STRING1  [']([^\']|"\\'"|[\'][\'])*[']
STRING2 [`]({WS}|.)*[`]


OBJETO_VAZIO        "{"{WS}*"}"
ARRAY_VAZIO         "["{WS}*"]"

INCREMENTO      "+""+"
BOLEANO       ("true"|"false")

%%

"\n"	   { linha++;coluna=1;}

" "        { coluna++; }

"\t"       { coluna += 4; }


{INT}     {return token(_INT);}
{FLOAT}   {return token(_FLOAT);}
{BOLEANO}    {return token(_BOLEANO);} 

{FOR}        {return token(_FOR);}
{WHILE}      {return token(_WHILE);}
{IF}         {return token(_IF);}
{ELSE}       {return token(_ELSE);}

"println"    {return token(_PRINT);}

"let"    {return token(_LET);}
"const"  {return token(_CONST);}
"var"    {return token(_VAR);}


"asm{".*"}"  {return token(_ASM); }

"function"   {return token(_FUNCTION);}
"return"     {return token(_RETURN);} 

{OBJETO_VAZIO}     {return token(_NOVO_OBJETO);}
{ARRAY_VAZIO}     {return token(_ARRAY);}
{INCREMENTO}   {return token(_MAISMAIS);}

"+"          {return token('+');}
">="         {return token(_MA_IG);}
"<="         {return token(_ME_IG);}
"=="         {return token(_IGUAL);}
"!="         {return token(_DIF);}
"+"/"="      {return token(_CONCAT);}




{ID}     {return token(_ID);}
{COMENTARIO_BLOCO}       {return token(_COMENTARIO);}
{COMENTARIO_LINHA}       {return token(_COMENTARIO);}
{STRING}            {return token(_STRING);}
{STRING1}           {return token(_STRING);}
{STRING2}           {return token(_STRING2);}

.       {return token(yytext[0]);}

%%