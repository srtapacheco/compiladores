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
#include <sstream>

using namespace std;

int token(int tk);

struct Atributos {
    vector<string> c;
};

#define YYSTYPE Atributos

int yyparse();
void yyerror(const char*);

vector<string> operator+(const vector<string>& a, const vector<string>& b);
vector<string> operator+(const vector<string>& a, const string& b);

string gera_label(const string& prefixo);

vector<string> resolve_enderecos(const vector<string>& entrada);
void imprime_vetor(const vector<string>& v);
string remove_espacos(const char* c);
vector<string> divide_string(const string& str);

vector<string> auxiliar;
map<string, int> vars;
vector<string> funcs;
int linha = 1, quantidade_parametros = 0;

vector<vector<string>> elements;
vector<vector<string>> pars;

#line 113 "y.tab.c"

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
    _FLOAT = 258,                  /* _FLOAT  */
    _STRING = 259,                 /* _STRING  */
    _ID = 260,                     /* _ID  */
    _IF = 261,                     /* _IF  */
    _ELSE = 262,                   /* _ELSE  */
    _FOR = 263,                    /* _FOR  */
    _WHILE = 264,                  /* _WHILE  */
    _IGUAL = 265,                  /* _IGUAL  */
    _MA_IG = 266,                  /* _MA_IG  */
    _ME_IG = 267,                  /* _ME_IG  */
    _BOLEANO = 268,                /* _BOLEANO  */
    _LET = 269,                    /* _LET  */
    _VAR = 270,                    /* _VAR  */
    _CONST = 271,                  /* _CONST  */
    _FUNCTION = 272,               /* _FUNCTION  */
    FUNC_ANON = 273,               /* FUNC_ANON  */
    _RETURN = 274,                 /* _RETURN  */
    ASM = 275,                     /* ASM  */
    APS = 276,                     /* APS  */
    _ARROW = 277                   /* _ARROW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define _FLOAT 258
#define _STRING 259
#define _ID 260
#define _IF 261
#define _ELSE 262
#define _FOR 263
#define _WHILE 264
#define _IGUAL 265
#define _MA_IG 266
#define _ME_IG 267
#define _BOLEANO 268
#define _LET 269
#define _VAR 270
#define _CONST 271
#define _FUNCTION 272
#define FUNC_ANON 273
#define _RETURN 274
#define ASM 275
#define APS 276
#define _ARROW 277

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
  YYSYMBOL__FLOAT = 3,                     /* _FLOAT  */
  YYSYMBOL__STRING = 4,                    /* _STRING  */
  YYSYMBOL__ID = 5,                        /* _ID  */
  YYSYMBOL__IF = 6,                        /* _IF  */
  YYSYMBOL__ELSE = 7,                      /* _ELSE  */
  YYSYMBOL__FOR = 8,                       /* _FOR  */
  YYSYMBOL__WHILE = 9,                     /* _WHILE  */
  YYSYMBOL__IGUAL = 10,                    /* _IGUAL  */
  YYSYMBOL__MA_IG = 11,                    /* _MA_IG  */
  YYSYMBOL__ME_IG = 12,                    /* _ME_IG  */
  YYSYMBOL__BOLEANO = 13,                  /* _BOLEANO  */
  YYSYMBOL__LET = 14,                      /* _LET  */
  YYSYMBOL__VAR = 15,                      /* _VAR  */
  YYSYMBOL__CONST = 16,                    /* _CONST  */
  YYSYMBOL__FUNCTION = 17,                 /* _FUNCTION  */
  YYSYMBOL_FUNC_ANON = 18,                 /* FUNC_ANON  */
  YYSYMBOL__RETURN = 19,                   /* _RETURN  */
  YYSYMBOL_ASM = 20,                       /* ASM  */
  YYSYMBOL_APS = 21,                       /* APS  */
  YYSYMBOL__ARROW = 22,                    /* _ARROW  */
  YYSYMBOL_23_ = 23,                       /* '='  */
  YYSYMBOL_24_ = 24,                       /* '<'  */
  YYSYMBOL_25_ = 25,                       /* '>'  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '-'  */
  YYSYMBOL_28_ = 28,                       /* '*'  */
  YYSYMBOL_29_ = 29,                       /* '/'  */
  YYSYMBOL_30_ = 30,                       /* '%'  */
  YYSYMBOL_31_ = 31,                       /* ';'  */
  YYSYMBOL_32_ = 32,                       /* '('  */
  YYSYMBOL_33_ = 33,                       /* ')'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* '['  */
  YYSYMBOL_38_ = 38,                       /* ']'  */
  YYSYMBOL_39_ = 39,                       /* '.'  */
  YYSYMBOL_40_ = 40,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_S = 42,                         /* S  */
  YYSYMBOL_Comandos = 43,                  /* Comandos  */
  YYSYMBOL_Comando = 44,                   /* Comando  */
  YYSYMBOL_Expressao = 45,                 /* Expressao  */
  YYSYMBOL_Declaracao_Simples = 46,        /* Declaracao_Simples  */
  YYSYMBOL_Declaracao_Complexa = 47,       /* Declaracao_Complexa  */
  YYSYMBOL_Bloco = 48,                     /* Bloco  */
  YYSYMBOL_B_ = 49,                        /* B_  */
  YYSYMBOL_D_LINHA = 50,                   /* D_LINHA  */
  YYSYMBOL_D_LINHA_ = 51,                  /* D_LINHA_  */
  YYSYMBOL_LV_ = 52,                       /* LV_  */
  YYSYMBOL_LVALUE = 53,                    /* LVALUE  */
  YYSYMBOL_P = 54,                         /* P  */
  YYSYMBOL_O = 55,                         /* O  */
  YYSYMBOL_Atribuicao = 56,                /* Atribuicao  */
  YYSYMBOL_F = 57,                         /* F  */
  YYSYMBOL_CF = 58,                        /* CF  */
  YYSYMBOL_ARRAY = 59,                     /* ARRAY  */
  YYSYMBOL_FA = 60,                        /* FA  */
  YYSYMBOL_Funcao_Seta = 61,               /* Funcao_Seta  */
  YYSYMBOL_P_ = 62,                        /* P_  */
  YYSYMBOL_ELS = 63,                       /* ELS  */
  YYSYMBOL_H = 64                          /* H  */
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
#define YYFINAL  59
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   505

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277


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
       2,     2,     2,     2,     2,     2,     2,    30,     2,     2,
      32,    33,    28,    26,    34,    27,    39,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    31,
      24,    23,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    62,    62,    65,    66,    69,    70,    71,    72,    73,
      74,    75,    80,    84,    89,    94,   102,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   128,   129,   132,   136,   142,   143,   144,
     147,   150,   173,   178,   183,   188,   195,   198,   201,   202,
     203,   204,   207,   208,   211,   212,   215,   216,   217,   218,
     219,   220,   221,   222,   225,   226,   227,   228,   231,   239,
     242,   248,   256,   264,   265,   268,   269,   272,   273,   274
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
  "\"end of file\"", "error", "\"invalid token\"", "_FLOAT", "_STRING",
  "_ID", "_IF", "_ELSE", "_FOR", "_WHILE", "_IGUAL", "_MA_IG", "_ME_IG",
  "_BOLEANO", "_LET", "_VAR", "_CONST", "_FUNCTION", "FUNC_ANON",
  "_RETURN", "ASM", "APS", "_ARROW", "'='", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "';'", "'('", "')'", "','", "'{'", "'}'", "'['",
  "']'", "'.'", "':'", "$accept", "S", "Comandos", "Comando", "Expressao",
  "Declaracao_Simples", "Declaracao_Complexa", "Bloco", "B_", "D_LINHA",
  "D_LINHA_", "LV_", "LVALUE", "P", "O", "Atribuicao", "F", "CF", "ARRAY",
  "FA", "Funcao_Seta", "P_", "ELS", "H", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-106)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-78)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     159,  -106,  -106,     2,    -7,    15,    32,  -106,    23,    23,
      23,    28,     9,   249,    31,   204,    -4,    98,    39,  -106,
     159,   416,  -106,     8,     7,  -106,  -106,  -106,  -106,  -106,
    -106,    51,    47,   210,   249,   159,   249,  -106,    50,    49,
      70,    64,    65,    66,     4,   184,    71,  -106,    44,   424,
      73,  -106,   348,    57,  -106,    72,  -106,   284,    75,  -106,
    -106,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,  -106,   249,   245,   249,   249,   104,  -106,   249,  -106,
    -106,   295,    81,   358,   249,   382,  -106,    23,   249,  -106,
    -106,    10,   249,    31,   134,  -106,  -106,  -106,   184,  -106,
    -106,  -106,   249,  -106,   249,  -106,   454,   454,   454,   454,
     454,    40,    40,  -106,  -106,  -106,   475,  -106,    82,   475,
     263,    45,   475,   249,  -106,   184,   446,   184,  -106,   475,
     184,    84,   316,  -106,    -3,    85,  -106,   327,  -106,  -106,
      45,  -106,  -106,   113,   249,  -106,  -106,   184,    31,  -106,
     117,  -106,   184,   392,  -106,  -106,  -106,  -106,   184,  -106
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    56,    57,    47,     0,     0,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       4,     0,    53,    29,    30,    31,    32,    60,    61,    62,
      63,     0,     0,     0,     0,     0,     0,    47,     0,    34,
      36,     0,     0,     0,    45,     0,     0,    41,    47,     0,
       0,    78,     0,     0,    40,     0,    69,    76,     0,     1,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,     0,    46,     0,     6,
      65,    74,     0,     0,     0,     0,     7,     0,     0,     8,
       9,     0,     0,     0,     0,    38,    70,    39,     0,    10,
      79,    59,     0,    52,     0,    68,    21,    19,    20,    17,
      18,    23,    24,    22,    25,    26,    27,    67,     0,    28,
       0,    51,    72,     0,    64,     0,     0,     0,    33,    35,
       0,     0,    44,    43,    47,     0,    71,    55,    75,    66,
      50,    49,    73,    12,     0,    13,    15,     0,     0,    37,
       0,    48,     0,     0,    16,    42,    54,    11,     0,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -106,  -106,    -2,     6,   -13,     1,  -106,   -53,   -40,   -11,
     -81,  -106,    -1,  -105,  -106,   -27,  -106,  -106,  -106,  -106,
    -106,   -60,    20,  -106
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    18,    19,    95,    21,    38,    39,    96,    22,    46,
      47,    23,    24,    77,    25,    55,    26,    27,    28,    29,
      30,    82,    58,    31
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    53,    52,    50,    57,    97,    20,    40,    40,    40,
      41,    42,   133,   118,    44,    44,   141,    32,    60,   -77,
      81,    83,    32,    85,   -77,    34,    20,    92,    37,    33,
      74,    72,    54,    43,    33,   151,    44,   102,    93,    59,
      73,    84,    45,   130,    75,   136,    76,    35,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    97,   116,
      81,   119,   120,   142,    36,   122,   -77,   155,    68,    69,
      70,   126,   143,    78,   145,   129,    33,   146,    79,   132,
     131,    86,    75,    87,    76,    97,    40,    97,   128,   137,
      97,    57,   135,    88,   154,    89,    90,   102,    91,   157,
      20,     1,     2,    48,    98,   159,   100,    97,   103,   121,
      81,     7,    97,   105,   124,   139,    12,   147,    97,    14,
     152,   149,    53,   156,   138,     0,     0,     0,     0,     0,
      15,   153,     0,    16,     0,    17,    56,     1,     2,   134,
       4,     0,     5,     6,     0,     0,     0,     7,     8,     9,
      10,    11,    12,    13,     0,    14,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,    15,     5,     6,    16,
      54,    17,     7,     8,     9,    10,    11,    12,    13,     0,
      14,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,    15,     5,     6,    16,     0,    17,     7,     8,     9,
      10,    11,    12,    13,     0,    14,     0,     1,     2,    48,
       0,     0,     0,     1,     2,    48,    15,     7,     0,    94,
       0,    17,    12,     7,     0,    14,     0,     0,    12,     0,
       0,    14,     0,     0,     0,     0,    15,    51,     0,    16,
       0,    17,    15,    80,     0,    16,     0,    17,     1,     2,
      48,     0,     1,     2,    48,     0,     0,     0,     7,     0,
       0,     0,     7,    12,     0,     0,    14,    12,     0,     0,
      14,     0,     0,    61,    62,    63,     0,    15,   117,     0,
      16,    15,    17,     0,    16,     0,    17,    64,    65,    66,
      67,    68,    69,    70,    61,    62,    63,     0,     0,     0,
       0,   140,     0,     0,     0,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,     0,     0,   104,    64,
      65,    66,    67,    68,    69,    70,    61,    62,    63,   123,
       0,     0,     0,     0,     0,     0,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,     0,     0,
     148,    64,    65,    66,    67,    68,    69,    70,    61,    62,
      63,   150,     0,     0,     0,     0,     0,     0,    61,    62,
      63,     0,    64,    65,    66,    67,    68,    69,    70,     0,
       0,   101,    64,    65,    66,    67,    68,    69,    70,     0,
       0,   125,    61,    62,    63,     0,     0,     0,     0,     0,
       0,     0,    61,    62,    63,     0,    64,    65,    66,    67,
      68,    69,    70,     0,     0,   127,    64,    65,    66,    67,
      68,    69,    70,     0,     0,   158,    61,    62,    63,     0,
       0,     0,     0,     0,    61,    62,    63,     0,     0,     0,
      64,    65,    66,    67,    68,    69,    70,    71,    64,    65,
      66,    67,    68,    69,    70,    99,    61,    62,    63,     0,
       0,     0,     0,     0,   -78,   -78,   -78,     0,     0,     0,
      64,    65,    66,    67,    68,    69,    70,   144,   -78,   -78,
      66,    67,    68,    69,    70,    61,    62,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    64,
      65,    66,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
      13,     5,    15,    14,    17,    45,     0,     8,     9,    10,
       9,    10,    93,    73,     5,     5,   121,    20,    20,    22,
      33,    34,    20,    36,    22,    32,    20,    23,     5,    32,
      23,    23,    36,     5,    32,   140,     5,    40,    34,     0,
      32,    35,    33,    33,    37,    98,    39,    32,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    98,    72,
      73,    74,    75,   123,    32,    78,    22,   148,    28,    29,
      30,    84,   125,    22,   127,    88,    32,   130,    31,    92,
      91,    31,    37,    34,    39,   125,    87,   127,    87,   102,
     130,   104,    94,    23,   147,    31,    31,    40,    32,   152,
      94,     3,     4,     5,    33,   158,    33,   147,    36,     5,
     123,    13,   152,    38,    33,    33,    18,    33,   158,    21,
       7,    36,     5,   150,   104,    -1,    -1,    -1,    -1,    -1,
      32,   144,    -1,    35,    -1,    37,    38,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    32,     8,     9,    35,
      36,    37,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    32,     8,     9,    35,    -1,    37,    13,    14,    15,
      16,    17,    18,    19,    -1,    21,    -1,     3,     4,     5,
      -1,    -1,    -1,     3,     4,     5,    32,    13,    -1,    35,
      -1,    37,    18,    13,    -1,    21,    -1,    -1,    18,    -1,
      -1,    21,    -1,    -1,    -1,    -1,    32,    33,    -1,    35,
      -1,    37,    32,    33,    -1,    35,    -1,    37,     3,     4,
       5,    -1,     3,     4,     5,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    13,    18,    -1,    -1,    21,    18,    -1,    -1,
      21,    -1,    -1,    10,    11,    12,    -1,    32,    33,    -1,
      35,    32,    37,    -1,    35,    -1,    37,    24,    25,    26,
      27,    28,    29,    30,    10,    11,    12,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    10,    11,    12,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    34,    24,
      25,    26,    27,    28,    29,    30,    10,    11,    12,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      34,    24,    25,    26,    27,    28,    29,    30,    10,    11,
      12,    34,    -1,    -1,    -1,    -1,    -1,    -1,    10,    11,
      12,    -1,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    33,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    33,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    -1,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    33,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    33,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    24,    25,
      26,    27,    28,    29,    30,    31,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    24,    25,
      26,    27,    28,    29,    30,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     8,     9,    13,    14,    15,
      16,    17,    18,    19,    21,    32,    35,    37,    42,    43,
      44,    45,    49,    52,    53,    55,    57,    58,    59,    60,
      61,    64,    20,    32,    32,    32,    32,     5,    46,    47,
      53,    46,    46,     5,     5,    33,    50,    51,     5,    45,
      50,    33,    45,     5,    36,    56,    38,    45,    63,     0,
      43,    10,    11,    12,    24,    25,    26,    27,    28,    29,
      30,    31,    23,    32,    23,    37,    39,    54,    22,    31,
      33,    45,    62,    45,    44,    45,    31,    34,    23,    31,
      31,    32,    23,    34,    35,    44,    48,    49,    33,    31,
      33,    33,    40,    36,    34,    38,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    33,    62,    45,
      45,     5,    45,    34,    33,    33,    45,    33,    46,    45,
      33,    50,    45,    51,     5,    43,    48,    45,    63,    33,
      38,    54,    62,    48,    31,    48,    48,    33,    34,    36,
      34,    54,     7,    45,    48,    51,    56,    48,    33,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    46,    46,    47,    47,    48,    48,    48,
      49,    50,    51,    51,    51,    51,    52,    53,    54,    54,
      54,    54,    55,    55,    56,    56,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    58,    58,    58,    59,    59,
      60,    60,    61,    62,    62,    63,    63,    64,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     3,     3,     3,     3,
       3,     7,     5,     5,     8,     5,     6,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     3,     1,     3,     1,     3,     1,     1,
       2,     1,     5,     3,     3,     1,     2,     1,     4,     3,
       3,     2,     3,     1,     5,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     4,     3,     4,     3,     3,     2,
       3,     4,     3,     3,     1,     3,     1,     1,     2,     3
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
  case 2: /* S: Comandos  */
#line 62 "mini_js.y"
             { imprime_vetor(resolve_enderecos(yyvsp[0].c + "." + funcs)); }
#line 1410 "y.tab.c"
    break;

  case 3: /* Comandos: Comando Comandos  */
#line 65 "mini_js.y"
                            { yyval.c = yyvsp[-1].c + yyvsp[0].c; }
#line 1416 "y.tab.c"
    break;

  case 4: /* Comandos: Comando  */
#line 66 "mini_js.y"
               { yyval.c = yyvsp[0].c; }
#line 1422 "y.tab.c"
    break;

  case 5: /* Comando: Expressao ';'  */
#line 69 "mini_js.y"
                        { yyval.c = yyvsp[-1].c + "^"; }
#line 1428 "y.tab.c"
    break;

  case 6: /* Comando: _ID ASM ';'  */
#line 70 "mini_js.y"
                  { yyval.c = yyvsp[-2].c + "@" + yyvsp[-1].c + "^"; }
#line 1434 "y.tab.c"
    break;

  case 7: /* Comando: _LET Declaracao_Simples ';'  */
#line 71 "mini_js.y"
                                  { yyval.c = yyvsp[-1].c; }
#line 1440 "y.tab.c"
    break;

  case 8: /* Comando: _VAR Declaracao_Simples ';'  */
#line 72 "mini_js.y"
                                  { yyval.c = yyvsp[-1].c; }
#line 1446 "y.tab.c"
    break;

  case 9: /* Comando: _CONST Declaracao_Simples ';'  */
#line 73 "mini_js.y"
                                    { yyval.c = yyvsp[-1].c; }
#line 1452 "y.tab.c"
    break;

  case 10: /* Comando: _RETURN Expressao ';'  */
#line 74 "mini_js.y"
                            { yyval.c = auxiliar + yyvsp[-1].c + "'&retorno'" + "@" + "~"; }
#line 1458 "y.tab.c"
    break;

  case 11: /* Comando: _IF '(' Expressao ')' Bloco _ELSE Bloco  */
#line 75 "mini_js.y"
                                              { 
        string r = gera_label("IF_ELSE"); 
        string s = gera_label("IF_CONTINUE"); 
        yyval.c = yyvsp[-4].c + "!" + r + "?" + yyvsp[-2].c + s + "#" + (":" + r) + yyvsp[0].c + (":" + s); 
    }
#line 1468 "y.tab.c"
    break;

  case 12: /* Comando: _IF '(' Expressao ')' Bloco  */
#line 80 "mini_js.y"
                                  { 
        string r = gera_label("ENDIF"); 
        yyval.c = yyvsp[-2].c + "!" + r + "?" + yyvsp[0].c + (":" + r); 
    }
#line 1477 "y.tab.c"
    break;

  case 13: /* Comando: _WHILE '(' Expressao ')' Bloco  */
#line 84 "mini_js.y"
                                     { 
        string r = gera_label("_WHILE"); 
        string s = gera_label("ENDWHILE"); 
        yyval.c = auxiliar + (":" + r) + yyvsp[-2].c + "!" + s + "?" + yyvsp[0].c + r + "#" + (":" + s); 
    }
#line 1487 "y.tab.c"
    break;

  case 14: /* Comando: _FOR '(' Comando Expressao ';' Expressao ')' Bloco  */
#line 89 "mini_js.y"
                                                         { 
        string r = gera_label("TESTFOR");
        string s = gera_label("ENDFOR"); 
        yyval.c = yyvsp[-5].c + (":" + r) + yyvsp[-4].c + "!" + s + "?" + yyvsp[0].c + yyvsp[-2].c + "^" + r + "#" + (":" + s); 
    }
#line 1497 "y.tab.c"
    break;

  case 15: /* Comando: _FUNCTION _ID '(' ')' Bloco  */
#line 94 "mini_js.y"
                                  { 
        string r = gera_label(yyvsp[-3].c[0]); 
        vector<string> retorna = auxiliar + "undefined" + "@" + "'&retorno'" + "@" + "~"; 
        funcs = funcs + (":" + r) + yyvsp[0].c + retorna;
        vector<string> end_decl = yyvsp[-3].c + "&" + yyvsp[-3].c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^";
        yyval.c = end_decl; 
        quantidade_parametros = 0; 
    }
#line 1510 "y.tab.c"
    break;

  case 16: /* Comando: _FUNCTION _ID '(' D_LINHA ')' Bloco  */
#line 102 "mini_js.y"
                                          { 
        string r = gera_label(yyvsp[-4].c[0]);
        vector<string> retorna = auxiliar + "undefined" + "@" + "'&retorno'" + "@" + "~";
        funcs = funcs + (":" + r) + yyvsp[-2].c + yyvsp[0].c + retorna;
        yyval.c = yyvsp[-4].c + "&" + yyvsp[-4].c + "{}" + "=" + "'&funcao'" + r + "[=]" + "^"; 
    }
#line 1521 "y.tab.c"
    break;

  case 17: /* Expressao: Expressao '<' Expressao  */
#line 110 "mini_js.y"
                                    { yyval.c = yyvsp[-2].c + yyvsp[0].c + "<"; }
#line 1527 "y.tab.c"
    break;

  case 18: /* Expressao: Expressao '>' Expressao  */
#line 111 "mini_js.y"
                            { yyval.c = yyvsp[-2].c + yyvsp[0].c + ">"; }
#line 1533 "y.tab.c"
    break;

  case 19: /* Expressao: Expressao _MA_IG Expressao  */
#line 112 "mini_js.y"
                               { yyval.c = yyvsp[-2].c + yyvsp[0].c + ">="; }
#line 1539 "y.tab.c"
    break;

  case 20: /* Expressao: Expressao _ME_IG Expressao  */
#line 113 "mini_js.y"
                               { yyval.c = yyvsp[-2].c + yyvsp[0].c + "<="; }
#line 1545 "y.tab.c"
    break;

  case 21: /* Expressao: Expressao _IGUAL Expressao  */
#line 114 "mini_js.y"
                               { yyval.c = yyvsp[-2].c + yyvsp[0].c + "=="; }
#line 1551 "y.tab.c"
    break;

  case 22: /* Expressao: Expressao '*' Expressao  */
#line 115 "mini_js.y"
                            { yyval.c = yyvsp[-2].c + yyvsp[0].c + "*"; }
#line 1557 "y.tab.c"
    break;

  case 23: /* Expressao: Expressao '+' Expressao  */
#line 116 "mini_js.y"
                            { yyval.c = yyvsp[-2].c + yyvsp[0].c + "+"; }
#line 1563 "y.tab.c"
    break;

  case 24: /* Expressao: Expressao '-' Expressao  */
#line 117 "mini_js.y"
                            { yyval.c = yyvsp[-2].c + yyvsp[0].c + "-"; }
#line 1569 "y.tab.c"
    break;

  case 25: /* Expressao: Expressao '/' Expressao  */
#line 118 "mini_js.y"
                            { yyval.c = yyvsp[-2].c + yyvsp[0].c + "/"; }
#line 1575 "y.tab.c"
    break;

  case 26: /* Expressao: Expressao '%' Expressao  */
#line 119 "mini_js.y"
                            { yyval.c = yyvsp[-2].c + yyvsp[0].c + "%"; }
#line 1581 "y.tab.c"
    break;

  case 27: /* Expressao: LV_ '=' Expressao  */
#line 120 "mini_js.y"
                      { yyval.c = yyvsp[-2].c + yyvsp[0].c + "[=]"; }
#line 1587 "y.tab.c"
    break;

  case 28: /* Expressao: LVALUE '=' Expressao  */
#line 121 "mini_js.y"
                         { yyval.c = yyvsp[-2].c + yyvsp[0].c + "="; }
#line 1593 "y.tab.c"
    break;

  case 29: /* Expressao: LV_  */
#line 122 "mini_js.y"
        { yyval.c = yyvsp[0].c + "[@]"; }
#line 1599 "y.tab.c"
    break;

  case 30: /* Expressao: LVALUE  */
#line 123 "mini_js.y"
           { yyval.c = yyvsp[0].c + "@"; }
#line 1605 "y.tab.c"
    break;

  case 31: /* Expressao: O  */
#line 124 "mini_js.y"
      { yyval = yyvsp[0]; }
#line 1611 "y.tab.c"
    break;

  case 32: /* Expressao: F  */
#line 125 "mini_js.y"
      { yyval = yyvsp[0]; }
#line 1617 "y.tab.c"
    break;

  case 33: /* Declaracao_Simples: Declaracao_Complexa ',' Declaracao_Simples  */
#line 128 "mini_js.y"
                                                                { yyval.c = yyvsp[-2].c + yyvsp[0].c; }
#line 1623 "y.tab.c"
    break;

  case 34: /* Declaracao_Simples: Declaracao_Complexa  */
#line 129 "mini_js.y"
                        { yyval.c = yyvsp[0].c; }
#line 1629 "y.tab.c"
    break;

  case 35: /* Declaracao_Complexa: LVALUE '=' Expressao  */
#line 132 "mini_js.y"
                                           { 
        yyval.c = yyvsp[-2].c + "&" + yyvsp[-2].c + yyvsp[0].c + "=" + "^";
        vars[yyvsp[-2].c[0]] = linha;
    }
#line 1638 "y.tab.c"
    break;

  case 36: /* Declaracao_Complexa: LVALUE  */
#line 136 "mini_js.y"
           { 
        yyval.c = yyvsp[0].c + "&";
        vars[yyvsp[0].c[0]] = linha;
    }
#line 1647 "y.tab.c"
    break;

  case 37: /* Bloco: '{' Comandos '}'  */
#line 142 "mini_js.y"
                         { yyval.c = yyvsp[-1].c; }
#line 1653 "y.tab.c"
    break;

  case 38: /* Bloco: Comando  */
#line 143 "mini_js.y"
            { yyval.c = yyvsp[0].c; }
#line 1659 "y.tab.c"
    break;

  case 39: /* Bloco: B_  */
#line 144 "mini_js.y"
       { yyval.c = auxiliar; }
#line 1665 "y.tab.c"
    break;

  case 40: /* B_: '{' '}'  */
#line 147 "mini_js.y"
             { yyval.c = auxiliar; }
#line 1671 "y.tab.c"
    break;

  case 41: /* D_LINHA: D_LINHA_  */
#line 150 "mini_js.y"
                   { 
        vector<string> decl_par;
        int tam = pars.size() / 2;
        for (int i = 0; i < tam; i++) {
            vector<string> defaultValue = pars.back();
            pars.pop_back();
            vector<string> id = pars.back();
            pars.pop_back();
            if (defaultValue.empty()) {
                decl_par = decl_par + id + "&" + id + "arguments" + "@" + to_string(i) + "[@]" + "=" + "^";
            } else {
                string r = gera_label("IF_ELSE");
                string s = gera_label("IF_CONTINUE");
                vector<string> def = auxiliar + "arguments" + "@" + to_string(i) + "[@]" + "undefined" + "@" + "==" + "!" + r + "?" + id + "&" + id + defaultValue + "=" + "^";
                vector<string> notDef = auxiliar + s + "#" + (":" + r) + id + "&" + id + "arguments" + "@" + to_string(i) + "[@]" + "=" + "^" + (":" + s);
                decl_par = decl_par + def + notDef;
            }
        }
        pars.clear();
        yyval.c = decl_par; 
    }
#line 1697 "y.tab.c"
    break;

  case 42: /* D_LINHA_: _ID '=' Expressao ',' D_LINHA_  */
#line 173 "mini_js.y"
                                          { 
        pars.push_back(yyvsp[-4].c);
        pars.push_back(yyvsp[-2].c);
        yyval.c = yyvsp[-4].c + yyvsp[-2].c + yyvsp[0].c; 
    }
#line 1707 "y.tab.c"
    break;

  case 43: /* D_LINHA_: _ID ',' D_LINHA_  */
#line 178 "mini_js.y"
                     { 
        pars.push_back(yyvsp[-2].c);
        pars.push_back(auxiliar);
        yyval.c = yyvsp[-2].c + yyvsp[0].c; 
    }
#line 1717 "y.tab.c"
    break;

  case 44: /* D_LINHA_: _ID '=' Expressao  */
#line 183 "mini_js.y"
                      { 
        pars.push_back(yyvsp[-2].c);
        pars.push_back(yyvsp[0].c);
        yyval.c = yyvsp[-2].c + yyvsp[0].c; 
    }
#line 1727 "y.tab.c"
    break;

  case 45: /* D_LINHA_: _ID  */
#line 188 "mini_js.y"
        { 
        pars.push_back(yyvsp[0].c);
        pars.push_back(auxiliar);
        yyval.c = yyvsp[0].c; 
    }
#line 1737 "y.tab.c"
    break;

  case 46: /* LV_: LVALUE P  */
#line 195 "mini_js.y"
               { yyval.c = yyvsp[-1].c + "@" + yyvsp[0].c; }
#line 1743 "y.tab.c"
    break;

  case 47: /* LVALUE: _ID  */
#line 198 "mini_js.y"
             { yyval.c = yyvsp[0].c; }
#line 1749 "y.tab.c"
    break;

  case 48: /* P: '[' Expressao ']' P  */
#line 201 "mini_js.y"
                        { yyval.c = yyvsp[-2].c + "[@]" + yyvsp[0].c; }
#line 1755 "y.tab.c"
    break;

  case 49: /* P: '.' _ID P  */
#line 202 "mini_js.y"
              { yyval.c = yyvsp[-1].c + "[@]" + yyvsp[0].c; }
#line 1761 "y.tab.c"
    break;

  case 50: /* P: '[' Expressao ']'  */
#line 203 "mini_js.y"
                      { yyval.c = yyvsp[-1].c; }
#line 1767 "y.tab.c"
    break;

  case 51: /* P: '.' _ID  */
#line 204 "mini_js.y"
            { yyval.c = yyvsp[0].c; }
#line 1773 "y.tab.c"
    break;

  case 52: /* O: '{' Atribuicao '}'  */
#line 207 "mini_js.y"
                       { yyval.c = auxiliar + "{}" + yyvsp[-1].c; }
#line 1779 "y.tab.c"
    break;

  case 53: /* O: B_  */
#line 208 "mini_js.y"
       { yyval.c = auxiliar + "{}"; }
#line 1785 "y.tab.c"
    break;

  case 54: /* Atribuicao: _ID ':' Expressao ',' Atribuicao  */
#line 211 "mini_js.y"
                                              { yyval.c = yyvsp[-4].c + yyvsp[-2].c + "[<=]" + yyvsp[0].c; }
#line 1791 "y.tab.c"
    break;

  case 55: /* Atribuicao: _ID ':' Expressao  */
#line 212 "mini_js.y"
                          { yyval.c = yyvsp[-2].c + yyvsp[0].c + "[<=]"; }
#line 1797 "y.tab.c"
    break;

  case 56: /* F: _FLOAT  */
#line 215 "mini_js.y"
           { yyval.c = yyvsp[0].c; }
#line 1803 "y.tab.c"
    break;

  case 57: /* F: _STRING  */
#line 216 "mini_js.y"
            { yyval.c = yyvsp[0].c; }
#line 1809 "y.tab.c"
    break;

  case 58: /* F: _BOLEANO  */
#line 217 "mini_js.y"
             { yyval.c = yyvsp[0].c; }
#line 1815 "y.tab.c"
    break;

  case 59: /* F: '(' Expressao ')'  */
#line 218 "mini_js.y"
                      { yyval = yyvsp[-1]; }
#line 1821 "y.tab.c"
    break;

  case 60: /* F: CF  */
#line 219 "mini_js.y"
       { yyval = yyvsp[0]; }
#line 1827 "y.tab.c"
    break;

  case 61: /* F: ARRAY  */
#line 220 "mini_js.y"
          { yyval = yyvsp[0]; }
#line 1833 "y.tab.c"
    break;

  case 62: /* F: FA  */
#line 221 "mini_js.y"
       { yyval = yyvsp[0]; }
#line 1839 "y.tab.c"
    break;

  case 63: /* F: Funcao_Seta  */
#line 222 "mini_js.y"
                { yyval = yyvsp[0]; }
#line 1845 "y.tab.c"
    break;

  case 64: /* CF: _ID '(' P_ ')'  */
#line 225 "mini_js.y"
                    { yyval.c = yyvsp[-1].c + to_string(quantidade_parametros) + yyvsp[-3].c + "@" + "$"; quantidade_parametros = 0; }
#line 1851 "y.tab.c"
    break;

  case 65: /* CF: _ID '(' ')'  */
#line 226 "mini_js.y"
                 { yyval.c = auxiliar + "0" + yyvsp[-2].c + "@" + "$"; }
#line 1857 "y.tab.c"
    break;

  case 66: /* CF: LV_ '(' P_ ')'  */
#line 227 "mini_js.y"
                    { yyval.c = yyvsp[-1].c + to_string(quantidade_parametros) + yyvsp[-3].c + "[@]" + "$"; quantidade_parametros = 0; }
#line 1863 "y.tab.c"
    break;

  case 67: /* CF: LV_ '(' ')'  */
#line 228 "mini_js.y"
                 { yyval.c = auxiliar + "0" + yyvsp[-2].c + "[@]" + "$"; }
#line 1869 "y.tab.c"
    break;

  case 68: /* ARRAY: '[' ELS ']'  */
#line 231 "mini_js.y"
                    { 
        yyval.c = auxiliar + "[]";
        int tam = elements.size();
        for (int i = 0; i < tam; i++) {
            yyval.c = yyval.c + to_string(i) + elements.back() + "[<=]";
            elements.pop_back();
        }
    }
#line 1882 "y.tab.c"
    break;

  case 69: /* ARRAY: '[' ']'  */
#line 239 "mini_js.y"
            { yyval.c = auxiliar + "[]"; }
#line 1888 "y.tab.c"
    break;

  case 70: /* FA: FUNC_ANON ')' Bloco  */
#line 242 "mini_js.y"
                         { 
        string r = gera_label("FUNCANON"); 
        vector<string> retorna = auxiliar + "undefined" + "@" + "'&retorno'" + "@" + "~";
        funcs = funcs + (":" + r) + yyvsp[0].c + retorna;
        yyval.c = auxiliar + "{}" + "'&funcao'" + r + "[<=]"; 
    }
#line 1899 "y.tab.c"
    break;

  case 71: /* FA: FUNC_ANON D_LINHA ')' Bloco  */
#line 248 "mini_js.y"
                                { 
        string r = gera_label("FUNCANON");
        vector<string> retorna = auxiliar + "undefined" + "@" + "'&retorno'" + "@" + "~";
        funcs = funcs + (":" + r) + yyvsp[-2].c + yyvsp[0].c + retorna;
        yyval.c = auxiliar + "{}" + "'&funcao'" + r + "[<=]"; 
    }
#line 1910 "y.tab.c"
    break;

  case 72: /* Funcao_Seta: H _ARROW Expressao  */
#line 256 "mini_js.y"
                                 { 
        string r = gera_label("FUNCANON"); 
        vector<string> retorna = auxiliar + yyvsp[0].c + "'&retorno'" + "@" + "~";
        funcs = funcs + (":" + r) + yyvsp[-2].c + retorna;
        yyval.c = auxiliar + "{}" + "'&funcao'" + r + "[<=]"; 
    }
#line 1921 "y.tab.c"
    break;

  case 73: /* P_: Expressao ',' P_  */
#line 264 "mini_js.y"
                      { yyval.c = yyvsp[-2].c + yyvsp[0].c; quantidade_parametros++; }
#line 1927 "y.tab.c"
    break;

  case 74: /* P_: Expressao  */
#line 265 "mini_js.y"
               { yyval.c = yyvsp[0].c; quantidade_parametros++; }
#line 1933 "y.tab.c"
    break;

  case 75: /* ELS: Expressao ',' ELS  */
#line 268 "mini_js.y"
                        { elements.push_back(yyvsp[-2].c); }
#line 1939 "y.tab.c"
    break;

  case 76: /* ELS: Expressao  */
#line 269 "mini_js.y"
                { elements.push_back(yyvsp[0].c); }
#line 1945 "y.tab.c"
    break;

  case 77: /* H: _ID  */
#line 272 "mini_js.y"
        { yyval.c = yyvsp[0].c + "&" + yyvsp[0].c + "arguments" + "@" + "0" + "[@]" + "=" + "^"; }
#line 1951 "y.tab.c"
    break;

  case 78: /* H: '(' ')'  */
#line 273 "mini_js.y"
            { yyval.c = auxiliar; }
#line 1957 "y.tab.c"
    break;

  case 79: /* H: APS D_LINHA ')'  */
#line 274 "mini_js.y"
                    { yyval.c = yyvsp[-1].c; }
#line 1963 "y.tab.c"
    break;


#line 1967 "y.tab.c"

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

#line 277 "mini_js.y"


#include "lex.yy.c"

vector<string> operator+(const vector<string>& a, const vector<string>& b) {
    vector<string> result(a);
    result.insert(result.end(), b.begin(), b.end());
    return result;
}

vector<string> operator+(const vector<string>& a, const string& b) {
    vector<string> result(a);
    result.push_back(b);
    return result;
}

string gera_label(const string& prefixo) {
    static int n = 0;
    return prefixo + "_" + to_string(++n) + ":";
}

vector<string> resolve_enderecos(const vector<string>& entrada) {
    map<string, int> label;
    vector<string> saida;

    for (const auto& item : entrada) {
        if (item[0] == ':') {
            label[item.substr(1)] = saida.size();
        } else {
            saida.push_back(item);
        }
    }

    for (auto& item : saida) {
        if (label.count(item) > 0) {
            item = to_string(label[item]);
        }
    }

    return saida;
}

void imprime_vetor(const vector<string>& v) {
    for (const auto& item : v) {
        cout << item << " ";
    }
}

string remove_espacos(const char* c) {
    string temp(c);
    return temp.erase(temp.size() - 1);
}

vector<string> divide_string(const string& str) {
    vector<string> tokens;
    istringstream iss(str);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int token(int tk) {
    yylval.c = auxiliar + yytext;
    return tk;
}

void yyerror(const char* st) {
    puts(st);
    printf("Proximo a: %s\n", yytext);
    exit(1);
}

int main(int argc, char* argv[]) {
    yyparse();
    return 0;
}
