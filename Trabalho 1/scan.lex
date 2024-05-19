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
    
    _EXPR        (\{[^}]*[a-zA-Z0-9_]*[^}])
    
    COMENTARIO_BLOCO  "/*"([^*]|"*"+[^*/])*"*"+"/"
    COMENTARIO_LINHA "//"[^\n]*
    
    _STRING    \"([^"\\]|\\.)*\"|'([^'\\]|\\.)*'
    
    STRING_1  (\"[^\"\n]*(\\.|"")*[^\"\\]*\") 
    STRING_2  (\'[^\'\n]*(\\.|'')*[^\'\\]*\')
    
    STRING2_1   (\`[^{]*\$)
    
    STRING2_2   (\}.*\`)
    STRING2 (\`[^\`{}]*\`)
    
    
    
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
    
    {_EXPR}      { 
                    lexema = yytext; 
                    lexema.erase(0, 1);
                    return _EXPR; 
                }
    
    {_STRING} {
        lexema = yytext;
                    lexema.erase(0, 1);
                    lexema.erase(lexema.length() - 1);
    
                   
                    size_t achado = lexema.find("\\\'");
                    while (achado != std::string::npos) {
                        lexema.erase(achado, 1);
                        achado = lexema.find("\\\'", achado);
                    }
    
                   
                    size_t achado2 = lexema.find("\'\'");
                    while (achado2 != std::string::npos) {
                        lexema.erase(achado2, 1);
                        achado2 = lexema.find("\'\'", achado2 + 1); 
                    }
                    return _STRING; 
    }
    
    
    {STRING2_1} { 
                    lexema = yytext;
                    lexema.erase(0, 1);
                    lexema.erase(lexema.length() - 1);
                    return _STRING2; 
                }
    {STRING2_2} { 
                    lexema = yytext;
                    lexema.erase(0, 1);
                    lexema.erase(lexema.length() - 1);
                    return _STRING2; 
                }
    {STRING2}   { 
                    lexema = yytext;
                    lexema.erase(0, 1);
                    lexema.erase(lexema.length() - 1);
                    return _STRING2; 
                }
    
    
    .       { 
            lexema = yytext;
            return *yytext; 
              /* Essa deve ser a última regra. Dessa forma qualquer caractere isolado será retornado pelo seu código ascii. */ 
            }
    
    %%
    
    /* Não coloque nada aqui - a função main é automaticamente incluída na hora de avaliar e dar a nota. */