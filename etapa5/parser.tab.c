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
  YYSYMBOL_raiz = 38,                      /* raiz  */
  YYSYMBOL_programa = 39,                  /* programa  */
  YYSYMBOL_lista_de_elementos = 40,        /* lista_de_elementos  */
  YYSYMBOL_elemento = 41,                  /* elemento  */
  YYSYMBOL_declaracao_global = 42,         /* declaracao_global  */
  YYSYMBOL_identificador = 43,             /* identificador  */
  YYSYMBOL_identificador_func = 44,        /* identificador_func  */
  YYSYMBOL_call_identificador = 45,        /* call_identificador  */
  YYSYMBOL_tipo = 46,                      /* tipo  */
  YYSYMBOL_INT = 47,                       /* INT  */
  YYSYMBOL_FLOAT = 48,                     /* FLOAT  */
  YYSYMBOL_BOOL = 49,                      /* BOOL  */
  YYSYMBOL_lista_identificador = 50,       /* lista_identificador  */
  YYSYMBOL_definicao_de_funcao = 51,       /* definicao_de_funcao  */
  YYSYMBOL_cabecalho = 52,                 /* cabecalho  */
  YYSYMBOL_criar_escopo = 53,              /* criar_escopo  */
  YYSYMBOL_fechar_escopo = 54,             /* fechar_escopo  */
  YYSYMBOL_criar_pilha = 55,               /* criar_pilha  */
  YYSYMBOL_fechar_pilha = 56,              /* fechar_pilha  */
  YYSYMBOL_OR = 57,                        /* OR  */
  YYSYMBOL_lista_de_parametros = 58,       /* lista_de_parametros  */
  YYSYMBOL_parametro = 59,                 /* parametro  */
  YYSYMBOL_corpo = 60,                     /* corpo  */
  YYSYMBOL_bloco_de_comandos = 61,         /* bloco_de_comandos  */
  YYSYMBOL_lista_de_comandos = 62,         /* lista_de_comandos  */
  YYSYMBOL_comando_simples = 63,           /* comando_simples  */
  YYSYMBOL_declaracao_variavel = 64,       /* declaracao_variavel  */
  YYSYMBOL_lista_identificador_local = 65, /* lista_identificador_local  */
  YYSYMBOL_comando_atribuicao = 66,        /* comando_atribuicao  */
  YYSYMBOL_RETURN = 67,                    /* RETURN  */
  YYSYMBOL_comando_retorno = 68,           /* comando_retorno  */
  YYSYMBOL_comando_controle_fluxo = 69,    /* comando_controle_fluxo  */
  YYSYMBOL_IF = 70,                        /* IF  */
  YYSYMBOL_ELSE = 71,                      /* ELSE  */
  YYSYMBOL_condicional = 72,               /* condicional  */
  YYSYMBOL_WHILE = 73,                     /* WHILE  */
  YYSYMBOL_loop = 74,                      /* loop  */
  YYSYMBOL_expressao = 75,                 /* expressao  */
  YYSYMBOL_operando = 76,                  /* operando  */
  YYSYMBOL_operador = 77,                  /* operador  */
  YYSYMBOL_comparacao_1 = 78,              /* comparacao_1  */
  YYSYMBOL_equal_or_not = 79,              /* equal_or_not  */
  YYSYMBOL_comparacao_2 = 80,              /* comparacao_2  */
  YYSYMBOL_greater_or_less = 81,           /* greater_or_less  */
  YYSYMBOL_adicaousub = 82,                /* adicaousub  */
  YYSYMBOL_op_adicaousub = 83,             /* op_adicaousub  */
  YYSYMBOL_multoudivoures = 84,            /* multoudivoures  */
  YYSYMBOL_op_multoudivoures = 85,         /* op_multoudivoures  */
  YYSYMBOL_unario = 86,                    /* unario  */
  YYSYMBOL_primario = 87,                  /* primario  */
  YYSYMBOL_chamada_funcao = 88,            /* chamada_funcao  */
  YYSYMBOL_lista_de_argumentos = 89,       /* lista_de_argumentos  */
  YYSYMBOL_nome_func = 90,                 /* nome_func  */
  YYSYMBOL_literais = 91,                  /* literais  */
  YYSYMBOL_LITINT = 92,                    /* LITINT  */
  YYSYMBOL_LITFLOAT = 93,                  /* LITFLOAT  */
  YYSYMBOL_LITFALSE = 94,                  /* LITFALSE  */
  YYSYMBOL_LITTRUE = 95,                   /* LITTRUE  */
  YYSYMBOL_INVERTSIG = 96,                 /* INVERTSIG  */
  YYSYMBOL_NEGATE = 97,                    /* NEGATE  */
  YYSYMBOL_MULTIPLY = 98,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 99,                    /* DIVIDE  */
  YYSYMBOL_REMAINDER = 100,                /* REMAINDER  */
  YYSYMBOL_ADD = 101,                      /* ADD  */
  YYSYMBOL_SUBTRACT = 102,                 /* SUBTRACT  */
  YYSYMBOL_GREATERTHAN = 103,              /* GREATERTHAN  */
  YYSYMBOL_LESSTHAN = 104,                 /* LESSTHAN  */
  YYSYMBOL_LESSEQUAL = 105,                /* LESSEQUAL  */
  YYSYMBOL_GREATEREQUAL = 106,             /* GREATEREQUAL  */
  YYSYMBOL_EQUAL = 107,                    /* EQUAL  */
  YYSYMBOL_NOTEQUAL = 108,                 /* NOTEQUAL  */
  YYSYMBOL_AND = 109                       /* AND  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 14 ".//parser.y"

#include <stdlib.h>
#include <stdio.h>
#include "sym_stack.h"
#include "sym_table.h"
#include "tree.h"
#include "gen_code.h"


//Tamanho do Buffer para Operações

#define OPCODE_SIZE_OF_BUFFER 64


// Protótipos das funções necessárias
int yylex(void);
int yyerror(char const *s);
extern int get_line_number(void);

int symbol_type_now; // Mantemos conta de quem é o tipo do símbolo no momento

extern char *yytext;
extern void *arvore;
stack_of_tables_t *stack_of_tables;
static int *label_counter = 0;
static int *temp_counter = 0;
int initial_space = 0;
int final_space = 0;
int current_opcode = 0;


#line 244 ".//parser.tab.c"


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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

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
       0,   155,   155,   163,   169,   178,   199,   208,   213,   222,
     231,   240,   255,   263,   270,   277,   287,   296,   305,   315,
     327,   344,   357,   367,   377,   386,   395,   403,   412,   430,
     436,   445,   467,   472,   483,   487,   496,   501,   524,   529,
     534,   539,   544,   549,   558,   565,   577,   594,   628,   634,
     645,   650,   659,   665,   671,   679,   692,   698,   750,   757,
     762,   780,   785,   804,   809,   824,   830,   840,   845,   861,
     867,   873,   879,   889,   894,   914,   920,   930,   935,   954,
     960,   966,   975,   980,   987,   998,  1044,  1049,  1054,  1064,
    1118,  1170,  1175,  1199,  1208,  1213,  1218,  1223,  1232,  1249,
    1259,  1269,  1279,  1285,  1291,  1297,  1303,  1309,  1315,  1321,
    1327,  1333,  1339,  1345,  1351,  1357
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
  "')'", "'{'", "'}'", "$accept", "raiz", "programa", "lista_de_elementos",
  "elemento", "declaracao_global", "identificador", "identificador_func",
  "call_identificador", "tipo", "INT", "FLOAT", "BOOL",
  "lista_identificador", "definicao_de_funcao", "cabecalho",
  "criar_escopo", "fechar_escopo", "criar_pilha", "fechar_pilha", "OR",
  "lista_de_parametros", "parametro", "corpo", "bloco_de_comandos",
  "lista_de_comandos", "comando_simples", "declaracao_variavel",
  "lista_identificador_local", "comando_atribuicao", "RETURN",
  "comando_retorno", "comando_controle_fluxo", "IF", "ELSE", "condicional",
  "WHILE", "loop", "expressao", "operando", "operador", "comparacao_1",
  "equal_or_not", "comparacao_2", "greater_or_less", "adicaousub",
  "op_adicaousub", "multoudivoures", "op_multoudivoures", "unario",
  "primario", "chamada_funcao", "lista_de_argumentos", "nome_func",
  "literais", "LITINT", "LITFLOAT", "LITFALSE", "LITTRUE", "INVERTSIG",
  "NEGATE", "MULTIPLY", "DIVIDE", "REMAINDER", "ADD", "SUBTRACT",
  "GREATERTHAN", "LESSTHAN", "LESSEQUAL", "GREATEREQUAL", "EQUAL",
  "NOTEQUAL", "AND", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-37)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -78,    27,   -78,   -78,     9,   -78,   -78,   -78,   -78,   -78,
       9,   -78,     8,   -78,   -78,   -78,   -78,    -3,     3,   -78,
     -78,   -78,   -78,    17,    35,    16,    15,   -78,   -78,     8,
     -78,   -78,   -78,    33,    43,   -78,     8,    -3,    34,   -78,
      38,   -78,   -78,    72,   -78,   -78,    46,   -78,    47,   -78,
     -78,    50,    35,   -78,     8,    -4,   -78,   -78,    72,   -78,
      52,    16,   -78,    59,   -78,   -78,   -78,   -78,   -78,   -78,
      72,   -78,   -78,    71,    73,    42,     5,     6,    36,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,    72,    72,    72,
      72,    48,    53,   -78,    15,    71,   -78,     8,   -78,   -78,
      54,   -78,    72,   -78,    72,   -78,   -78,    72,   -78,   -78,
     -78,   -78,   -78,   -78,    72,   -78,   -78,   -78,   -78,   -78,
     -78,    72,   -78,   -78,   -78,   -78,   -78,    72,   -78,   -78,
     -78,   -78,   -78,    57,    58,   -78,    62,    69,   -78,   -78,
      15,   -78,   -78,    73,    42,     5,     6,    36,   -78,   -78,
     -78,    72,   -78,    82,    -3,    -3,   -78,    80,    16,    16,
     -78,   -78,   100,   -78,   -78,   -78,    -3,    16,   -78
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      25,     0,    23,     1,     4,    16,    17,    18,    24,     3,
       6,     7,     0,    13,    14,    15,     8,     0,     0,    26,
       5,    10,    20,     0,    23,    24,    30,     2,     9,     0,
      52,    56,    48,    10,     0,    93,     0,     0,     0,    35,
       0,    38,    39,     0,    41,    42,     0,    50,     0,    51,
      40,     0,    23,    21,     0,     0,    29,    19,     0,    46,
      44,    24,    32,    23,   103,   102,    98,    99,   100,   101,
       0,    85,    49,    58,    59,    61,    63,    67,    73,    77,
      82,    87,    86,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    31,     0,     0,    47,     0,    43,    37,
       0,    27,     0,   115,     0,   113,   114,     0,    65,    66,
     111,   112,   110,   109,     0,    71,    72,    70,    69,   107,
     108,     0,    75,    76,   104,   105,   106,     0,    79,    80,
      81,    83,    84,     0,     0,    90,    91,     0,    33,    28,
       0,    45,    88,    60,    62,    64,    68,    74,    78,    23,
      23,     0,    89,     0,     0,     0,    92,     0,    24,    24,
      11,    22,    54,    57,    53,    23,     0,    24,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,    98,   -78,   -78,    -7,   -78,   -78,    -1,
     -78,   -78,   -78,   -78,   -78,   -78,    -2,   -24,   -78,   -78,
      14,   -78,    18,   -33,    61,    51,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -37,   -78,
      13,     7,   -78,    10,   -78,     2,   -78,   -11,   -78,   -77,
     -78,   -17,   -32,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     8,     9,    10,    11,    71,   161,    35,    36,
      13,    14,    15,    23,    16,    17,    37,    19,     2,    27,
     102,    55,    56,    25,    38,    39,    40,    41,    60,    42,
      43,    44,    45,    46,   165,    47,    48,    49,   136,    73,
      74,    75,   107,    76,   114,    77,   121,    78,   127,    79,
      80,    81,   137,    51,    82,    83,    84,    85,    86,    87,
      88,   128,   129,   130,   122,   123,   115,   116,   117,   118,
     108,   109,   104
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       4,    53,    18,    12,    61,    22,    72,    50,    18,    12,
     131,   132,     5,     6,     7,   110,   111,    34,     5,     6,
       7,    96,    57,   112,   113,    54,   119,     3,    94,    59,
      95,   120,    24,   100,    21,    50,    26,    98,     5,     6,
       7,    30,   -23,    31,    32,    34,    50,    93,    28,    29,
     148,    52,   133,   134,   105,   106,    34,   124,   125,   126,
      58,    33,     5,     6,     7,    30,   -12,    31,    32,    63,
      62,   -34,    64,    65,    33,    66,    67,    68,    69,    89,
      90,    70,   135,    91,    97,    33,   101,   103,   142,   138,
     141,   149,   150,    54,   151,   -36,    64,    65,    33,    66,
      67,    68,    69,   152,   157,    70,   160,   164,    20,   140,
     147,   144,   139,    92,    99,   143,   146,   145,     0,   156,
       0,   158,   159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   167,   162,   163,     0,     0,     0,   153,
       0,     0,     0,   168,     0,     0,     0,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   166
};

static const yytype_int16 yycheck[] =
{
       2,    25,     4,     4,    37,    12,    43,    24,    10,    10,
      87,    88,     3,     4,     5,    10,    11,    24,     3,     4,
       5,    58,    29,    18,    19,    26,    20,     0,    32,    36,
      34,    25,    35,    70,    26,    52,    33,    61,     3,     4,
       5,     6,    33,     8,     9,    52,    63,    54,    31,    32,
     127,    35,    89,    90,    12,    13,    63,    21,    22,    23,
      17,    26,     3,     4,     5,     6,    33,     8,     9,    31,
      36,    36,    24,    25,    26,    27,    28,    29,    30,    33,
      33,    33,    34,    33,    32,    26,    15,    14,    34,    36,
      97,    34,    34,    94,    32,    36,    24,    25,    26,    27,
      28,    29,    30,    34,    22,    33,    26,     7,    10,    95,
     121,   104,    94,    52,    63,   102,   114,   107,    -1,   151,
      -1,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   158,   159,    -1,    -1,    -1,   140,
      -1,    -1,    -1,   167,    -1,    -1,    -1,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   165
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    55,     0,    53,     3,     4,     5,    39,    40,
      41,    42,    46,    47,    48,    49,    51,    52,    53,    54,
      40,    26,    43,    50,    35,    60,    33,    56,    31,    32,
       6,     8,     9,    26,    43,    45,    46,    53,    61,    62,
      63,    64,    66,    67,    68,    69,    70,    72,    73,    74,
      88,    90,    35,    54,    46,    58,    59,    43,    17,    43,
      65,    60,    36,    31,    24,    25,    27,    28,    29,    30,
      33,    43,    75,    76,    77,    78,    80,    82,    84,    86,
      87,    88,    91,    92,    93,    94,    95,    96,    97,    33,
      33,    33,    61,    43,    32,    34,    75,    32,    54,    62,
      75,    15,    57,    14,   109,    12,    13,    79,   107,   108,
      10,    11,    18,    19,    81,   103,   104,   105,   106,    20,
      25,    83,   101,   102,    21,    22,    23,    85,    98,    99,
     100,    86,    86,    75,    75,    34,    75,    89,    36,    59,
      57,    43,    34,    77,    78,    80,    82,    84,    86,    34,
      34,    32,    34,    46,    53,    53,    89,    22,    60,    60,
      26,    44,    54,    54,     7,    71,    53,    60,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      43,    44,    45,    46,    46,    46,    47,    48,    49,    50,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    58,
      58,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    64,    65,    65,    66,    67,    68,
      69,    69,    70,    71,    72,    72,    73,    74,    75,    76,
      76,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    81,    81,    82,    82,    83,    83,    84,    84,    85,
      85,    85,    86,    86,    86,    87,    87,    87,    87,    88,
      88,    89,    89,    90,    91,    91,    91,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     1,     0,     2,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     8,     0,     0,     0,     0,     1,     3,     1,
       0,     2,     3,     4,     0,     1,     2,     3,     1,     1,
       1,     1,     1,     3,     2,     3,     1,     3,     1,     2,
       1,     1,     1,     1,     7,    11,     1,     7,     1,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     2,     2,     1,     1,     1,     3,     4,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  case 2: /* raiz: criar_pilha criar_escopo programa fechar_escopo fechar_pilha  */
#line 156 ".//parser.y"
        {
		(yyval.tree) = (yyvsp[-2].tree);
		arvore = (yyval.tree);
	}
#line 1608 ".//parser.tab.c"
    break;

  case 3: /* programa: lista_de_elementos  */
#line 164 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Created ARVORE node\n"); // Debug print
		}
#line 1617 ".//parser.tab.c"
    break;

  case 4: /* programa: %empty  */
#line 169 ".//parser.y"
                {
			(yyval.tree) = NULL; // Se não houver elementos, o programa é nulo
			arvore = NULL;
			//printf("Empty arvore\n"); // Debug print
		}
#line 1627 ".//parser.tab.c"
    break;

  case 5: /* lista_de_elementos: elemento lista_de_elementos  */
#line 179 ".//parser.y"
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
                            (yyval.tree)->code = append_node_operation((yyvsp[-1].tree), (yyvsp[0].tree));
							//printf("Added elemento to lista_de_elementos\n"); // Debug print
						}
					}	
				  }
#line 1652 ".//parser.tab.c"
    break;

  case 6: /* lista_de_elementos: elemento  */
#line 200 ".//parser.y"
                                  {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added elemento to lista_de_elementos\n"); // Debug print
				  }
#line 1661 ".//parser.tab.c"
    break;

  case 7: /* elemento: declaracao_global  */
#line 209 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added declaracao_global to elemento\n"); // Debug print
		}
#line 1670 ".//parser.tab.c"
    break;

  case 8: /* elemento: definicao_de_funcao  */
#line 214 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added definicao_de_funcao to elemento\n"); // Debug print
		}
#line 1679 ".//parser.tab.c"
    break;

  case 9: /* declaracao_global: tipo lista_identificador ','  */
#line 223 ".//parser.y"
                                 {
					(yyval.tree) = NULL; // Não há ações associadas à declaração global
					//printf("Added tipo and lista_identificador to declaracao_global\n"); // Debug print
				 }
#line 1688 ".//parser.tab.c"
    break;

  case 10: /* identificador: TK_IDENTIFICADOR  */
#line 232 ".//parser.y"
                         {
				(yyval.tree) = ast_new((yyvsp[0].valor_lexico)); // Cria um novo nó na árvore com o identificador
				//printf("Added TK_IDENTIFICADOR to identificador\n"); // Debug print
			 }
#line 1697 ".//parser.tab.c"
    break;

  case 11: /* identificador_func: TK_IDENTIFICADOR  */
#line 241 ".//parser.y"
                  {
                        (yyval.tree) = ast_new((yyvsp[0].valor_lexico)); // Cria um novo nó na árvore com o identificador
				        //printf("Added TK_IDENTIFICADOR to identificador\n"); // Debug print
						char *new_key = strdup((yyval.tree)->valor_lexico->token_value);
                        //printf("In the Hood We ballling[%s]\n\n", new_key);
						if(find_symbol(stack_of_tables->tables[0], new_key) != NULL)
            			{
                			printf("[ERR_DECLARED] Funcao [%s] na linha %d ja foi declarada neste scope\n", new_key, get_line_number());
                			exit(ERR_DECLARED);
            			}
						insert_symbol(stack_of_tables->tables[0], new_key, create_symbol((yyval.tree),TOKEN_NATURE_FUNCTION, symbol_type_now));
                  }
#line 1714 ".//parser.tab.c"
    break;

  case 12: /* call_identificador: TK_IDENTIFICADOR  */
#line 256 ".//parser.y"
                        {
				(yyval.tree) = ast_new_call_func((yyvsp[0].valor_lexico)); // Cria um novo nó representando uma chamada de função com o identificador
				//printf("Added TK_IDENTIFICADOR to identificador\n"); // Debug print
			}
#line 1723 ".//parser.tab.c"
    break;

  case 13: /* tipo: INT  */
#line 264 ".//parser.y"
        {
		(yyval.tree) = (yyvsp[0].tree);
        symbol_type_now = TYPE_INT;

		//printf("Added INT to tipo\n"); // Debug print
	}
#line 1734 ".//parser.tab.c"
    break;

  case 14: /* tipo: FLOAT  */
#line 271 ".//parser.y"
        {
		(yyval.tree) = (yyvsp[0].tree);
        symbol_type_now = TYPE_FLOAT;

		//printf("Added FLOAT to tipo\n"); // Debug print
	}
#line 1745 ".//parser.tab.c"
    break;

  case 15: /* tipo: BOOL  */
#line 278 ".//parser.y"
        {
		(yyval.tree) = (yyvsp[0].tree);
        symbol_type_now = TYPE_BOOL;
		//printf("Added BOOL to tipo\n"); // Debug print
	}
#line 1755 ".//parser.tab.c"
    break;

  case 16: /* INT: TK_PR_INT  */
#line 288 ".//parser.y"
   {
		(yyval.tree) = NULL; // Espero que seja null mesmo.
		//printf("Empty INT\n"); // Debug print
   }
#line 1764 ".//parser.tab.c"
    break;

  case 17: /* FLOAT: TK_PR_FLOAT  */
#line 297 ".//parser.y"
         {
		(yyval.tree) = NULL; // Espero que seja null mesmo.
		//printf("Empty FLOAT\n"); // Debug print
	 }
#line 1773 ".//parser.tab.c"
    break;

  case 18: /* BOOL: TK_PR_BOOL  */
#line 306 ".//parser.y"
        {
		(yyval.tree) = NULL; // Espero que seja null mesmo.
		//printf("Empty BOOL\n"); // Debug print
	}
#line 1782 ".//parser.tab.c"
    break;

  case 19: /* lista_identificador: lista_identificador ';' identificador  */
#line 316 ".//parser.y"
                                   {
					    (yyval.tree) = (yyvsp[-2].tree); // Se houver uma lista de identificadores existente nós as mantemos
					    //printf("Added identificador and lista_identificador to lista_identificador\n"); // Debug print
                        char* new_key = strdup((yyvsp[0].tree)->valor_lexico->token_value);
                        //printf("In the Hood [%s]\n\n", new_key);
                        if(find_symbol(stack_of_tables->top, new_key) != NULL){
                            printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
                            exit(ERR_DECLARED);
                        }
                        insert_symbol(stack_of_tables->tables[0], new_key, create_symbol((yyvsp[0].tree),TOKEN_NATURE_IDENTIFIER, symbol_type_now));
				   }
#line 1798 ".//parser.tab.c"
    break;

  case 20: /* lista_identificador: identificador  */
#line 328 ".//parser.y"
                                   {
					    (yyval.tree) = (yyvsp[0].tree);
                        char* new_key = strdup((yyvsp[0].tree)->valor_lexico->token_value);
                        //printf("In the Hood [%s]\n\n", new_key);
                        if(find_symbol(stack_of_tables->top, new_key) != NULL){
                            printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
                            exit(ERR_DECLARED);
                        }

                        insert_symbol(stack_of_tables->tables[0], new_key, create_symbol((yyvsp[0].tree),TOKEN_NATURE_IDENTIFIER, symbol_type_now));
					    //printf("Added identificador to lista_identificador\n"); // Debug print
				   }
#line 1815 ".//parser.tab.c"
    break;

  case 21: /* definicao_de_funcao: cabecalho corpo fechar_escopo  */
#line 345 ".//parser.y"
                                   {

						(yyval.tree) = (yyvsp[-2].tree); // Define a definição de função como o cabeçalho
						if ((yyvsp[-1].tree) != NULL){
							ast_add_child((yyval.tree), (yyvsp[-1].tree)); // Se houver corpo , adiciona o corpo como filho da definição de função
						}
						//printf("Added cabecalho and corpo to definicao_de_funcao\n"); // Debug print
				   }
#line 1828 ".//parser.tab.c"
    break;

  case 22: /* cabecalho: criar_escopo '(' lista_de_parametros ')' OR tipo '/' identificador_func  */
#line 358 ".//parser.y"
                 {
			(yyval.tree) = (yyvsp[0].tree); // Define o cabeçalho como o identificador
			//printf("Added lista_de_parametros, tipo and identificador to cabecalho\n"); // Debug print
		 }
#line 1837 ".//parser.tab.c"
    break;

  case 23: /* criar_escopo: %empty  */
#line 367 ".//parser.y"
           {
                (yyval.tree) = NULL;
                table_of_symbols_t *new_scope = create_table_of_symbols(stack_of_tables->top);
                push_scope(stack_of_tables,new_scope);
           }
#line 1847 ".//parser.tab.c"
    break;

  case 24: /* fechar_escopo: %empty  */
#line 377 ".//parser.y"
           {
                (yyval.tree) = NULL;
                pop_scope(stack_of_tables);
           }
#line 1856 ".//parser.tab.c"
    break;

  case 25: /* criar_pilha: %empty  */
#line 386 ".//parser.y"
           {   
                (yyval.tree) = NULL;
                stack_of_tables = create_stack_of_tables();
           }
#line 1865 ".//parser.tab.c"
    break;

  case 26: /* fechar_pilha: %empty  */
#line 395 ".//parser.y"
           {   
                (yyval.tree) = NULL;
                free_stack_of_tables(stack_of_tables);
           }
#line 1874 ".//parser.tab.c"
    break;

  case 27: /* OR: TK_OC_OR  */
#line 404 ".//parser.y"
  {
  	(yyval.tree) = ast_new_label_only("|");
	//printf("Label OR\n"); // Debug print
  }
#line 1883 ".//parser.tab.c"
    break;

  case 28: /* lista_de_parametros: lista_de_parametros ';' parametro  */
#line 413 ".//parser.y"
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
#line 1905 ".//parser.tab.c"
    break;

  case 29: /* lista_de_parametros: parametro  */
#line 431 ".//parser.y"
                                   {
						(yyval.tree) = (yyvsp[0].tree);
						//printf("Added parametro to lista_de_parametros\n"); // Debug print
				   }
#line 1914 ".//parser.tab.c"
    break;

  case 30: /* lista_de_parametros: %empty  */
#line 436 ".//parser.y"
                                   {
						(yyval.tree) = NULL;
						//printf("lista_de_parametros is empty\n"); // Debug print
				   }
#line 1923 ".//parser.tab.c"
    break;

  case 31: /* parametro: tipo identificador  */
#line 446 ".//parser.y"
         {
			(yyval.tree) = (yyvsp[-1].tree);
			ast_add_child((yyval.tree), (yyvsp[0].tree));
            char *new_key = strdup((yyvsp[0].tree)->valor_lexico->token_value);
            if(find_symbol(stack_of_tables->top, new_key) != NULL)
            {
               printf("[ERR_DECLARED] Funcao [%s] na linha %d ja foi declarada neste scope\n", new_key, get_line_number());
               exit(ERR_DECLARED);
            }
            //printf("In the Hood Param [%s]\n\n", new_key);
            insert_symbol(stack_of_tables->top, new_key, create_symbol((yyvsp[0].tree),TOKEN_NATURE_IDENTIFIER, symbol_type_now));
            int nature = stack_of_tables->top->items[0]->content->nature;
            //printf("Nature Wtf %d\n\n" , nature);
			//printf("Added tipo and identificador to parametro\n"); // Debug print
            //free($2->valor_lexico->token_value); 
            //free($2->valor_lexico); 
            //free($2);
		 }
#line 1946 ".//parser.tab.c"
    break;

  case 32: /* corpo: '{' bloco_de_comandos '}'  */
#line 468 ".//parser.y"
         {
		(yyval.tree) = (yyvsp[-1].tree);
		//printf("Added bloco_de_comandos to corpo\n"); // Debug print
	 }
#line 1955 ".//parser.tab.c"
    break;

  case 33: /* corpo: corpo '{' bloco_de_comandos '}'  */
#line 473 ".//parser.y"
         {
		(yyval.tree) = (yyvsp[-3].tree);
		ast_add_child((yyval.tree), (yyvsp[-1].tree));
		//printf("Added bloco_de_comandos to corpo\n"); // Debug print
	 }
#line 1965 ".//parser.tab.c"
    break;

  case 34: /* bloco_de_comandos: %empty  */
#line 483 ".//parser.y"
                                 {
					(yyval.tree) = NULL;
					//printf("Empty bloco_de_comandos\n"); // Debug print
				 }
#line 1974 ".//parser.tab.c"
    break;

  case 35: /* bloco_de_comandos: lista_de_comandos  */
#line 488 ".//parser.y"
                                 {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added lista_de_comandos to bloco_de_comandos\n"); // Debug print
				 }
#line 1983 ".//parser.tab.c"
    break;

  case 36: /* lista_de_comandos: comando_simples ','  */
#line 497 ".//parser.y"
                                 {
					(yyval.tree) = (yyvsp[-1].tree); // O resultado é o comando simples
					//printf("Added comando_simples to lista_de_comandos\n"); // Debug print
				 }
#line 1992 ".//parser.tab.c"
    break;

  case 37: /* lista_de_comandos: comando_simples ',' lista_de_comandos  */
#line 502 ".//parser.y"
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
#line 2015 ".//parser.tab.c"
    break;

  case 38: /* comando_simples: declaracao_variavel  */
#line 525 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added declaracao_variavel to comando_simples\n"); // Debug print
			   }
#line 2024 ".//parser.tab.c"
    break;

  case 39: /* comando_simples: comando_atribuicao  */
#line 530 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added comando_atribuicao to comando_simples\n"); // Debug print
			   }
#line 2033 ".//parser.tab.c"
    break;

  case 40: /* comando_simples: chamada_funcao  */
#line 535 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added comando_funcao to comando_simples\n"); // Debug print
			   }
#line 2042 ".//parser.tab.c"
    break;

  case 41: /* comando_simples: comando_retorno  */
#line 540 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added comando_retorno to comando_simples\n"); // Debug print
			   }
#line 2051 ".//parser.tab.c"
    break;

  case 42: /* comando_simples: comando_controle_fluxo  */
#line 545 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added comando_controle_fluxo to comando_simples\n"); // Debug print
			   }
#line 2060 ".//parser.tab.c"
    break;

  case 43: /* comando_simples: criar_escopo corpo fechar_escopo  */
#line 550 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[-1].tree);
					//printf("Added corpo to comando_simples\n"); // Debug print
			   }
#line 2069 ".//parser.tab.c"
    break;

  case 44: /* declaracao_variavel: tipo lista_identificador_local  */
#line 559 ".//parser.y"
                                   {
						(yyval.tree) = NULL;
						//printf("Empty declaracao_variavel\n"); // Debug print
				   }
#line 2078 ".//parser.tab.c"
    break;

  case 45: /* lista_identificador_local: lista_identificador_local ';' identificador  */
#line 566 ".//parser.y"
                                   {
					    (yyval.tree) = (yyvsp[-2].tree); // Se houver uma lista de identificadores existente nós as mantemos
					    //printf("Added identificador and lista_identificador to lista_identificador\n"); // Debug print
                        char* new_key = strdup((yyvsp[0].tree)->valor_lexico->token_value);
                        //printf("In the Hood Local List[%s]\n\n", new_key);
                        if(find_symbol(stack_of_tables->top, new_key) != NULL){
                            printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
                            exit(ERR_DECLARED);
                         }
                        insert_symbol(stack_of_tables->top, new_key, create_symbol((yyvsp[0].tree),TOKEN_NATURE_IDENTIFIER, symbol_type_now));
				   }
#line 2094 ".//parser.tab.c"
    break;

  case 46: /* lista_identificador_local: identificador  */
#line 578 ".//parser.y"
                                   {
					    (yyval.tree) = (yyvsp[0].tree);
                        char* new_key = strdup((yyvsp[0].tree)->valor_lexico->token_value);
                      
                        if(find_symbol(stack_of_tables->top, new_key) != NULL){
                            printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
                            exit(ERR_DECLARED);
                        }
                        //printf("In the Hood Local Ident[%s]\n\n", new_key);
                        insert_symbol(stack_of_tables->top, new_key, create_symbol((yyvsp[0].tree),TOKEN_NATURE_IDENTIFIER, symbol_type_now));
					    //printf("Added identificador to lista_identificador\n"); // Debug print
				   }
#line 2111 ".//parser.tab.c"
    break;

  case 47: /* comando_atribuicao: identificador '=' expressao  */
#line 595 ".//parser.y"
                                  {
					(yyval.tree) = ast_new_label_only("="); // Cria um novo nó com o rótulo "="
					ast_add_child((yyval.tree), (yyvsp[-2].tree)); // Adiciona o identificador como filho do nó
					ast_add_child((yyval.tree), (yyvsp[0].tree)); // Adiciona a expressão como filho do nó
						
                    char* new_key = (yyvsp[-2].tree)->valor_lexico->token_value;
							  
					symbol_t* result = search_symbol_stack(stack_of_tables, new_key);
//Dessa linha					
                    if(result == NULL){
                        printf("[ERR_UNDECLARED] Var [%s] na linha %d nao foi declarada\n", new_key, get_line_number());
                        exit(ERR_UNDECLARED);
                    }
                    else {
                        
                        int nature = result->nature;
                        //printf("Nature: [%d]\n\n", nature);
                        (yyval.tree)->node_type = result->data_type;
                            
                        if(nature == TOKEN_NATURE_FUNCTION){
                            printf("[ERR_VARIABLE] Funcao [%s] na linha %d esta sendo usada como variavel\n", new_key, get_line_number());
                            exit(ERR_FUNCTION);
                        }
                    }
                    (yyval.tree)->node_type = new_type((yyvsp[-2].tree),(yyvsp[0].tree)); // Adiciona novo tipo resultante
//ate aqui tem que ser comentado 
//pra ver se nao quebrou a arvore em tese funciona                 
					//printf("Added expressao to comando_atribuicao\n"); // Debug print
				  }
#line 2145 ".//parser.tab.c"
    break;

  case 48: /* RETURN: TK_PR_RETURN  */
#line 629 ".//parser.y"
          {
		(yyval.tree) = ast_new_label_only("return"); // Cria um novo nó com o rótulo "return"
		//printf("Label RETURN\n"); // Debug print
	  }
#line 2154 ".//parser.tab.c"
    break;

  case 49: /* comando_retorno: RETURN expressao  */
#line 635 ".//parser.y"
                           {
					(yyval.tree) = (yyvsp[-1].tree);
					ast_add_child((yyval.tree), (yyvsp[0].tree));
                    (yyval.tree)->node_type = (yyvsp[0].tree)->node_type;
					//printf("Added expressao to comando_retorno\n"); // Debug print
			   }
#line 2165 ".//parser.tab.c"
    break;

  case 50: /* comando_controle_fluxo: condicional  */
#line 646 ".//parser.y"
                                          {
						(yyval.tree) = (yyvsp[0].tree);
						//printf("Added condicional to comando_controle_fluxo\n"); // Debug print
					  }
#line 2174 ".//parser.tab.c"
    break;

  case 51: /* comando_controle_fluxo: loop  */
#line 651 ".//parser.y"
                                          {
						(yyval.tree) = (yyvsp[0].tree);
						//printf("Added loop to comando_controle_fluxo\n"); // Debug print
					  }
#line 2183 ".//parser.tab.c"
    break;

  case 52: /* IF: TK_PR_IF  */
#line 660 ".//parser.y"
  {
  	(yyval.tree) = ast_new_label_only("if"); // Cria um novo nó com o rótulo "if"
	//printf("Label IF\n"); // Debug print
  }
#line 2192 ".//parser.tab.c"
    break;

  case 53: /* ELSE: TK_PR_ELSE  */
#line 666 ".//parser.y"
        {
		(yyval.tree) = NULL; // Cria um novo nó com o rótulo "else"
		//printf("Label ELSE\n"); // Debug print
	}
#line 2201 ".//parser.tab.c"
    break;

  case 54: /* condicional: IF '(' expressao ')' criar_escopo corpo fechar_escopo  */
#line 672 ".//parser.y"
                   {
				(yyval.tree) = (yyvsp[-6].tree); // Define a condicional como o nó "if"
				ast_add_child((yyval.tree), (yyvsp[-4].tree)); // Adiciona a expressão como filho do nó "if"
				ast_add_child((yyval.tree), (yyvsp[-2].tree)); // Adiciona o corpo como filho do nó "if"
                (yyval.tree)->node_type = (yyvsp[-4].tree)->node_type;
				//printf("Added expressao and corpo to condicional\n"); // Debug print
		   }
#line 2213 ".//parser.tab.c"
    break;

  case 55: /* condicional: IF '(' expressao ')' criar_escopo corpo fechar_escopo ELSE criar_escopo corpo fechar_escopo  */
#line 680 ".//parser.y"
                   {
				(yyval.tree) = (yyvsp[-10].tree);
				ast_add_child((yyval.tree), (yyvsp[-8].tree)); // Adiciona a expressão como filho do nó "if"
				ast_add_child((yyval.tree), (yyvsp[-6].tree)); // Adiciona o corpo do "if" como filho do nó "if"
				ast_add_child((yyval.tree), (yyvsp[-4].tree)); // Adiciona o nó "else" como filho do nó "if"
                (yyval.tree)->node_type = (yyvsp[-8].tree)->node_type;
				//printf("Added expressao, corpo, and corpo to condicional\n"); // Debug print
		   }
#line 2226 ".//parser.tab.c"
    break;

  case 56: /* WHILE: TK_PR_WHILE  */
#line 693 ".//parser.y"
         {
		(yyval.tree) = ast_new_label_only("while"); // Cria um novo nó com o rótulo "while"
		//printf("Label WHILE\n"); // Debug print
	 }
#line 2235 ".//parser.tab.c"
    break;

  case 57: /* loop: WHILE '(' expressao ')' criar_escopo corpo fechar_escopo  */
#line 699 ".//parser.y"
        {
		(yyval.tree) = (yyvsp[-6].tree);
		ast_add_child((yyval.tree), (yyvsp[-4].tree)); // Adiciona a expressão como filho do nó "while"
		ast_add_child((yyval.tree), (yyvsp[-2].tree)); // Adiciona o corpo como filho do nó "while"
        (yyval.tree)->node_type = (yyvsp[-4].tree)->node_type;
		//printf("Added expressao and corpo to loop\n"); // Debug print

        char* test_label = generate_label(label_counter);
        char* true_label = generate_label(label_counter);
        char* after_label = generate_label(label_counter);
        
        char* temp = generate_temp(temp_counter);
        char* temp_opaque = generate_temp(temp_counter);
        char* op1 = strdup("0");
        operation_t* generated_code1 = initialize_operation(NULL, LOADI, op1, temp, NULL);

        operation_t* generated_code_test = initialize_operation(strdup(test_label), NOP, NULL, NULL, NULL);
        append_operations(generated_code1, generated_code_test);
        
        operation_t* generated_code2 = initialize_operation(NULL, CMP_NE, strdup((yyvsp[-4].tree)->temp), strdup(temp), temp_opaque);
        append_operations(generated_code1, generated_code2);
        
        operation_t* generated_code3 = initialize_operation(NULL, CBR, strdup(temp_opaque), true_label, after_label);
        append_operations(generated_code1, generated_code3);
        
        operation_t* generated_code4 = initialize_operation(true_label, NOP, NULL, NULL, NULL);
        append_operations(generated_code1, generated_code4);

        if ((yyvsp[-1].tree) != NULL)
            append_operations(generated_code1, (yyvsp[-1].tree)->code);

        operation_t* generated_code5 = initialize_operation(NULL, JUMPI, test_label, NULL, NULL);
        append_operations(generated_code1, generated_code5);

        operation_t* generated_code6 = initialize_operation(strdup(after_label), NOP, NULL, NULL, NULL);
        append_operations(generated_code1, generated_code6);

        (yyval.tree)->code = append_operations((yyvsp[-4].tree)->code, generated_code1);
	}
#line 2279 ".//parser.tab.c"
    break;

  case 58: /* expressao: operando  */
#line 751 ".//parser.y"
                 {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added operando to expressao\n"); // Debug print
		 }
#line 2288 ".//parser.tab.c"
    break;

  case 59: /* operando: operador  */
#line 758 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added operador to operando\n"); // Debug print
		}
#line 2297 ".//parser.tab.c"
    break;

  case 60: /* operando: operando OR operador  */
#line 763 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[-1].tree);
			ast_add_child((yyval.tree), (yyvsp[-2].tree));
			ast_add_child((yyval.tree), (yyvsp[0].tree));
            (yyval.tree)->node_type = new_type((yyvsp[-2].tree),(yyvsp[0].tree));
			//printf("Added operando and operador to operando\n"); // Debug print

            char* temp = generate_temp(temp_counter);
            operation_t* generated_code = initialize_operation(NULL, OR , strdup((yyvsp[-2].tree)->temp), strdup((yyvsp[0].tree)->temp), strdup(temp));
            (yyval.tree)->code = append_operations((yyvsp[-2].tree)->code, (yyvsp[0].tree)->code);
            (yyval.tree)->code = append_operations((yyval.tree)->code, generated_code);
            (yyval.tree)->temp = temp;
		}
#line 2315 ".//parser.tab.c"
    break;

  case 61: /* operador: comparacao_1  */
#line 781 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added comparacao to operador\n"); // Debug print
		}
#line 2324 ".//parser.tab.c"
    break;

  case 62: /* operador: operador AND comparacao_1  */
#line 786 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[-1].tree);
			ast_add_child((yyval.tree), (yyvsp[-2].tree));
			ast_add_child((yyval.tree), (yyvsp[0].tree));
            (yyval.tree)->node_type = new_type((yyvsp[-2].tree),(yyvsp[0].tree));
			//printf("Added operador and comparacao to operador\n"); // Debug print

            char* temp = generate_temp(temp_counter);
            operation_t* generated_code = initialize_operation(NULL, AND , strdup((yyvsp[-2].tree)->temp), strdup((yyvsp[0].tree)->temp), strdup(temp));
            (yyval.tree)->code = append_operations((yyvsp[-2].tree)->code, (yyvsp[0].tree)->code);
            (yyval.tree)->code = append_operations((yyval.tree)->code, generated_code);
            (yyval.tree)->temp = temp;

		}
#line 2343 ".//parser.tab.c"
    break;

  case 63: /* comparacao_1: comparacao_2  */
#line 805 ".//parser.y"
                  {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added comparacao_1 to comparacao_2\n"); // Debug print
		  }
#line 2352 ".//parser.tab.c"
    break;

  case 64: /* comparacao_1: comparacao_1 equal_or_not comparacao_2  */
#line 810 ".//parser.y"
                  {
				(yyval.tree) = (yyvsp[-1].tree);
				ast_add_child((yyval.tree), (yyvsp[-2].tree));
				ast_add_child((yyval.tree), (yyvsp[0].tree));
                (yyval.tree)->node_type = new_type((yyvsp[-2].tree),(yyvsp[0].tree));
				//printf("Added comparacao_1, equal_or_not, and comparacao_2 to comparacao_1\n"); // Debug print

                char* temp = generate_temp(temp_counter);
                operation_t* generated_code = initialize_operation(NULL, current_opcode, strdup((yyvsp[-2].tree)->temp), strdup((yyvsp[0].tree)->temp), strdup(temp));
                (yyval.tree)->code = append_operations((yyvsp[-2].tree)->code, (yyvsp[0].tree)->code);
                (yyval.tree)->code = append_operations((yyval.tree)->code, generated_code);
                (yyval.tree)->temp = temp;
		  }
#line 2370 ".//parser.tab.c"
    break;

  case 65: /* equal_or_not: EQUAL  */
#line 825 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
                current_opcode = CMP_EQ;
				//printf("Added EQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2380 ".//parser.tab.c"
    break;

  case 66: /* equal_or_not: NOTEQUAL  */
#line 831 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
                current_opcode = CMP_NE;
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2390 ".//parser.tab.c"
    break;

  case 67: /* comparacao_2: adicaousub  */
#line 841 ".//parser.y"
                  {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added adicaousub to comparacao_2\n"); // Debug print
		  }
#line 2399 ".//parser.tab.c"
    break;

  case 68: /* comparacao_2: comparacao_2 greater_or_less adicaousub  */
#line 847 ".//parser.y"
                  {
				(yyval.tree) = (yyvsp[-1].tree);
				ast_add_child((yyval.tree), (yyvsp[-2].tree));
				ast_add_child((yyval.tree), (yyvsp[0].tree));
                (yyval.tree)->node_type = new_type((yyvsp[-2].tree),(yyvsp[0].tree));
				//printf("Added comparacao_2, greater_or_less, and adicaousub to comparacao_2\n"); // Debug print

                char* temp = generate_temp(temp_counter);
                operation_t* generated_code = initialize_operation(NULL, current_opcode, strdup((yyvsp[-2].tree)->temp), strdup((yyvsp[0].tree)->temp), strdup(temp));
                (yyval.tree)->code = append_operations((yyvsp[-2].tree)->code, (yyvsp[0].tree)->code);
                (yyval.tree)->code = append_operations((yyval.tree)->code, generated_code);
                (yyval.tree)->temp = temp;
		  }
#line 2417 ".//parser.tab.c"
    break;

  case 69: /* greater_or_less: GREATEREQUAL  */
#line 862 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
                current_opcode = CMP_GE;
				//printf("Added EQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2427 ".//parser.tab.c"
    break;

  case 70: /* greater_or_less: LESSEQUAL  */
#line 868 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
                current_opcode = CMP_LE;
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2437 ".//parser.tab.c"
    break;

  case 71: /* greater_or_less: GREATERTHAN  */
#line 874 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
                current_opcode = CMP_GT;
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2447 ".//parser.tab.c"
    break;

  case 72: /* greater_or_less: LESSTHAN  */
#line 880 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
                current_opcode = CMP_LT;
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
#line 2457 ".//parser.tab.c"
    break;

  case 73: /* adicaousub: multoudivoures  */
#line 890 ".//parser.y"
                  {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added multoudivoures to adicaousub\n"); // Debug print
		  }
#line 2466 ".//parser.tab.c"
    break;

  case 74: /* adicaousub: adicaousub op_adicaousub multoudivoures  */
#line 895 ".//parser.y"
                  {
					(yyval.tree) = (yyvsp[-1].tree);
					ast_add_child((yyval.tree), (yyvsp[-2].tree));
					ast_add_child((yyval.tree), (yyvsp[0].tree));
                    (yyval.tree)->node_type = new_type((yyvsp[-2].tree),(yyvsp[0].tree));
					//printf("Added adicaousub, op_adicaousub, and multoudivoures to adicaousub\n"); // Debug print

                    char* temp = generate_temp(temp_counter);
                    operation_t* generated_code = initialize_operation(NULL, current_opcode, strdup((yyvsp[-2].tree)->temp), strdup((yyvsp[0].tree)->temp), strdup(temp));
                    (yyval.tree)->code = append_operations((yyvsp[-2].tree)->code, (yyvsp[0].tree)->code);
                    (yyval.tree)->code = append_operations((yyval.tree)->code, generated_code);
                    (yyval.tree)->temp = temp;


		  }
#line 2486 ".//parser.tab.c"
    break;

  case 75: /* op_adicaousub: ADD  */
#line 915 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
                current_opcode = ADD;
				//printf("Added ADD to op_adicaousub\n"); // Debug print
			 }
#line 2496 ".//parser.tab.c"
    break;

  case 76: /* op_adicaousub: SUBTRACT  */
#line 921 ".//parser.y"
                         {
				(yyval.tree) = (yyvsp[0].tree);
                current_opcode = SUB;
				//printf("Added SUBTRACT to op_adicaousub\n"); // Debug print
			 }
#line 2506 ".//parser.tab.c"
    break;

  case 77: /* multoudivoures: unario  */
#line 931 ".//parser.y"
                          {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added unario to multoudivoures\n"); // Debug print
			  }
#line 2515 ".//parser.tab.c"
    break;

  case 78: /* multoudivoures: multoudivoures op_multoudivoures unario  */
#line 936 ".//parser.y"
                          {
					(yyval.tree) = (yyvsp[-1].tree);
					ast_add_child((yyval.tree), (yyvsp[-2].tree));
					ast_add_child((yyval.tree), (yyvsp[0].tree));
                    (yyval.tree)->node_type = new_type((yyvsp[-2].tree),(yyvsp[0].tree));
					//printf("Added multoudivoures, op_multoudivoures, and unario to multoudivoures\n"); // Debug print

                    char* temp = generate_temp(temp_counter);
                    operation_t* generated_code = initialize_operation(NULL, current_opcode, strdup((yyvsp[-2].tree)->temp), strdup((yyvsp[0].tree)->temp), strdup(temp));
                    (yyval.tree)->code = append_operations((yyvsp[-2].tree)->code, (yyvsp[0].tree)->code);
                    (yyval.tree)->code = append_operations((yyval.tree)->code, generated_code);
                    (yyval.tree)->temp = temp;

			  }
#line 2534 ".//parser.tab.c"
    break;

  case 79: /* op_multoudivoures: MULTIPLY  */
#line 955 ".//parser.y"
                                 {
					(yyval.tree) = (yyvsp[0].tree);
                    current_opcode = MULT;
					//printf("Added MULTIPLY to op_multoudivoures\n"); // Debug print
				 }
#line 2544 ".//parser.tab.c"
    break;

  case 80: /* op_multoudivoures: DIVIDE  */
#line 961 ".//parser.y"
                                 {
					(yyval.tree) = (yyvsp[0].tree);
                    current_opcode = DIV;
					//printf("Added DIVIDE to op_multoudivoures\n"); // Debug print
				 }
#line 2554 ".//parser.tab.c"
    break;

  case 81: /* op_multoudivoures: REMAINDER  */
#line 967 ".//parser.y"
                                 {
					(yyval.tree) = (yyvsp[0].tree);
					//printf("Added REMAINDER to op_multoudivoures\n"); // Debug print
				 }
#line 2563 ".//parser.tab.c"
    break;

  case 82: /* unario: primario  */
#line 976 ".//parser.y"
          {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added primario to unario\n"); // Debug print
	  }
#line 2572 ".//parser.tab.c"
    break;

  case 83: /* unario: INVERTSIG unario  */
#line 981 ".//parser.y"
          {
			(yyval.tree) = (yyvsp[-1].tree);
		    ast_add_child((yyval.tree), (yyvsp[0].tree));
            (yyval.tree)->node_type = (yyvsp[0].tree)->node_type;
		    //printf("Added INVERTSIG and unario to unario\n"); // Debug print
	  }
#line 2583 ".//parser.tab.c"
    break;

  case 84: /* unario: NEGATE unario  */
#line 988 ".//parser.y"
          {
			(yyval.tree) = (yyvsp[-1].tree);
		    ast_add_child((yyval.tree), (yyvsp[0].tree));
            (yyval.tree)->node_type = (yyvsp[0].tree)->node_type;
		    //printf("Added NEGATE and unario to unario\n"); // Debug print
	  }
#line 2594 ".//parser.tab.c"
    break;

  case 85: /* primario: identificador  */
#line 999 ".//parser.y"
                {
            (yyval.tree) = (yyvsp[0].tree);
			//printf("Added identificador to primario\n");
            
			char* new_key = (yyvsp[0].tree)->valor_lexico->token_value;
							  
            symbol_t* result = search_symbol_stack(stack_of_tables, new_key);

            table_of_symbols_t* current_scope = search_stack_for_adress(stack_of_tables, new_key);

            int adress = result->adress_displacement;

            char* temp = generate_temp(temp_counter);

            char* op1;

            if(current_scope->is_global)
                op1 = strdup("rbss");
            else
                op1 = strdup("rfp");

            char* op2 = (char*) malloc(sizeof(char) * OPCODE_SIZE_OF_BUFFER);

            sprintf(op2, "%d", adress + initial_space);

            operation_t* generated_code = initialize_operation(NULL, LOADAI, op1, op2, strdup(temp));

            (yyval.tree)->temp = temp;
            (yyval.tree)->code = append_operations((yyval.tree)->code, generated_code);

			if(result == NULL){
               printf("[ERR_UNDECLARED] Var [%s] na linha %d nao foi declarada\n", new_key, get_line_number());
               exit(ERR_UNDECLARED);
            }
            else {
                int nature = result->nature;
                //printf("Nature: [%d]\n\n", nature);
                (yyval.tree)->node_type = result->data_type;
                    
                if(nature == TOKEN_NATURE_FUNCTION){
                    printf("[ERR_VARIABLE] Funcao [%s] na linha %d esta sendo usada como variavel\n", new_key, get_line_number());
                    exit(ERR_FUNCTION);
                }
            }
		}
#line 2644 ".//parser.tab.c"
    break;

  case 86: /* primario: literais  */
#line 1045 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added literais to primario\n"); // Debug print
		}
#line 2653 ".//parser.tab.c"
    break;

  case 87: /* primario: chamada_funcao  */
#line 1050 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added chamada_funcao to primario\n"); // Debug print
		}
#line 2662 ".//parser.tab.c"
    break;

  case 88: /* primario: '(' expressao ')'  */
#line 1055 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[-1].tree);
            (yyval.tree)->node_type = (yyvsp[-1].tree)->node_type;
			//printf("Added expressao to primario\n"); // Debug print
		}
#line 2672 ".//parser.tab.c"
    break;

  case 89: /* chamada_funcao: nome_func '(' lista_de_argumentos ')'  */
#line 1065 ".//parser.y"
                          {
				(yyval.tree) = (yyvsp[-3].tree);
				ast_add_child((yyval.tree), (yyvsp[-1].tree));
                char *new_key = (yyvsp[-3].tree)->valor_lexico->token_value;

                char *parsed_key = ast_parse_function_call(new_key);



                symbol_t* result = search_symbol_stack(stack_of_tables, parsed_key);
                if(result == NULL)
                {
                    printf("[ERR_UNDECLARED] Funcao [%s] na linha %d nao foi declarada\n", parsed_key, get_line_number());
    				exit(ERR_UNDECLARED);
                }
				//printf("Added nome_func and lista_de_argumentos to chamada_funcao\n"); // Debug print
                else
                {
                    int nature = result->nature;
                    //printf("Nature: [%d]\n\n", nature);
                    (yyval.tree)->node_type = result->data_type;
                    if(nature == TOKEN_NATURE_IDENTIFIER){
                        printf("[ERR_FUNCTION] Variavel [%s] na linha %d esta sendo usada como funcao\n", parsed_key, get_line_number());
                        exit(ERR_VARIABLE);
                    }
                }
                table_of_symbols_t* current_scope = search_stack_for_adress(stack_of_tables, new_key);
                
                (yyval.tree)->temp = generate_temp(temp_counter);

                operation_t* generated_code1 = initialize_operation(NULL, LOADI, NULL, generate_temp(temp_counter), NULL);

                operation_t* generated_code2 = initialize_operation(NULL, STOREAI, strdup(generated_code1->op2), strdup("rsp"), strdup("0"));

                append_operations(generated_code1, generated_code2);

                operation_t* generated_code3 = initialize_operation(NULL, STOREAI, strdup("rsp"), strdup("rsp"), strdup("4"));
                append_operations(generated_code1, generated_code3);

                operation_t* generated_code4 = initialize_operation(NULL, STOREAI, strdup("rfp"), strdup("rsp"), strdup("8"));
                append_operations(generated_code1, generated_code4);

                char* function_label = strdup(result->label);
                operation_t* generated_code5 = initialize_operation(NULL, JUMPI, function_label, NULL, NULL);
                append_operations(generated_code1, generated_code5);

                operation_t* generated_code6 = initialize_operation(NULL, LOADAI, strdup("rsp"), strdup("12"), strdup((yyval.tree)->temp));
                append_operations(generated_code1, generated_code6);

                if ((yyvsp[-1].tree) != NULL) {
                    (yyval.tree)->code = append_operations((yyvsp[-1].tree)->code, generated_code1);
                }
			  }
#line 2730 ".//parser.tab.c"
    break;

  case 90: /* chamada_funcao: nome_func '(' ')'  */
#line 1119 ".//parser.y"
                          {
				(yyval.tree) = (yyvsp[-2].tree);
				//printf("Added nome_func to chamada_funcao\n"); // Debug print
				char *new_key = (yyvsp[-2].tree)->valor_lexico->token_value;

                char *parsed_key = ast_parse_function_call(new_key);

                symbol_t* result = search_symbol_stack(stack_of_tables, parsed_key);
                if(result == NULL)
                {
                    printf("[ERR_UNDECLARED] Funcao [%s] na linha %d nao foi declarada\n", parsed_key, get_line_number());
    				exit(ERR_UNDECLARED);
                }
				//printf("Added nome_func and lista_de_argumentos to chamada_funcao\n"); // Debug print
                else
                {
                    int nature = result->nature;
                    //printf("Nature: [%d]\n\n", nature);
                    (yyval.tree)->node_type = result->data_type;
                    if(nature == TOKEN_NATURE_IDENTIFIER){
                        printf("[ERR_FUNCTION] Variavel [%s] na linha %d esta sendo usada como funcao\n", parsed_key, get_line_number());
                        exit(ERR_VARIABLE);
                    }
                }
                table_of_symbols_t* current_scope = search_stack_for_adress(stack_of_tables, new_key);
                (yyval.tree)->temp = generate_temp(temp_counter);

                operation_t* generated_code1 = initialize_operation(NULL, LOADI, NULL, generate_temp(temp_counter), NULL);

                operation_t* generated_code2 = initialize_operation(NULL, STOREAI, strdup(generated_code1->op2), strdup("rsp"), strdup("0"));
                append_operations(generated_code1, generated_code2);

                operation_t* generated_code3 = initialize_operation(NULL, STOREAI, strdup("rsp"), strdup("rsp"), strdup("4"));
                append_operations(generated_code1, generated_code3);

                operation_t* generated_code4 = initialize_operation(NULL, STOREAI, strdup("rfp"), strdup("rsp"), strdup("8"));
                append_operations(generated_code1, generated_code4);

                char* function_label = strdup(result->label);
                operation_t* generated_code5 = initialize_operation(NULL, JUMPI, function_label, NULL, NULL);
                append_operations(generated_code1, generated_code5);

                operation_t* generated_code6 = initialize_operation(NULL, LOADAI, strdup("rsp"), strdup("12"), strdup((yyval.tree)->temp));
                append_operations(generated_code1, generated_code6);

                (yyval.tree)->code = generated_code1;
			  }
#line 2782 ".//parser.tab.c"
    break;

  case 91: /* lista_de_argumentos: expressao  */
#line 1171 ".//parser.y"
                           {
				(yyval.tree) = (yyvsp[0].tree);
				//printf("Added expressao to lista_de_argumentos\n"); // Debug print
			   }
#line 2791 ".//parser.tab.c"
    break;

  case 92: /* lista_de_argumentos: expressao ';' lista_de_argumentos  */
#line 1176 ".//parser.y"
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
#line 2815 ".//parser.tab.c"
    break;

  case 93: /* nome_func: call_identificador  */
#line 1200 ".//parser.y"
                 {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added identificador to nome_func\n"); // Debug print
		 }
#line 2824 ".//parser.tab.c"
    break;

  case 94: /* literais: LITINT  */
#line 1209 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added LITINT to literais\n"); // Debug print
		}
#line 2833 ".//parser.tab.c"
    break;

  case 95: /* literais: LITFLOAT  */
#line 1214 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added LITFLOAT to literais\n"); // Debug print
		}
#line 2842 ".//parser.tab.c"
    break;

  case 96: /* literais: LITFALSE  */
#line 1219 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added LITFALSE to literais\n"); // Debug print
		}
#line 2851 ".//parser.tab.c"
    break;

  case 97: /* literais: LITTRUE  */
#line 1224 ".//parser.y"
                {
			(yyval.tree) = (yyvsp[0].tree);
			//printf("Added LITTRUE to literais\n"); // Debug print
		}
#line 2860 ".//parser.tab.c"
    break;

  case 98: /* LITINT: TK_LIT_INT  */
#line 1233 ".//parser.y"
          {
			(yyval.tree) = ast_new((yyvsp[0].valor_lexico));
            (yyval.tree)->node_type = NODE_TYPE_INT;
            char* temp = generate_temp(temp_counter);
            (yyval.tree)->temp = temp;

            char* op1 = (char*) malloc(sizeof(char) * OPCODE_SIZE_OF_BUFFER);
            op1 = (yyval.tree)->valor_lexico->token_value;
            operation_t* generated_code = initialize_operation(NULL, LOADI, op1, strdup(temp), NULL);

			//printf("Added TK_LIT_INT to LITINT\n"); // Debug print
	  }
#line 2877 ".//parser.tab.c"
    break;

  case 99: /* LITFLOAT: TK_LIT_FLOAT  */
#line 1250 ".//parser.y"
                {
			(yyval.tree) = ast_new((yyvsp[0].valor_lexico));
            (yyval.tree)->node_type = NODE_TYPE_FLOAT;
			//printf("Added TK_LIT_FLOAT to LITFLOAT\n"); // Debug print
		}
#line 2887 ".//parser.tab.c"
    break;

  case 100: /* LITFALSE: TK_LIT_FALSE  */
#line 1260 ".//parser.y"
                {
			(yyval.tree) = ast_new((yyvsp[0].valor_lexico));
            (yyval.tree)->node_type = NODE_TYPE_BOOL;
			//printf("Added TK_LIT_FALSE to LITFALSE\n"); // Debug print
		}
#line 2897 ".//parser.tab.c"
    break;

  case 101: /* LITTRUE: TK_LIT_TRUE  */
#line 1270 ".//parser.y"
           {
			(yyval.tree) = ast_new((yyvsp[0].valor_lexico));
            (yyval.tree)->node_type = NODE_TYPE_BOOL;
			//printf("Added TK_LIT_TRUE to LITTRUE\n"); // Debug print
	   }
#line 2907 ".//parser.tab.c"
    break;

  case 102: /* INVERTSIG: '-'  */
#line 1280 ".//parser.y"
                 {
				(yyval.tree) = ast_new_label_only("-");
				//printf("Label INVERTSIG\n"); // Debug print
		 }
#line 2916 ".//parser.tab.c"
    break;

  case 103: /* NEGATE: '!'  */
#line 1286 ".//parser.y"
          {
			(yyval.tree) = ast_new_label_only("!");
			//printf("Label NEGATE\n"); // Debug print
	  }
#line 2925 ".//parser.tab.c"
    break;

  case 104: /* MULTIPLY: '*'  */
#line 1292 ".//parser.y"
                {
			(yyval.tree) = ast_new_label_only("*");
			//printf("Label MULTIPLY\n"); // Debug print
		}
#line 2934 ".//parser.tab.c"
    break;

  case 105: /* DIVIDE: '/'  */
#line 1298 ".//parser.y"
          {
			(yyval.tree) = ast_new_label_only("/");
			//printf("Label DIVIDE\n"); // Debug print
	  }
#line 2943 ".//parser.tab.c"
    break;

  case 106: /* REMAINDER: '%'  */
#line 1304 ".//parser.y"
                 {
				(yyval.tree) = ast_new_label_only("%");
				//printf("Label REMAINDER\n"); // Debug print
		 }
#line 2952 ".//parser.tab.c"
    break;

  case 107: /* ADD: '+'  */
#line 1310 ".//parser.y"
   {
		(yyval.tree) = ast_new_label_only("+");
		//printf("Label ADD\n"); // Debug print
   }
#line 2961 ".//parser.tab.c"
    break;

  case 108: /* SUBTRACT: '-'  */
#line 1316 ".//parser.y"
                {
			(yyval.tree) = ast_new_label_only("-");
			//printf("Label SUBTRACT\n"); // Debug print
		}
#line 2970 ".//parser.tab.c"
    break;

  case 109: /* GREATERTHAN: '>'  */
#line 1322 ".//parser.y"
                   {
				(yyval.tree) = ast_new_label_only(">");
				//printf("Label GREATERTHAN\n"); // Debug print
		   }
#line 2979 ".//parser.tab.c"
    break;

  case 110: /* LESSTHAN: '<'  */
#line 1328 ".//parser.y"
                {
			(yyval.tree) = ast_new_label_only("<");
			//printf("Label LESSTHAN\n"); // Debug print
		}
#line 2988 ".//parser.tab.c"
    break;

  case 111: /* LESSEQUAL: TK_OC_LE  */
#line 1334 ".//parser.y"
                 {
		 	(yyval.tree) = ast_new_label_only("<=");
			//printf("Label 'LESSEQUAL'\n"); // Debug print
		 }
#line 2997 ".//parser.tab.c"
    break;

  case 112: /* GREATEREQUAL: TK_OC_GE  */
#line 1340 ".//parser.y"
                        {
				(yyval.tree) = ast_new_label_only(">=");
				//printf("Label 'GREATEREQUAL'\n"); // Debug print
			}
#line 3006 ".//parser.tab.c"
    break;

  case 113: /* EQUAL: TK_OC_EQ  */
#line 1346 ".//parser.y"
         {
		(yyval.tree) = ast_new_label_only("==");
		//printf("Label 'EQUAL'\n"); // Debug print
	 }
#line 3015 ".//parser.tab.c"
    break;

  case 114: /* NOTEQUAL: TK_OC_NE  */
#line 1352 ".//parser.y"
                {
			(yyval.tree) = ast_new_label_only("!=");
			//printf("Label 'NOTEQUAL'\n"); // Debug print
		}
#line 3024 ".//parser.tab.c"
    break;

  case 115: /* AND: TK_OC_AND  */
#line 1358 ".//parser.y"
   {
		(yyval.tree) = ast_new_label_only("&");
		//printf("Label 'AND'\n"); // Debug print
   }
#line 3033 ".//parser.tab.c"
    break;


#line 3037 ".//parser.tab.c"

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

#line 1363 ".//parser.y"


//##########################
// Função de tratamento de erro
int yyerror(char const *s){
    printf("%s on line %d \n", s, get_line_number());
    return 1;
}
