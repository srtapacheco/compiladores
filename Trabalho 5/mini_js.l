WS      [ \t\n]*

DIGITO  [0-9]
LETRA   [A-Za-z]
NUM     {DIGITO}+("."{DIGITO}+)?
ID      {LETRA}({LETRA}|{DIGITO})*
STRING     (\"([^\"\n]|(\\\")|\"\")+\")|(\'([^\'\n]|(\\\')|\'\')+\')

FOR     "for"|"For"|"fOr"|"foR"|"FOr"|"FoR"|"fOR"|"FOR"
WHILE   "while"|"While"|"wHile"|"whIle"|"whiLe"|"whilE"|"WHile"|"WhIle"|"WhiLe"|"WhilE"|"wHIle"|"wHiLe"|"wHilE"|"whILe"|"wHIlE"|"WHILe"|"WHilE"|"WhIlE"|"WHiLe"|"WhIL"|"WHiLe"|"WHIL"
IF      "if"|"If"|"iF"|"IF"z
ELSE    "else"|"Else"|"eLse"|"elSe"|"elsE"|"ELse"|"ElSe"|"ElsE"|"eLSe"|"elSE"|"eLSE"|"ELSE"

BOLEANO       ("true"|"false")

%%

"\t"        { coluna += 4; }
"\n"        { linha++; coluna = 1; }
" "         { coluna++; }

{NUM}       { return token(_NUM); }
{BOLEANO}    {return token(_BOLEANO);} 


"+"         { return token(_MAIS); }
"-"         { return token(_MENOS); }
"*"         { return token(_MULT); }
"/"         { return token(_DIV); }
"%"         { return token(_MODULO); }
"=>"        { return token(_MA_IG); }
"[<=]"      { return token(_SETA_ESQUERDA); }
"<="        { return token(_ME_IG); }
">="        { return token(_MA_IG); }
"<"         { return token(_MENOR); }
">"         { return token(_MAIOR); }
"=="        { return token(_IGUAL); }
"!="        { return token(_DIF); }
"&&"        { return token(_AND); }
"||"        { return token(_OR); }

{FOR}        {return token(_FOR);}
{WHILE}      {return token(_WHILE);}
{IF}         {return token(_IF);}
{ELSE}       {return token(_ELSE);}

"let"	    { return token(_LET); }

"function"  { return token(_FUNCTION); }
"return"    { return token(_RETURN); }

"[]"        { return token(_ARRAY); }
"{}"        { return token(_OBJETO); }
"{"         { return token(_ABRE_CHAVE); }
"}"         { return token(_FECHA_CHAVE); }

"asm{".*"}" {  string lexema = trim(yytext + 3, "{}" );
               yylval.c = token(lexema);
               coluna += strlen(yytext); 
               return _ASM;}

{STRING}       { return token(TK_STR); }
{ID}        { return token(_ID); }
.           { return token(*yytext); }

%%