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
#line 1 "miniJS.y"


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <list>

using namespace std;

int contador = 0, linha = 1;

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

void motrar_erro(string c);
void mostrar(string c);

void setVar(string var, int linha);
void checkVar(string var);

map<string,int> var_declaradas;

  
struct Atributos {
  string c;
  string retorno = "";
  string getRetorno(){
        if(" " + c == retorno){
                return "";
        } 
        else return retorno;
  }
};

#define YYSTYPE Atributos
#define LABEL_IF ":then_"
#define LABEL_ENDIF ":end_if"
#define LABEL_WHILE ":while_"
#define LABEL_CORPO_WHILE ":whilec_"
#define LABEL_ENDWHILE ":end_while"
#define LABEL_FOR ":for_"
#define LABEL_CORPO_FOR ":forc_"
#define LABEL_ENDFOR ":end_for"

#define LABEL_RIF ";then_"
#define LABEL_RENDIF ";end_if"
#define LABEL_RWHILE ";while_"
#define LABEL_RCORPO_WHILE ";whilec_"
#define LABEL_RENDWHILE ";end_while"
#define LABEL_RFOR ";for_"
#define LABEL_RCORPO_FOR ";forc_"
#define LABEL_RENDFOR ";end_for"


#line 130 "y.tab.c"

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
    ID = 258,                      /* ID  */
    IF = 259,                      /* IF  */
    ELSE = 260,                    /* ELSE  */
    LET = 261,                     /* LET  */
    PRINT = 262,                   /* PRINT  */
    FOR = 263,                     /* FOR  */
    WHILE = 264,                   /* WHILE  */
    CINT = 265,                    /* CINT  */
    CSTRING = 266,                 /* CSTRING  */
    CSTRING2 = 267,                /* CSTRING2  */
    CDOUBLE = 268,                 /* CDOUBLE  */
    MA_IG = 269,                   /* MA_IG  */
    ME_IG = 270,                   /* ME_IG  */
    IGUAL = 271,                   /* IGUAL  */
    DIF = 272,                     /* DIF  */
    _COMENTARIO = 273,             /* _COMENTARIO  */
    CONST = 274,                   /* CONST  */
    VAR = 275,                     /* VAR  */
    _CONC = 276,                   /* _CONC  */
    _MAISMAIS = 277,               /* _MAISMAIS  */
    ABRE_FECHA_CHAVE = 278         /* ABRE_FECHA_CHAVE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define IF 259
#define ELSE 260
#define LET 261
#define PRINT 262
#define FOR 263
#define WHILE 264
#define CINT 265
#define CSTRING 266
#define CSTRING2 267
#define CDOUBLE 268
#define MA_IG 269
#define ME_IG 270
#define IGUAL 271
#define DIF 272
#define _COMENTARIO 273
#define CONST 274
#define VAR 275
#define _CONC 276
#define _MAISMAIS 277
#define ABRE_FECHA_CHAVE 278

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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_IF = 4,                         /* IF  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_LET = 6,                        /* LET  */
  YYSYMBOL_PRINT = 7,                      /* PRINT  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_CINT = 10,                      /* CINT  */
  YYSYMBOL_CSTRING = 11,                   /* CSTRING  */
  YYSYMBOL_CSTRING2 = 12,                  /* CSTRING2  */
  YYSYMBOL_CDOUBLE = 13,                   /* CDOUBLE  */
  YYSYMBOL_MA_IG = 14,                     /* MA_IG  */
  YYSYMBOL_ME_IG = 15,                     /* ME_IG  */
  YYSYMBOL_IGUAL = 16,                     /* IGUAL  */
  YYSYMBOL_DIF = 17,                       /* DIF  */
  YYSYMBOL__COMENTARIO = 18,               /* _COMENTARIO  */
  YYSYMBOL_CONST = 19,                     /* CONST  */
  YYSYMBOL_VAR = 20,                       /* VAR  */
  YYSYMBOL__CONC = 21,                     /* _CONC  */
  YYSYMBOL__MAISMAIS = 22,                 /* _MAISMAIS  */
  YYSYMBOL_ABRE_FECHA_CHAVE = 23,          /* ABRE_FECHA_CHAVE  */
  YYSYMBOL_24_ = 24,                       /* ';'  */
  YYSYMBOL_25_ = 25,                       /* ','  */
  YYSYMBOL_26_ = 26,                       /* '='  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '<'  */
  YYSYMBOL_31_ = 31,                       /* '^'  */
  YYSYMBOL_32_ = 32,                       /* '!'  */
  YYSYMBOL_33_ = 33,                       /* '*'  */
  YYSYMBOL_34_ = 34,                       /* '/'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* '.'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_S = 43,                         /* S  */
  YYSYMBOL_Argumentos = 44,                /* Argumentos  */
  YYSYMBOL_Atribuicao_Objeto2 = 45,        /* Atribuicao_Objeto2  */
  YYSYMBOL_Atribuicao_Objeto = 46,         /* Atribuicao_Objeto  */
  YYSYMBOL_Atribuicao_MIGUAL = 47,         /* Atribuicao_MIGUAL  */
  YYSYMBOL_AtribuicaoObj_MIGUAL = 48,      /* AtribuicaoObj_MIGUAL  */
  YYSYMBOL_Atribuicao_ID2 = 49,            /* Atribuicao_ID2  */
  YYSYMBOL_Atribuicao_ID = 50,             /* Atribuicao_ID  */
  YYSYMBOL_Conta_Simples = 51,             /* Conta_Simples  */
  YYSYMBOL_Conta_Complexa2 = 52,           /* Conta_Complexa2  */
  YYSYMBOL_Conta_Complexa = 53,            /* Conta_Complexa  */
  YYSYMBOL_Funcao = 54,                    /* Funcao  */
  YYSYMBOL_Declaracao_Complexa = 55,       /* Declaracao_Complexa  */
  YYSYMBOL_Declaracao_Simples = 56,        /* Declaracao_Simples  */
  YYSYMBOL_Expressao_Declaracao = 57,      /* Expressao_Declaracao  */
  YYSYMBOL_Declaracao = 58,                /* Declaracao  */
  YYSYMBOL_Membro_Simples = 59,            /* Membro_Simples  */
  YYSYMBOL_Dimensoes = 60,                 /* Dimensoes  */
  YYSYMBOL_Objeto = 61,                    /* Objeto  */
  YYSYMBOL_Casos_ID = 62,                  /* Casos_ID  */
  YYSYMBOL_Casos_Objeto = 63,              /* Casos_Objeto  */
  YYSYMBOL_Membro = 64,                    /* Membro  */
  YYSYMBOL_Termo = 65,                     /* Termo  */
  YYSYMBOL_Conta = 66,                     /* Conta  */
  YYSYMBOL_Jump_IF = 67,                   /* Jump_IF  */
  YYSYMBOL_Jump_While = 68,                /* Jump_While  */
  YYSYMBOL_Jump_For = 69,                  /* Jump_For  */
  YYSYMBOL_SENAO = 70,                     /* SENAO  */
  YYSYMBOL_CMD = 71,                       /* CMD  */
  YYSYMBOL_Expressao = 72,                 /* Expressao  */
  YYSYMBOL_Continuacao = 73                /* Continuacao  */
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
#define YYFINAL  50
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


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
       2,     2,     2,    32,     2,     2,     2,     2,     2,     2,
      35,    36,    33,    28,    25,    27,    40,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
      30,    26,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    37,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    66,    66,    67,    71,    72,    73,    76,    77,    80,
      81,    84,    87,    90,    91,    94,    95,    98,    99,   100,
     101,   102,   103,   106,   107,   108,   111,   112,   113,   114,
     117,   118,   121,   122,   123,   126,   127,   130,   131,   134,
     135,   136,   137,   140,   141,   142,   143,   144,   147,   148,
     151,   152,   153,   156,   157,   158,   161,   162,   163,   167,
     168,   169,   170,   171,   172,   173,   174,   177,   180,   183,
     184,   187,   188,   191,   192,   193,   198,   199,   202,   203,
     204,   207,   208,   211,   212,   213,   214
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "IF", "ELSE",
  "LET", "PRINT", "FOR", "WHILE", "CINT", "CSTRING", "CSTRING2", "CDOUBLE",
  "MA_IG", "ME_IG", "IGUAL", "DIF", "_COMENTARIO", "CONST", "VAR", "_CONC",
  "_MAISMAIS", "ABRE_FECHA_CHAVE", "';'", "','", "'='", "'-'", "'+'",
  "'>'", "'<'", "'^'", "'!'", "'*'", "'/'", "'('", "')'", "'}'", "'['",
  "']'", "'.'", "'{'", "$accept", "S", "Argumentos", "Atribuicao_Objeto2",
  "Atribuicao_Objeto", "Atribuicao_MIGUAL", "AtribuicaoObj_MIGUAL",
  "Atribuicao_ID2", "Atribuicao_ID", "Conta_Simples", "Conta_Complexa2",
  "Conta_Complexa", "Funcao", "Declaracao_Complexa", "Declaracao_Simples",
  "Expressao_Declaracao", "Declaracao", "Membro_Simples", "Dimensoes",
  "Objeto", "Casos_ID", "Casos_Objeto", "Membro", "Termo", "Conta",
  "Jump_IF", "Jump_While", "Jump_For", "SENAO", "CMD", "Expressao",
  "Continuacao", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     300,    70,   -34,     4,   410,   -26,   -23,  -117,  -117,  -117,
       4,     4,   -19,   410,   410,   410,   -15,    20,  -117,  -117,
    -117,    -5,  -117,  -117,   116,    97,   323,   205,     3,     8,
      15,   429,    12,   410,    43,  -117,   357,    32,  -117,  -117,
      24,   391,   357,  -117,  -117,  -117,  -117,  -117,    19,  -117,
    -117,    25,    47,   410,  -117,   410,   410,   410,   410,  -117,
    -117,   410,   410,   410,   410,   410,  -117,  -117,   169,   169,
      54,  -117,   205,   410,  -117,    97,   224,  -117,  -117,    46,
      60,    62,    67,   103,   410,  -117,  -117,   410,    83,    81,
    -117,   410,  -117,  -117,  -117,     7,  -117,  -117,  -117,    38,
    -117,    97,    97,    97,    97,    97,  -117,  -117,   169,  -117,
    -117,  -117,   429,  -117,    80,   410,    74,    48,    94,  -117,
     391,   228,  -117,   410,   116,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,   410,  -117,    84,   264,  -117,   104,   126,   410,
    -117,  -117,   106,   264,  -117,   108,  -117,  -117,    95,  -117,
      98,   140,   130,    94,   357,   114,  -117,    80,   140,   169,
    -117,  -117,   122,  -117,  -117,  -117,  -117,   133,   264,  -117,
     135,   125,  -117,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      66,    16,     0,     0,     6,     0,     0,    44,    43,    45,
       0,     0,     0,    66,    66,    66,     0,     0,    60,    81,
      59,    10,    62,    61,    25,    22,    66,    66,     0,     0,
       0,    66,    66,    66,     0,    53,    66,    34,    39,    31,
       4,    66,    66,    40,    41,    46,    64,    63,     0,    47,
       1,     0,     0,    66,    56,    66,    66,    66,    66,    28,
      67,    66,    66,    66,    66,    66,    68,    82,    66,    66,
       0,     3,    66,    66,    54,    22,    16,    15,    14,     0,
       0,    50,     0,     0,    66,    38,    32,    66,     0,     0,
      65,    66,    57,    58,     9,    10,     8,    23,    24,    25,
      27,    22,    22,    22,    22,    22,    85,    84,    66,     2,
      11,    55,    66,    30,    49,    66,    66,    36,    34,     5,
      66,    66,    12,    66,    25,    21,    17,    18,    19,    20,
      83,    13,    66,    52,     0,    66,    78,     0,     0,    66,
      35,    37,     0,    66,    80,     0,     7,    26,     0,    51,
       0,    77,    36,    34,    66,     0,    71,    49,    77,    66,
      69,    33,     0,    72,    48,    70,    76,    66,    66,    79,
       0,     0,    73,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,   131,    41,  -117,  -117,  -117,    53,  -117,   -37,
      82,    42,  -117,  -116,  -107,    78,  -117,  -117,    26,   -47,
    -117,  -117,   127,    -2,    -1,  -117,  -117,  -117,    27,   186,
       0,   -64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    17,    39,    94,    54,    74,    92,    77,    35,    66,
      59,    60,    18,    85,    86,    38,    19,    20,   133,    21,
      22,    23,    24,    25,    26,   136,   144,   169,   160,    69,
      70,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    36,   141,    40,   106,   107,    95,    37,   109,    41,
     140,    46,    42,    47,    48,     1,    51,    52,    45,     4,
      50,    53,     7,     8,    49,     9,    67,    72,    51,    52,
      78,    40,    80,   123,    73,    12,    82,   161,   111,    13,
      14,    88,    89,    75,   130,   140,    81,    15,    -6,    87,
      16,    91,    96,    97,    98,    90,   100,    83,    84,   101,
     102,   103,   104,   105,   125,   126,   127,   128,   129,    55,
      56,   150,   110,   138,   139,    93,    95,     1,   108,   155,
       3,     4,   113,   118,     7,     8,   119,     9,    43,    44,
     122,    29,    30,    10,    11,   166,    31,    12,   -42,   114,
     115,    13,    14,   116,   171,    32,   117,   120,    33,    15,
      34,    78,    16,    61,   134,   135,   137,   121,   132,    83,
     142,   145,    96,   149,    62,    63,    64,    65,   151,   152,
     154,   148,   156,   -75,   157,   158,     1,   -75,   153,     3,
       4,   -75,   -75,     7,     8,   159,     9,    55,    56,    57,
      58,   163,    10,    11,   162,   138,    12,   -42,   167,   172,
      13,    14,   173,    79,   146,   131,   147,   170,    15,   -86,
     -75,    16,     1,     2,   168,     3,     4,     5,     6,     7,
       8,   124,     9,   164,    99,   165,    27,     0,    10,    11,
       0,     0,    12,    68,     0,     0,    13,    14,     0,     0,
       0,     0,     0,     0,    15,   -86,   -86,    16,     1,     2,
       0,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,     0,     0,    10,    11,     0,     0,    12,    68,
       0,     1,    13,    14,     3,     4,     0,     0,     7,     8,
      15,     9,     0,    16,     0,    29,    30,    10,    11,     0,
     112,    12,   -42,     0,     0,    13,    14,     0,     0,    32,
       0,     0,    33,    15,    34,     0,    16,     1,     2,   143,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,     0,     0,    10,    11,     0,     0,    12,    68,     0,
       0,    13,    14,     0,     0,     0,     0,     0,     0,    15,
       0,   -86,    16,     1,     2,     0,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,     0,     0,    10,
      11,     0,     0,    12,   -42,     0,     1,    13,    14,     3,
       4,     0,     0,     7,     8,    15,     9,     0,    16,     0,
       0,     0,    10,    11,     0,     0,    12,   -42,     0,     0,
      13,    14,     0,     0,     0,     0,     0,     0,    15,   -42,
       1,    16,     0,     3,     4,     0,     0,     7,     8,     0,
       9,     0,     0,     0,     0,     0,    10,    11,     0,     0,
      12,     0,     0,     0,    13,    14,     0,     0,     0,     0,
       0,     0,    15,   -42,     1,    16,     0,     3,     4,     0,
       0,     7,     8,     0,     9,     0,     0,     0,     0,     0,
      10,    11,     0,     1,    12,   -42,     0,     4,    13,    14,
       7,     8,     0,     9,     0,     0,    15,     0,     0,    16,
       0,     0,    76,    12,     0,     0,     4,    13,    14,     7,
       8,     0,     9,     0,     0,    15,     0,     0,    16,     0,
       0,     0,    12,     0,     0,     0,    13,    14,     0,     0,
       0,     0,     0,     0,    15,     0,     0,    16
};

static const yytype_int16 yycheck[] =
{
       0,    35,   118,     4,    68,    69,    53,     3,    72,    35,
     117,    13,    35,    14,    15,     3,    21,    22,    37,     7,
       0,    26,    10,    11,    39,    13,    26,    24,    21,    22,
      31,    32,    33,    26,    26,    23,    36,   153,    75,    27,
      28,    41,    42,    28,   108,   152,     3,    35,    36,    25,
      38,    26,    53,    55,    56,    36,    58,    25,    26,    61,
      62,    63,    64,    65,   101,   102,   103,   104,   105,    31,
      32,   135,    73,    25,    26,    28,   123,     3,    24,   143,
       6,     7,    36,    84,    10,    11,    87,    13,    10,    11,
      91,    21,    22,    19,    20,   159,    26,    23,    24,    39,
      38,    27,    28,    36,   168,    35,     3,    24,    38,    35,
      40,   112,    38,    16,   115,    41,   116,    36,    38,    25,
     120,   121,   123,    39,    27,    28,    29,    30,    24,     3,
      24,   132,    24,     0,    39,    37,     3,     4,   139,     6,
       7,     8,     9,    10,    11,     5,    13,    31,    32,    33,
      34,    37,    19,    20,   154,    25,    23,    24,    36,    24,
      27,    28,    37,    32,   123,   112,   124,   167,    35,     0,
      37,    38,     3,     4,    41,     6,     7,     8,     9,    10,
      11,    99,    13,   157,    57,   158,     0,    -1,    19,    20,
      -1,    -1,    23,    24,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,     0,    37,    38,     3,     4,
      -1,     6,     7,     8,     9,    10,    11,    -1,    13,    -1,
      -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,    24,
      -1,     3,    27,    28,     6,     7,    -1,    -1,    10,    11,
      35,    13,    -1,    38,    -1,    21,    22,    19,    20,    -1,
      26,    23,    24,    -1,    -1,    27,    28,    -1,    -1,    35,
      -1,    -1,    38,    35,    40,    -1,    38,     3,     4,    41,
       6,     7,     8,     9,    10,    11,    -1,    13,    -1,    -1,
      -1,    -1,    -1,    19,    20,    -1,    -1,    23,    24,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    37,    38,     3,     4,    -1,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    23,    24,    -1,     3,    27,    28,     6,
       7,    -1,    -1,    10,    11,    35,    13,    -1,    38,    -1,
      -1,    -1,    19,    20,    -1,    -1,    23,    24,    -1,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
       3,    38,    -1,     6,     7,    -1,    -1,    10,    11,    -1,
      13,    -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,
      23,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,     3,    38,    -1,     6,     7,    -1,
      -1,    10,    11,    -1,    13,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,     3,    23,    24,    -1,     7,    27,    28,
      10,    11,    -1,    13,    -1,    -1,    35,    -1,    -1,    38,
      -1,    -1,     3,    23,    -1,    -1,     7,    27,    28,    10,
      11,    -1,    13,    -1,    -1,    35,    -1,    -1,    38,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    10,    11,    13,
      19,    20,    23,    27,    28,    35,    38,    43,    54,    58,
      59,    61,    62,    63,    64,    65,    66,    71,    72,    21,
      22,    26,    35,    38,    40,    50,    35,     3,    57,    44,
      66,    35,    35,    57,    57,    37,    65,    66,    66,    39,
       0,    21,    22,    26,    46,    31,    32,    33,    34,    52,
      53,    16,    27,    28,    29,    30,    51,    72,    24,    71,
      72,    73,    24,    26,    47,    28,     3,    49,    66,    44,
      66,     3,    72,    25,    26,    55,    56,    25,    72,    72,
      36,    26,    48,    28,    45,    61,    66,    65,    65,    64,
      65,    65,    65,    65,    65,    65,    73,    73,    24,    73,
      66,    51,    26,    36,    39,    38,    36,     3,    66,    66,
      24,    36,    66,    26,    52,    51,    51,    51,    51,    51,
      73,    49,    38,    60,    66,    41,    67,    72,    25,    26,
      56,    55,    72,    41,    68,    72,    45,    53,    66,    39,
      73,    24,     3,    66,    24,    73,    24,    39,    37,     5,
      70,    55,    72,    37,    60,    70,    73,    36,    41,    69,
      72,    73,    24,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    44,    45,    45,    46,
      46,    47,    48,    49,    49,    50,    50,    51,    51,    51,
      51,    51,    51,    52,    52,    52,    53,    53,    53,    53,
      54,    54,    55,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    59,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    62,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    66,    67,
      67,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      71,    72,    72,    73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     0,     3,     1,     2,
       0,     2,     2,     3,     1,     2,     0,     3,     3,     3,
       3,     3,     0,     2,     2,     0,     4,     2,     1,     0,
       4,     2,     1,     5,     0,     3,     0,     4,     2,     2,
       2,     2,     0,     1,     1,     1,     2,     2,     4,     0,
       3,     6,     5,     2,     3,     4,     2,     3,     3,     1,
       1,     1,     1,     2,     2,     3,     0,     2,     2,     3,
       4,     2,     3,     2,     3,     0,     2,     0,     5,     9,
       5,     1,     2,     3,     2,     2,     0
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
  case 2: /* S: Expressao ';' Continuacao  */
#line 66 "miniJS.y"
                                        {mostrar(yyvsp[-2].c + yyvsp[0].c + " .");}
#line 1445 "y.tab.c"
    break;

  case 3: /* S: CMD Continuacao  */
#line 67 "miniJS.y"
                                          {mostrar(yyvsp[-1].c + yyvsp[0].c + " .");}
#line 1451 "y.tab.c"
    break;

  case 4: /* Argumentos: Conta  */
#line 71 "miniJS.y"
                                  {yyval.c = yyvsp[0].c;}
#line 1457 "y.tab.c"
    break;

  case 5: /* Argumentos: Conta ',' Conta  */
#line 72 "miniJS.y"
                                  {yyval.c = yyvsp[-2].c + " " + yyvsp[0].c;}
#line 1463 "y.tab.c"
    break;

  case 6: /* Argumentos: %empty  */
#line 73 "miniJS.y"
                                  {yyval.c = "";}
#line 1469 "y.tab.c"
    break;

  case 7: /* Atribuicao_Objeto2: Objeto '=' Atribuicao_Objeto2  */
#line 76 "miniJS.y"
                                                         {yyval.c = " " +yyvsp[-2].c + yyvsp[0].c + " " + yyvsp[-2].c + "[@]" + " [=] ^";}
#line 1475 "y.tab.c"
    break;

  case 8: /* Atribuicao_Objeto2: Conta  */
#line 77 "miniJS.y"
                                                         {yyval.c = " " + yyvsp[0].c + " [=] ^";}
#line 1481 "y.tab.c"
    break;

  case 9: /* Atribuicao_Objeto: '=' Atribuicao_Objeto2  */
#line 80 "miniJS.y"
                                                    {yyval.c = yyvsp[0].c;}
#line 1487 "y.tab.c"
    break;

  case 10: /* Atribuicao_Objeto: %empty  */
#line 81 "miniJS.y"
                                                    {yyval.c = "[@]";}
#line 1493 "y.tab.c"
    break;

  case 11: /* Atribuicao_MIGUAL: '=' Conta  */
#line 84 "miniJS.y"
                                         {yyval.c = yyvsp[0].c + " + = ^";}
#line 1499 "y.tab.c"
    break;

  case 12: /* AtribuicaoObj_MIGUAL: '=' Conta  */
#line 87 "miniJS.y"
                                         {yyval.c = yyvsp[0].c + " + [=] ^";}
#line 1505 "y.tab.c"
    break;

  case 13: /* Atribuicao_ID2: ID '=' Atribuicao_ID2  */
#line 90 "miniJS.y"
                                        {yyval.c = " " +yyvsp[-2].c + yyvsp[0].c + " " + yyvsp[-2].c + "@" + " = ^";}
#line 1511 "y.tab.c"
    break;

  case 14: /* Atribuicao_ID2: Conta  */
#line 91 "miniJS.y"
                                         {yyval.c = " " + yyvsp[0].c + " = ^";}
#line 1517 "y.tab.c"
    break;

  case 15: /* Atribuicao_ID: '=' Atribuicao_ID2  */
#line 94 "miniJS.y"
                                          {yyval.c = yyvsp[0].c;}
#line 1523 "y.tab.c"
    break;

  case 16: /* Atribuicao_ID: %empty  */
#line 95 "miniJS.y"
                                          {yyval.c = "@";}
#line 1529 "y.tab.c"
    break;

  case 17: /* Conta_Simples: '-' Termo Conta_Simples  */
#line 98 "miniJS.y"
                                                        {yyval.c = " " + yyvsp[-1].c + " -" + yyvsp[0].c;}
#line 1535 "y.tab.c"
    break;

  case 18: /* Conta_Simples: '+' Termo Conta_Simples  */
#line 99 "miniJS.y"
                                                        {yyval.c = " " + yyvsp[-1].c + " +" + yyvsp[0].c;}
#line 1541 "y.tab.c"
    break;

  case 19: /* Conta_Simples: '>' Termo Conta_Simples  */
#line 100 "miniJS.y"
                                                        {yyval.c = " " + yyvsp[-1].c + yyvsp[0].c + " >";}
#line 1547 "y.tab.c"
    break;

  case 20: /* Conta_Simples: '<' Termo Conta_Simples  */
#line 101 "miniJS.y"
                                                        {yyval.c = " " + yyvsp[-1].c + yyvsp[0].c + " <";}
#line 1553 "y.tab.c"
    break;

  case 21: /* Conta_Simples: IGUAL Termo Conta_Simples  */
#line 102 "miniJS.y"
                                                          {yyval.c = " " + yyvsp[-1].c + yyvsp[0].c + " ==";}
#line 1559 "y.tab.c"
    break;

  case 22: /* Conta_Simples: %empty  */
#line 103 "miniJS.y"
                                                        {yyval.c = "";}
#line 1565 "y.tab.c"
    break;

  case 23: /* Conta_Complexa2: '^' Termo  */
#line 106 "miniJS.y"
                                {yyval.c = " " + yyvsp[0].c + " ^";}
#line 1571 "y.tab.c"
    break;

  case 24: /* Conta_Complexa2: '!' Termo  */
#line 107 "miniJS.y"
                                {yyval.c = " fat #" + yyvsp[0].c;}
#line 1577 "y.tab.c"
    break;

  case 25: /* Conta_Complexa2: %empty  */
#line 108 "miniJS.y"
                                {yyval.c = "";}
#line 1583 "y.tab.c"
    break;

  case 26: /* Conta_Complexa: '*' Membro Conta_Complexa2 Conta_Complexa  */
#line 111 "miniJS.y"
                                                                {yyval.c = " " + yyvsp[-2].c + yyvsp[-1].c + " *" + yyvsp[0].c;}
#line 1589 "y.tab.c"
    break;

  case 27: /* Conta_Complexa: '/' Termo  */
#line 112 "miniJS.y"
                                                                {yyval.c = " " + yyvsp[0].c + " /";}
#line 1595 "y.tab.c"
    break;

  case 28: /* Conta_Complexa: Conta_Complexa2  */
#line 113 "miniJS.y"
                                                                {yyval.c = yyvsp[0].c;}
#line 1601 "y.tab.c"
    break;

  case 29: /* Conta_Complexa: %empty  */
#line 114 "miniJS.y"
                                                                {yyval.c = "";}
#line 1607 "y.tab.c"
    break;

  case 30: /* Funcao: ID '(' Argumentos ')'  */
#line 117 "miniJS.y"
                                 {yyval.c = yyvsp[-1].c + " " + yyvsp[-3].c + " #";}
#line 1613 "y.tab.c"
    break;

  case 31: /* Funcao: PRINT Argumentos  */
#line 118 "miniJS.y"
                                 {yyval.c = yyvsp[0].c + " print #";}
#line 1619 "y.tab.c"
    break;

  case 32: /* Declaracao_Complexa: Declaracao_Simples  */
#line 121 "miniJS.y"
                                                                {yyval.c = yyvsp[0].c;}
#line 1625 "y.tab.c"
    break;

  case 33: /* Declaracao_Complexa: ',' ID '=' Conta Declaracao_Complexa  */
#line 122 "miniJS.y"
                                                               {setVar(yyvsp[-3].c, linha);yyval.c = " " + yyvsp[-3].c + "& " + yyvsp[-3].c + " " + yyvsp[-1].c + " = ^"+ yyvsp[0].c;}
#line 1631 "y.tab.c"
    break;

  case 34: /* Declaracao_Complexa: %empty  */
#line 123 "miniJS.y"
                                                                {yyval.c = "";}
#line 1637 "y.tab.c"
    break;

  case 35: /* Declaracao_Simples: ',' ID Declaracao_Simples  */
#line 126 "miniJS.y"
                                                 {setVar(yyvsp[-1].c, linha);yyval.c = " " + yyvsp[-1].c + "&" + yyvsp[0].c;}
#line 1643 "y.tab.c"
    break;

  case 36: /* Declaracao_Simples: %empty  */
#line 127 "miniJS.y"
                                                  {yyval.c = "";}
#line 1649 "y.tab.c"
    break;

  case 37: /* Expressao_Declaracao: ID '=' Conta Declaracao_Complexa  */
#line 130 "miniJS.y"
                                                             {setVar(yyvsp[-3].c, linha); yyval.c = yyvsp[-3].c + "& " + yyvsp[-3].c + " " + yyvsp[-1].c + " = ^" + yyvsp[0].c;}
#line 1655 "y.tab.c"
    break;

  case 38: /* Expressao_Declaracao: ID Declaracao_Complexa  */
#line 131 "miniJS.y"
                                                             {setVar(yyvsp[-1].c, linha); yyval.c = yyvsp[-1].c + "&" + yyvsp[0].c;}
#line 1661 "y.tab.c"
    break;

  case 39: /* Declaracao: LET Expressao_Declaracao  */
#line 134 "miniJS.y"
                                             {yyval.c = yyvsp[0].c;}
#line 1667 "y.tab.c"
    break;

  case 40: /* Declaracao: CONST Expressao_Declaracao  */
#line 135 "miniJS.y"
                                             {yyval.c = yyvsp[0].c;}
#line 1673 "y.tab.c"
    break;

  case 41: /* Declaracao: VAR Expressao_Declaracao  */
#line 136 "miniJS.y"
                                             {yyval.c = yyvsp[0].c;}
#line 1679 "y.tab.c"
    break;

  case 42: /* Declaracao: %empty  */
#line 137 "miniJS.y"
                                              {yyval.c = "";}
#line 1685 "y.tab.c"
    break;

  case 43: /* Membro_Simples: CSTRING  */
#line 140 "miniJS.y"
                                   {yyval.c = yyvsp[0].c;}
#line 1691 "y.tab.c"
    break;

  case 44: /* Membro_Simples: CINT  */
#line 141 "miniJS.y"
                                   {yyval.c = yyvsp[0].c;}
#line 1697 "y.tab.c"
    break;

  case 45: /* Membro_Simples: CDOUBLE  */
#line 142 "miniJS.y"
                                    {yyval.c = yyvsp[0].c;}
#line 1703 "y.tab.c"
    break;

  case 46: /* Membro_Simples: ABRE_FECHA_CHAVE '}'  */
#line 143 "miniJS.y"
                                         {yyval.c = "{}";}
#line 1709 "y.tab.c"
    break;

  case 47: /* Membro_Simples: '[' ']'  */
#line 144 "miniJS.y"
                                   {yyval.c = "[]";}
#line 1715 "y.tab.c"
    break;

  case 48: /* Dimensoes: '[' Conta ']' Dimensoes  */
#line 147 "miniJS.y"
                                            {yyval.c ="[@] " + yyvsp[-2].c + yyvsp[-2].getRetorno() + yyvsp[0].c;}
#line 1721 "y.tab.c"
    break;

  case 49: /* Dimensoes: %empty  */
#line 148 "miniJS.y"
                                            {yyval.c = "";}
#line 1727 "y.tab.c"
    break;

  case 50: /* Objeto: ID '.' ID  */
#line 151 "miniJS.y"
                                       {yyval.c = yyvsp[-2].c + "@ " + yyvsp[0].c;}
#line 1733 "y.tab.c"
    break;

  case 51: /* Objeto: ID '.' ID '[' Conta ']'  */
#line 152 "miniJS.y"
                                       {yyval.c = yyvsp[-5].c + "@ " + yyvsp[-3].c + "[@] " + yyvsp[-1].c;}
#line 1739 "y.tab.c"
    break;

  case 52: /* Objeto: ID '[' Conta ']' Dimensoes  */
#line 153 "miniJS.y"
                                        {yyval.c = yyvsp[-4].c + "@ " + yyvsp[-2].c + yyvsp[-2].getRetorno() + yyvsp[0].c;}
#line 1745 "y.tab.c"
    break;

  case 53: /* Casos_ID: ID Atribuicao_ID  */
#line 156 "miniJS.y"
                                                   {checkVar(yyvsp[-1].c);yyval.c = yyvsp[-1].c + yyvsp[0].c; yyval.retorno = " " + yyvsp[-1].c + "@";}
#line 1751 "y.tab.c"
    break;

  case 54: /* Casos_ID: ID _CONC Atribuicao_MIGUAL  */
#line 157 "miniJS.y"
                                                   {yyval.c = yyvsp[-2].c + " " + yyvsp[-2].c + "@ " + yyvsp[0].c;}
#line 1757 "y.tab.c"
    break;

  case 55: /* Casos_ID: ID _MAISMAIS '+' Conta_Simples  */
#line 158 "miniJS.y"
                                                   {yyval.c = yyvsp[-3].c + "@" + yyvsp[0].c + " " + yyvsp[-3].c + " " + yyvsp[-3].c + "@ 1 + = ^";}
#line 1763 "y.tab.c"
    break;

  case 56: /* Casos_Objeto: Objeto Atribuicao_Objeto  */
#line 161 "miniJS.y"
                                                        {yyval.c = yyvsp[-1].c + yyvsp[0].c;}
#line 1769 "y.tab.c"
    break;

  case 57: /* Casos_Objeto: Objeto _CONC AtribuicaoObj_MIGUAL  */
#line 162 "miniJS.y"
                                                        {yyval.c = yyvsp[-2].c + " " + yyvsp[-2].c + "[@] " + yyvsp[0].c;}
#line 1775 "y.tab.c"
    break;

  case 58: /* Casos_Objeto: Objeto _MAISMAIS '+'  */
#line 163 "miniJS.y"
                                                        {yyval.c = yyvsp[-2].c + " " + yyvsp[-2].c + "@ 1 + [=] ^ " + yyvsp[-2].c + "@";}
#line 1781 "y.tab.c"
    break;

  case 59: /* Membro: Membro_Simples  */
#line 167 "miniJS.y"
                                                  {yyval.c = yyvsp[0].c;}
#line 1787 "y.tab.c"
    break;

  case 60: /* Membro: Funcao  */
#line 168 "miniJS.y"
                                                  {yyval.c = yyvsp[0].c;}
#line 1793 "y.tab.c"
    break;

  case 61: /* Membro: Casos_Objeto  */
#line 169 "miniJS.y"
                                                  {yyval.c = yyvsp[0].c;}
#line 1799 "y.tab.c"
    break;

  case 62: /* Membro: Casos_ID  */
#line 170 "miniJS.y"
                                                  {yyval.c = yyvsp[0].c;yyval.retorno=yyvsp[0].retorno;}
#line 1805 "y.tab.c"
    break;

  case 63: /* Membro: '+' Conta  */
#line 171 "miniJS.y"
                                                  {yyval.c = yyvsp[0].c;}
#line 1811 "y.tab.c"
    break;

  case 64: /* Membro: '-' Termo  */
#line 172 "miniJS.y"
                                                  {yyval.c = "0 " + yyvsp[0].c + " -";}
#line 1817 "y.tab.c"
    break;

  case 65: /* Membro: '(' Conta ')'  */
#line 173 "miniJS.y"
                                                  {yyval.c = yyvsp[-1].c;}
#line 1823 "y.tab.c"
    break;

  case 66: /* Membro: %empty  */
#line 174 "miniJS.y"
                                                  {yyval.c = "";}
#line 1829 "y.tab.c"
    break;

  case 67: /* Termo: Membro Conta_Complexa  */
#line 177 "miniJS.y"
                                  {yyval.c = yyvsp[-1].c + yyvsp[0].c;yyval.retorno=yyvsp[-1].retorno;}
#line 1835 "y.tab.c"
    break;

  case 68: /* Conta: Termo Conta_Simples  */
#line 180 "miniJS.y"
                                  {yyval.c = yyvsp[-1].c + yyvsp[0].c;yyval.retorno=yyvsp[-1].retorno;}
#line 1841 "y.tab.c"
    break;

  case 69: /* Jump_IF: Expressao ';' SENAO  */
#line 183 "miniJS.y"
                                            {contador++; yyval.c = yyvsp[0].c + " " + LABEL_ENDIF + to_string(contador) + " # " + LABEL_RIF + to_string(contador) + " " + yyvsp[-2].c + " " + LABEL_RENDIF + to_string(contador);}
#line 1847 "y.tab.c"
    break;

  case 70: /* Jump_IF: '{' Continuacao '}' SENAO  */
#line 184 "miniJS.y"
                                            {contador++; yyval.c = yyvsp[0].c + " " + LABEL_ENDIF + to_string(contador) + " # " + LABEL_RIF + to_string(contador) + yyvsp[-2].c + " "+ LABEL_RENDIF + to_string(contador);}
#line 1853 "y.tab.c"
    break;

  case 71: /* Jump_While: Expressao ';'  */
#line 187 "miniJS.y"
                                           {contador++; yyval.c = LABEL_ENDWHILE + to_string(contador) + " # " + LABEL_RCORPO_WHILE + to_string(contador) + " " + yyvsp[-1].c + " " + LABEL_WHILE + to_string(contador) + " # " + LABEL_RENDWHILE + to_string(contador);}
#line 1859 "y.tab.c"
    break;

  case 72: /* Jump_While: '{' Continuacao '}'  */
#line 188 "miniJS.y"
                                           {contador++; yyval.c = LABEL_ENDWHILE + to_string(contador) + " # " + LABEL_RCORPO_WHILE + to_string(contador) + yyvsp[-1].c + " " + LABEL_WHILE + to_string(contador) + " # " + LABEL_RENDWHILE + to_string(contador);}
#line 1865 "y.tab.c"
    break;

  case 73: /* Jump_For: Expressao ';'  */
#line 191 "miniJS.y"
                                           {contador++; yyval.c = LABEL_ENDFOR + to_string(contador) + " # " + LABEL_RCORPO_FOR + to_string(contador) + " " + yyvsp[-1].c;}
#line 1871 "y.tab.c"
    break;

  case 74: /* Jump_For: '{' Continuacao '}'  */
#line 192 "miniJS.y"
                                           {contador++; yyval.c = LABEL_ENDFOR + to_string(contador) + " # " + LABEL_RCORPO_FOR + to_string(contador) + yyvsp[-1].c;}
#line 1877 "y.tab.c"
    break;

  case 76: /* SENAO: ELSE Continuacao  */
#line 198 "miniJS.y"
                             {yyval.c = yyvsp[0].c;}
#line 1883 "y.tab.c"
    break;

  case 77: /* SENAO: %empty  */
#line 199 "miniJS.y"
                              {yyval.c = "";}
#line 1889 "y.tab.c"
    break;

  case 78: /* CMD: IF '(' Expressao ')' Jump_IF  */
#line 202 "miniJS.y"
                                                                   {yyval.c = yyvsp[-2].c + " " + LABEL_IF + to_string(contador) + " ?" + yyvsp[0].c;}
#line 1895 "y.tab.c"
    break;

  case 79: /* CMD: FOR '(' Expressao ';' Expressao ';' Expressao ')' Jump_For  */
#line 203 "miniJS.y"
                                                                       {yyval.c = yyvsp[-6].c + " " + LABEL_RFOR + to_string(contador) + " " + yyvsp[-4].c + " " + LABEL_CORPO_FOR + to_string(contador) + " ? " + yyvsp[0].c + " " + yyvsp[-2].c + " " + LABEL_FOR + to_string(contador) + " # " + LABEL_RENDFOR + to_string(contador);}
#line 1901 "y.tab.c"
    break;

  case 80: /* CMD: WHILE '(' Expressao ')' Jump_While  */
#line 204 "miniJS.y"
                                                                       {yyval.c = LABEL_RWHILE + to_string(contador) + " " + yyvsp[-2].c + " " + LABEL_CORPO_WHILE + to_string(contador) + " ? " + yyvsp[0].c;}
#line 1907 "y.tab.c"
    break;

  case 81: /* Expressao: Declaracao  */
#line 207 "miniJS.y"
                                            {yyval.c = yyvsp[0].c;}
#line 1913 "y.tab.c"
    break;

  case 82: /* Expressao: Conta Expressao  */
#line 208 "miniJS.y"
                                            {yyval.c = yyvsp[-1].c + yyvsp[0].c;}
#line 1919 "y.tab.c"
    break;

  case 83: /* Continuacao: Expressao ';' Continuacao  */
#line 211 "miniJS.y"
                                                 {yyval.c = " " + yyvsp[-2].c + yyvsp[0].c;}
#line 1925 "y.tab.c"
    break;

  case 84: /* Continuacao: CMD Continuacao  */
#line 212 "miniJS.y"
                                             {yyval.c = " " + yyvsp[-1].c + yyvsp[0].c;}
#line 1931 "y.tab.c"
    break;

  case 85: /* Continuacao: ';' Continuacao  */
#line 213 "miniJS.y"
                                                 {yyval.c = yyvsp[0].c;}
#line 1937 "y.tab.c"
    break;

  case 86: /* Continuacao: %empty  */
#line 214 "miniJS.y"
                                                 {yyval.c = "";}
#line 1943 "y.tab.c"
    break;


#line 1947 "y.tab.c"

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

#line 218 "miniJS.y"


#include "lex.yy.c"

void setVar(string var, int linha){
        map<string,int>::iterator it;
        for (it = var_declaradas.begin(); it != var_declaradas.end(); ++it){
                if(var == it->first) motrar_erro("a variável '" + var + "' já foi declarada na linha " + to_string(it->second) +".");
        }
        var_declaradas[var] = linha;
}

void checkVar(string var){
        map<string,int>::iterator it;
        for (it = var_declaradas.begin(); it != var_declaradas.end(); ++it){
                if(var == it->first) return;
        }
        motrar_erro("a variável '" + var + "' não foi declarada.");
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

void mostrar(string c){
   int pc_nolabel = 0;
   bool palavra = false;
   bool palavra2 = false;
   bool palavra3 = false;
   bool label = false;
   map<string,int> instPC;
   string label_in_process = "";
   string tk = "";

   for(int pc = 0; pc != c.size() ; pc++) {
     
        if(c[pc] == ';'){
                label = true;
                tk += c[pc];
                continue;
        }

        if(label){
                if(c[pc] == ' '){
                        label = false;
                        instPC[label_in_process] = pc_nolabel;
                        label_in_process = "";
                }else{
                        label_in_process += c[pc];
                        tk += c[pc];
                }

                continue;       
        }

        if(c[pc] == '"'){
                if(!palavra){
                        palavra = true;
                }else{
                        palavra = false;
                }
                continue;
        }

        if(palavra){
                tk += c[pc];
                continue;
        }

        if(c[pc] == '\''){
                if(!palavra3 && !palavra){
                        palavra3 = true;
                }else{
                        if(!palavra){
                                palavra3 = false;
                        }
                }
                continue;
        }

        

        if(c[pc] == ':'){
                if(!palavra2){
                        palavra2 = true;
                        tk += c[pc];
                }

                continue;
        }
        
        
        if(palavra2){
                if(c[pc] == ' '){
                        palavra2 = false;
                        tk = printToken(pc_nolabel,tk);
                        pc_nolabel++;
                } else{
                        tk += c[pc];
                }
                continue;
        }
        
        if(c[pc] == ' ') {
                tk = printToken(pc_nolabel, tk);
                pc_nolabel++;
                continue;
        }else{
                if(c[pc] == '&' || c[pc] == '@') {
                        tk = printToken(pc_nolabel, tk);
                        pc_nolabel++;
                        tk = c[pc];
                        continue;
                }
        }

        tk += c[pc];
   }

   map<string,int>::iterator it;
   for(it=instPC.begin(); it!=instPC.end(); ++it){
      ReplaceStringInPlace(c, ":" + it->first, to_string(it->second)); 
      ReplaceStringInPlace(c, ";" + it->first + " ", ""); 
   }
        
   cout << c;

}

void motrar_erro( string msg ) {
  cout << "Erro: " << msg << endl;
  exit(0); 

}


void yyerror( const char* st ) {
   cerr << st << endl; 
   cerr << "Proximo a: " << yytext << endl;
   exit( 1 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  return 0;
}
