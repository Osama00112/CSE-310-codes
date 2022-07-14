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
#line 1 "parser.y"

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "1805002_SymbolTable.h"
//#include "1805002_ScopeTable.h"
//#define YYSTYPE SymbolInfo*

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE *yyin;
FILE *fp;
//FILE *fp_error = fopen("error.txt","w");
//FILE *fp_log = fopen("log.txt","w");

ofstream logout;
ofstream errorout;

extern int line_count;
extern int error;

//temporary variables
variable tempVar;
vector<variable> variableList;
myfunction tempFunction;
vector<myfunction> functionList;


SymbolTable *table = new SymbolTable(30,1);


void yyerror(char *s)
{
	//write your code
}



#line 114 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    LPAREN = 258,                  /* LPAREN  */
    RPAREN = 259,                  /* RPAREN  */
    LCURL = 260,                   /* LCURL  */
    RCURL = 261,                   /* RCURL  */
    LTHIRD = 262,                  /* LTHIRD  */
    RTHIRD = 263,                  /* RTHIRD  */
    SEMICOLON = 264,               /* SEMICOLON  */
    COMMA = 265,                   /* COMMA  */
    INT = 266,                     /* INT  */
    FLOAT = 267,                   /* FLOAT  */
    CHAR = 268,                    /* CHAR  */
    DOUBLE = 269,                  /* DOUBLE  */
    VOID = 270,                    /* VOID  */
    IF = 271,                      /* IF  */
    ELSE = 272,                    /* ELSE  */
    FOR = 273,                     /* FOR  */
    WHILE = 274,                   /* WHILE  */
    RETURN = 275,                  /* RETURN  */
    PRINTLN = 276,                 /* PRINTLN  */
    ASSIGNOP = 277,                /* ASSIGNOP  */
    BITOP = 278,                   /* BITOP  */
    NOT = 279,                     /* NOT  */
    INCOP = 280,                   /* INCOP  */
    DECOP = 281,                   /* DECOP  */
    ID = 282,                      /* ID  */
    CONST_INT = 283,               /* CONST_INT  */
    CONST_FLOAT = 284,             /* CONST_FLOAT  */
    CONST_CHAR = 285,              /* CONST_CHAR  */
    ADDOP = 286,                   /* ADDOP  */
    MULOP = 287,                   /* MULOP  */
    RELOP = 288,                   /* RELOP  */
    LOGICOP = 289                  /* LOGICOP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LPAREN 258
#define RPAREN 259
#define LCURL 260
#define RCURL 261
#define LTHIRD 262
#define RTHIRD 263
#define SEMICOLON 264
#define COMMA 265
#define INT 266
#define FLOAT 267
#define CHAR 268
#define DOUBLE 269
#define VOID 270
#define IF 271
#define ELSE 272
#define FOR 273
#define WHILE 274
#define RETURN 275
#define PRINTLN 276
#define ASSIGNOP 277
#define BITOP 278
#define NOT 279
#define INCOP 280
#define DECOP 281
#define ID 282
#define CONST_INT 283
#define CONST_FLOAT 284
#define CONST_CHAR 285
#define ADDOP 286
#define MULOP 287
#define RELOP 288
#define LOGICOP 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "parser.y"

	SymbolInfo *Symbol;

#line 239 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LPAREN = 3,                     /* LPAREN  */
  YYSYMBOL_RPAREN = 4,                     /* RPAREN  */
  YYSYMBOL_LCURL = 5,                      /* LCURL  */
  YYSYMBOL_RCURL = 6,                      /* RCURL  */
  YYSYMBOL_LTHIRD = 7,                     /* LTHIRD  */
  YYSYMBOL_RTHIRD = 8,                     /* RTHIRD  */
  YYSYMBOL_SEMICOLON = 9,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_INT = 11,                       /* INT  */
  YYSYMBOL_FLOAT = 12,                     /* FLOAT  */
  YYSYMBOL_CHAR = 13,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 14,                    /* DOUBLE  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_PRINTLN = 21,                   /* PRINTLN  */
  YYSYMBOL_ASSIGNOP = 22,                  /* ASSIGNOP  */
  YYSYMBOL_BITOP = 23,                     /* BITOP  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_INCOP = 25,                     /* INCOP  */
  YYSYMBOL_DECOP = 26,                     /* DECOP  */
  YYSYMBOL_ID = 27,                        /* ID  */
  YYSYMBOL_CONST_INT = 28,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 29,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHAR = 30,                /* CONST_CHAR  */
  YYSYMBOL_ADDOP = 31,                     /* ADDOP  */
  YYSYMBOL_MULOP = 32,                     /* MULOP  */
  YYSYMBOL_RELOP = 33,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 34,                   /* LOGICOP  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_start = 36,                     /* start  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_unit = 38,                      /* unit  */
  YYSYMBOL_func_declaration = 39,          /* func_declaration  */
  YYSYMBOL_func_definition = 40,           /* func_definition  */
  YYSYMBOL_41_1 = 41,                      /* $@1  */
  YYSYMBOL_42_2 = 42,                      /* $@2  */
  YYSYMBOL_parameter_list = 43,            /* parameter_list  */
  YYSYMBOL_compound_statement = 44,        /* compound_statement  */
  YYSYMBOL_var_declaration = 45,           /* var_declaration  */
  YYSYMBOL_type_specifier = 46,            /* type_specifier  */
  YYSYMBOL_declaration_list = 47,          /* declaration_list  */
  YYSYMBOL_statements = 48,                /* statements  */
  YYSYMBOL_statement = 49,                 /* statement  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_expression_statement = 51,      /* expression_statement  */
  YYSYMBOL_variable = 52,                  /* variable  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_logic_expression = 54,          /* logic_expression  */
  YYSYMBOL_rel_expression = 55,            /* rel_expression  */
  YYSYMBOL_simple_expression = 56,         /* simple_expression  */
  YYSYMBOL_term = 57,                      /* term  */
  YYSYMBOL_unary_expression = 58,          /* unary_expression  */
  YYSYMBOL_factor = 59,                    /* factor  */
  YYSYMBOL_argument_list = 60,             /* argument_list  */
  YYSYMBOL_arguments = 61                  /* arguments  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    79,    85,    93,    99,   105,   113,   134,
     157,   156,   255,   254,   306,   321,   330,   344,   355,   364,
     375,   435,   440,   445,   452,   466,   484,   497,   516,   522,
     530,   536,   543,   543,   549,   555,   561,   567,   573,   593,
     606,   610,   618,   642,   679,   685,   718,   724,   746,   752,
     760,   766,   780,   786,   820,   826,   832,   840,   846,   886,
     892,   898,   904,   911,   919,   926,   933,   963
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
  "\"end of file\"", "error", "\"invalid token\"", "LPAREN", "RPAREN",
  "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", "INT",
  "FLOAT", "CHAR", "DOUBLE", "VOID", "IF", "ELSE", "FOR", "WHILE",
  "RETURN", "PRINTLN", "ASSIGNOP", "BITOP", "NOT", "INCOP", "DECOP", "ID",
  "CONST_INT", "CONST_FLOAT", "CONST_CHAR", "ADDOP", "MULOP", "RELOP",
  "LOGICOP", "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "$@1", "$@2", "parameter_list", "compound_statement",
  "var_declaration", "type_specifier", "declaration_list", "statements",
  "statement", "$@3", "expression_statement", "variable", "expression",
  "logic_expression", "rel_expression", "simple_expression", "term",
  "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,   -73,   -73,   -73,    32,    10,   -73,   -73,   -73,   -73,
      34,   -73,   -73,    50,     7,   133,     9,   -73,    48,    36,
       8,    52,    76,    78,   -73,    82,    79,    10,   -73,   -73,
      66,    62,   -73,   -73,    82,    70,    88,    31,   -73,   -73,
      96,    99,   100,    31,   103,    31,    69,   -73,   -73,    31,
     -73,    84,    89,   -73,    82,   -73,    18,   105,   -73,    85,
      19,    80,   -73,   -73,   -73,   -73,   -73,   118,    31,    -1,
      31,   116,   102,    38,   -73,    31,    31,   -73,   119,   -73,
     -73,   -73,    31,   -73,   -73,   -73,    31,    31,    31,    31,
     -73,   130,    -1,   131,   -73,   134,   -73,   138,   136,   139,
     -73,   -73,    80,   120,   -73,   112,    31,   112,   140,   -73,
      31,   -73,   135,   146,   -73,   -73,   -73,   112,   112,   -73,
     -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    21,    22,    23,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    26,     0,     0,     0,    20,     0,    12,
       0,    17,     0,    24,     9,     0,    10,     0,    16,    27,
       0,    32,    13,     8,     0,    15,     0,     0,    19,    40,
       0,     0,     0,     0,     0,     0,    42,    60,    61,     0,
      30,     0,    32,    28,     0,    31,    57,     0,    44,    46,
      48,    50,    52,    56,    11,    14,    25,     0,     0,     0,
       0,     0,     0,    57,    55,    65,     0,    54,    26,    18,
      29,    33,     0,    62,    63,    41,     0,     0,     0,     0,
      59,     0,     0,     0,    39,     0,    67,     0,    64,     0,
      45,    47,    51,    49,    53,    32,     0,    32,     0,    58,
       0,    43,    35,     0,    37,    38,    66,    32,    32,    36,
      34
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -73,   -73,   -73,   148,   -73,   -73,   -73,   -73,   -73,   -30,
      15,    14,   -73,   -73,   -51,   -73,   -56,   -40,   -37,   -72,
      68,    67,    71,   -38,   -73,   -73,   -73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,    34,    25,    20,    32,
      50,    51,    14,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    97,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    80,    37,    96,    64,    73,    71,    74,    39,    73,
     100,    77,    26,    92,    10,     9,    17,    18,    27,    10,
       9,     1,     2,    45,    81,     3,    46,    47,    48,    21,
      49,    91,    11,    93,    37,    73,   106,    22,   116,    99,
      82,    35,    73,    83,    84,    24,    73,    73,    73,    73,
      87,   104,    88,    15,   112,    45,   114,    16,    46,    47,
      48,    13,    49,    83,    84,    37,   119,   120,    38,   113,
      73,    39,    75,     1,     2,    23,    76,     3,    40,    28,
      41,    42,    43,    44,    29,    30,    45,    31,    33,    46,
      47,    48,    37,    49,    36,    79,    66,    65,    39,    68,
       1,     2,    69,    70,     3,    40,    72,    41,    42,    43,
      44,    78,    89,    45,    85,    37,    46,    47,    48,    86,
      49,    39,    90,     1,     2,    94,    16,     3,    40,    95,
      41,    42,    43,    44,   105,   107,    45,    19,   108,    46,
      47,    48,   109,    49,     1,     2,   110,   111,     3,   115,
     118,    87,   117,    12,   101,   103,     0,     0,   102
};

static const yytype_int8 yycheck[] =
{
      37,    52,     3,    75,    34,    45,    43,    45,     9,    49,
      82,    49,     4,    69,     0,     0,     9,    10,    10,     5,
       5,    11,    12,    24,    54,    15,    27,    28,    29,    15,
      31,    68,     0,    70,     3,    75,    92,    28,   110,    76,
      22,    27,    82,    25,    26,     9,    86,    87,    88,    89,
      31,    89,    33,     3,   105,    24,   107,     7,    27,    28,
      29,    27,    31,    25,    26,     3,   117,   118,     6,   106,
     110,     9,     3,    11,    12,    27,     7,    15,    16,    27,
      18,    19,    20,    21,     8,     7,    24,     5,     9,    27,
      28,    29,     3,    31,    28,     6,     8,    27,     9,     3,
      11,    12,     3,     3,    15,    16,     3,    18,    19,    20,
      21,    27,    32,    24,     9,     3,    27,    28,    29,    34,
      31,     9,     4,    11,    12,     9,     7,    15,    16,    27,
      18,    19,    20,    21,     4,     4,    24,     4,     4,    27,
      28,    29,     4,    31,    11,    12,    10,     8,    15,     9,
       4,    31,    17,     5,    86,    88,    -1,    -1,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    12,    15,    36,    37,    38,    39,    40,    45,
      46,     0,    38,    27,    47,     3,     7,     9,    10,     4,
      43,    46,    28,    27,     9,    42,     4,    10,    27,     8,
       7,     5,    44,     9,    41,    46,    28,     3,     6,     9,
      16,    18,    19,    20,    21,    24,    27,    28,    29,    31,
      45,    46,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    44,    27,     8,    53,     3,     3,
       3,    53,     3,    52,    58,     3,     7,    58,    27,     6,
      49,    44,    22,    25,    26,     9,    34,    31,    33,    32,
       4,    53,    51,    53,     9,    27,    54,    60,    61,    53,
      54,    55,    57,    56,    58,     4,    51,     4,     4,     4,
      10,     8,    49,    53,    49,     9,    54,    17,     4,    49,
      49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    38,    39,    39,
      41,    40,    42,    40,    43,    43,    43,    43,    44,    44,
      45,    46,    46,    46,    47,    47,    47,    47,    48,    48,
      49,    49,    50,    49,    49,    49,    49,    49,    49,    49,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     3,     2,
       3,     1,     1,     1,     3,     6,     1,     4,     1,     2,
       1,     1,     0,     2,     7,     5,     7,     5,     5,     3,
       1,     2,     1,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     2,     1,     1,     4,     3,
       1,     1,     2,     2,     1,     0,     3,     1
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
  case 2: /* start: program  */
#line 72 "parser.y"
        {
		//write your code in this block in all the similar blocks below
		logout << "Line " << line_count << ": start : program\n\n";
		table->printAllShorts(logout);
	}
#line 1369 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 80 "parser.y"
        {
		logout << "Line " << line_count << ": program : program unit\n\n";
		logout << (yyvsp[-1].Symbol)-> getName() << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)-> getName() + (yyvsp[0].Symbol)-> getName(), "nonterm");
	}
#line 1379 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 86 "parser.y"
        {
		logout << "Line " << line_count << ": program : unit\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	}
#line 1389 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 94 "parser.y"
        {
		logout << "Line " << line_count << ": unit : var_declaration\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	}
#line 1399 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 100 "parser.y"
         {
		logout << "Line " << line_count << ": unit : func_declaration\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	 }
#line 1409 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 106 "parser.y"
         {
		logout << "Line " << line_count << ": unit : func_definition\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	 }
#line 1419 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 114 "parser.y"
                {
			logout << "Line " << line_count << ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n";
			logout << (yyvsp[-5].Symbol)-> getName() << " " << (yyvsp[-4].Symbol)-> getName() << "(" << (yyvsp[-2].Symbol)-> getName() << ");\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-5].Symbol)-> getName() + " " +  (yyvsp[-4].Symbol)-> getName() + "(" + (yyvsp[-2].Symbol)-> getName() + ");\n", "nonterm");
			//$$->parameterList = $4-> parameterList;

			SymbolInfo *temp = table->lookUpSymbol_currentScope(new SymbolInfo((yyvsp[-4].Symbol)-> getName(), ""));
			if(temp != nullptr){
				error ++;
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-4].Symbol)->getName() << "\n\n";
			}else{
				SymbolInfo *tempFunc = new SymbolInfo((yyvsp[-4].Symbol)-> getName(), "ID");
				tempFunc->setIsFunc(true); tempFunc->setReturn_type((yyvsp[-5].Symbol)->getName()); tempFunc->setIfDefined(false); tempFunc-> parameterList = (yyvsp[-2].Symbol)-> parameterList;
				if(table->insertSymbol(tempFunc)){}
				else{cout << "unsuccessful insertion in func_declaration";}

				//SymbolInfo *newTemp = table-> lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));

			}
		}
#line 1444 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 135 "parser.y"
                {
			logout << "Line " << line_count << ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n";
			logout << (yyvsp[-4].Symbol)-> getName() << " " << (yyvsp[-3].Symbol)-> getName() << "();\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-4].Symbol)-> getName() + " " +  (yyvsp[-3].Symbol)-> getName() + "();\n", "nonterm");

			SymbolInfo *temp = table->lookUpSymbol_currentScope(new SymbolInfo((yyvsp[-3].Symbol)-> getName(), ""));
			if(temp != nullptr){
				error ++;
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].Symbol)->getName() << "\n\n";
			}else{
				SymbolInfo *tempFunc = new SymbolInfo((yyvsp[-3].Symbol)-> getName(), "ID");
				tempFunc->setIsFunc(true); tempFunc->setReturn_type((yyvsp[-4].Symbol)->getName()); tempFunc->setIfDefined(false);
				if(table->insertSymbol(tempFunc)){}
				else{cout << "unsuccessful insertion in func_declaration";}

				//SymbolInfo *newTemp = table-> lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));

			}
		}
#line 1468 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 157 "parser.y"
                {
			string funcNameFound = (yyvsp[-3].Symbol)-> getName();
			string returnTypeFound = (yyvsp[-4].Symbol)-> getName();
			

			vector<parameter> parametersFound = (yyvsp[-1].Symbol)-> parameterList;
			SymbolInfo *ifExists = table-> lookUpSymbol(new SymbolInfo(funcNameFound, ""));

			//Error
			if(ifExists != nullptr){
				if(ifExists-> getIsFunc()){
					if(ifExists-> getIfDefined()){
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].Symbol)->getName() << "\n\n";
					}
					else{
						bool validity = true;
						string declaredReturnType = ifExists-> getReturn_type();
						int parameterCount1 = ifExists-> parameterList.size();
						int parameterCount2 = parametersFound.size();
						if(parameterCount1 != parameterCount2){
							error ++;
							errorout << "Error at line " << line_count << ": The number of parameters are not the same for the function " << (yyvsp[-3].Symbol)->getName() << "()\n\n";
							validity = false;
						}
						else{
						
							if(parameterCount1 != 0){
								for(int i=0; i<parameterCount1; i++){
									string tempReturnType1 = ifExists->parameterList[i].type;
									string tempReturnType2 = parametersFound[i].type; 
									if(tempReturnType1 != tempReturnType2){
										error ++;
										errorout << "Error at line " << line_count << ": Return type does not match for parameter" << parametersFound[i].name << "\n\n";
										validity = false;
									}
								}
							}
						}
						if(returnTypeFound != declaredReturnType){
							error ++;
							errorout << "Error at line " << line_count << ": Return type does not match for the function " << (yyvsp[-3].Symbol)->getName() << "()\n\n";
							validity = false;
						}


						table-> removeSymbol(new SymbolInfo(funcNameFound, ""));
						SymbolInfo *tempFunc = new SymbolInfo(funcNameFound, "ID");
						tempFunc->parameterList = parametersFound;
						tempFunc-> setIfDefined(true);
						tempFunc-> setIsFunc(true);
						tempFunc->setReturn_type(returnTypeFound);
						//logout << "now inserting within function def\n\n";
						table-> insertSymbol(tempFunc);

						table-> EnterScope();
						for(int i=0; i< parametersFound.size(); i++){
							if(table->insertSymbol(new SymbolInfo(parametersFound[i].name, parametersFound[i].type))){}
							else{
								error ++;
								errorout << "Error at line " << line_count << ": Multiple declaration of variables in parameter " << parametersFound[i].name << "()\n\n";
							}
						}

					}
				}else{
					table-> EnterScope();
					error ++;
					errorout << "Error at line " << line_count << ": ID is not a function : " << (yyvsp[-3].Symbol)->getName()  << "()\n\n";

				}
			}else{
				SymbolInfo *tempFunc = new SymbolInfo(funcNameFound, "ID");
				tempFunc-> parameterList = parametersFound;
				tempFunc-> setIfDefined(true);
				tempFunc-> setIsFunc(true);
				tempFunc->setReturn_type(returnTypeFound);
				table-> insertSymbol(tempFunc);

				table-> EnterScope();
				for(int i=0; i< parametersFound.size(); i++){
					if(table->insertSymbol(new SymbolInfo(parametersFound[i].name, parametersFound[i].type))){}
					else{
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of variables in parameter " << parametersFound[i].name << "()\n\n";
					}
				}

			}
		}
#line 1563 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 248 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-6].Symbol)->getName()+ " "  + (yyvsp[-5].Symbol)->getName() + "(" + (yyvsp[-3].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName(), "func_def");
			logout << "Line " << line_count << ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n";
			logout << (yyvsp[-6].Symbol)-> getName() << " " << (yyvsp[-5].Symbol)-> getName() << "(" << (yyvsp[-3].Symbol)->getName() << ")" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 1573 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 255 "parser.y"
                {
			string funcNameFound = (yyvsp[-2].Symbol)-> getName();
			string returnTypeFound = (yyvsp[-3].Symbol)-> getName();

			SymbolInfo *ifExists = table-> lookUpSymbol(new SymbolInfo(funcNameFound, ""));

			//Error
			if(ifExists != nullptr){
				if(ifExists-> getIsFunc()){
					if(ifExists-> getIfDefined()){
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-2].Symbol)->getName() << "\n\n";
					}
					else{
						bool validity = true;
						string declaredReturnType = ifExists-> getReturn_type();
						//cout << returnTypeFound << " " << declaredReturnType << endl;
						if(returnTypeFound != declaredReturnType){
							error ++;
							errorout << "Error at line " << line_count << ": Return type does not match for the function " << (yyvsp[-2].Symbol)->getName() << "()\n\n";
							validity = false;
						}
						table-> EnterScope();

					}
				}else{
					table-> EnterScope();
					error ++;
					errorout << "Error at line " << line_count << ": ID is not a function : " << (yyvsp[-2].Symbol)->getName()  << "()\n\n";

				}
			}else{
				SymbolInfo *tempFunc = new SymbolInfo(funcNameFound, "ID");
				tempFunc-> setIfDefined(true);
				tempFunc-> setIsFunc(true);
				tempFunc-> setReturn_type(returnTypeFound);
				table-> insertSymbol(tempFunc);

				table-> EnterScope();

			}
		}
#line 1620 "y.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 298 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-5].Symbol)->getName()+ " "  + (yyvsp[-4].Symbol)->getName() + "()" + (yyvsp[0].Symbol)->getName(), "func_def");
			logout << "Line " << line_count << ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n";
			logout << (yyvsp[-5].Symbol)-> getName() << " " << (yyvsp[-4].Symbol)-> getName() << "()" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 1630 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 307 "parser.y"
                {
			logout << "Line " << line_count << ": parameter_list  : parameter_list COMMA type_specifier ID\n\n";
			logout << (yyvsp[-3].Symbol)-> getName() << " , " << (yyvsp[-1].Symbol)-> getName() << " " << (yyvsp[0].Symbol)->getName() << "\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-3].Symbol)-> getName() + "," +  (yyvsp[-1].Symbol)-> getName() + " " + (yyvsp[0].Symbol)->getName(), "nonterm");

			(yyval.Symbol)-> parameterList = (yyvsp[-3].Symbol)-> parameterList;
			(yyval.Symbol)-> parameterListAdd((yyvsp[0].Symbol)-> getName(), (yyvsp[-1].Symbol)-> getName());

			//Error
			if((yyvsp[-1].Symbol)-> getName() == "void"){
				error ++;
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
			}
		}
#line 1649 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 322 "parser.y"
                {
			logout << "Line " << line_count << ": parameter_list  : parameter_list COMMA type_specifier\n\n";
			logout << (yyvsp[-2].Symbol)-> getName() << " , " << (yyvsp[0].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)-> getName() + "," +  (yyvsp[0].Symbol)-> getName(), "nonterm");

			(yyval.Symbol)-> parameterList = (yyvsp[-2].Symbol)-> parameterList;
			(yyval.Symbol)-> parameterListAdd("", (yyvsp[0].Symbol)-> getName());
		}
#line 1662 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 331 "parser.y"
                {
			logout << "Line " << line_count << ": parameter_list  : type_specifier ID\n\n";
			logout << (yyvsp[-1].Symbol)-> getName() << " " << (yyvsp[0].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)-> getName() + " " + (yyvsp[0].Symbol)-> getName() , "nonterm");

			//cout << "in param list " << $1->getName() + " " + $2-> getName() << "and type " << $1->getType() + " " + $2-> getType()<< endl;
			//Error
			if((yyvsp[-1].Symbol)-> getName() == "void"){
				error ++;
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
			}
			(yyval.Symbol)-> parameterListAdd((yyvsp[0].Symbol)-> getName(), (yyvsp[-1].Symbol)-> getName());
		}
#line 1680 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 345 "parser.y"
                {
			logout << "Line " << line_count << ": parameter_list  : type_specifier\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = (yyvsp[0].Symbol);

			(yyval.Symbol)-> parameterListAdd("", (yyvsp[0].Symbol)-> getName());
		}
#line 1692 "y.tab.c"
    break;

  case 18: /* compound_statement: LCURL statements RCURL  */
#line 356 "parser.y"
                        {
				(yyval.Symbol) = new SymbolInfo("{\n" + (yyvsp[-1].Symbol)->getName() +  "}", "compound");
				logout << "Line " << line_count << ": compound_statement : LCURL statements RCURL\n\n";
				logout << "{\n" << " " << (yyvsp[-1].Symbol)->getName() << "}\n\n";
				table-> printAllShorts(logout);
				table-> ExitScope();
				variableList.clear();
			}
#line 1705 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL RCURL  */
#line 365 "parser.y"
                        {
				(yyval.Symbol) = new SymbolInfo("{\n}", "compound");
				logout << "Line " << line_count << ": compound_statement : LCURL RCURL\n\n";
				logout << "{\n}\n\n";
				table-> printAllShorts(logout);
				table-> ExitScope();
				variableList.clear();
			}
#line 1718 "y.tab.c"
    break;

  case 20: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 376 "parser.y"
                {
			string Type_found = (yyvsp[-2].Symbol)->getName();
			string Var_found = (yyvsp[-1].Symbol)->getName();
			logout << "Line " << line_count << ": var_declaration : type_specifier declaration_list SEMICOLON\n\n";
			logout << Type_found << " " << Var_found << ";\n\n";
			(yyval.Symbol) = new SymbolInfo(Type_found + " " + Var_found + ";\n", "nonterm");

			(yyval.Symbol)->setVariable_type(Type_found);
			for(int i=0; i< (yyvsp[-1].Symbol)->varList.size(); i++){
				(yyvsp[-1].Symbol)->varList[i].type = Type_found;
			}
				

			//Error	
			if(Type_found == "void"){
				error ++ ;
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
				//logout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
			}

			//not_error
			else{
				SymbolInfo *temp;
				for(int i=0; i< (yyvsp[-1].Symbol)->varList.size(); i++){
					temp = table->lookUpSymbol_currentScope(new SymbolInfo((yyvsp[-1].Symbol)->varList[i].name, ""));

					//Error
					if(temp != nullptr){
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-1].Symbol)->varList[i].name << "\n\n";
						//logout << "Error at line " << line_count << ": Multiple declaration of " << $2->varList[i].name << "\n\n";
					}

					//not_error
					else{
						temp = new SymbolInfo((yyvsp[-1].Symbol)->varList[i].name, "ID");

						if((yyvsp[-1].Symbol)->varList[i].ifArray != 0){
							temp->setId("array");
						}else{
							temp->setId("variable");
						}
						if(table->insertSymbol(temp)){/*cout << "hoitese " << $2->varList[i].name << endl;*/}
						else{
							cout << "insertion to table unsuccessful in var_declaration\n";
						}


						//todo(somewhat solved)
						// SymbolInfo *newTemp = table->lookUpSymbol_currentScope(new SymbolInfo($2->varList[i].name, ""));
						// newTemp-> setVariable_type(Type_found);
						//newTemp-> setId($2-> getId());
						
					}
				}
			}
		}
#line 1780 "y.tab.c"
    break;

  case 21: /* type_specifier: INT  */
#line 436 "parser.y"
                {
			logout << "Line " << line_count << ": type_specifier : INT\n\nint\n\n";
			(yyval.Symbol) = new SymbolInfo("int" , "int");
		}
#line 1789 "y.tab.c"
    break;

  case 22: /* type_specifier: FLOAT  */
#line 441 "parser.y"
                {
			logout << "Line " << line_count << ": type_specifier : FLOAT\n\nfloat\n\n";
			(yyval.Symbol) = new SymbolInfo("float" , "float");
		}
#line 1798 "y.tab.c"
    break;

  case 23: /* type_specifier: VOID  */
#line 446 "parser.y"
                {
			logout << "Line " << line_count << ": type_specifier : VOID\n\nvoid\n\n";
			(yyval.Symbol) = new SymbolInfo("void" , "void");
		}
#line 1807 "y.tab.c"
    break;

  case 24: /* declaration_list: declaration_list COMMA ID  */
#line 453 "parser.y"
                {
			logout << "Line " << line_count << ": declaration_list : declaration_list COMMA ID\n\n";
			logout << (yyvsp[-2].Symbol)->getName() << "," << (yyvsp[0].Symbol)->getName() << "\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + "," + (yyvsp[0].Symbol)->getName(), "nonterm");
			(yyval.Symbol)->setId("variable");

			tempVar.name = (yyvsp[0].Symbol)-> getName();
			tempVar.size = -1;
			variableList.push_back(tempVar);
			(yyval.Symbol)->varList = (yyvsp[-2].Symbol)->varList;
			(yyval.Symbol)->varListAdd((yyvsp[0].Symbol)->getName(),(yyvsp[0].Symbol)->getType() , 0);
			
		}
#line 1825 "y.tab.c"
    break;

  case 25: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 467 "parser.y"
                {
			logout << "Line " << line_count << ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n";
			logout << (yyvsp[-5].Symbol)->getName() << "," << (yyvsp[-3].Symbol)->getName() << "[" << (yyvsp[-1].Symbol)->getName() << "]\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-5].Symbol)->getName() + "," + (yyvsp[-3].Symbol)->getName() + "[" + (yyvsp[-1].Symbol)->getName() + "]", "nonterm");
			(yyval.Symbol)->setId("array");

			tempVar.name = (yyvsp[-3].Symbol)-> getName();
			stringstream tempStr((yyvsp[-1].Symbol)-> getName());
			tempStr >> tempVar.size;
			variableList.push_back(tempVar);

			stringstream diff((yyvsp[-1].Symbol)-> getName());
			int size = 0;
			diff >> size;
			(yyval.Symbol)->varList = (yyvsp[-5].Symbol)->varList;
			(yyval.Symbol)->varListAdd((yyvsp[-3].Symbol)->getName(), (yyvsp[-3].Symbol)->getType() , size);
		}
#line 1847 "y.tab.c"
    break;

  case 26: /* declaration_list: ID  */
#line 485 "parser.y"
                {
			logout << "Line " << line_count << ": declaration_list : ID\n\n";
			logout << (yyvsp[0].Symbol)->getName() << "\n\n";
			(yyval.Symbol) = (yyvsp[0].Symbol); //new SymbolInfo($1->getName(), "ID");
			(yyval.Symbol)->setId("variable");

			tempVar.name = (yyvsp[0].Symbol)-> getName();
			tempVar.size = -1;
			variableList.push_back(tempVar);
			(yyval.Symbol)->varList = (yyvsp[0].Symbol)->varList;
			(yyval.Symbol)->varListAdd((yyvsp[0].Symbol)->getName(), (yyvsp[0].Symbol)->getType(), 0);
		}
#line 1864 "y.tab.c"
    break;

  case 27: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 498 "parser.y"
                {
			logout << "Line " << line_count << ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n";
			logout << (yyvsp[-3].Symbol)->getName() << "[" << (yyvsp[-1].Symbol)->getName() << "]\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-3].Symbol)->getName() + "[" + (yyvsp[-1].Symbol)->getName() + "]", "nonterm");
			
			tempVar.name = (yyvsp[-3].Symbol)-> getName();
			stringstream tempStr((yyvsp[-1].Symbol)-> getName());
			tempStr >> tempVar.size;
			variableList.push_back(tempVar);

			stringstream diff((yyvsp[-1].Symbol)-> getName());
			int size = 0;
			diff >> size;
			(yyval.Symbol)->varList = (yyvsp[-3].Symbol)->varList;
			(yyval.Symbol)->varListAdd((yyvsp[-3].Symbol)->getName(), "" , size);
		}
#line 1885 "y.tab.c"
    break;

  case 28: /* statements: statement  */
#line 517 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statements : statement\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 1895 "y.tab.c"
    break;

  case 29: /* statements: statements statement  */
#line 523 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + " " + (yyvsp[0].Symbol)->getName(), "statements");
			logout << "Line " << line_count << ": statements : statements statement\n\n";
			logout << (yyvsp[-1].Symbol)-> getName() << " " << (yyvsp[0].Symbol)->getName() << "\n\n";
		}
#line 1905 "y.tab.c"
    break;

  case 30: /* statement: var_declaration  */
#line 531 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statement : var_declaration\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 1915 "y.tab.c"
    break;

  case 31: /* statement: expression_statement  */
#line 537 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statement : expression_statement\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 1925 "y.tab.c"
    break;

  case 32: /* $@3: %empty  */
#line 543 "parser.y"
                  {table-> EnterScope();}
#line 1931 "y.tab.c"
    break;

  case 33: /* statement: $@3 compound_statement  */
#line 544 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statement : compound_statement\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 1941 "y.tab.c"
    break;

  case 34: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 550 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo("for(" + (yyvsp[-4].Symbol)->getName() + (yyvsp[-3].Symbol)->getName() + (yyvsp[-2].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName() , "statement");
			logout << "Line " << line_count << ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n";
			logout << "for(" << (yyvsp[-4].Symbol)-> getName() << " " <<  (yyvsp[-3].Symbol)->getName() << " " << (yyvsp[-2].Symbol)->getName() << ")" << (yyvsp[0].Symbol)->getName() << "\n\n";
		}
#line 1951 "y.tab.c"
    break;

  case 35: /* statement: IF LPAREN expression RPAREN statement  */
#line 556 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo("if(" + (yyvsp[-2].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName() , "statement");
			logout << "Line " << line_count << ": statement : IF LPAREN expression RPAREN statement\n\n";
			logout << "if(" << (yyvsp[-2].Symbol)-> getName() <<  ")" << (yyvsp[0].Symbol)->getName() << "\n\n";
		}
#line 1961 "y.tab.c"
    break;

  case 36: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 562 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo("if(" + (yyvsp[-4].Symbol)->getName() + ")" + (yyvsp[-2].Symbol)->getName() + "else" + (yyvsp[0].Symbol)-> getName() , "statement");
			logout << "Line " << line_count << ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n";
			logout << "if(" << (yyvsp[-4].Symbol)-> getName() <<  ")" << (yyvsp[0].Symbol)->getName() << "else" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 1971 "y.tab.c"
    break;

  case 37: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 568 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo("while(" + (yyvsp[-2].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName() , "statement");
			logout << "Line " << line_count << ": statement : WHILE LPAREN expression RPAREN statement\n\n";
			logout << "while(" << (yyvsp[-2].Symbol)-> getName() <<  ")" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 1981 "y.tab.c"
    break;

  case 38: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 574 "parser.y"
                {
			string nameFound = (yyvsp[-2].Symbol)-> getName();
			SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, ""));

			if(ifExists == nullptr){
				error ++ ;
				errorout << "Error at line " << line_count << ": ID not declared :" << nameFound <<"\n\n";
			}else{
				if(ifExists-> getIsFunc()){
					error ++ ;
					errorout << "Error at line " << line_count << ": function can not be inside a print function : "<< nameFound << "\n\n";
				}

			}	

			(yyval.Symbol) = new SymbolInfo("printf(" + (yyvsp[-2].Symbol)->getName() + ");\n", "statement");
			logout << "Line " << line_count << ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n";
			logout << "printf(" << (yyvsp[-2].Symbol)-> getName() <<  ");\n\n";
		}
#line 2005 "y.tab.c"
    break;

  case 39: /* statement: RETURN expression SEMICOLON  */
#line 594 "parser.y"
                {
			string returnTypeFound = (yyvsp[-1].Symbol)->getReturn_type();
			if(returnTypeFound == "void"){
				error ++ ;
				errorout << "Error at line " << line_count << ": void doesnt have return types\n\n";
			}
			(yyval.Symbol) = new SymbolInfo("return " + (yyvsp[-1].Symbol)->getName() + ";\n", "statement");
			logout << "Line " << line_count << ": statement : RETURN expression SEMICOLON\n\n";
			logout << "return " << (yyvsp[-1].Symbol)-> getName() <<  ";\n\n";
		}
#line 2020 "y.tab.c"
    break;

  case 40: /* expression_statement: SEMICOLON  */
#line 607 "parser.y"
                        {
				(yyval.Symbol) = new SymbolInfo(";\n", "statement");
			}
#line 2028 "y.tab.c"
    break;

  case 41: /* expression_statement: expression SEMICOLON  */
#line 611 "parser.y"
                        {
				(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + ";\n", "expression_statement");
				logout << "Line " << line_count << ": expression_statement : expression SEMICOLON \n\n";
				logout << (yyvsp[-1].Symbol)-> getName() <<  ";\n\n";
			}
#line 2038 "y.tab.c"
    break;

  case 42: /* variable: ID  */
#line 619 "parser.y"
        {
		string nameFound = (yyvsp[0].Symbol)->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, ""));

		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			(yyval.Symbol) = new SymbolInfo(nameFound , "INVALID");
		}else{
			if(ifExists->getId() == "array"){
				error ++ ;
			
				errorout << "Error at line " << line_count << ": Type mismatch, "<< nameFound  <<" is an array\n\n";
				(yyval.Symbol) = new SymbolInfo(nameFound, "INVALID");

			}else{
				(yyval.Symbol) = new SymbolInfo(nameFound, ifExists->getType());
			}
		}
		logout << "Line " << line_count << ": variable : ID\n\n";
		logout << (yyvsp[0].Symbol)-> getName() <<  "\n\n";

	}
#line 2066 "y.tab.c"
    break;

  case 43: /* variable: ID LTHIRD expression RTHIRD  */
#line 643 "parser.y"
        {
		string nameFound = (yyvsp[-3].Symbol)->getName();
		string indexType = (yyvsp[-1].Symbol)->getType();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, "" ));
		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			(yyval.Symbol) = new SymbolInfo(nameFound , "INVALID");
		}else{
			if(ifExists->getId() == "array"){
				string finalType = indexType;
				if(indexType != "int"){
					error ++ ;
					errorout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
					//cout << "index type for " << $3->getName() << " is " << indexType << "\n";
					finalType = "INVALID";
				}
				else if(stoi((yyvsp[-1].Symbol)->getName()) < 0){
					error ++ ;
					errorout << "Error at line " << line_count << ": Expression inside third brackets is negative :" << (yyvsp[-1].Symbol)-> getName() << "\n\n";
					finalType = "INVALID";
				}
				SymbolInfo *temp = new SymbolInfo(nameFound + "[" + (yyvsp[-1].Symbol)->getName() + "]", finalType);
				(yyval.Symbol) = temp;

			}else{
				error ++ ;
				errorout << "Error at line " << line_count << ": Type mismatch, "<< nameFound  <<" is a variable\n\n";
				(yyval.Symbol) =  new SymbolInfo(nameFound + "[" + (yyvsp[-1].Symbol)->getName() + "]", "INVALID");
			}
		}
		logout << "Line " << line_count << ": variable : ID LTHIRD expression RTHIRD\n\n";
		logout << (yyvsp[-3].Symbol)-> getName() << "[" << (yyvsp[-1].Symbol)->getName() << "]\n\n";
	}
#line 2105 "y.tab.c"
    break;

  case 44: /* expression: logic_expression  */
#line 680 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": expression : logic_expression\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 2115 "y.tab.c"
    break;

  case 45: /* expression: variable ASSIGNOP logic_expression  */
#line 686 "parser.y"
           {
			string operand1 = (yyvsp[-2].Symbol)-> getName();
			string operand2 = (yyvsp[0].Symbol)-> getName();
			string type1 = (yyvsp[-2].Symbol)-> getType();
			string type2 = (yyvsp[0].Symbol)-> getType();

			if(type1 == type2){

			}else{
				if(type1 == "INVALID" || type2 == "INVALID"){
					if((yyvsp[-2].Symbol)->getId() == "array"){
						error ++ ;
						errorout << "Error at line " << line_count << ": Type mismatch, "<< (yyvsp[-2].Symbol)->getName()  <<" is an array\n\n";
					}else if((yyvsp[0].Symbol)->getName() == "array"){
						error ++ ;
						errorout << "Error at line " << line_count << ": Type mismatch, "<< (yyvsp[0].Symbol)->getName()  <<" is an array\n\n";
					}
				}else if(type1 == "float" && type2 == "int"){}
				else{
					error ++ ;
					//cout << "types mismatched for var " << operand1 << " type: " << type1 << " id: " << $1->getReturn_type() <<endl; 
					errorout << "Error at line " << line_count << ": Type mismatch for variable "<< (yyvsp[-2].Symbol)->getName()  <<"\n\n";
				}
			}

			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + "=" + (yyvsp[0].Symbol)->getName() , "expression");
			logout << "Line " << line_count << ": expression : variable ASSIGNOP logic_expression\n\n";
			logout << (yyvsp[-2].Symbol)->getName() << "=" << (yyvsp[0].Symbol)->getName() <<"\n\n";
	   }
#line 2149 "y.tab.c"
    break;

  case 46: /* logic_expression: rel_expression  */
#line 719 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": logic_expression : rel_expression \n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2159 "y.tab.c"
    break;

  case 47: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 725 "parser.y"
                {
			string type1 = (yyvsp[-2].Symbol)->getType();
			string type2 = (yyvsp[0].Symbol)->getType();
			string finalType = "int";

			if(type1 == type2){}
			else{
				if(type1 != "int" || type2!= "int"){
					cout << "rel express types are " << type1 << " " << type2 << endl;
					error ++ ;
					errorout << "Error at line " << line_count << ": not integer type found : " << "\n\n";
					//todo
					//finalType = "INVALID";
				}
			}
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)-> getName() + (yyvsp[0].Symbol)->getName() , finalType);
			logout << "Line " << line_count << ": logic_expression : rel_expression LOGICOP rel_expression \n\n";
			logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2183 "y.tab.c"
    break;

  case 48: /* rel_expression: simple_expression  */
#line 747 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": rel_expression : simple_expression \n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2193 "y.tab.c"
    break;

  case 49: /* rel_expression: simple_expression RELOP simple_expression  */
#line 753 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)-> getName() + (yyvsp[0].Symbol)->getName() , "int");
			logout << "Line " << line_count << ": rel_expression : simple_expression RELOP simple_expression\n\n";
			logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2203 "y.tab.c"
    break;

  case 50: /* simple_expression: term  */
#line 761 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": simple_expression : term \n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2213 "y.tab.c"
    break;

  case 51: /* simple_expression: simple_expression ADDOP term  */
#line 767 "parser.y"
                {
			string type1 = (yyvsp[-2].Symbol)->getType();
			string type2 = (yyvsp[0].Symbol)->getType();

			if(type1 == "float" || type2 == "float")
				(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)->getName() + (yyvsp[0].Symbol)->getName(), "float");
			else
				(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)->getName() + (yyvsp[0].Symbol)->getName(), "int");
			logout << "Line " << line_count << ": simple_expression : simple_expression ADDOP term \n\n";
			logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2229 "y.tab.c"
    break;

  case 52: /* term: unary_expression  */
#line 781 "parser.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": term : unary_expression\n\n";
		logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
	}
#line 2239 "y.tab.c"
    break;

  case 53: /* term: term MULOP unary_expression  */
#line 787 "parser.y"
        {
		string operand1 = (yyvsp[-2].Symbol)-> getName();
		string operand2 = (yyvsp[0].Symbol)-> getName();
		string type1 = (yyvsp[-2].Symbol)-> getType();
		string type2 = (yyvsp[0].Symbol)-> getType();
		string operatorFound = (yyvsp[-1].Symbol)->getName();
		string finalType = "int";

		if(operatorFound == "/" || operatorFound == "*"){
			if(type1 == "float" || type2 == "float")
				finalType = "float";

		}else if(operatorFound == "%"){
			if(type1 != "int" || type2 != "int"){
				error ++ ;
				errorout << "Error at line " << line_count << ": Non-Integer operand on modulus operator\n\n";
				finalType = "INVALID";
			}else{
				if(operand2 == "0"){
					//todo
					finalType = "INVALID";
				}
			}
		}else{
			//todo
		}

		(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)->getName() + (yyvsp[0].Symbol)->getName() , finalType);
		logout << "Line " << line_count << ": term : term MULOP unary_expression\n\n";
		logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
	}
#line 2275 "y.tab.c"
    break;

  case 54: /* unary_expression: ADDOP unary_expression  */
#line 821 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName()  + (yyvsp[0].Symbol)->getName(), "unary");
			logout << "Line " << line_count << ": unary_expression : ADDOP unary_expression \n\n";
			logout << (yyvsp[-1].Symbol)-> getName()  << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2285 "y.tab.c"
    break;

  case 55: /* unary_expression: NOT unary_expression  */
#line 827 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo("!" + (yyvsp[0].Symbol)->getName(), "unary");
			logout << "Line " << line_count << ": unary_expression : NOT unary_expression \n\n";
			logout << "!"  << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2295 "y.tab.c"
    break;

  case 56: /* unary_expression: factor  */
#line 833 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": unary_expression : factor\n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2305 "y.tab.c"
    break;

  case 57: /* factor: variable  */
#line 841 "parser.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": factor : variable\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
	}
#line 2315 "y.tab.c"
    break;

  case 58: /* factor: ID LPAREN argument_list RPAREN  */
#line 847 "parser.y"
        {
		string nameFound = (yyvsp[-3].Symbol)->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo((yyvsp[-3].Symbol)->getName(),""));
		string returnTypeDeclared = ifExists->getType();

		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": ID is not declared : " << nameFound << "\n\n";
		}else{
			if(ifExists->getIsFunc()){
				//todo
			
				if(returnTypeDeclared == "void"){
					error ++ ;
					errorout << "Error at line " << line_count << ": void functions cant be factors : " << nameFound << "\n\n";
				}else if(ifExists->parameterList.size() != (yyvsp[-1].Symbol)->argumentList.size()){
					error ++ ;
					errorout << "Error at line " << line_count << ": Number of arguments and parameters do not match for ID : " << nameFound << "\n\n";
					cout << "argument size " << (yyvsp[-1].Symbol)->argumentList.size() << " parameter size " << ifExists->parameterList.size() << endl;
				}else{
					for(int i=0; i < (yyvsp[-1].Symbol)->argumentList.size(); i++){
						if((yyvsp[-1].Symbol)->argumentList[i].type != ifExists->parameterList[i].type && (yyvsp[-1].Symbol)->argumentList[i].type != "INVALID"){
							cout << "argument type and parameter type: " << (yyvsp[-1].Symbol)->argumentList[i].type << " " << ifExists->parameterList[i].type << endl;
							error ++ ;
							errorout << "Error at line " << line_count << ": types mismatched for parameter : " << ifExists->parameterList[i].name << "\n\n";
						}
					}
				}

			}else{
				error ++ ;
				errorout << "Error at line " << line_count << ": non function accessed : " << nameFound << "\n\n";
			}
		}

		(yyval.Symbol) = new SymbolInfo((yyvsp[-3].Symbol)-> getName() + "(" + (yyvsp[-1].Symbol)->getName() + ")", returnTypeDeclared);
		logout << "Line " << line_count << ": factor : ID LPAREN argument_list RPAREN\n\n";
		logout << (yyvsp[-3].Symbol)-> getName() << "(" << (yyvsp[-1].Symbol)-> getName() << ")\n\n";
	}
#line 2359 "y.tab.c"
    break;

  case 59: /* factor: LPAREN expression RPAREN  */
#line 887 "parser.y"
        {
		(yyval.Symbol) = new SymbolInfo("(" + (yyvsp[-1].Symbol)->getName() + ")", "factor");
		logout << "Line " << line_count << ": factor : LPAREN expression RPAREN\n\n";
		logout << "(" << (yyvsp[-1].Symbol)-> getName() << ")" << "\n\n";
	}
#line 2369 "y.tab.c"
    break;

  case 60: /* factor: CONST_INT  */
#line 893 "parser.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": factor : CONST_INT\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
	}
#line 2379 "y.tab.c"
    break;

  case 61: /* factor: CONST_FLOAT  */
#line 899 "parser.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": factor : CONST_FLOAT\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
	}
#line 2389 "y.tab.c"
    break;

  case 62: /* factor: variable INCOP  */
#line 905 "parser.y"
        {
		(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + "++" , "factor");
		logout << "Line " << line_count << ": factor : variable INCOP \n\n";
		logout << (yyvsp[-1].Symbol)-> getName() << "++\n\n";
	}
#line 2399 "y.tab.c"
    break;

  case 63: /* factor: variable DECOP  */
#line 912 "parser.y"
        {
		(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + "--" , "factor");
		logout << "Line " << line_count << ": factor : variable DECOP\n\n";
		logout << (yyvsp[-1].Symbol)-> getName() << "--\n\n";
	}
#line 2409 "y.tab.c"
    break;

  case 64: /* argument_list: arguments  */
#line 920 "parser.y"
                                {
					(yyval.Symbol) = (yyvsp[0].Symbol);
					logout << "Line " << line_count << ": argument_list : arguments\n\n";
					logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
				}
#line 2419 "y.tab.c"
    break;

  case 65: /* argument_list: %empty  */
#line 926 "parser.y"
                                {
					(yyval.Symbol) = new SymbolInfo("", "void");
					logout << "Line " << line_count << ": argument_list : \n\n";
					logout << "\n\n";
				}
#line 2429 "y.tab.c"
    break;

  case 66: /* arguments: arguments COMMA logic_expression  */
#line 934 "parser.y"
                        {
				string nameFound = (yyvsp[-2].Symbol)->getName()+","+(yyvsp[0].Symbol)->getName();
				string typeFound = (yyvsp[-2].Symbol)->getType()+","+(yyvsp[0].Symbol)->getType();
				string finalType = (yyvsp[0].Symbol)->getType();

				(yyval.Symbol) = new SymbolInfo(nameFound, typeFound);
				(yyval.Symbol)-> argumentList = (yyvsp[-2].Symbol)-> argumentList;
				
				string varNameFound = (yyvsp[0].Symbol)-> getName();
				bool validity = false;
				//todo
				// for(variable indexedVar : variableList){
				// 	//cout << "variable is " << indexedVar.ifArray << endl;
				// 	if(varNameFound == indexedVar.name && indexedVar.size > 0){
				// 		validity = true;
				// 		$$->argumentListAdd(varNameFound, $3->getType(), indexedVar.size);
				// 		$$->setparamValidity($3->getparamValidity());
				// 		break;
				// 	}

				// 	if(!validity){
				// 		$$->argumentListAdd(varNameFound, $3->getType(), 0);
				// 	}
					
				// }
				(yyval.Symbol)-> argumentListAdd(varNameFound, (yyvsp[0].Symbol)->getType(), 0);
				logout << "Line " << line_count << ": arguments : arguments COMMA logic_expression\n\n";
				logout << (yyvsp[-2].Symbol)-> getName() << "," << (yyvsp[0].Symbol)->getName() << "\n\n";
			}
#line 2463 "y.tab.c"
    break;

  case 67: /* arguments: logic_expression  */
#line 964 "parser.y"
                        {
					(yyval.Symbol) = (yyvsp[0].Symbol);
					logout << "Line " << line_count << ": arguments : logic_expression\n\n";
					logout << (yyvsp[0].Symbol)-> getName() << "\n\n";

					string varNameFound = (yyvsp[0].Symbol)-> getName();
					bool validity = false;
					//todo
					// for(variable indexedVar : variableList){
					// 	if(varNameFound == indexedVar.name && indexedVar.size > 0){
					// 		validity = true;
					// 		$$->argumentListAdd(varNameFound, $1->getType(), indexedVar.size);
					// 		$$->setparamValidity($1->getparamValidity());
					// 		break;
					// 	}

					// 	if(!validity){
					// 		$$->argumentListAdd(varNameFound, $1->getType(), 0);
					// 	}
					
					// }
					(yyval.Symbol)->argumentListAdd(varNameFound, (yyvsp[0].Symbol)->getType(), 0);
		  		}
#line 2491 "y.tab.c"
    break;


#line 2495 "y.tab.c"

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

#line 990 "parser.y"

int main(int argc,char *argv[])
{
	logout.open("1805002_log.txt");
	errorout.open("1805002_error.txt");


	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	//fp2= fopen(argv[2],"w");
	//fclose(fp2);
	//fp3= fopen(argv[3],"w");
	//fclose(fp3);
	
	//fp2= fopen(argv[2],"a");
	//fp3= fopen(argv[3],"a");
	

	yyin=fp;
	yyparse();
	

	//fclose(fp2);
	//fclose(fp3);
	fclose(fp);
	
	return 0;
}

