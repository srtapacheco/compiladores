/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    _INT = 258,                    /* _INT  */
    _FLOAT = 259,                  /* _FLOAT  */
    _STRING = 260,                 /* _STRING  */
    _STRING2 = 261,                /* _STRING2  */
    _ID = 262,                     /* _ID  */
    _FOR = 263,                    /* _FOR  */
    _IF = 264,                     /* _IF  */
    _ELSE = 265,                   /* _ELSE  */
    _LET = 266,                    /* _LET  */
    _PRINT = 267,                  /* _PRINT  */
    _MAISMAIS = 268,               /* _MAISMAIS  */
    _MA_IG = 269,                  /* _MA_IG  */
    _IGUAL = 270,                  /* _IGUAL  */
    _DIF = 271,                    /* _DIF  */
    _ME_IG = 272,                  /* _ME_IG  */
    _COMENTARIO = 273,             /* _COMENTARIO  */
    _CONST = 274,                  /* _CONST  */
    _VAR = 275,                    /* _VAR  */
    _CONCAT = 276,                 /* _CONCAT  */
    _NOVO_OBJETO = 277,            /* _NOVO_OBJETO  */
    _WHILE = 278,                  /* _WHILE  */
    _FUNCTION = 279,               /* _FUNCTION  */
    _BOLEANO = 280,                /* _BOLEANO  */
    _RETURN = 281,                 /* _RETURN  */
    _ASM = 282,                    /* _ASM  */
    _ARRAY = 283,                  /* _ARRAY  */
    _LAMBDA = 284                  /* _LAMBDA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define _INT 258
#define _FLOAT 259
#define _STRING 260
#define _STRING2 261
#define _ID 262
#define _FOR 263
#define _IF 264
#define _ELSE 265
#define _LET 266
#define _PRINT 267
#define _MAISMAIS 268
#define _MA_IG 269
#define _IGUAL 270
#define _DIF 271
#define _ME_IG 272
#define _COMENTARIO 273
#define _CONST 274
#define _VAR 275
#define _CONCAT 276
#define _NOVO_OBJETO 277
#define _WHILE 278
#define _FUNCTION 279
#define _BOLEANO 280
#define _RETURN 281
#define _ASM 282
#define _ARRAY 283
#define _LAMBDA 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
