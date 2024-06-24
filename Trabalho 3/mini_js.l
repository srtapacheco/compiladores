WS      [ \s\t\n]*

DIGITO  [0-9]
LETRA   [A-Za-z]
INT     {DIGITO}+
FLOAT   {INT}("."{INT})?([Ee]("-"|"+")?{INT})?
ID ("$"|{LETRA}|_)+({LETRA}|{DIGITO})*


FOR     "for"|"For"|"fOr"|"foR"|"FOr"|"FoR"|"fOR"|"FOR"
WHILE   "while"|"While"|"wHile"|"whIle"|"whiLe"|"whilE"|"WHile"|"WhIle"|"WhiLe"|"WhilE"|"wHIle"|"wHiLe"|"wHilE"|"whILe"|"wHIlE"|"WHILe"|"WHilE"|"WhIlE"|"WHiLe"|"WhIL"|"WHiLe"|"WHIL"
IF      "if"|"If"|"iF"|"IF"z
ELSE    "else"|"Else"|"eLse"|"elSe"|"elsE"|"ELse"|"ElSe"|"ElsE"|"eLSe"|"elSE"|"eLSE"|"ELSE"


COMENTARIO_BLOCO   "//"(.)*[\n]
COMENTARIO_LINHA   "/*"([^\*]|"*"[^/])*"*/"
LINHA   [^\n]*


STRING  ["]([^\"]|"\\"[\"]|[\"][\"])*["]
STRING1 [']([^\']|"\\'"|[\'][\'])*[']
STRING2 [`]({WS}|.)*[`]


%%

"\n"	  { linha_atual++;}
{WS}      { }

{INT}     {return obter_valor_token(_INT);}
{FLOAT}   {return obter_valor_token(_FLOAT);}

{FOR}   {return obter_valor_token(_FOR);}
{WHILE} {return obter_valor_token(_WHILE);}
{IF}    {return obter_valor_token(_IF);}
{ELSE}  {return obter_valor_token(_ELSE);}
"print" {return obter_valor_token(_PRINT);}

"let"    {return obter_valor_token(_LET);}
"const"  {return obter_valor_token(_CONST);}
"var"    {return obter_valor_token(_VAR);}

"{"/"}"     {return obter_valor_token(_NOVO_OBJETO);}
"+"         {return obter_valor_token('+');}
"+"/"+"     {return obter_valor_token(_MAISMAIS);}
"+"/"="     {return obter_valor_token(_CONC);}
">="        {return obter_valor_token(_MAIG);}
"<="        {return obter_valor_token(_MEIG);}
"=="        {return obter_valor_token(_IG);}
"!="        {return obter_valor_token(_DIF);}

{ID}                        {return obter_valor_token(_ID);}
{COMENTARIO_LINHA}          {return obter_valor_token(_COMENTARIO);}
{COMENTARIO_BLOCO}          {return obter_valor_token(_COMENTARIO);}
{STRING}                    {return obter_valor_token(_STRING);}
{STRING1}                   {return obter_valor_token(_STRING);}
{STRING2}                   {return obter_valor_token(_STRING2);}

.       {return obter_valor_token(yytext[0]);}

%%