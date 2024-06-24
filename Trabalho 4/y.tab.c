/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mini_js.y"

extern "C" int yylex();

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

int contador = 0, linha = 0, coluna = 1, args = 0, locais = 0, declaracaoAntecedente = 0;

string declaracao = "";

int token(int tk);

void exibir_codigo_processado(string valor);
void exibir_erro(string valor);

int yyparse();
void yyerror(const char *);

void setVar(string var);
void checkVar(string var);
string enderecoPraFrente(string nome);
string enderecoResolvido(string nome);
string declarar(string var);
string declarar_arg(vector<string> args);
string acessar_campo(string nome_objeto, string campo);
string acessar_objeto(string nome_var);
string jumpComandos(string label_endereco_final, string label_endereco_corpo);
void ReplaceStringInPlace(std::string& subject, const std::string& search, const std::string& replace);
string asm_trim(string asm_command);
string declara_funcao(string nome, string parametros, string corpo);
string acessar_variavel(string nome_var);

#define YYSTYPE Atributos

map<string,int> variaveis_globais;
map<string, map<string,int>> variaveis_locais;
string undefined = "undefined";
string retorno_padrao = undefined + " @" + " '&retorno'" + " @" + " ~";

string funcoes = "";
map<string, string> retornos;

bool escopo_local = false;

string funcao = "";
string id = "";

struct Atributos {
    string valor;
    string retorno;
    int parametros;
    vector<string> args_value;

    Atributos() : valor(""), retorno(""), parametros(0) {}

    string getRetorno() const {
        return (retorno == " " + valor) ? "" : retorno;
    }
};

#line 139 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


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
    _ARRAY = 283                   /* _ARRAY  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL__INT = 3,                       /* _INT  */
  YYSYMBOL__FLOAT = 4,                     /* _FLOAT  */
  YYSYMBOL__STRING = 5,                    /* _STRING  */
  YYSYMBOL__STRING2 = 6,                   /* _STRING2  */
  YYSYMBOL__ID = 7,                        /* _ID  */
  YYSYMBOL__FOR = 8,                       /* _FOR  */
  YYSYMBOL__IF = 9,                        /* _IF  */
  YYSYMBOL__ELSE = 10,                     /* _ELSE  */
  YYSYMBOL__LET = 11,                      /* _LET  */
  YYSYMBOL__PRINT = 12,                    /* _PRINT  */
  YYSYMBOL__MAISMAIS = 13,                 /* _MAISMAIS  */
  YYSYMBOL__MA_IG = 14,                    /* _MA_IG  */
  YYSYMBOL__IGUAL = 15,                    /* _IGUAL  */
  YYSYMBOL__DIF = 16,                      /* _DIF  */
  YYSYMBOL__ME_IG = 17,                    /* _ME_IG  */
  YYSYMBOL__COMENTARIO = 18,               /* _COMENTARIO  */
  YYSYMBOL__CONST = 19,                    /* _CONST  */
  YYSYMBOL__VAR = 20,                      /* _VAR  */
  YYSYMBOL__CONCAT = 21,                   /* _CONCAT  */
  YYSYMBOL__NOVO_OBJETO = 22,              /* _NOVO_OBJETO  */
  YYSYMBOL__WHILE = 23,                    /* _WHILE  */
  YYSYMBOL__FUNCTION = 24,                 /* _FUNCTION  */
  YYSYMBOL__BOLEANO = 25,                  /* _BOLEANO  */
  YYSYMBOL__RETURN = 26,                   /* _RETURN  */
  YYSYMBOL__ASM = 27,                      /* _ASM  */
  YYSYMBOL__ARRAY = 28,                    /* _ARRAY  */
  YYSYMBOL_29_ = 29,                       /* '='  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '+'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '<'  */
  YYSYMBOL_34_ = 34,                       /* '^'  */
  YYSYMBOL_35_ = 35,                       /* '!'  */
  YYSYMBOL_36_ = 36,                       /* '*'  */
  YYSYMBOL_37_ = 37,                       /* '/'  */
  YYSYMBOL_38_ = 38,                       /* '%'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '['  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '.'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_Atribuicao_Objeto2 = 49,        /* Atribuicao_Objeto2  */
  YYSYMBOL_Atribuicao_Objeto = 50,         /* Atribuicao_Objeto  */
  YYSYMBOL_Atribuicao_MIGUAL = 51,         /* Atribuicao_MIGUAL  */
  YYSYMBOL_AtribuicaoObj_MIGUAL = 52,      /* AtribuicaoObj_MIGUAL  */
  YYSYMBOL_Atribuicao_ID2 = 53,            /* Atribuicao_ID2  */
  YYSYMBOL_Atribuicao_ID = 54,             /* Atribuicao_ID  */
  YYSYMBOL_Conta_Simples = 55,             /* Conta_Simples  */
  YYSYMBOL_Conta_Complexa2 = 56,           /* Conta_Complexa2  */
  YYSYMBOL_Conta_Complexa = 57,            /* Conta_Complexa  */
  YYSYMBOL_Declaracao_Complexa = 58,       /* Declaracao_Complexa  */
  YYSYMBOL_Declaracao_Simples = 59,        /* Declaracao_Simples  */
  YYSYMBOL_Expressao_Declaracao = 60,      /* Expressao_Declaracao  */
  YYSYMBOL_Declaracao = 61,                /* Declaracao  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_64_3 = 64,                      /* $@3  */
  YYSYMBOL_Membro_Simples = 65,            /* Membro_Simples  */
  YYSYMBOL_Dimensoes = 66,                 /* Dimensoes  */
  YYSYMBOL_Array = 67,                     /* Array  */
  YYSYMBOL_Campo_Objeto = 68,              /* Campo_Objeto  */
  YYSYMBOL_Continuacao_Objeto = 69,        /* Continuacao_Objeto  */
  YYSYMBOL_Objeto = 70,                    /* Objeto  */
  YYSYMBOL_Casos_ID = 71,                  /* Casos_ID  */
  YYSYMBOL_Casos_Objeto = 72,              /* Casos_Objeto  */
  YYSYMBOL_Membro = 73,                    /* Membro  */
  YYSYMBOL_Termo = 74,                     /* Termo  */
  YYSYMBOL_Conta = 75,                     /* Conta  */
  YYSYMBOL_Argumentos = 76,                /* Argumentos  */
  YYSYMBOL_Parametros = 77,                /* Parametros  */
  YYSYMBOL_Bloco_Funcao = 78,              /* Bloco_Funcao  */
  YYSYMBOL_Retorno = 79,                   /* Retorno  */
  YYSYMBOL_Funcao = 80,                    /* Funcao  */
  YYSYMBOL_81_4 = 81,                      /* $@4  */
  YYSYMBOL_Jump_IF = 82,                   /* Jump_IF  */
  YYSYMBOL_Jump_While = 83,                /* Jump_While  */
  YYSYMBOL_Jump_For = 84,                  /* Jump_For  */
  YYSYMBOL_SENAO = 85,                     /* SENAO  */
  YYSYMBOL_Comando = 86,                   /* Comando  */
  YYSYMBOL_Retorno_Comandos = 87,          /* Retorno_Comandos  */
  YYSYMBOL_Bloco = 88,                     /* Bloco  */
  YYSYMBOL_89_5 = 89,                      /* $@5  */
  YYSYMBOL_Expressao = 90,                 /* Expressao  */
  YYSYMBOL_Continuacao = 91,               /* Continuacao  */
  YYSYMBOL_S = 92                          /* S  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  88
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   569

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  231

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,     2,     2,    38,     2,     2,
      42,    43,    36,    31,    39,    30,    44,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      33,    29,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    78,    78,    79,    82,    83,    86,    89,    92,    93,
      96,    97,   100,   101,   102,   103,   104,   105,   108,   109,
     110,   113,   114,   115,   116,   117,   120,   121,   122,   125,
     126,   129,   130,   133,   133,   134,   134,   135,   135,   136,
     139,   140,   141,   142,   143,   146,   147,   151,   152,   153,
     156,   157,   160,   161,   162,   163,   166,   167,   168,   169,
     172,   173,   174,   175,   176,   179,   180,   181,   182,   185,
     186,   187,   188,   189,   190,   191,   192,   195,   198,   201,
     202,   203,   206,   207,   210,   213,   214,   216,   216,   217,
     220,   221,   224,   225,   228,   229,   230,   233,   234,   237,
     238,   239,   242,   243,   246,   246,   247,   250,   251,   252,
     253,   254,   255,   256,   259,   260,   261,   262,   265,   266
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "_INT", "_FLOAT",
  "_STRING", "_STRING2", "_ID", "_FOR", "_IF", "_ELSE", "_LET", "_PRINT",
  "_MAISMAIS", "_MA_IG", "_IGUAL", "_DIF", "_ME_IG", "_COMENTARIO",
  "_CONST", "_VAR", "_CONCAT", "_NOVO_OBJETO", "_WHILE", "_FUNCTION",
  "_BOLEANO", "_RETURN", "_ASM", "_ARRAY", "'='", "'-'", "'+'", "'>'",
  "'<'", "'^'", "'!'", "'*'", "'/'", "'%'", "','", "'['", "']'", "'('",
  "')'", "'.'", "'{'", "'}'", "';'", "$accept", "Atribuicao_Objeto2",
  "Atribuicao_Objeto", "Atribuicao_MIGUAL", "AtribuicaoObj_MIGUAL",
  "Atribuicao_ID2", "Atribuicao_ID", "Conta_Simples", "Conta_Complexa2",
  "Conta_Complexa", "Declaracao_Complexa", "Declaracao_Simples",
  "Expressao_Declaracao", "Declaracao", "$@1", "$@2", "$@3",
  "Membro_Simples", "Dimensoes", "Array", "Campo_Objeto",
  "Continuacao_Objeto", "Objeto", "Casos_ID", "Casos_Objeto", "Membro",
  "Termo", "Conta", "Argumentos", "Parametros", "Bloco_Funcao", "Retorno",
  "Funcao", "$@4", "Jump_IF", "Jump_While", "Jump_For", "SENAO", "Comando",
  "Retorno_Comandos", "Bloco", "$@5", "Expressao", "Continuacao", "S", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-177)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     351,  -177,  -177,  -177,   130,   -28,   -25,  -177,  -177,  -177,
    -177,   -21,    18,  -177,   467,  -177,  -177,   467,   467,   425,
    -177,  -177,  -177,  -177,   523,  -177,  -177,   158,   114,   380,
    -177,   234,  -177,   380,   -17,    36,   114,    21,   483,   467,
     438,    11,  -177,   264,   380,   380,    62,    62,    62,   380,
    -177,   130,   454,   523,  -177,  -177,  -177,    78,   438,   503,
     409,    45,   234,  -177,    61,   467,  -177,   264,   467,   467,
     467,   467,   467,  -177,  -177,   467,   467,   467,   467,   467,
    -177,  -177,   234,   234,    42,  -177,  -177,   234,  -177,  -177,
     467,  -177,   497,  -177,  -177,    52,   438,    55,    89,    -1,
    -177,    11,  -177,  -177,    50,    58,   -13,  -177,  -177,  -177,
      63,    66,  -177,   491,  -177,    33,  -177,    64,   467,  -177,
    -177,    77,   467,  -177,  -177,   527,  -177,  -177,  -177,  -177,
       5,  -177,     5,   114,   114,   114,   114,   114,  -177,  -177,
     234,  -177,  -177,   483,    64,    69,  -177,    11,  -177,   380,
     322,   467,   102,  -177,  -177,   322,    62,    33,   467,    11,
     264,   467,  -177,  -177,    70,  -177,   467,   158,   158,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,    75,  -177,    76,
    -177,   293,    80,    85,    -7,  -177,   322,    81,  -177,    82,
    -177,    96,  -177,  -177,    97,  -177,  -177,  -177,  -177,   380,
     234,  -177,   129,  -177,   467,   135,  -177,  -177,   103,    64,
      64,   110,  -177,  -177,    85,   117,   234,  -177,  -177,  -177,
     322,  -177,   132,  -177,   322,   116,   467,   115,  -177,  -177,
    -177
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      39,    41,    42,    40,    11,     0,     0,    33,    35,    37,
      43,     0,     0,    76,     0,   113,    44,     0,     0,    81,
     104,   107,    69,    58,     5,    71,    70,    20,    17,    39,
      72,   117,   106,    39,     0,     0,    17,     0,     0,     0,
      81,    55,    64,    62,    39,    39,     0,     0,     0,    39,
      87,    11,    81,     5,   102,    74,    73,    11,    81,     5,
       0,     0,   117,    67,     0,     0,    65,    68,     0,     0,
       0,     0,     0,    24,    77,     0,     0,     0,     0,     0,
      78,   111,   117,   117,     0,   119,   112,   117,     1,    61,
       0,    60,    11,    10,     9,     0,    81,    51,     0,     0,
      50,    55,    56,   108,     0,     0,    28,    34,    36,    38,
       0,     0,    62,    11,    68,     0,    80,    46,     0,    79,
      89,   103,     0,    66,     4,     5,     3,   110,    18,    19,
      20,    22,    20,    17,    17,    17,    17,    17,   116,   115,
     117,   118,     6,     0,    46,     0,    50,    55,    52,    39,
     103,     0,     0,    32,    26,   103,    83,     0,     0,    55,
      63,     0,    59,    75,     0,     7,     0,    20,    20,    16,
      12,    13,    14,    15,   114,     8,    48,     0,    54,     0,
      99,    98,     0,    28,    30,   101,    93,     0,    82,     0,
      63,     0,    57,   109,     0,   105,     2,    21,    23,    39,
     117,    91,    98,    31,     0,     0,    29,    92,     0,    46,
      46,     0,    97,    90,    28,    30,   117,    88,    49,    45,
      96,    27,    86,   100,    95,     0,     0,     0,    94,    85,
      84
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,     1,  -177,  -177,  -177,    22,  -177,    -2,   -95,  -121,
    -176,  -173,   -46,  -177,  -177,  -177,  -177,  -177,  -124,   -33,
      65,   -96,     0,  -177,  -177,   -57,   154,    40,   -48,  -177,
    -177,  -177,    60,  -177,  -177,  -177,  -177,   -34,   169,    57,
    -146,  -177,    27,   -59,  -177
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,   124,    66,    91,   123,    93,    42,    80,    73,    74,
     153,   154,   107,    21,    46,    47,    48,    22,   162,    23,
     101,   102,    53,    25,    26,    27,    28,    29,    61,   189,
     217,   227,    30,   111,   180,   185,   223,   201,    83,    32,
      33,    62,    84,    85,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   108,   109,   121,   181,   148,    97,   203,   100,   186,
     116,   206,   119,   130,    44,   132,   151,    45,    97,    59,
     176,    49,   204,   138,   139,    50,   152,    34,   141,    24,
      87,    24,   205,    24,    89,   167,    88,   168,   221,    68,
      69,    98,   206,    24,    24,    24,   197,   198,   119,    24,
      90,   178,    59,    98,    54,    99,    81,    12,    56,    60,
      86,   163,    24,   192,    43,   125,   146,    24,   100,   106,
     103,   104,   105,   158,   224,    40,   110,   159,    94,    95,
      96,   174,    24,    24,    67,   218,   219,    24,   120,   140,
     122,    36,    60,   144,   127,    39,   145,   149,    96,    37,
      96,   150,    12,    14,   161,   126,   155,    38,   156,   184,
     188,   112,   177,   114,   100,   158,   195,   112,    39,   114,
      40,   115,    41,   199,   152,   208,   100,   202,   207,    75,
     142,   169,   170,   171,   172,   173,    96,   209,   210,   200,
      24,   212,   215,    36,    76,    77,    78,    79,   216,    24,
      24,    37,   112,   220,    12,    24,   205,   222,   226,    38,
      24,   230,   165,   228,   147,   175,   125,   196,   213,    31,
      39,    55,    40,   112,    41,   160,   179,   182,   164,     0,
       0,    24,   187,    94,     0,   114,    24,   193,     0,     0,
       0,   183,    68,    69,    70,    71,    72,     0,   191,    24,
      24,   194,     0,     0,     0,     0,   126,     0,    86,     0,
       0,     0,     0,    86,     0,     0,    24,   190,     0,     0,
      24,     0,   128,   129,    24,   131,   211,     0,     0,   133,
     134,   135,   136,   137,     0,     0,     0,     1,     2,     3,
       0,     4,     5,     6,   214,     7,     0,   225,     0,     0,
       0,    86,     0,     8,     9,     0,    10,    11,    12,    13,
      14,    15,    16,     0,    17,    18,   229,     1,     2,     3,
       0,     4,     0,     0,     0,     7,    19,     0,     0,    20,
       0,    82,     0,     8,     9,     0,    10,     0,    12,    13,
      14,    15,    16,     0,    17,    18,     1,     2,     3,     0,
       4,     0,     0,   200,     7,     0,    19,   -39,     0,    20,
       0,   -39,     8,     9,     0,    10,     0,    12,    13,    14,
      15,    16,     0,    17,    18,     1,     2,     3,     0,     4,
       0,     0,     0,     7,     0,    19,     0,     0,    20,     0,
     -39,     8,     9,     0,    10,     0,    12,    13,    14,    15,
      16,     0,    17,    18,     1,     2,     3,     0,     4,     5,
       6,     0,     7,     0,    19,     0,     0,    20,     0,   -39,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
       0,    17,    18,     1,     2,     3,     0,     4,     0,     0,
       0,     7,     0,    19,     0,     0,    20,     0,     0,     8,
       9,     0,    10,     0,    12,    13,    14,    15,    16,     0,
      17,    18,     1,     2,     3,     0,    51,     0,     0,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     1,     2,
       3,    10,    57,    12,    13,     0,     0,    16,     0,    17,
      18,     1,     2,     3,     0,    51,     0,    10,    58,    12,
      13,    52,   118,    16,     0,    17,    18,     1,     2,     3,
      10,   113,    12,    13,    58,     0,    16,    52,    17,    18,
       1,     2,     3,     0,    51,     0,    10,    58,    12,    13,
      52,     0,    16,     0,    17,    18,     1,     2,     3,    10,
      92,    12,    13,    58,     0,    16,    52,    17,    18,     0,
       0,     0,     0,     0,    36,    10,     0,    12,    13,    52,
      36,    16,    37,    17,    18,    12,    63,     0,    37,     0,
      38,    12,     0,     0,    64,    52,   143,    12,     0,     0,
       0,    39,    65,    40,   157,    41,    63,    39,     0,    40,
      63,    41,     0,     0,    64,    40,   117,    12,    64,     0,
       0,    12,    65,     0,     0,     0,   166,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,     0,     0,    40
};

static const yytype_int16 yycheck[] =
{
       0,    47,    48,    62,   150,   101,     7,   183,    41,   155,
      58,   184,    60,    70,    42,    72,    29,    42,     7,    19,
     144,    42,    29,    82,    83,     7,    39,     0,    87,    29,
      47,    31,    39,    33,    36,   130,     0,   132,   214,    34,
      35,    42,   215,    43,    44,    45,   167,   168,    96,    49,
      29,   147,    52,    42,    14,    44,    29,    24,    18,    19,
      33,   118,    62,   159,     4,    65,    99,    67,   101,     7,
      43,    44,    45,    40,   220,    42,    49,    44,    38,    39,
      40,   140,    82,    83,    24,   209,   210,    87,    43,    47,
      29,    13,    52,    41,    67,    40,     7,    47,    58,    21,
      60,    43,    24,    26,    40,    65,    43,    29,    42,     7,
     156,    51,    43,    53,   147,    40,    46,    57,    40,    59,
      42,    43,    44,    47,    39,    43,   159,    47,    47,    15,
      90,   133,   134,   135,   136,   137,    96,    41,    41,    10,
     140,   200,     7,    13,    30,    31,    32,    33,    45,   149,
     150,    21,    92,    43,    24,   155,    39,   216,    26,    29,
     160,    46,   122,    47,    99,   143,   166,   166,   202,     0,
      40,    17,    42,   113,    44,   115,   149,   150,   121,    -1,
      -1,   181,   155,   143,    -1,   125,   186,   160,    -1,    -1,
      -1,   151,    34,    35,    36,    37,    38,    -1,   158,   199,
     200,   161,    -1,    -1,    -1,    -1,   166,    -1,   181,    -1,
      -1,    -1,    -1,   186,    -1,    -1,   216,   157,    -1,    -1,
     220,    -1,    68,    69,   224,    71,   199,    -1,    -1,    75,
      76,    77,    78,    79,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,   204,    11,    -1,   220,    -1,    -1,
      -1,   224,    -1,    19,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    31,   226,     3,     4,     5,
      -1,     7,    -1,    -1,    -1,    11,    42,    -1,    -1,    45,
      -1,    47,    -1,    19,    20,    -1,    22,    -1,    24,    25,
      26,    27,    28,    -1,    30,    31,     3,     4,     5,    -1,
       7,    -1,    -1,    10,    11,    -1,    42,    43,    -1,    45,
      -1,    47,    19,    20,    -1,    22,    -1,    24,    25,    26,
      27,    28,    -1,    30,    31,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    -1,    42,    -1,    -1,    45,    -1,
      47,    19,    20,    -1,    22,    -1,    24,    25,    26,    27,
      28,    -1,    30,    31,     3,     4,     5,    -1,     7,     8,
       9,    -1,    11,    -1,    42,    -1,    -1,    45,    -1,    47,
      19,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    31,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    11,    -1,    42,    -1,    -1,    45,    -1,    -1,    19,
      20,    -1,    22,    -1,    24,    25,    26,    27,    28,    -1,
      30,    31,     3,     4,     5,    -1,     7,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    45,    -1,    -1,     3,     4,
       5,    22,     7,    24,    25,    -1,    -1,    28,    -1,    30,
      31,     3,     4,     5,    -1,     7,    -1,    22,    39,    24,
      25,    42,    43,    28,    -1,    30,    31,     3,     4,     5,
      22,     7,    24,    25,    39,    -1,    28,    42,    30,    31,
       3,     4,     5,    -1,     7,    -1,    22,    39,    24,    25,
      42,    -1,    28,    -1,    30,    31,     3,     4,     5,    22,
       7,    24,    25,    39,    -1,    28,    42,    30,    31,    -1,
      -1,    -1,    -1,    -1,    13,    22,    -1,    24,    25,    42,
      13,    28,    21,    30,    31,    24,    13,    -1,    21,    -1,
      29,    24,    -1,    -1,    21,    42,    29,    24,    -1,    -1,
      -1,    40,    29,    42,    43,    44,    13,    40,    -1,    42,
      13,    44,    -1,    -1,    21,    42,    43,    24,    21,    -1,
      -1,    24,    29,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    11,    19,    20,
      22,    23,    24,    25,    26,    27,    28,    30,    31,    42,
      45,    61,    65,    67,    70,    71,    72,    73,    74,    75,
      80,    86,    87,    88,    90,    92,    13,    21,    29,    40,
      42,    44,    54,    80,    42,    42,    62,    63,    64,    42,
       7,     7,    42,    70,    75,    74,    75,     7,    39,    70,
      75,    76,    89,    13,    21,    29,    50,    80,    34,    35,
      36,    37,    38,    56,    57,    15,    30,    31,    32,    33,
      55,    90,    47,    86,    90,    91,    90,    47,     0,    55,
      29,    51,     7,    53,    75,    75,    75,     7,    42,    44,
      67,    68,    69,    90,    90,    90,     7,    60,    60,    60,
      90,    81,    80,     7,    80,    43,    76,    43,    43,    76,
      43,    91,    29,    52,    49,    70,    75,    90,    74,    74,
      73,    74,    73,    74,    74,    74,    74,    74,    91,    91,
      47,    91,    75,    29,    41,     7,    67,    68,    69,    47,
      43,    29,    39,    58,    59,    43,    42,    43,    40,    44,
      80,    40,    66,    73,    87,    75,    29,    56,    56,    55,
      55,    55,    55,    55,    91,    53,    66,    43,    69,    90,
      82,    88,    90,    75,     7,    83,    88,    90,    60,    77,
      80,    75,    69,    90,    75,    46,    49,    57,    57,    47,
      10,    85,    47,    58,    29,    39,    59,    47,    43,    41,
      41,    90,    91,    85,    75,     7,    45,    78,    66,    66,
      43,    58,    91,    84,    88,    90,    26,    79,    47,    75,
      46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    51,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    56,    56,
      56,    57,    57,    57,    57,    57,    58,    58,    58,    59,
      59,    60,    60,    62,    61,    63,    61,    64,    61,    61,
      65,    65,    65,    65,    65,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      71,    71,    71,    71,    71,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    76,
      76,    76,    77,    77,    78,    79,    79,    81,    80,    80,
      82,    82,    83,    83,    84,    84,    84,    85,    85,    86,
      86,    86,    87,    87,    89,    88,    88,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    91,    91,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     1,     2,     0,     2,     2,     3,     1,
       2,     0,     3,     3,     3,     3,     3,     0,     2,     2,
       0,     4,     2,     4,     1,     0,     1,     5,     0,     3,
       0,     4,     2,     0,     3,     0,     3,     0,     3,     0,
       1,     1,     1,     1,     1,     4,     0,     4,     5,     7,
       1,     1,     2,     1,     3,     0,     3,     5,     1,     4,
       3,     3,     2,     4,     2,     2,     3,     2,     2,     1,
       1,     1,     1,     2,     2,     4,     1,     2,     2,     2,
       2,     0,     1,     0,     4,     2,     0,     0,     7,     3,
       3,     2,     2,     1,     2,     1,     0,     2,     0,     5,
       9,     5,     2,     0,     0,     5,     1,     1,     3,     5,
       3,     2,     2,     1,     3,     2,     2,     0,     3,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Atribuicao_Objeto2: Objeto '=' Atribuicao_Objeto2  */
#line 78 "mini_js.y"
                                                         {yyval.valor = yyvsp[-2].valor + yyvsp[0].valor + " " + yyvsp[-2].valor + "[@] [=] ^ ";}
#line 1536 "y.tab.c"
    break;

  case 3: /* Atribuicao_Objeto2: Conta  */
#line 79 "mini_js.y"
                                                         {yyval.valor = yyvsp[0].valor + "[=] ^ ";}
#line 1542 "y.tab.c"
    break;

  case 4: /* Atribuicao_Objeto: '=' Atribuicao_Objeto2  */
#line 82 "mini_js.y"
                                                    {yyval.valor = yyvsp[0].valor;}
#line 1548 "y.tab.c"
    break;

  case 5: /* Atribuicao_Objeto: %empty  */
#line 83 "mini_js.y"
                                                    {yyval.valor = "[@] ";}
#line 1554 "y.tab.c"
    break;

  case 6: /* Atribuicao_MIGUAL: '=' Conta  */
#line 86 "mini_js.y"
                                         {yyval.valor = yyvsp[0].valor + " + = ^ ";}
#line 1560 "y.tab.c"
    break;

  case 7: /* AtribuicaoObj_MIGUAL: '=' Conta  */
#line 89 "mini_js.y"
                                         {yyval.valor = yyvsp[0].valor + " + [=] ^ ";}
#line 1566 "y.tab.c"
    break;

  case 8: /* Atribuicao_ID2: _ID '=' Atribuicao_ID2  */
#line 92 "mini_js.y"
                                         {yyval.valor = yyvsp[-2].valor + yyvsp[0].valor + acessar_variavel(yyvsp[-2].valor) + "= ^ ";}
#line 1572 "y.tab.c"
    break;

  case 9: /* Atribuicao_ID2: Conta  */
#line 93 "mini_js.y"
                                         {yyval.valor = yyvsp[0].valor + "= ^ ";}
#line 1578 "y.tab.c"
    break;

  case 10: /* Atribuicao_ID: '=' Atribuicao_ID2  */
#line 96 "mini_js.y"
                                          {yyval.valor = " " + yyvsp[0].valor;}
#line 1584 "y.tab.c"
    break;

  case 11: /* Atribuicao_ID: %empty  */
#line 97 "mini_js.y"
                                          {string space = " ";yyval.valor = " @" + space;}
#line 1590 "y.tab.c"
    break;

  case 12: /* Conta_Simples: '-' Termo Conta_Simples  */
#line 100 "mini_js.y"
                                                        {yyval.valor = yyvsp[-1].valor + "- " + yyvsp[0].valor;}
#line 1596 "y.tab.c"
    break;

  case 13: /* Conta_Simples: '+' Termo Conta_Simples  */
#line 101 "mini_js.y"
                                                        {yyval.valor = yyvsp[-1].valor + "+ " + yyvsp[0].valor;}
#line 1602 "y.tab.c"
    break;

  case 14: /* Conta_Simples: '>' Termo Conta_Simples  */
#line 102 "mini_js.y"
                                                        {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor + "> ";}
#line 1608 "y.tab.c"
    break;

  case 15: /* Conta_Simples: '<' Termo Conta_Simples  */
#line 103 "mini_js.y"
                                                        {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor + "< ";}
#line 1614 "y.tab.c"
    break;

  case 16: /* Conta_Simples: _IGUAL Termo Conta_Simples  */
#line 104 "mini_js.y"
                                                           {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor + "== ";}
#line 1620 "y.tab.c"
    break;

  case 17: /* Conta_Simples: %empty  */
#line 105 "mini_js.y"
                                                        {yyval.valor = "";}
#line 1626 "y.tab.c"
    break;

  case 18: /* Conta_Complexa2: '^' Termo  */
#line 108 "mini_js.y"
                                {yyval.valor = " " + yyvsp[0].valor + " ^";}
#line 1632 "y.tab.c"
    break;

  case 19: /* Conta_Complexa2: '!' Termo  */
#line 109 "mini_js.y"
                                {yyval.valor = " fat #" + yyvsp[0].valor;}
#line 1638 "y.tab.c"
    break;

  case 20: /* Conta_Complexa2: %empty  */
#line 110 "mini_js.y"
                                {yyval.valor = "";}
#line 1644 "y.tab.c"
    break;

  case 21: /* Conta_Complexa: '*' Membro Conta_Complexa2 Conta_Complexa  */
#line 113 "mini_js.y"
                                                                {yyval.valor = yyvsp[-2].valor + yyvsp[-1].valor + "* " + yyvsp[0].valor;}
#line 1650 "y.tab.c"
    break;

  case 22: /* Conta_Complexa: '/' Termo  */
#line 114 "mini_js.y"
                                                                {yyval.valor = yyvsp[0].valor + "/ ";}
#line 1656 "y.tab.c"
    break;

  case 23: /* Conta_Complexa: '%' Membro Conta_Complexa2 Conta_Complexa  */
#line 115 "mini_js.y"
                                                                {yyval.valor = yyvsp[-2].valor + yyvsp[-1].valor + "% " + yyvsp[0].valor;}
#line 1662 "y.tab.c"
    break;

  case 24: /* Conta_Complexa: Conta_Complexa2  */
#line 116 "mini_js.y"
                                                                {yyval.valor = yyvsp[0].valor;}
#line 1668 "y.tab.c"
    break;

  case 25: /* Conta_Complexa: %empty  */
#line 117 "mini_js.y"
                                                                {yyval.valor = "";}
#line 1674 "y.tab.c"
    break;

  case 26: /* Declaracao_Complexa: Declaracao_Simples  */
#line 120 "mini_js.y"
                                                                {yyval.valor = yyvsp[0].valor; yyval.args_value = yyvsp[0].args_value;}
#line 1680 "y.tab.c"
    break;

  case 27: /* Declaracao_Complexa: ',' _ID '=' Conta Declaracao_Complexa  */
#line 121 "mini_js.y"
                                                                {yyval.valor = declarar(yyvsp[-3].valor) + yyvsp[-3].valor + " " + yyvsp[-1].valor + "= ^ "+ yyvsp[0].valor;}
#line 1686 "y.tab.c"
    break;

  case 28: /* Declaracao_Complexa: %empty  */
#line 122 "mini_js.y"
                                                                {yyval.valor = "";}
#line 1692 "y.tab.c"
    break;

  case 29: /* Declaracao_Simples: ',' _ID Declaracao_Simples  */
#line 125 "mini_js.y"
                                                  {yyval.valor = declarar(yyvsp[-1].valor) + yyvsp[0].valor; yyvsp[0].args_value.push_back(yyvsp[-1].valor); yyval.args_value = yyvsp[0].args_value;}
#line 1698 "y.tab.c"
    break;

  case 30: /* Declaracao_Simples: %empty  */
#line 126 "mini_js.y"
                                                  {yyval.valor = ""; }
#line 1704 "y.tab.c"
    break;

  case 31: /* Expressao_Declaracao: _ID '=' Conta Declaracao_Complexa  */
#line 129 "mini_js.y"
                                                              {yyval.valor = declarar(yyvsp[-3].valor) + yyvsp[-3].valor + " " + yyvsp[-1].valor + "= ^ " + yyvsp[0].valor;}
#line 1710 "y.tab.c"
    break;

  case 32: /* Expressao_Declaracao: _ID Declaracao_Complexa  */
#line 130 "mini_js.y"
                                                              {yyval.valor = declarar(yyvsp[-1].valor) + yyvsp[0].valor; yyvsp[0].args_value.push_back(yyvsp[-1].valor); yyval.args_value = yyvsp[0].args_value;}
#line 1716 "y.tab.c"
    break;

  case 33: /* $@1: %empty  */
#line 133 "mini_js.y"
                     {declaracao = yyvsp[0].valor;}
#line 1722 "y.tab.c"
    break;

  case 34: /* Declaracao: _LET $@1 Expressao_Declaracao  */
#line 133 "mini_js.y"
                                                                      {yyval.valor = yyvsp[0].valor;}
#line 1728 "y.tab.c"
    break;

  case 35: /* $@2: %empty  */
#line 134 "mini_js.y"
                     {declaracao = yyvsp[0].valor;}
#line 1734 "y.tab.c"
    break;

  case 36: /* Declaracao: _CONST $@2 Expressao_Declaracao  */
#line 134 "mini_js.y"
                                                                      {yyval.valor = yyvsp[0].valor;}
#line 1740 "y.tab.c"
    break;

  case 37: /* $@3: %empty  */
#line 135 "mini_js.y"
                     {declaracao = yyvsp[0].valor;}
#line 1746 "y.tab.c"
    break;

  case 38: /* Declaracao: _VAR $@3 Expressao_Declaracao  */
#line 135 "mini_js.y"
                                                                      {yyval.valor = yyvsp[0].valor;}
#line 1752 "y.tab.c"
    break;

  case 39: /* Declaracao: %empty  */
#line 136 "mini_js.y"
                                              {yyval.valor = "";}
#line 1758 "y.tab.c"
    break;

  case 40: /* Membro_Simples: _STRING  */
#line 139 "mini_js.y"
                                   {yyval.valor = yyvsp[0].valor + " ";}
#line 1764 "y.tab.c"
    break;

  case 41: /* Membro_Simples: _INT  */
#line 140 "mini_js.y"
                                   {yyval.valor = yyvsp[0].valor + " ";}
#line 1770 "y.tab.c"
    break;

  case 42: /* Membro_Simples: _FLOAT  */
#line 141 "mini_js.y"
                                   {yyval.valor = yyvsp[0].valor + " ";}
#line 1776 "y.tab.c"
    break;

  case 43: /* Membro_Simples: _NOVO_OBJETO  */
#line 142 "mini_js.y"
                                     {yyval.valor = "{} ";}
#line 1782 "y.tab.c"
    break;

  case 44: /* Membro_Simples: _ARRAY  */
#line 143 "mini_js.y"
                                   {yyval.valor = "[] ";}
#line 1788 "y.tab.c"
    break;

  case 45: /* Dimensoes: '[' Conta ']' Dimensoes  */
#line 146 "mini_js.y"
                                            {yyval.valor ="[@] " + yyvsp[-2].valor + yyvsp[-2].getRetorno() + yyvsp[0].valor;}
#line 1794 "y.tab.c"
    break;

  case 46: /* Dimensoes: %empty  */
#line 147 "mini_js.y"
                                            {yyval.valor = "";}
#line 1800 "y.tab.c"
    break;

  case 47: /* Array: _ID '[' Conta ']'  */
#line 151 "mini_js.y"
                                                           {yyval.valor = acessar_objeto(yyvsp[-3].valor) + yyvsp[-1].valor;}
#line 1806 "y.tab.c"
    break;

  case 48: /* Array: _ID '[' Conta ']' Dimensoes  */
#line 152 "mini_js.y"
                                                           {yyval.valor = acessar_campo(yyvsp[-4].valor, yyvsp[-2].valor) + yyvsp[-2].getRetorno() + yyvsp[0].valor;}
#line 1812 "y.tab.c"
    break;

  case 49: /* Array: '(' _ID ')' '[' Conta ']' Dimensoes  */
#line 153 "mini_js.y"
                                                           {yyval.valor = acessar_campo(yyvsp[-5].valor, yyvsp[-2].valor) + yyvsp[-2].getRetorno() + yyvsp[0].valor;}
#line 1818 "y.tab.c"
    break;

  case 50: /* Campo_Objeto: Array  */
#line 156 "mini_js.y"
                                                     {yyval.valor = yyvsp[0].valor;}
#line 1824 "y.tab.c"
    break;

  case 51: /* Campo_Objeto: _ID  */
#line 157 "mini_js.y"
                                                     {yyval.valor = yyvsp[0].valor + " ";}
#line 1830 "y.tab.c"
    break;

  case 52: /* Continuacao_Objeto: Campo_Objeto Continuacao_Objeto  */
#line 160 "mini_js.y"
                                                                      {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;}
#line 1836 "y.tab.c"
    break;

  case 53: /* Continuacao_Objeto: Array  */
#line 161 "mini_js.y"
                                                                      {yyval.valor = yyvsp[0].valor;}
#line 1842 "y.tab.c"
    break;

  case 54: /* Continuacao_Objeto: '.' Campo_Objeto Continuacao_Objeto  */
#line 162 "mini_js.y"
                                                                      {string space = " ";yyval.valor = " [@]" + space + yyvsp[-1].valor + yyvsp[0].valor;}
#line 1848 "y.tab.c"
    break;

  case 55: /* Continuacao_Objeto: %empty  */
#line 163 "mini_js.y"
                                                                      {yyval.valor = "";}
#line 1854 "y.tab.c"
    break;

  case 56: /* Objeto: _ID '.' Continuacao_Objeto  */
#line 166 "mini_js.y"
                                                               {yyval.valor = acessar_campo(yyvsp[-2].valor, yyvsp[0].valor);}
#line 1860 "y.tab.c"
    break;

  case 57: /* Objeto: '(' _ID ')' '.' Continuacao_Objeto  */
#line 167 "mini_js.y"
                                                               {yyval.valor = acessar_campo(yyvsp[-3].valor, yyvsp[0].valor);}
#line 1866 "y.tab.c"
    break;

  case 58: /* Objeto: Array  */
#line 168 "mini_js.y"
                                                               {yyval.valor = yyvsp[0].valor;}
#line 1872 "y.tab.c"
    break;

  case 59: /* Objeto: '(' Objeto ')' Dimensoes  */
#line 169 "mini_js.y"
                                                               {yyval.valor = yyvsp[-2].valor + yyvsp[0].valor;}
#line 1878 "y.tab.c"
    break;

  case 60: /* Casos_ID: _ID _CONCAT Atribuicao_MIGUAL  */
#line 172 "mini_js.y"
                                                           {yyval.valor = yyvsp[-2].valor + acessar_variavel(yyvsp[-2].valor) + yyvsp[0].valor;}
#line 1884 "y.tab.c"
    break;

  case 61: /* Casos_ID: _ID _MAISMAIS Conta_Simples  */
#line 173 "mini_js.y"
                                                         {yyval.valor = yyvsp[-2].valor + " @" + yyvsp[0].valor + " " + yyvsp[-2].valor + " " + acessar_variavel(yyvsp[-2].valor) + "1 + = ^ ";}
#line 1890 "y.tab.c"
    break;

  case 62: /* Casos_ID: _ID Funcao  */
#line 174 "mini_js.y"
                                                         {yyval.valor = yyvsp[0].valor + acessar_variavel(yyvsp[-1].valor) + "$ ";}
#line 1896 "y.tab.c"
    break;

  case 63: /* Casos_ID: '(' _ID ')' Funcao  */
#line 175 "mini_js.y"
                                                         {yyval.valor = yyvsp[0].valor + acessar_variavel(yyvsp[-2].valor) + "$ ";}
#line 1902 "y.tab.c"
    break;

  case 64: /* Casos_ID: _ID Atribuicao_ID  */
#line 176 "mini_js.y"
                                                         {checkVar(yyvsp[-1].valor);yyval.valor = yyvsp[-1].valor + yyvsp[0].valor; yyval.retorno = yyvsp[0].valor == " @ "? "" : acessar_variavel(yyvsp[-1].valor);}
#line 1908 "y.tab.c"
    break;

  case 65: /* Casos_Objeto: Objeto Atribuicao_Objeto  */
#line 179 "mini_js.y"
                                                                    {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;}
#line 1914 "y.tab.c"
    break;

  case 66: /* Casos_Objeto: Objeto _CONCAT AtribuicaoObj_MIGUAL  */
#line 180 "mini_js.y"
                                                                      {yyval.valor = yyvsp[-2].valor + " " + acessar_objeto(yyvsp[-2].valor) + yyvsp[0].valor;}
#line 1920 "y.tab.c"
    break;

  case 67: /* Casos_Objeto: Objeto _MAISMAIS  */
#line 181 "mini_js.y"
                                                                    {yyval.valor = yyvsp[-1].valor + acessar_variavel(yyvsp[-1].valor) + "1 + [=] ^ " + acessar_variavel(yyvsp[-1].valor);}
#line 1926 "y.tab.c"
    break;

  case 68: /* Casos_Objeto: Objeto Funcao  */
#line 182 "mini_js.y"
                                                                    {yyval.valor = yyvsp[0].valor + yyvsp[-1].valor + "[@] $ ";}
#line 1932 "y.tab.c"
    break;

  case 69: /* Membro: Membro_Simples  */
#line 185 "mini_js.y"
                                                  {yyval.valor = yyvsp[0].valor;}
#line 1938 "y.tab.c"
    break;

  case 70: /* Membro: Casos_Objeto  */
#line 186 "mini_js.y"
                                                  {yyval.valor = yyvsp[0].valor;}
#line 1944 "y.tab.c"
    break;

  case 71: /* Membro: Casos_ID  */
#line 187 "mini_js.y"
                                                  {yyval.valor = yyvsp[0].valor; yyval.retorno=yyvsp[0].retorno;}
#line 1950 "y.tab.c"
    break;

  case 72: /* Membro: Funcao  */
#line 188 "mini_js.y"
                                                  {yyval.valor = yyvsp[0].valor;}
#line 1956 "y.tab.c"
    break;

  case 73: /* Membro: '+' Conta  */
#line 189 "mini_js.y"
                                                  {yyval.valor = yyvsp[0].valor;}
#line 1962 "y.tab.c"
    break;

  case 74: /* Membro: '-' Termo  */
#line 190 "mini_js.y"
                                                  {yyval.valor = "0 " + yyvsp[0].valor + "- ";}
#line 1968 "y.tab.c"
    break;

  case 75: /* Membro: '(' Conta ')' Membro  */
#line 191 "mini_js.y"
                                                  {yyval.valor = yyvsp[-2].valor;}
#line 1974 "y.tab.c"
    break;

  case 76: /* Membro: _BOLEANO  */
#line 192 "mini_js.y"
                                                  {yyval.valor = yyvsp[0].valor + " ";}
#line 1980 "y.tab.c"
    break;

  case 77: /* Termo: Membro Conta_Complexa  */
#line 195 "mini_js.y"
                                  {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;yyval.retorno=yyvsp[-1].retorno;}
#line 1986 "y.tab.c"
    break;

  case 78: /* Conta: Termo Conta_Simples  */
#line 198 "mini_js.y"
                                  {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;yyval.retorno=yyvsp[-1].retorno;}
#line 1992 "y.tab.c"
    break;

  case 79: /* Argumentos: Conta Argumentos  */
#line 201 "mini_js.y"
                                  {yyval.valor = yyvsp[-1].valor + yyvsp[-1].getRetorno() + yyvsp[0].valor; yyval.parametros = 1 + yyvsp[0].parametros;}
#line 1998 "y.tab.c"
    break;

  case 80: /* Argumentos: ',' Argumentos  */
#line 202 "mini_js.y"
                                  {yyval.valor = yyvsp[0].valor; yyval.parametros = yyvsp[0].parametros;}
#line 2004 "y.tab.c"
    break;

  case 81: /* Argumentos: %empty  */
#line 203 "mini_js.y"
                                  {yyval.valor = ""; yyval.parametros = 0;}
#line 2010 "y.tab.c"
    break;

  case 82: /* Parametros: Expressao_Declaracao  */
#line 206 "mini_js.y"
                                  {yyval.valor = declarar_arg(yyvsp[0].args_value);}
#line 2016 "y.tab.c"
    break;

  case 83: /* Parametros: %empty  */
#line 207 "mini_js.y"
                                  {yyval.valor = "";}
#line 2022 "y.tab.c"
    break;

  case 84: /* Bloco_Funcao: '{' Continuacao Retorno '}'  */
#line 210 "mini_js.y"
                                           {yyval.valor = yyvsp[-2].valor + yyvsp[-1].valor;}
#line 2028 "y.tab.c"
    break;

  case 85: /* Retorno: _RETURN Conta  */
#line 213 "mini_js.y"
                        {yyval.valor = yyvsp[0].valor + acessar_variavel("'&retorno'") + "~ ";}
#line 2034 "y.tab.c"
    break;

  case 86: /* Retorno: %empty  */
#line 214 "mini_js.y"
                        {yyval.valor = "undefined @" + acessar_variavel("'&retorno'") + " ~";}
#line 2040 "y.tab.c"
    break;

  case 87: /* $@4: %empty  */
#line 216 "mini_js.y"
                        {funcao = yyvsp[0].valor; escopo_local = true;}
#line 2046 "y.tab.c"
    break;

  case 88: /* Funcao: _FUNCTION _ID $@4 '(' Parametros ')' Bloco_Funcao  */
#line 216 "mini_js.y"
                                                                                                  {yyval.valor = declara_funcao(yyvsp[-5].valor, yyvsp[-2].valor, yyvsp[0].valor);}
#line 2052 "y.tab.c"
    break;

  case 89: /* Funcao: '(' Argumentos ')'  */
#line 217 "mini_js.y"
                                                  {yyval.valor = yyvsp[-1].valor + to_string(yyvsp[-1].parametros) + " ";}
#line 2058 "y.tab.c"
    break;

  case 90: /* Jump_IF: Expressao ';' SENAO  */
#line 220 "mini_js.y"
                                           {contador++;yyval.valor = yyvsp[0].valor + jumpComandos("end_if", "then_") + yyvsp[-2].valor + enderecoResolvido("end_if") + " ";}
#line 2064 "y.tab.c"
    break;

  case 91: /* Jump_IF: Bloco SENAO  */
#line 221 "mini_js.y"
                                           {contador++;yyval.valor = yyvsp[0].valor + jumpComandos("end_if", "then_") + yyvsp[-1].valor + enderecoResolvido("end_if") + " ";}
#line 2070 "y.tab.c"
    break;

  case 92: /* Jump_While: Expressao ';'  */
#line 224 "mini_js.y"
                                           {contador++;yyval.valor = jumpComandos("end_while", "whilec_") + yyvsp[-1].valor + " " + jumpComandos("while_", "end_while");}
#line 2076 "y.tab.c"
    break;

  case 93: /* Jump_While: Bloco  */
#line 225 "mini_js.y"
                                           {contador++;yyval.valor = jumpComandos("end_while", "whilec_") + yyvsp[0].valor + " " + jumpComandos("while_", "end_while");}
#line 2082 "y.tab.c"
    break;

  case 94: /* Jump_For: Expressao ';'  */
#line 228 "mini_js.y"
                                           {contador++;yyval.valor = jumpComandos("end_for", "forc_") + yyvsp[-1].valor;}
#line 2088 "y.tab.c"
    break;

  case 95: /* Jump_For: Bloco  */
#line 229 "mini_js.y"
                                           {contador++;yyval.valor = jumpComandos("end_for", "forc_") + yyvsp[0].valor;}
#line 2094 "y.tab.c"
    break;

  case 97: /* SENAO: _ELSE Continuacao  */
#line 233 "mini_js.y"
                              {yyval.valor = yyvsp[0].valor;}
#line 2100 "y.tab.c"
    break;

  case 98: /* SENAO: %empty  */
#line 234 "mini_js.y"
                              {yyval.valor = "";}
#line 2106 "y.tab.c"
    break;

  case 99: /* Comando: _IF '(' Expressao ')' Jump_IF  */
#line 237 "mini_js.y"
                                                                         {yyval.valor = yyvsp[-2].valor + enderecoPraFrente("then_") + " ?" + yyvsp[0].valor;}
#line 2112 "y.tab.c"
    break;

  case 100: /* Comando: _FOR '(' Expressao ';' Expressao ';' Expressao ')' Jump_For  */
#line 238 "mini_js.y"
                                                                         {yyval.valor = yyvsp[-6].valor + " " + enderecoResolvido("for_") + " " + yyvsp[-4].valor + " " + enderecoPraFrente("forc_") + " ?" + yyvsp[0].valor + " " + yyvsp[-2].valor + " " + enderecoPraFrente("for_") + " # " + enderecoResolvido("end_for");}
#line 2118 "y.tab.c"
    break;

  case 101: /* Comando: _WHILE '(' Expressao ')' Jump_While  */
#line 239 "mini_js.y"
                                                                         {yyval.valor = enderecoResolvido("while_") + " " + yyvsp[-2].valor + " " + enderecoPraFrente("whilec_") + " ?" + yyvsp[0].valor;}
#line 2124 "y.tab.c"
    break;

  case 102: /* Retorno_Comandos: _RETURN Conta  */
#line 242 "mini_js.y"
                                 {yyval.valor = yyvsp[0].valor + acessar_variavel("'&retorno'") + "~ ";}
#line 2130 "y.tab.c"
    break;

  case 103: /* Retorno_Comandos: %empty  */
#line 243 "mini_js.y"
                                 {yyval.valor = "";}
#line 2136 "y.tab.c"
    break;

  case 104: /* $@5: %empty  */
#line 246 "mini_js.y"
            {escopo_local = true; funcao = "local" + to_string(locais++);}
#line 2142 "y.tab.c"
    break;

  case 105: /* Bloco: '{' $@5 Continuacao Retorno_Comandos '}'  */
#line 246 "mini_js.y"
                                                                                                           {escopo_local=false;yyval.valor = "<{ " +  yyvsp[-2].valor + yyvsp[-1].valor + "}> ";}
#line 2148 "y.tab.c"
    break;

  case 106: /* Bloco: Retorno_Comandos  */
#line 247 "mini_js.y"
                                            {yyval.valor = yyvsp[0].valor;}
#line 2154 "y.tab.c"
    break;

  case 107: /* Expressao: Declaracao  */
#line 250 "mini_js.y"
                                                   {yyval.valor = yyvsp[0].valor;}
#line 2160 "y.tab.c"
    break;

  case 108: /* Expressao: _ID Funcao Expressao  */
#line 251 "mini_js.y"
                                                   {yyval.valor = yyvsp[-1].valor + acessar_variavel(yyvsp[-2].valor) + "$ ^ " + yyvsp[0].valor;}
#line 2166 "y.tab.c"
    break;

  case 109: /* Expressao: '(' _ID ')' Funcao Expressao  */
#line 252 "mini_js.y"
                                                   {yyval.valor = yyvsp[-1].valor + acessar_variavel(yyvsp[-3].valor) + "$ ^ " + yyvsp[0].valor;}
#line 2172 "y.tab.c"
    break;

  case 110: /* Expressao: Objeto Funcao Expressao  */
#line 253 "mini_js.y"
                                                   {yyval.valor = yyvsp[-1].valor + yyvsp[-2].valor + "[@] $ ^ " + yyvsp[0].valor;}
#line 2178 "y.tab.c"
    break;

  case 111: /* Expressao: Conta Expressao  */
#line 254 "mini_js.y"
                                                   {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;}
#line 2184 "y.tab.c"
    break;

  case 112: /* Expressao: Bloco Expressao  */
#line 255 "mini_js.y"
                                                   {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;}
#line 2190 "y.tab.c"
    break;

  case 113: /* Expressao: _ASM  */
#line 256 "mini_js.y"
                                                   {yyval.valor = asm_trim(yyvsp[0].valor);}
#line 2196 "y.tab.c"
    break;

  case 114: /* Continuacao: Expressao ';' Continuacao  */
#line 259 "mini_js.y"
                                                 {yyval.valor = yyvsp[-2].valor + yyvsp[0].valor;}
#line 2202 "y.tab.c"
    break;

  case 115: /* Continuacao: Comando Continuacao  */
#line 260 "mini_js.y"
                                                 {yyval.valor = yyvsp[-1].valor + yyvsp[0].valor;}
#line 2208 "y.tab.c"
    break;

  case 116: /* Continuacao: ';' Continuacao  */
#line 261 "mini_js.y"
                                                 {yyval.valor = yyvsp[0].valor;}
#line 2214 "y.tab.c"
    break;

  case 117: /* Continuacao: %empty  */
#line 262 "mini_js.y"
                                                 {yyval.valor = "";}
#line 2220 "y.tab.c"
    break;

  case 118: /* S: Expressao ';' Continuacao  */
#line 265 "mini_js.y"
                                        {exibir_codigo_processado(yyvsp[-2].valor + yyvsp[0].valor + "." + funcoes);}
#line 2226 "y.tab.c"
    break;

  case 119: /* S: Comando Continuacao  */
#line 266 "mini_js.y"
                                              {exibir_codigo_processado(yyvsp[-1].valor + yyvsp[0].valor + "." + funcoes);}
#line 2232 "y.tab.c"
    break;


#line 2236 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 268 "mini_js.y"


#include "lex.yy.c"

string declara_funcao(string nome, string parametros, string corpo){
        contador++; 
        escopo_local = false; 
        funcao = "";
        string label = enderecoPraFrente(nome);
        funcoes = funcoes + " " + enderecoResolvido(nome) + " " + parametros + corpo;
        setVar(nome);
        return nome + " & " + nome + " {} = '&funcao' " + label + " [=] ^ ";
}

string asm_trim(string asm_command){
        ReplaceStringInPlace(asm_command, "asm{", "");
        ReplaceStringInPlace(asm_command, "}", "");
        return asm_command + " ^ ";
}

string acessar_objeto(string nome_var){
        return nome_var + "[@]" + " ";
}

string acessar_variavel(string nome_var){
        return nome_var + " @" + " ";
}

string acessar_campo(string nome_objeto, string campo){
        campo = " " + campo;
        return nome_objeto + " @" + campo;
}

string declarar(string var){
        setVar(var);
        if(declaracao == "var" && declaracaoAntecedente){
                declaracaoAntecedente = 0;
                return "";
        }
        return var + " & ";
}

string declarar_arg(vector<string> args){
        int count = args.size() - 1;
        string result = "";
        string space = "";

        for(string var : args){
                result = var + " & " + var + " " + acessar_variavel("arguments") +  to_string(count) + " [@] = ^" + space + result; 
                space = " ";
                count--;
        }

        return result + " ";
}

string enderecoPraFrente(string nome){
        return ":" + nome + to_string(contador);
}

string enderecoResolvido(string nome){
        return ";" + nome + to_string(contador);
}

string jumpComandos(string label_endereco_final, string label_endereco_corpo){
        return enderecoPraFrente(label_endereco_final) + " # " + enderecoResolvido(label_endereco_corpo) + " ";
}

void setVar(string var){
        map<string,int>::iterator it;

        int linhaAtual = linha + 1;
        if(escopo_local){
                map<string, int> vars = variaveis_locais[funcao];
                
                for (it = vars.begin(); it != vars.end(); ++it){
                        if(var == it->first && declaracao != "var") exibir_erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) +".");
                }
                variaveis_locais[funcao][var] = linhaAtual;
        }else{
                for (it = variaveis_globais.begin(); it != variaveis_globais.end(); ++it){
                        if(var == it->first & !escopo_local && declaracao != "var") exibir_erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) + ".");
                        if(var == it->first & !escopo_local && declaracao == "var") declaracaoAntecedente = 1;
                }
                variaveis_globais[var] = linhaAtual;
        }        
}

void checkVar(string var){
        map<string,int>::iterator it;
        if(escopo_local){
                map<string, int> vars = variaveis_locais[funcao];
                for (it = vars.begin(); it != vars.end(); ++it){
                        if(var == it->first) return;
                }   
        }else{
                for (it = variaveis_globais.begin(); it != variaveis_globais.end(); ++it){
                        if(var == it->first) return;
                }
                exibir_erro("a variável '" + var + "' não foi declarada.");
        }  
}

void ReplaceStringInPlace(std::string& subject, const std::string& search,
                          const std::string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != std::string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

string printToken(int numToken, string tk){
        return "";
}

void exibir_codigo_processado(string valor){
    int pc_nolabel = 0;
    bool palavra = false;
    bool label = false;
    map<string,int> instPC;
    string label_in_process = "";
    string tk = "";

    for(int pc = 0; pc != valor.size(); pc++) {
        if(valor[pc] == ';'){
            label = true;
            tk += valor[pc];
            continue;
        }

        if(valor[pc] == '"' || valor[pc] == '\''){
            palavra = !palavra;
        }

        if(label){
            if(valor[pc] == ' '){
                label = false;
                instPC[label_in_process] = pc_nolabel;
                label_in_process = "";
                tk = printToken(pc_nolabel, tk);
                pc_nolabel++;
            }else{
                label_in_process += valor[pc];
                tk += valor[pc];
            }
            continue;       
        }
        
        if(valor[pc] == ' ' && !palavra && tk != "println" && tk != "println #") {
            tk = printToken(pc_nolabel, tk);
            pc_nolabel++;
            continue;
        }
        tk += valor[pc];
    }

    for(auto it=instPC.begin(); it!=instPC.end(); ++it){
        ReplaceStringInPlace(valor, ":" + it->first, to_string(it->second)); 
        ReplaceStringInPlace(valor, ";" + it->first + " ", ""); 
    }
    
    cout << valor;
}

void exibir_erro(string msg) {
    cerr << "Erro: " << msg << endl;
    exit(1); 
}


int token( int tk ) {  
  yylval.valor = yytext; 

  return tk;
}

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Proximo a: %s\nCoord: %d-%d\n", yytext, linha, coluna);
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}
