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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PR_INT = 3,                  /* TK_PR_INT  */
  YYSYMBOL_TK_PR_FLOAT = 4,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_BOOL = 5,                 /* TK_PR_BOOL  */
  YYSYMBOL_TK_PR_IF = 6,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_ELSE = 7,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 8,                /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_RETURN = 9,               /* TK_PR_RETURN  */
  YYSYMBOL_TK_OC_LE = 10,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 11,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 12,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 13,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 14,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 15,                  /* TK_OC_OR  */
  YYSYMBOL_TK_ERRO = 16,                   /* TK_ERRO  */
  YYSYMBOL_17_ = 17,                       /* '='  */
  YYSYMBOL_18_ = 18,                       /* '<'  */
  YYSYMBOL_19_ = 19,                       /* '>'  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '*'  */
  YYSYMBOL_22_ = 22,                       /* '/'  */
  YYSYMBOL_23_ = 23,                       /* '%'  */
  YYSYMBOL_24_ = 24,                       /* '!'  */
  YYSYMBOL_25_ = 25,                       /* '-'  */
  YYSYMBOL_TK_IDENTIFICADOR = 26,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_LIT_INT = 27,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 28,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_FALSE = 29,              /* TK_LIT_FALSE  */
  YYSYMBOL_TK_LIT_TRUE = 30,               /* TK_LIT_TRUE  */
  YYSYMBOL_31_ = 31,                       /* ','  */
  YYSYMBOL_32_ = 32,                       /* ';'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_lista_de_elementos = 39,        /* lista_de_elementos  */
  YYSYMBOL_elemento = 40,                  /* elemento  */
  YYSYMBOL_declaracao_global = 41,         /* declaracao_global  */
  YYSYMBOL_identificador = 42,             /* identificador  */
  YYSYMBOL_call_identificador = 43,        /* call_identificador  */
  YYSYMBOL_tipo = 44,                      /* tipo  */
  YYSYMBOL_INT = 45,                       /* INT  */
  YYSYMBOL_FLOAT = 46,                     /* FLOAT  */
  YYSYMBOL_BOOL = 47,                      /* BOOL  */
  YYSYMBOL_lista_identificador = 48,       /* lista_identificador  */
  YYSYMBOL_definicao_de_funcao = 49,       /* definicao_de_funcao  */
  YYSYMBOL_cabecalho = 50,                 /* cabecalho  */
  YYSYMBOL_criar_scope = 51,               /* criar_scope  */
  YYSYMBOL_OR = 52,                        /* OR  */
  YYSYMBOL_lista_de_parametros = 53,       /* lista_de_parametros  */
  YYSYMBOL_parametro = 54,                 /* parametro  */
  YYSYMBOL_corpo = 55,                     /* corpo  */
  YYSYMBOL_bloco_de_comandos = 56,         /* bloco_de_comandos  */
  YYSYMBOL_lista_de_comandos = 57,         /* lista_de_comandos  */
  YYSYMBOL_comando_simples = 58,           /* comando_simples  */
  YYSYMBOL_declaracao_variavel = 59,       /* declaracao_variavel  */
  YYSYMBOL_comando_atribuicao = 60,        /* comando_atribuicao  */
  YYSYMBOL_RETURN = 61,                    /* RETURN  */
  YYSYMBOL_comando_retorno = 62,           /* comando_retorno  */
  YYSYMBOL_comando_controle_fluxo = 63,    /* comando_controle_fluxo  */
  YYSYMBOL_IF = 64,                        /* IF  */
  YYSYMBOL_ELSE = 65,                      /* ELSE  */
  YYSYMBOL_condicional = 66,               /* condicional  */
  YYSYMBOL_WHILE = 67,                     /* WHILE  */
  YYSYMBOL_loop = 68,                      /* loop  */
  YYSYMBOL_expressao = 69,                 /* expressao  */
  YYSYMBOL_operando = 70,                  /* operando  */
  YYSYMBOL_operador = 71,                  /* operador  */
  YYSYMBOL_comparacao_1 = 72,              /* comparacao_1  */
  YYSYMBOL_equal_or_not = 73,              /* equal_or_not  */
  YYSYMBOL_comparacao_2 = 74,              /* comparacao_2  */
  YYSYMBOL_greater_or_less = 75,           /* greater_or_less  */
  YYSYMBOL_adicaousub = 76,                /* adicaousub  */
  YYSYMBOL_op_adicaousub = 77,             /* op_adicaousub  */
  YYSYMBOL_multoudivoures = 78,            /* multoudivoures  */
  YYSYMBOL_op_multoudivoures = 79,         /* op_multoudivoures  */
  YYSYMBOL_unario = 80,                    /* unario  */
  YYSYMBOL_primario = 81,                  /* primario  */
  YYSYMBOL_chamada_funcao = 82,            /* chamada_funcao  */
  YYSYMBOL_lista_de_argumentos = 83,       /* lista_de_argumentos  */
  YYSYMBOL_nome_func = 84,                 /* nome_func  */
  YYSYMBOL_literais = 85,                  /* literais  */
  YYSYMBOL_LITINT = 86,                    /* LITINT  */
  YYSYMBOL_LITFLOAT = 87,                  /* LITFLOAT  */
  YYSYMBOL_LITFALSE = 88,                  /* LITFALSE  */
  YYSYMBOL_LITTRUE = 89,                   /* LITTRUE  */
  YYSYMBOL_INVERTSIG = 90,                 /* INVERTSIG  */
  YYSYMBOL_NEGATE = 91,                    /* NEGATE  */
  YYSYMBOL_MULTIPLY = 92,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 93,                    /* DIVIDE  */
  YYSYMBOL_REMAINDER = 94,                 /* REMAINDER  */
  YYSYMBOL_ADD = 95,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 96,                  /* SUBTRACT  */
  YYSYMBOL_GREATERTHAN = 97,               /* GREATERTHAN  */
  YYSYMBOL_LESSTHAN = 98,                  /* LESSTHAN  */
  YYSYMBOL_LESSEQUAL = 99,                 /* LESSEQUAL  */
  YYSYMBOL_GREATEREQUAL = 100,             /* GREATEREQUAL  */
  YYSYMBOL_EQUAL = 101,                    /* EQUAL  */
  YYSYMBOL_NOTEQUAL = 102,                 /* NOTEQUAL  */
  YYSYMBOL_AND = 103                       /* AND  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 11 ".//parser.y"

#include <stdlib.h>
#include <stdio.h>
#include "sym_stack.h"

// Protótipos das funções necessárias
int yylex(void);
int yyerror(char const *s);
extern int get_line_number(void);
extern char *yytext;
extern void *arvore;
extern void *global_sym_table;
extern void *scope;

#line 221 ".//parser.tab.c"


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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   138

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,    24,     2,     2,     2,    23,     2,     2,
      33,    34,    21,    20,    31,    25,     2,    22,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
      18,    17,    19,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   135,   144,   164,   173,   178,   187,   196,
     202,   210,   215,   220,   229,   238,   247,   257,   262,   271,
     285,   306,   311,   320,   338,   344,   352,   361,   366,   377,
     381,   390,   395,   418,   423,   428,   433,   438,   443,   452,
     461,   472,   478,   488,   493,   502,   508,   514,   521,   533,
     539,   558,   565,   570,   581,   586,   597,   602,   610,   615,
     624,   629,   638,   643,   648,   653,   662,   667,   678,   683,
     692,   697,   708,   713,   718,   727,   732,   738,   748,   753,
     758,   763,   772,   778,   787,   792,   816,   825,   830,   835,
     840,   849,   858,   867,   876,   885,   891,   897,   903,   909,
     915,   921,   927,   933,   939,   945,   951,   957,   963
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_BOOL", "TK_PR_IF", "TK_PR_ELSE", "TK_PR_WHILE",
  "TK_PR_RETURN", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE",
  "TK_OC_AND", "TK_OC_OR", "TK_ERRO", "'='", "'<'", "'>'", "'+'", "'*'",
  "'/'", "'%'", "'!'", "'-'", "TK_IDENTIFICADOR", "TK_LIT_INT",
  "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE", "','", "';'", "'('",
  "')'", "'{'", "'}'", "$accept", "programa", "lista_de_elementos",
  "elemento", "declaracao_global", "identificador", "call_identificador",
  "tipo", "INT", "FLOAT", "BOOL", "lista_identificador",
  "definicao_de_funcao", "cabecalho", "criar_scope", "OR",
  "lista_de_parametros", "parametro", "corpo", "bloco_de_comandos",
  "lista_de_comandos", "comando_simples", "declaracao_variavel",
  "comando_atribuicao", "RETURN", "comando_retorno",
  "comando_controle_fluxo", "IF", "ELSE", "condicional", "WHILE", "loop",
  "expressao", "operando", "operador", "comparacao_1", "equal_or_not",
  "comparacao_2", "greater_or_less", "adicaousub", "op_adicaousub",
  "multoudivoures", "op_multoudivoures", "unario", "primario",
  "chamada_funcao", "lista_de_argumentos", "nome_func", "literais",
  "LITINT", "LITFLOAT", "LITFALSE", "LITTRUE", "INVERTSIG", "NEGATE",
  "MULTIPLY", "DIVIDE", "REMAINDER", "ADD", "SUBTRACT", "GREATERTHAN",
  "LESSTHAN", "LESSEQUAL", "GREATEREQUAL", "EQUAL", "NOTEQUAL", "AND", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      10,   -77,   -77,   -77,     9,   -77,    10,   -77,    11,   -77,
     -77,   -77,   -77,    16,    28,   -77,   -77,   -77,   -77,    -4,
      27,    40,    17,   -77,    11,   -77,   -77,   -77,    43,    61,
     -77,    11,    40,    44,   -77,    46,   -77,   -77,    41,   -77,
     -77,    48,   -77,    49,   -77,   -77,    50,    27,    11,    18,
     -77,   -77,    41,    47,   -77,    27,   -77,   -77,   -77,   -77,
     -77,   -77,    41,   -77,   -77,    69,    71,    60,     7,   -14,
      23,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,    41,
      41,    41,    41,    30,    51,   -77,    17,    69,   -77,   -77,
      52,   -77,    41,   -77,    41,   -77,   -77,    41,   -77,   -77,
     -77,   -77,   -77,   -77,    41,   -77,   -77,   -77,   -77,   -77,
     -77,    41,   -77,   -77,   -77,   -77,   -77,    41,   -77,   -77,
     -77,   -77,   -77,    55,    56,   -77,    59,    58,   -77,   -77,
      17,   -77,    71,    60,     7,   -14,    23,   -77,    16,    16,
      41,   -77,    72,     3,    40,   -77,    11,   -77,    16,   -77,
      40
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    14,    15,    16,     0,     2,     5,     6,     0,    11,
      12,    13,     7,     0,     0,     1,     4,     9,    18,     0,
      29,    19,    25,     8,     0,    45,    49,    41,     9,     0,
      86,     0,    38,     0,    30,     0,    33,    34,     0,    36,
      37,     0,    43,     0,    44,    35,     0,    29,     0,     0,
      24,    17,     0,    39,    27,    31,    96,    95,    91,    92,
      93,    94,     0,    78,    42,    51,    52,    54,    56,    60,
      66,    70,    75,    80,    79,    87,    88,    89,    90,     0,
       0,     0,     0,     0,     0,    26,     0,     0,    40,    32,
       0,    22,     0,   108,     0,   106,   107,     0,    58,    59,
     104,   105,   103,   102,     0,    64,    65,    63,    62,   100,
     101,     0,    68,    69,    97,    98,    99,     0,    72,    73,
      74,    76,    77,     0,     0,    83,    84,     0,    28,    23,
       0,    81,    53,    55,    57,    61,    67,    71,     0,     0,
       0,    82,     0,    47,    50,    85,     0,    46,     0,    20,
      48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,    87,   -77,   -77,    -8,   -77,     2,   -77,   -77,
     -77,    64,   -77,   -77,   -77,    12,   -77,    14,   -12,    54,
      42,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -33,   -77,     4,     8,   -77,     1,   -77,    -1,
     -77,    -7,   -77,   -76,   -77,   -13,   -35,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,     7,    63,    30,    31,     9,    10,
      11,    19,    12,    13,    14,    92,    49,    50,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,   148,    42,
      43,    44,   126,    65,    66,    67,    97,    68,   104,    69,
     111,    70,   117,    71,    72,    73,   127,    46,    74,    75,
      76,    77,    78,    79,    80,   118,   119,   120,   112,   113,
     105,   106,   107,   108,    98,    99,    94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    21,     8,   121,   122,    64,   109,    45,     8,    15,
     147,   110,    29,     1,     2,     3,    51,   100,   101,    88,
       1,     2,     3,    18,    48,   102,   103,    23,    24,    90,
       1,     2,     3,    25,    45,    26,    27,    17,    47,    29,
      85,   137,    45,   -21,   114,   115,   116,    29,   123,   124,
      86,    20,    87,    28,    56,    57,    28,    58,    59,    60,
      61,    22,    20,    62,   125,    56,    57,    28,    58,    59,
      60,    61,    95,    96,    62,    47,   -10,    55,    52,    24,
      54,    81,    82,    83,    91,    93,   131,   128,    48,   138,
     139,   140,   141,    16,   146,    53,   132,    89,   134,   130,
     129,    84,   133,   135,   136,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,     0,     0,
       0,     0,   142,     0,     0,     0,   150,     0,   149
};

static const yytype_int16 yycheck[] =
{
       8,    13,     0,    79,    80,    38,    20,    20,     6,     0,
       7,    25,    20,     3,     4,     5,    24,    10,    11,    52,
       3,     4,     5,    31,    22,    18,    19,    31,    32,    62,
       3,     4,     5,     6,    47,     8,     9,    26,    35,    47,
      48,   117,    55,    33,    21,    22,    23,    55,    81,    82,
      32,    35,    34,    26,    24,    25,    26,    27,    28,    29,
      30,    33,    35,    33,    34,    24,    25,    26,    27,    28,
      29,    30,    12,    13,    33,    35,    33,    31,    17,    32,
      36,    33,    33,    33,    15,    14,    34,    36,    86,    34,
      34,    32,    34,     6,    22,    31,    92,    55,    97,    87,
      86,    47,    94,   104,   111,   140,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,   139,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,   148,    -1,   146
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    38,    39,    40,    41,    44,    45,
      46,    47,    49,    50,    51,     0,    39,    26,    42,    48,
      35,    55,    33,    31,    32,     6,     8,     9,    26,    42,
      43,    44,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    66,    67,    68,    82,    84,    35,    44,    53,
      54,    42,    17,    48,    36,    31,    24,    25,    27,    28,
      29,    30,    33,    42,    69,    70,    71,    72,    74,    76,
      78,    80,    81,    82,    85,    86,    87,    88,    89,    90,
      91,    33,    33,    33,    56,    42,    32,    34,    69,    57,
      69,    15,    52,    14,   103,    12,    13,    73,   101,   102,
      10,    11,    18,    19,    75,    97,    98,    99,   100,    20,
      25,    77,    95,    96,    21,    22,    23,    79,    92,    93,
      94,    80,    80,    69,    69,    34,    69,    83,    36,    54,
      52,    34,    71,    72,    74,    76,    78,    80,    34,    34,
      32,    34,    44,    55,    55,    83,    22,     7,    65,    42,
      55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    41,    42,
      43,    44,    44,    44,    45,    46,    47,    48,    48,    49,
      50,    51,    52,    53,    53,    53,    54,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    58,    58,    58,    59,
      60,    61,    62,    63,    63,    64,    65,    66,    66,    67,
      68,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    79,    80,    80,    80,    81,    81,
      81,    81,    82,    82,    83,    83,    84,    85,    85,    85,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       8,     0,     1,     3,     1,     0,     2,     3,     4,     0,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     2,     1,     1,     1,     1,     5,     7,     1,
       5,     1,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     3,     4,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* programa: lista_de_elementos  */
#line 129 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			arvore = (yyval.tree);
			//printf("Created ARVORE node\n"); // Debug print
		}
#line 1570 ".//parser.tab.c"
    break;

  case 3: /* programa: %empty  */
#line 135 ".//parser.y"
                {
			(yyval.tree) = NULL; // Se não houver elementos, o programa é nulo
			arvore = NULL;
			//printf("Empty arvore\n"); // Debug print
		}
#line 1580 ".//parser.tab.c"
    break;

  case 4: /* lista_de_elementos: elemento lista_de_elementos  */
#line 145 ".//parser.y"
                                  {
					if ((yyvsp[-1].tree) == NULL)
						 {
						 	(yyval.tree) = (yyvsp[0].tree); // Se o primeiro elemento for nulo, a lista de elementos é a segunda
						 }
					else
					{
						if ((yyvsp[0].tree) == NULL) // Se o segundo elemento for nulo, a lista de elementos é o primeiro
						{
							(yyval.tree) = (yyvsp[-1].tree);
						}
						else
						{
							(yyval.tree) = (yyvsp[-1].tree); // Caso contrário, o elementos é o primeiro elemento
							ast_add_child((yyval.tree), (yyvsp[0].tree)); // Adiciona a lista_de_elementos como filho do primeiro
							//printf("Added elemento to lista_de_elementos\n"); // Debug print
						}
					}	
				  }
#line 1604 ".//parser.tab.c"
    break;

  case 5: /* lista_de_elementos: elemento  */
#line 165 ".//parser.y"
                                  {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added elemento to lista_de_elementos\n"); // Debug print
				  }
#line 1613 ".//parser.tab.c"
    break;

  case 6: /* elemento: declaracao_global  */
#line 174 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added declaracao_global to elemento\n"); // Debug print
		}
#line 1622 ".//parser.tab.c"
    break;

  case 7: /* elemento: definicao_de_funcao  */
#line 179 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added definicao_de_funcao to elemento\n"); // Debug print
		}
#line 1631 ".//parser.tab.c"
    break;

  case 8: /* declaracao_global: tipo lista_identificador ','  */
#line 188 ".//parser.y"
                                 {
					(yyval.tree) = NULL; // Não há ações associadas à declaração global
					//printf("Added tipo and lista_identificador to declaracao_global\n"); // Debug print
				 }
#line 1640 ".//parser.tab.c"
    break;

  case 9: /* identificador: TK_IDENTIFICADOR  */
#line 197 ".//parser.y"
                         {
				(yyval.tree) = ast_new((yyvsp[0].valor_lexico)); // Cria um novo nó na árvore com o identificador
				//printf("Added TK_IDENTIFICADOR to identificador\n"); // Debug print
			 }
#line 1649 ".//parser.tab.c"
    break;

  case 10: /* call_identificador: TK_IDENTIFICADOR  */
#line 203 ".//parser.y"
                        {
				(yyval.tree) = ast_new_call_func((yyvsp[0].valor_lexico)); // Cria um novo nó representando uma chamada de função com o identificador
				//printf("Added TK_IDENTIFICADOR to identificador\n"); // Debug print
			}
#line 1658 ".//parser.tab.c"
    break;

  case 11: /* tipo: INT  */
#line 211 ".//parser.y"
        {
		(yyval.tree) = (yyvsp[0].tree);
		//printf("Added INT to tipo\n"); // Debug print
	}
#line 1667 ".//parser.tab.c"
    break;

  case 12: /* tipo: FLOAT  */
#line 216 ".//parser.y"
        {
		(yyval.tree) = (yyvsp[0].tree);
		//printf("Added FLOAT to tipo\n"); // Debug print
	}
#line 1676 ".//parser.tab.c"
    break;

  case 13: /* tipo: BOOL  */
#line 221 ".//parser.y"
        {
		(yyval.tree) = (yyvsp[0].tree);
		//printf("Added BOOL to tipo\n"); // Debug print
	}
#line 1685 ".//parser.tab.c"
    break;

  case 14: /* INT: TK_PR_INT  */
#line 230 ".//parser.y"
   {
		(yyval.tree) = NULL; // Espero que seja null mesmo.
		//printf("Empty INT\n"); // Debug print
   }
#line 1694 ".//parser.tab.c"
    break;

  case 15: /* FLOAT: TK_PR_FLOAT  */
#line 239 ".//parser.y"
         {
		(yyval.tree) = NULL; // Espero que seja null mesmo.
		//printf("Empty FLOAT\n"); // Debug print
	 }
#line 1703 ".//parser.tab.c"
    break;

  case 16: /* BOOL: TK_PR_BOOL  */
#line 248 ".//parser.y"
        {
		(yyval.tree) = NULL; // Espero que seja null mesmo.
		//printf("Empty BOOL\n"); // Debug print
	}
#line 1712 ".//parser.tab.c"
    break;

  case 17: /* lista_identificador: lista_identificador ';' identificador  */
#line 258 ".//parser.y"
                                   {
					 (yyval.tree) = (yyvsp[-2].tree); // Se houver uma lista de identificadores existente nós as mantemos
					 //printf("Added identificador and lista_identificador to lista_identificador\n"); // Debug print
				   }
#line 1721 ".//parser.tab.c"
    break;

  case 18: /* lista_identificador: identificador  */
#line 263 ".//parser.y"
                                   {
					 (yyval.tree) = (yyvsp[0].tree);
					 //printf("Added identificador to lista_identificador\n"); // Debug print
				   }
#line 1730 ".//parser.tab.c"
    break;

  case 19: /* definicao_de_funcao: cabecalho corpo  */
#line 272 ".//parser.y"
                                   {

						(yyval.tree) = (yyvsp[-1].tree); // Define a definição de função como o cabeçalho
						if ((yyvsp[0].tree) != NULL){
							ast_add_child((yyval.tree), (yyvsp[0].tree)); // Se houver corpo , adiciona o corpo como filho da definição de função
						}
                        free_table_of_symbols(pop_scope(scope));
						//printf("Added cabecalho and corpo to definicao_de_funcao\n"); // Debug print
				   }
#line 1744 ".//parser.tab.c"
    break;

  case 20: /* cabecalho: criar_scope '(' lista_de_parametros ')' OR tipo '/' identificador  */
#line 286 ".//parser.y"
                 {
			(yyval.tree) = (yyvsp[0].tree); // Define o cabeçalho como o identificador

            const char* new_key = strdup((yyvsp[0].tree)->valor_lexico->token_value);

            if(find_symbol(scope->top, new_key) != NULL)
            {
                printf("[ERR_DECLARED] Funcao [%s] na linha %d ja foi declarada neste scope\n", symbol_key, get_line_number());
                exit(ERR_DECLARED);
            }

            insert_symbol(scope->top, new_key, create_symbol((yyvsp[0].tree)->token_value,TOKEN_NATURE_FUNCTION));

			//printf("Added lista_de_parametros, tipo and identificador to cabecalho\n"); // Debug print
		 }
#line 1764 ".//parser.tab.c"
    break;

  case 21: /* criar_scope: %empty  */
#line 306 ".//parser.y"
           {
                push_scope(scope);
           }
#line 1772 ".//parser.tab.c"
    break;

  case 22: /* OR: TK_OC_OR  */
#line 312 ".//parser.y"
  {
  	(yyval.tree) = ast_new_label_only("|");
	//printf("Label OR\n"); // Debug print
  }
#line 1781 ".//parser.tab.c"
    break;

  case 23: /* lista_de_parametros: lista_de_parametros ';' parametro  */
#line 321 ".//parser.y"
                                        {
						if ((yyvsp[-2].tree) = NULL){ // Se não houver parâmetros existentes
							(yyval.tree) = (yyvsp[0].tree); // O resultado é o parâmetro atual
						}
						else 
						{
							if ((yyvsp[0].tree) == NULL) // Se não houver mais parâmetros
							{
								(yyval.tree) = (yyvsp[-2].tree); // O resultado é a lista de parâmetros existentes
							}
							else 
							{
								 (yyval.tree) = (yyvsp[-2].tree); // O resultado é a lista de parâmetros existentes
							}
						}
						//printf("Added parametro to lista_de_parametros\n"); // Debug print
					}
#line 1803 ".//parser.tab.c"
    break;

  case 24: /* lista_de_parametros: parametro  */
#line 339 ".//parser.y"
                                   {
						(yyval.tree) = (yyvsp[0].tree);
						//printf("Added parametro to lista_de_parametros\n"); // Debug print
				   }
#line 1812 ".//parser.tab.c"
    break;

  case 25: /* lista_de_parametros: %empty  */
#line 344 ".//parser.y"
                                   {
						(yyval.tree) = NULL;
						//printf("lista_de_parametros is empty\n"); // Debug print
				   }
#line 1821 ".//parser.tab.c"
    break;

  case 26: /* parametro: tipo identificador  */
#line 353 ".//parser.y"
         {
			(yyval.tree) = (yyvsp[-1].tree);
			ast_add_child((yyval.tree), (yyvsp[0].tree));
			//printf("Added tipo and identificador to parametro\n"); // Debug print
		 }
#line 1831 ".//parser.tab.c"
    break;

  case 27: /* corpo: '{' bloco_de_comandos '}'  */
#line 362 ".//parser.y"
         {
		(yyval.tree) = (yyvsp[-1].tree);
		//printf("Added bloco_de_comandos to corpo\n"); // Debug print
	 }
#line 1840 ".//parser.tab.c"
    break;

  case 28: /* corpo: corpo '{' bloco_de_comandos '}'  */
#line 367 ".//parser.y"
         {
		(yyval.tree) = (yyvsp[-3].tree);
		ast_add_child((yyval.tree), (yyvsp[-1].tree));
		//printf("Added bloco_de_comandos to corpo\n"); // Debug print
	 }
#line 1850 ".//parser.tab.c"
    break;

  case 29: /* bloco_de_comandos: %empty  */
#line 377 ".//parser.y"
                                 {
					(yyval.tree) = NULL;
					//printf("Empty bloco_de_comandos\n"); // Debug print
				 }
#line 1859 ".//parser.tab.c"
    break;

  case 30: /* bloco_de_comandos: lista_de_comandos  */
#line 382 ".//parser.y"
                                 {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added lista_de_comandos to bloco_de_comandos\n"); // Debug print
				 }
#line 1868 ".//parser.tab.c"
    break;

  case 31: /* lista_de_comandos: comando_simples ','  */
#line 391 ".//parser.y"
                                 {
					(yyval.tree) = (yyvsp[-1].tree); // O resultado é o comando simples
					//printf("Added comando_simples to lista_de_comandos\n"); // Debug print
				 }
#line 1877 ".//parser.tab.c"
    break;

  case 32: /* lista_de_comandos: comando_simples ',' lista_de_comandos  */
#line 396 ".//parser.y"
                                 {
					if ((yyvsp[0].tree) == NULL)  // Se não houver mais comandos na lista
					{
            			(yyval.tree) = (yyvsp[-2].tree); // O resultado é o primeiro comando simples
        		    }
					else
					{
						if ((yyvsp[-2].tree) == NULL)  // Se não houver mais comandos na lista
						{
            				(yyval.tree) = (yyvsp[0].tree);  // O resultado é a lista restante de comandos
        		    	}
						else
				 		{
							(yyval.tree) = (yyvsp[-2].tree); // O resultado é o primeiro comando simples
            				ast_add_child((yyvsp[-2].tree), (yyvsp[0].tree)); // Adiciona a lista restante de comandos como filho do primeiro comando simples
       			  		}
					} 	
				 }
#line 1900 ".//parser.tab.c"
    break;

  case 33: /* comando_simples: declaracao_variavel  */
#line 419 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added declaracao_variavel to comando_simples\n"); // Debug print
			   }
#line 1909 ".//parser.tab.c"
    break;

  case 34: /* comando_simples: comando_atribuicao  */
#line 424 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added comando_atribuicao to comando_simples\n"); // Debug print
			   }
#line 1918 ".//parser.tab.c"
    break;

  case 35: /* comando_simples: chamada_funcao  */
#line 429 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added comando_funcao to comando_simples\n"); // Debug print
			   }
#line 1927 ".//parser.tab.c"
    break;

  case 36: /* comando_simples: comando_retorno  */
#line 434 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added comando_retorno to comando_simples\n"); // Debug print
			   }
#line 1936 ".//parser.tab.c"
    break;

  case 37: /* comando_simples: comando_controle_fluxo  */
#line 439 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added comando_controle_fluxo to comando_simples\n"); // Debug print
			   }
#line 1945 ".//parser.tab.c"
    break;

  case 38: /* comando_simples: corpo  */
#line 444 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added corpo to comando_simples\n"); // Debug print
			   }
#line 1954 ".//parser.tab.c"
    break;

  case 39: /* declaracao_variavel: tipo lista_identificador  */
#line 453 ".//parser.y"
                                   {
						(yyval.tree) = NULL;
						//printf("Empty declaracao_variavel\n"); // Debug print
				   }
#line 1963 ".//parser.tab.c"
    break;

  case 40: /* comando_atribuicao: identificador '=' expressao  */
#line 462 ".//parser.y"
                                  {
					(yyval.tree) = ast_new_label_only("="); // Cria um novo nó com o rótulo "="
					ast_add_child((yyval.tree), (yyvsp[-2].tree)); // Adiciona o identificador como filho do nó
					ast_add_child((yyval.tree), (yyvsp[0].tree)); // Adiciona a expressão como filho do nó
					//printf("Added expressao to comando_atribuicao\n"); // Debug print
				  }
#line 1974 ".//parser.tab.c"
    break;

  case 41: /* RETURN: TK_PR_RETURN  */
#line 473 ".//parser.y"
          {
		(yyval.tree) = ast_new_label_only("return"); // Cria um novo nó com o rótulo "return"
		//printf("Label RETURN\n"); // Debug print
	  }
#line 1983 ".//parser.tab.c"
    break;

  case 42: /* comando_retorno: RETURN expressao  */
#line 479 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[-1].tree);
					ast_add_child((yyval.tree), (yyvsp[0].tree));
					//printf("Added expressao to comando_retorno\n"); // Debug print
			   }
#line 1993 ".//parser.tab.c"
    break;

  case 43: /* comando_controle_fluxo: condicional  */
#line 489 ".//parser.y"
                                          {
						(yyval.tree) = (yyvsp[0].tree);
						//printf("Added condicional to comando_controle_fluxo\n"); // Debug print
					  }
#line 2002 ".//parser.tab.c"
    break;

  case 44: /* comando_controle_fluxo: loop  */
#line 494 ".//parser.y"
                                          {
						(yyval.tree) = (yyvsp[0].tree);
						//printf("Added loop to comando_controle_fluxo\n"); // Debug print
					  }
#line 2011 ".//parser.tab.c"
    break;

  case 45: /* IF: TK_PR_IF  */
#line 503 ".//parser.y"
  {
  	(yyval.tree) = ast_new_label_only("if"); // Cria um novo nó com o rótulo "if"
	//printf("Label IF\n"); // Debug print
  }
#line 2020 ".//parser.tab.c"
    break;

  case 46: /* ELSE: TK_PR_ELSE  */
#line 509 ".//parser.y"
        {
		(yyval.tree) = NULL; // Cria um novo nó com o rótulo "else"
		//printf("Label ELSE\n"); // Debug print
	}
#line 2029 ".//parser.tab.c"
    break;

  case 47: /* condicional: IF '(' expressao ')' corpo  */
#line 515 ".//parser.y"
                   {
				(yyval.tree) = (yyvsp[-4].tree); // Define a condicional como o nó "if"
				ast_add_child((yyval.tree), (yyvsp[-2].tree)); // Adiciona a expressão como filho do nó "if"
				ast_add_child((yyval.tree), (yyvsp[0].tree)); // Adiciona o corpo como filho do nó "if"
				//printf("Added expressao and corpo to condicional\n"); // Debug print
		   }
#line 2040 ".//parser.tab.c"
    break;

  case 48: /* condicional: IF '(' expressao ')' corpo ELSE corpo  */
#line 522 ".//parser.y"
                   {
				(yyval.tree) = (yyvsp[-6].tree);
				ast_add_child((yyval.tree), (yyvsp[-4].tree)); // Adiciona a expressão como filho do nó "if"
				ast_add_child((yyval.tree), (yyvsp[-2].tree)); // Adiciona o corpo do "if" como filho do nó "if"
				ast_add_child((yyval.tree), (yyvsp[0].tree)); // Adiciona o nó "else" como filho do nó "if"
				//printf("Added expressao, corpo, and corpo to condicional\n"); // Debug print
		   }
#line 2052 ".//parser.tab.c"
    break;

  case 49: /* WHILE: TK_PR_WHILE  */
#line 534 ".//parser.y"
         {
		(yyval.tree) = ast_new_label_only("while"); // Cria um novo nó com o rótulo "while"
		//printf("Label WHILE\n"); // Debug print
	 }
#line 2061 ".//parser.tab.c"
    break;

  case 50: /* loop: WHILE '(' expressao ')' corpo  */
#line 540 ".//parser.y"
        {
		(yyval.tree) = (yyvsp[-4].tree);
		ast_add_child((yyval.tree), (yyvsp[-2].tree)); // Adiciona a expressão como filho do nó "while"
		ast_add_child((yyval.tree), (yyvsp[0].tree)); // Adiciona o corpo como filho do nó "while"
		//printf("Added expressao and corpo to loop\n"); // Debug print
	}
#line 2072 ".//parser.tab.c"
    break;

  case 51: /* expressao: operando  */
#line 559 ".//parser.y"
                 {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added operando to expressao\n"); // Debug print
		 }
#line 2081 ".//parser.tab.c"
    break;

  case 52: /* operando: operador  */
#line 566 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added operador to operando\n"); // Debug print
		}
#line 2090 ".//parser.tab.c"
    break;

  case 53: /* operando: operando OR operador  */
#line 571 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[-1].tree);
			ast_add_child((yyval.tree), (yyvsp[-2].tree));
			ast_add_child((yyval.tree), (yyvsp[0].tree));
			//printf("Added operando and operador to operando\n"); // Debug print
		}
#line 2101 ".//parser.tab.c"
    break;

  case 54: /* operador: comparacao_1  */
#line 582 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added comparacao to operador\n"); // Debug print
		}
#line 2110 ".//parser.tab.c"
    break;

  case 55: /* operador: operador AND comparacao_1  */
#line 587 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[-1].tree);
			ast_add_child((yyval.tree), (yyvsp[-2].tree));
			ast_add_child((yyval.tree), (yyvsp[0].tree));
			//printf("Added operador and comparacao to operador\n"); // Debug print
		}
#line 2121 ".//parser.tab.c"
    break;

  case 56: /* comparacao_1: comparacao_2  */
#line 598 ".//parser.y"
                  {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added comparacao_1 to comparacao_2\n"); // Debug print
		  }
#line 2130 ".//parser.tab.c"
    break;

  case 57: /* comparacao_1: comparacao_1 equal_or_not comparacao_2  */
#line 603 ".//parser.y"
                  {
				(yyval.tree) = (yyvsp[-1].tree);
				ast_add_child((yyval.tree), (yyvsp[-2].tree));
				ast_add_child((yyval.tree), (yyvsp[0].tree));
				//printf("Added comparacao_1, equal_or_not, and comparacao_2 to comparacao_1\n"); // Debug print
		  }
#line 2141 ".//parser.tab.c"
    break;

  case 58: /* equal_or_not: EQUAL  */
#line 611 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added EQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2150 ".//parser.tab.c"
    break;

  case 59: /* equal_or_not: NOTEQUAL  */
#line 616 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2159 ".//parser.tab.c"
    break;

  case 60: /* comparacao_2: adicaousub  */
#line 625 ".//parser.y"
                  {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added adicaousub to comparacao_2\n"); // Debug print
		  }
#line 2168 ".//parser.tab.c"
    break;

  case 61: /* comparacao_2: comparacao_2 greater_or_less adicaousub  */
#line 631 ".//parser.y"
                  {
				(yyval.tree) = (yyvsp[-1].tree);
				ast_add_child((yyval.tree), (yyvsp[-2].tree));
				ast_add_child((yyval.tree), (yyvsp[0].tree));
				//printf("Added comparacao_2, greater_or_less, and adicaousub to comparacao_2\n"); // Debug print
		  }
#line 2179 ".//parser.tab.c"
    break;

  case 62: /* greater_or_less: GREATEREQUAL  */
#line 639 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added EQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2188 ".//parser.tab.c"
    break;

  case 63: /* greater_or_less: LESSEQUAL  */
#line 644 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2197 ".//parser.tab.c"
    break;

  case 64: /* greater_or_less: GREATERTHAN  */
#line 649 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2206 ".//parser.tab.c"
    break;

  case 65: /* greater_or_less: LESSTHAN  */
#line 654 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2215 ".//parser.tab.c"
    break;

  case 66: /* adicaousub: multoudivoures  */
#line 663 ".//parser.y"
                  {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added multoudivoures to adicaousub\n"); // Debug print
		  }
#line 2224 ".//parser.tab.c"
    break;

  case 67: /* adicaousub: adicaousub op_adicaousub multoudivoures  */
#line 668 ".//parser.y"
                  {
					(yyval.tree) = (yyvsp[-1].tree);
					ast_add_child((yyval.tree), (yyvsp[-2].tree));
					ast_add_child((yyval.tree), (yyvsp[0].tree));
					//printf("Added adicaousub, op_adicaousub, and multoudivoures to adicaousub\n"); // Debug print
		  }
#line 2235 ".//parser.tab.c"
    break;

  case 68: /* op_adicaousub: ADD  */
#line 679 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added ADD to op_adicaousub\n"); // Debug print
			 }
#line 2244 ".//parser.tab.c"
    break;

  case 69: /* op_adicaousub: SUBTRACT  */
#line 684 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added SUBTRACT to op_adicaousub\n"); // Debug print
			 }
#line 2253 ".//parser.tab.c"
    break;

  case 70: /* multoudivoures: unario  */
#line 693 ".//parser.y"
                          {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added unario to multoudivoures\n"); // Debug print
			  }
#line 2262 ".//parser.tab.c"
    break;

  case 71: /* multoudivoures: multoudivoures op_multoudivoures unario  */
#line 698 ".//parser.y"
                          {
					(yyval.tree) = (yyvsp[-1].tree);
					ast_add_child((yyval.tree), (yyvsp[-2].tree));
					ast_add_child((yyval.tree), (yyvsp[0].tree));
					//printf("Added multoudivoures, op_multoudivoures, and unario to multoudivoures\n"); // Debug print
			  }
#line 2273 ".//parser.tab.c"
    break;

  case 72: /* op_multoudivoures: MULTIPLY  */
#line 709 ".//parser.y"
                                 {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added MULTIPLY to op_multoudivoures\n"); // Debug print
				 }
#line 2282 ".//parser.tab.c"
    break;

  case 73: /* op_multoudivoures: DIVIDE  */
#line 714 ".//parser.y"
                                 {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added DIVIDE to op_multoudivoures\n"); // Debug print
				 }
#line 2291 ".//parser.tab.c"
    break;

  case 74: /* op_multoudivoures: REMAINDER  */
#line 719 ".//parser.y"
                                 {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added REMAINDER to op_multoudivoures\n"); // Debug print
				 }
#line 2300 ".//parser.tab.c"
    break;

  case 75: /* unario: primario  */
#line 728 ".//parser.y"
          {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added primario to unario\n"); // Debug print
	  }
#line 2309 ".//parser.tab.c"
    break;

  case 76: /* unario: INVERTSIG unario  */
#line 733 ".//parser.y"
          {
			(yyval.tree) = (yyvsp[-1].tree);
		    ast_add_child((yyval.tree), (yyvsp[0].tree));
		    //printf("Added INVERTSIG and unario to unario\n"); // Debug print
	  }
#line 2319 ".//parser.tab.c"
    break;

  case 77: /* unario: NEGATE unario  */
#line 739 ".//parser.y"
          {
			(yyval.tree) = (yyvsp[-1].tree);
		    ast_add_child((yyval.tree), (yyvsp[0].tree));
		    //printf("Added NEGATE and unario to unario\n"); // Debug print
	  }
#line 2329 ".//parser.tab.c"
    break;

  case 78: /* primario: identificador  */
#line 749 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added identificador to primario\n");
		}
#line 2338 ".//parser.tab.c"
    break;

  case 79: /* primario: literais  */
#line 754 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added literais to primario\n"); // Debug print
		}
#line 2347 ".//parser.tab.c"
    break;

  case 80: /* primario: chamada_funcao  */
#line 759 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added chamada_funcao to primario\n"); // Debug print
		}
#line 2356 ".//parser.tab.c"
    break;

  case 81: /* primario: '(' expressao ')'  */
#line 764 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[-1].tree);
			//printf("Added expressao to primario\n"); // Debug print
		}
#line 2365 ".//parser.tab.c"
    break;

  case 82: /* chamada_funcao: nome_func '(' lista_de_argumentos ')'  */
#line 773 ".//parser.y"
                          {
				(yyval.tree) = (yyvsp[-3].tree);
				ast_add_child((yyval.tree), (yyvsp[-1].tree));
				//printf("Added nome_func and lista_de_argumentos to chamada_funcao\n"); // Debug print
			  }
#line 2375 ".//parser.tab.c"
    break;

  case 83: /* chamada_funcao: nome_func '(' ')'  */
#line 779 ".//parser.y"
                          {
				(yyval.tree) = (yyvsp[-2].tree);
				//printf("Added nome_func to chamada_funcao\n"); // Debug print
			  }
#line 2384 ".//parser.tab.c"
    break;

  case 84: /* lista_de_argumentos: expressao  */
#line 788 ".//parser.y"
                           {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added expressao to lista_de_argumentos\n"); // Debug print
			   }
#line 2393 ".//parser.tab.c"
    break;

  case 85: /* lista_de_argumentos: expressao ';' lista_de_argumentos  */
#line 793 ".//parser.y"
                           {
				if ((yyvsp[0].tree) == NULL)
				{
					(yyval.tree) = (yyvsp[-2].tree); 
				}
				else
				{
					if ((yyvsp[-2].tree) == NULL)
					{
						(yyval.tree) = (yyvsp[0].tree);
					}
					else
					{
						(yyval.tree) = (yyvsp[-2].tree);
						ast_add_child((yyvsp[-2].tree), (yyvsp[0].tree));
					}
				}
				//printf("Added lista_de_argumentos and expressao to lista_de_argumentos\n"); // Debug print
			   }
#line 2417 ".//parser.tab.c"
    break;

  case 86: /* nome_func: call_identificador  */
#line 817 ".//parser.y"
                 {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added identificador to nome_func\n"); // Debug print
		 }
#line 2426 ".//parser.tab.c"
    break;

  case 87: /* literais: LITINT  */
#line 826 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added LITINT to literais\n"); // Debug print
		}
#line 2435 ".//parser.tab.c"
    break;

  case 88: /* literais: LITFLOAT  */
#line 831 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added LITFLOAT to literais\n"); // Debug print
		}
#line 2444 ".//parser.tab.c"
    break;

  case 89: /* literais: LITFALSE  */
#line 836 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added LITFALSE to literais\n"); // Debug print
		}
#line 2453 ".//parser.tab.c"
    break;

  case 90: /* literais: LITTRUE  */
#line 841 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added LITTRUE to literais\n"); // Debug print
		}
#line 2462 ".//parser.tab.c"
    break;

  case 91: /* LITINT: TK_LIT_INT  */
#line 850 ".//parser.y"
          {
			(yyval.tree) = ast_new((yyvsp[0].valor_lexico));
			//printf("Added TK_LIT_INT to LITINT\n"); // Debug print
	  }
#line 2471 ".//parser.tab.c"
    break;

  case 92: /* LITFLOAT: TK_LIT_FLOAT  */
#line 859 ".//parser.y"
                {
			(yyval.tree) = ast_new((yyvsp[0].valor_lexico));
			//printf("Added TK_LIT_FLOAT to LITFLOAT\n"); // Debug print
		}
#line 2480 ".//parser.tab.c"
    break;

  case 93: /* LITFALSE: TK_LIT_FALSE  */
#line 868 ".//parser.y"
                {
			(yyval.tree) = ast_new((yyvsp[0].valor_lexico));
			//printf("Added TK_LIT_FALSE to LITFALSE\n"); // Debug print
		}
#line 2489 ".//parser.tab.c"
    break;

  case 94: /* LITTRUE: TK_LIT_TRUE  */
#line 877 ".//parser.y"
           {
			(yyval.tree) = ast_new((yyvsp[0].valor_lexico));
			//printf("Added TK_LIT_TRUE to LITTRUE\n"); // Debug print
	   }
#line 2498 ".//parser.tab.c"
    break;

  case 95: /* INVERTSIG: '-'  */
#line 886 ".//parser.y"
                 {
				(yyval.tree) = ast_new_label_only("-");
				//printf("Label INVERTSIG\n"); // Debug print
		 }
#line 2507 ".//parser.tab.c"
    break;

  case 96: /* NEGATE: '!'  */
#line 892 ".//parser.y"
          {
			(yyval.tree) = ast_new_label_only("!");
			//printf("Label NEGATE\n"); // Debug print
	  }
#line 2516 ".//parser.tab.c"
    break;

  case 97: /* MULTIPLY: '*'  */
#line 898 ".//parser.y"
                {
			(yyval.tree) = ast_new_label_only("*");
			//printf("Label MULTIPLY\n"); // Debug print
		}
#line 2525 ".//parser.tab.c"
    break;

  case 98: /* DIVIDE: '/'  */
#line 904 ".//parser.y"
          {
			(yyval.tree) = ast_new_label_only("/");
			//printf("Label DIVIDE\n"); // Debug print
	  }
#line 2534 ".//parser.tab.c"
    break;

  case 99: /* REMAINDER: '%'  */
#line 910 ".//parser.y"
                 {
				(yyval.tree) = ast_new_label_only("%");
				//printf("Label REMAINDER\n"); // Debug print
		 }
#line 2543 ".//parser.tab.c"
    break;

  case 100: /* ADD: '+'  */
#line 916 ".//parser.y"
   {
		(yyval.tree) = ast_new_label_only("+");
		//printf("Label ADD\n"); // Debug print
   }
#line 2552 ".//parser.tab.c"
    break;

  case 101: /* SUBTRACT: '-'  */
#line 922 ".//parser.y"
                {
			(yyval.tree) = ast_new_label_only("-");
			//printf("Label SUBTRACT\n"); // Debug print
		}
#line 2561 ".//parser.tab.c"
    break;

  case 102: /* GREATERTHAN: '>'  */
#line 928 ".//parser.y"
                   {
				(yyval.tree) = ast_new_label_only(">");
				//printf("Label GREATERTHAN\n"); // Debug print
		   }
#line 2570 ".//parser.tab.c"
    break;

  case 103: /* LESSTHAN: '<'  */
#line 934 ".//parser.y"
                {
			(yyval.tree) = ast_new_label_only("<");
			//printf("Label LESSTHAN\n"); // Debug print
		}
#line 2579 ".//parser.tab.c"
    break;

  case 104: /* LESSEQUAL: TK_OC_LE  */
#line 940 ".//parser.y"
                 {
		 	(yyval.tree) = ast_new_label_only("<=");
			//printf("Label 'LESSEQUAL'\n"); // Debug print
		 }
#line 2588 ".//parser.tab.c"
    break;

  case 105: /* GREATEREQUAL: TK_OC_GE  */
#line 946 ".//parser.y"
                        {
				(yyval.tree) = ast_new_label_only(">=");
				//printf("Label 'GREATEREQUAL'\n"); // Debug print
			}
#line 2597 ".//parser.tab.c"
    break;

  case 106: /* EQUAL: TK_OC_EQ  */
#line 952 ".//parser.y"
         {
		(yyval.tree) = ast_new_label_only("==");
		//printf("Label 'EQUAL'\n"); // Debug print
	 }
#line 2606 ".//parser.tab.c"
    break;

  case 107: /* NOTEQUAL: TK_OC_NE  */
#line 958 ".//parser.y"
                {
			(yyval.tree) = ast_new_label_only("!=");
			//printf("Label 'NOTEQUAL'\n"); // Debug print
		}
#line 2615 ".//parser.tab.c"
    break;

  case 108: /* AND: TK_OC_AND  */
#line 964 ".//parser.y"
   {
		(yyval.tree) = ast_new_label_only("&");
		//printf("Label 'AND'\n"); // Debug print
   }
#line 2624 ".//parser.tab.c"
    break;


#line 2628 ".//parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 969 ".//parser.y"


//##########################
// Função de tratamento de erro
int yyerror(char const *s){
    printf("%s on line %d \n", s, get_line_number());
    return 1;
}
