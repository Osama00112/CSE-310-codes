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


SymbolTable *table = new SymbolTable(31,1);


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
    MAIN = 266,                    /* MAIN  */
    INT = 267,                     /* INT  */
    FLOAT = 268,                   /* FLOAT  */
    CHAR = 269,                    /* CHAR  */
    DOUBLE = 270,                  /* DOUBLE  */
    VOID = 271,                    /* VOID  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    FOR = 274,                     /* FOR  */
    WHILE = 275,                   /* WHILE  */
    RETURN = 276,                  /* RETURN  */
    PRINTLN = 277,                 /* PRINTLN  */
    ASSIGNOP = 278,                /* ASSIGNOP  */
    BITOP = 279,                   /* BITOP  */
    NOT = 280,                     /* NOT  */
    INCOP = 281,                   /* INCOP  */
    DECOP = 282,                   /* DECOP  */
    ID = 283,                      /* ID  */
    CONST_INT = 284,               /* CONST_INT  */
    CONST_FLOAT = 285,             /* CONST_FLOAT  */
    CONST_CHAR = 286,              /* CONST_CHAR  */
    ADDOP = 287,                   /* ADDOP  */
    MULOP = 288,                   /* MULOP  */
    RELOP = 289,                   /* RELOP  */
    LOGICOP = 290                  /* LOGICOP  */
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
#define MAIN 266
#define INT 267
#define FLOAT 268
#define CHAR 269
#define DOUBLE 270
#define VOID 271
#define IF 272
#define ELSE 273
#define FOR 274
#define WHILE 275
#define RETURN 276
#define PRINTLN 277
#define ASSIGNOP 278
#define BITOP 279
#define NOT 280
#define INCOP 281
#define DECOP 282
#define ID 283
#define CONST_INT 284
#define CONST_FLOAT 285
#define CONST_CHAR 286
#define ADDOP 287
#define MULOP 288
#define RELOP 289
#define LOGICOP 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "parser.y"

	SymbolInfo *Symbol;

#line 241 "y.tab.c"

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
  YYSYMBOL_MAIN = 11,                      /* MAIN  */
  YYSYMBOL_INT = 12,                       /* INT  */
  YYSYMBOL_FLOAT = 13,                     /* FLOAT  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_DOUBLE = 15,                    /* DOUBLE  */
  YYSYMBOL_VOID = 16,                      /* VOID  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_PRINTLN = 22,                   /* PRINTLN  */
  YYSYMBOL_ASSIGNOP = 23,                  /* ASSIGNOP  */
  YYSYMBOL_BITOP = 24,                     /* BITOP  */
  YYSYMBOL_NOT = 25,                       /* NOT  */
  YYSYMBOL_INCOP = 26,                     /* INCOP  */
  YYSYMBOL_DECOP = 27,                     /* DECOP  */
  YYSYMBOL_ID = 28,                        /* ID  */
  YYSYMBOL_CONST_INT = 29,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 30,               /* CONST_FLOAT  */
  YYSYMBOL_CONST_CHAR = 31,                /* CONST_CHAR  */
  YYSYMBOL_ADDOP = 32,                     /* ADDOP  */
  YYSYMBOL_MULOP = 33,                     /* MULOP  */
  YYSYMBOL_RELOP = 34,                     /* RELOP  */
  YYSYMBOL_LOGICOP = 35,                   /* LOGICOP  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_start = 37,                     /* start  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_unit = 39,                      /* unit  */
  YYSYMBOL_func_declaration = 40,          /* func_declaration  */
  YYSYMBOL_func_definition = 41,           /* func_definition  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_43_2 = 43,                      /* $@2  */
  YYSYMBOL_parameter_list = 44,            /* parameter_list  */
  YYSYMBOL_compound_statement = 45,        /* compound_statement  */
  YYSYMBOL_var_declaration = 46,           /* var_declaration  */
  YYSYMBOL_type_specifier = 47,            /* type_specifier  */
  YYSYMBOL_declaration_list = 48,          /* declaration_list  */
  YYSYMBOL_statements = 49,                /* statements  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_51_3 = 51,                      /* $@3  */
  YYSYMBOL_expression_statement = 52,      /* expression_statement  */
  YYSYMBOL_variable = 53,                  /* variable  */
  YYSYMBOL_expression = 54,                /* expression  */
  YYSYMBOL_logic_expression = 55,          /* logic_expression  */
  YYSYMBOL_rel_expression = 56,            /* rel_expression  */
  YYSYMBOL_simple_expression = 57,         /* simple_expression  */
  YYSYMBOL_term = 58,                      /* term  */
  YYSYMBOL_unary_expression = 59,          /* unary_expression  */
  YYSYMBOL_factor = 60,                    /* factor  */
  YYSYMBOL_argument_list = 61,             /* argument_list  */
  YYSYMBOL_arguments = 62                  /* arguments  */
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
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    70,    76,    84,    90,    96,   104,   125,
     148,   147,   240,   239,   288,   303,   312,   325,   336,   343,
     352,   405,   410,   415,   422,   436,   454,   467,   486,   487,
     490,   496,   503,   503,   509,   515,   521,   527,   533,   553,
     566,   570,   578,   601,   629,   635,   644,   650,   658,   664,
     672,   678,   686,   692,   700,   706,   712,   720,   726,   727,
     733,   739,   745,   752,   760,   767,   774,   775
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
  "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", "MAIN",
  "INT", "FLOAT", "CHAR", "DOUBLE", "VOID", "IF", "ELSE", "FOR", "WHILE",
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
      10,   -73,   -73,   -73,    12,    10,   -73,   -73,   -73,   -73,
       9,   -73,   -73,    27,    43,     4,    21,   -73,    15,    46,
      11,    32,    51,    54,   -73,    58,    55,    10,   -73,   -73,
      44,    59,   -73,   -73,    58,    49,    66,   134,   -73,   -73,
      79,    80,    82,   134,    83,   134,    29,   -73,   -73,   134,
     -73,    64,    87,   -73,    58,   -73,    18,    85,   -73,    60,
      -5,    65,   -73,   -73,   -73,   -73,   -73,    93,   134,   126,
     134,    92,    74,    31,   -73,   134,   134,   -73,    98,   -73,
     -73,   -73,   134,   -73,   -73,   -73,   134,   134,   134,   134,
     -73,   106,   126,   107,   -73,   109,   -73,   114,   112,   113,
     -73,   -73,    65,    94,   -73,   111,   134,   111,   116,   -73,
     134,   -73,   120,   130,   -73,   -73,   -73,   111,   111,   -73,
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
     -73,   -73,   -73,   137,   -73,   -73,   -73,   -73,   -73,   -30,
      14,    13,   -73,   -73,   -51,   -73,   -67,   -40,   -37,   -72,
      61,    56,    62,   -38,   -73,   -73,   -73
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
      67,    80,    92,    96,    64,    73,    71,    74,    19,    73,
     100,    77,    11,    10,     9,    26,     1,     2,    10,     9,
       3,    27,     1,     2,    81,   106,     3,    87,    21,    88,
      15,    91,    75,    93,    16,    73,    76,    13,   116,    99,
      35,    82,    73,    23,    83,    84,    73,    73,    73,    73,
      22,   104,    17,    18,   112,    24,   114,    83,    84,    29,
      28,    30,    37,    31,    33,    38,   119,   120,    39,   113,
      73,     1,     2,    36,    66,     3,    40,    65,    41,    42,
      43,    44,    68,    69,    45,    70,    72,    46,    47,    48,
      37,    49,    78,    79,    85,    86,    39,    90,    89,     1,
       2,    94,    95,     3,    40,    16,    41,    42,    43,    44,
     105,   107,    45,   108,    37,    46,    47,    48,   109,    49,
      39,   111,   110,     1,     2,   115,    87,     3,    40,    37,
      41,    42,    43,    44,   118,    39,    45,    37,   117,    46,
      47,    48,    12,    49,   103,     0,     0,   101,     0,   102,
       0,    45,     0,     0,    46,    47,    48,     0,    49,    45,
       0,     0,    46,    47,    48,     0,    49
};

static const yytype_int8 yycheck[] =
{
      37,    52,    69,    75,    34,    45,    43,    45,     4,    49,
      82,    49,     0,     0,     0,     4,    12,    13,     5,     5,
      16,    10,    12,    13,    54,    92,    16,    32,    15,    34,
       3,    68,     3,    70,     7,    75,     7,    28,   110,    76,
      27,    23,    82,    28,    26,    27,    86,    87,    88,    89,
      29,    89,     9,    10,   105,     9,   107,    26,    27,     8,
      28,     7,     3,     5,     9,     6,   117,   118,     9,   106,
     110,    12,    13,    29,     8,    16,    17,    28,    19,    20,
      21,    22,     3,     3,    25,     3,     3,    28,    29,    30,
       3,    32,    28,     6,     9,    35,     9,     4,    33,    12,
      13,     9,    28,    16,    17,     7,    19,    20,    21,    22,
       4,     4,    25,     4,     3,    28,    29,    30,     4,    32,
       9,     8,    10,    12,    13,     9,    32,    16,    17,     3,
      19,    20,    21,    22,     4,     9,    25,     3,    18,    28,
      29,    30,     5,    32,    88,    -1,    -1,    86,    -1,    87,
      -1,    25,    -1,    -1,    28,    29,    30,    -1,    32,    25,
      -1,    -1,    28,    29,    30,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    13,    16,    37,    38,    39,    40,    41,    46,
      47,     0,    39,    28,    48,     3,     7,     9,    10,     4,
      44,    47,    29,    28,     9,    43,     4,    10,    28,     8,
       7,     5,    45,     9,    42,    47,    29,     3,     6,     9,
      17,    19,    20,    21,    22,    25,    28,    29,    30,    32,
      46,    47,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    45,    28,     8,    54,     3,     3,
       3,    54,     3,    53,    59,     3,     7,    59,    28,     6,
      50,    45,    23,    26,    27,     9,    35,    32,    34,    33,
       4,    54,    52,    54,     9,    28,    55,    61,    62,    54,
      55,    56,    58,    57,    59,     4,    52,     4,     4,     4,
      10,     8,    50,    54,    50,     9,    55,    18,     4,    50,
      50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    40,    40,
      42,    41,    43,    41,    44,    44,    44,    44,    45,    45,
      46,    47,    47,    47,    48,    48,    48,    48,    49,    49,
      50,    50,    51,    50,    50,    50,    50,    50,    50,    50,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    62,    62
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
#line 65 "parser.y"
        {
		//write your code in this block in all the similar blocks below
	}
#line 1373 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 71 "parser.y"
        {
		logout << "Line " << line_count << ": program : program unit\n\n";
		logout << (yyvsp[-1].Symbol)-> getName() << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)-> getName() + (yyvsp[0].Symbol)-> getName(), "nonterm");
	}
#line 1383 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 77 "parser.y"
        {
		logout << "Line " << line_count << ": program : unit\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	}
#line 1393 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 85 "parser.y"
        {
		logout << "Line " << line_count << ": unit : var_declaration\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	}
#line 1403 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 91 "parser.y"
         {
		logout << "Line " << line_count << ": unit : func_declaration\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	 }
#line 1413 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 97 "parser.y"
         {
		logout << "Line " << line_count << ": unit : func_definition\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	 }
#line 1423 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 105 "parser.y"
                {
			logout << "Line " << line_count << ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n";
			logout << (yyvsp[-5].Symbol)-> getName() << " " << (yyvsp[-4].Symbol)-> getName() << "(" << (yyvsp[-2].Symbol)-> getName() << ");\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-5].Symbol)-> getName() + " " +  (yyvsp[-4].Symbol)-> getName() + "(" + (yyvsp[-2].Symbol)-> getName() + ");", "nonterm");
			//$$->parameterList = $4-> parameterList;

			SymbolInfo *temp = table->lookUpSymbol_currentScope(new SymbolInfo((yyvsp[-4].Symbol)-> getName(), ""));
			if(temp != nullptr){
				error ++;
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-4].Symbol)->getName() << "\n\n";
			}else{
				SymbolInfo *tempFunc = new SymbolInfo((yyvsp[-4].Symbol)-> getName(), "ID");
				tempFunc->setIsFunc(true); tempFunc->setIfDefined(false); tempFunc-> parameterList = (yyvsp[-2].Symbol)-> parameterList;
				if(table->insertSymbol(tempFunc)){}
				else{cout << "unsuccessful insertion in func_declaration";}

				//SymbolInfo *newTemp = table-> lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));

			}
		}
#line 1448 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 126 "parser.y"
                {
			logout << "Line " << line_count << ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n";
			logout << (yyvsp[-4].Symbol)-> getName() << " " << (yyvsp[-3].Symbol)-> getName() << "();\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-4].Symbol)-> getName() + " " +  (yyvsp[-3].Symbol)-> getName() + "();", "nonterm");

			SymbolInfo *temp = table->lookUpSymbol_currentScope(new SymbolInfo((yyvsp[-3].Symbol)-> getName(), ""));
			if(temp != nullptr){
				error ++;
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].Symbol)->getName() << "\n\n";
			}else{
				SymbolInfo *tempFunc = new SymbolInfo((yyvsp[-3].Symbol)-> getName(), "ID");
				tempFunc->setIsFunc(true); tempFunc->setIfDefined(false);
				if(table->insertSymbol(tempFunc)){}
				else{cout << "unsuccessful insertion in func_declaration";}

				//SymbolInfo *newTemp = table-> lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));

			}
		}
#line 1472 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 148 "parser.y"
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
						SymbolInfo *tempFunc = new SymbolInfo(funcNameFound, returnTypeFound);
						tempFunc-> setIfDefined(true);
						tempFunc-> setIsFunc(true);
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
				SymbolInfo *tempFunc = new SymbolInfo(funcNameFound, returnTypeFound);
				tempFunc-> setIfDefined(true);
				tempFunc-> setIsFunc(true);
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
#line 1562 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 234 "parser.y"
                {
			logout << "Line " << line_count << ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n";
			logout << (yyvsp[-6].Symbol)-> getName() << " " << (yyvsp[-5].Symbol)-> getName() << "(" << (yyvsp[-3].Symbol)->getName() << ")" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 1571 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 240 "parser.y"
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
				SymbolInfo *tempFunc = new SymbolInfo(funcNameFound, returnTypeFound);
				tempFunc-> setIfDefined(true);
				tempFunc-> setIsFunc(true);
				table-> insertSymbol(tempFunc);

				table-> EnterScope();

			}
		}
#line 1616 "y.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 281 "parser.y"
                {
			logout << "Line " << line_count << ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n";
			logout << (yyvsp[-5].Symbol)-> getName() << " " << (yyvsp[-4].Symbol)-> getName() << "()" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 1625 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 289 "parser.y"
                {
			logout << "Line " << line_count << ": parameter_list  : parameter_list COMMA type_specifier ID\n\n";
			logout << (yyvsp[-3].Symbol)-> getName() << " , " << (yyvsp[-1].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-3].Symbol)-> getName() + "," +  (yyvsp[-1].Symbol)-> getName(), "nonterm");

			(yyval.Symbol)-> parameterList = (yyvsp[-3].Symbol)-> parameterList;
			(yyval.Symbol)-> parameterListAdd((yyvsp[0].Symbol)-> getName(), (yyvsp[-1].Symbol)-> getName());

			//Error
			if((yyvsp[-1].Symbol)-> getName() == "void"){
				error ++;
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
			}
		}
#line 1644 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 304 "parser.y"
                {
			logout << "Line " << line_count << ": parameter_list  : parameter_list COMMA type_specifier\n\n";
			logout << (yyvsp[-2].Symbol)-> getName() << " , " << (yyvsp[0].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)-> getName() + "," +  (yyvsp[0].Symbol)-> getName(), "nonterm");

			(yyval.Symbol)-> parameterList = (yyvsp[-2].Symbol)-> parameterList;
			(yyval.Symbol)-> parameterListAdd("", (yyvsp[0].Symbol)-> getName());
		}
#line 1657 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 313 "parser.y"
                {
			logout << "Line " << line_count << ": type_specifier ID\n\n";
			logout << (yyvsp[-1].Symbol)-> getName() << " " << (yyvsp[0].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)-> getName() + " " + (yyvsp[0].Symbol)-> getName() , "nonterm");

			//Error
			if((yyvsp[-1].Symbol)-> getName() == "void"){
				error ++;
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
			}
			(yyval.Symbol)-> parameterListAdd((yyvsp[0].Symbol)-> getName(), (yyvsp[-1].Symbol)-> getName());
		}
#line 1674 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 326 "parser.y"
                {
			logout << "Line " << line_count << ": type_specifier\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = (yyvsp[0].Symbol);

			(yyval.Symbol)-> parameterListAdd("", (yyvsp[0].Symbol)-> getName());
		}
#line 1686 "y.tab.c"
    break;

  case 18: /* compound_statement: LCURL statements RCURL  */
#line 337 "parser.y"
                        {
				(yyval.Symbol) = new SymbolInfo("{" + (yyvsp[-1].Symbol)->getName() +  "}", "compound");
				logout << "Line " << line_count << ": compound_statement : LCURL statements RCURL\n\n";
				table-> printAllShorts(logout);
				table-> ExitScope();
			}
#line 1697 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL RCURL  */
#line 344 "parser.y"
                        {
				(yyval.Symbol) = new SymbolInfo("{\n}", "compound");
				logout << "Line " << line_count << ": compound_statement : LCURL RCURL\n\n";
				table-> printAllShorts(logout);
				table-> ExitScope();
			}
#line 1708 "y.tab.c"
    break;

  case 20: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 353 "parser.y"
                {
			string Type_found = (yyvsp[-2].Symbol)->getName();
			string Var_found = (yyvsp[-1].Symbol)->getName();
			logout << "Line " << line_count << ": var_declaration : type_specifier declaration_list SEMICOLON\n\n";
			logout << Type_found << " " << Var_found << ";\n\n";
			(yyval.Symbol) = new SymbolInfo(Type_found + " " + Var_found + ";", "nonterm");

			(yyval.Symbol)->setVariable_type(Type_found);
			for(int i=0; i< (yyvsp[-1].Symbol)->varList.size(); i++)
				(yyvsp[-1].Symbol)->varList[i].type = Type_found;

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
						if(table->insertSymbol(new SymbolInfo((yyvsp[-1].Symbol)->varList[i].name, "ID"))){}
						else{
							cout << "insertion to table unsuccessful in var_declaration\n";
						}

						SymbolInfo *newTemp = table->lookUpSymbol_currentScope(new SymbolInfo((yyvsp[-1].Symbol)->varList[i].name, ""));
						newTemp-> setVariable_type(Type_found);
						//newTemp-> setId($2-> getId());
						if((yyvsp[-1].Symbol)->varList[i].ifArray != -1){
							newTemp->setId("array");
						}else{
							newTemp->setId("variable");
						}
					}
				}
			}
		}
#line 1763 "y.tab.c"
    break;

  case 21: /* type_specifier: INT  */
#line 406 "parser.y"
                {
			logout << "Line " << line_count << ": type_specifier : INT\n\nint\n\n";
			(yyval.Symbol) = new SymbolInfo("int" , "int");
		}
#line 1772 "y.tab.c"
    break;

  case 22: /* type_specifier: FLOAT  */
#line 411 "parser.y"
                {
			logout << "Line " << line_count << ": type_specifier : FLOAT\n\nint\n\n";
			(yyval.Symbol) = new SymbolInfo("float" , "float");
		}
#line 1781 "y.tab.c"
    break;

  case 23: /* type_specifier: VOID  */
#line 416 "parser.y"
                {
			logout << "Line " << line_count << ": type_specifier : VOID\n\nvoid\n\n";
			(yyval.Symbol) = new SymbolInfo("void" , "void");
		}
#line 1790 "y.tab.c"
    break;

  case 24: /* declaration_list: declaration_list COMMA ID  */
#line 423 "parser.y"
                {
			logout << "Line " << line_count << ": declaration_list : declaration_list COMMA ID\n\n";
			logout << (yyvsp[-2].Symbol)->getName() << "," << (yyvsp[0].Symbol)->getName() << "\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + "," + (yyvsp[0].Symbol)->getName(), "nonterm");
			(yyval.Symbol)->setId("variable");

			tempVar.name = (yyvsp[0].Symbol)-> getName();
			tempVar.size = -1;
			variableList.push_back(tempVar);
			(yyval.Symbol)->varList = (yyvsp[-2].Symbol)->varList;
			(yyval.Symbol)->varListAdd((yyvsp[0].Symbol)->getName(), "" , 0);
			
		}
#line 1808 "y.tab.c"
    break;

  case 25: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 437 "parser.y"
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
			(yyval.Symbol)->varListAdd((yyvsp[-3].Symbol)->getName(), "" , size);
		}
#line 1830 "y.tab.c"
    break;

  case 26: /* declaration_list: ID  */
#line 455 "parser.y"
                {
			logout << "Line " << line_count << ": declaration_list : ID\n\n";
			logout << (yyvsp[0].Symbol)->getName() << "\n\n";
			(yyval.Symbol) = (yyvsp[0].Symbol); //new SymbolInfo($1->getName(), "ID");
			(yyval.Symbol)->setId("variable");

			tempVar.name = (yyvsp[0].Symbol)-> getName();
			tempVar.size = -1;
			variableList.push_back(tempVar);
			(yyval.Symbol)->varList = (yyvsp[0].Symbol)->varList;
			(yyval.Symbol)->varListAdd((yyvsp[0].Symbol)->getName(), "" , 0);
		}
#line 1847 "y.tab.c"
    break;

  case 27: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 468 "parser.y"
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
#line 1868 "y.tab.c"
    break;

  case 30: /* statement: var_declaration  */
#line 491 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statement : var_declaration\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 1878 "y.tab.c"
    break;

  case 31: /* statement: expression_statement  */
#line 497 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statement : expression_statement\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 1888 "y.tab.c"
    break;

  case 32: /* $@3: %empty  */
#line 503 "parser.y"
                  {table-> EnterScope();}
#line 1894 "y.tab.c"
    break;

  case 33: /* statement: $@3 compound_statement  */
#line 504 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statement : compound_statement\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 1904 "y.tab.c"
    break;

  case 34: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 510 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo("for(" + (yyvsp[-4].Symbol)->getName() + (yyvsp[-3].Symbol)->getName() + (yyvsp[-2].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName() , "statement");
			logout << "Line " << line_count << ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n";
			logout << "for(" << (yyvsp[-4].Symbol)-> getName() << " " <<  (yyvsp[-3].Symbol)->getName() << " " << (yyvsp[-2].Symbol)->getName() << ")" << (yyvsp[0].Symbol)->getName() << "\n\n";
		}
#line 1914 "y.tab.c"
    break;

  case 35: /* statement: IF LPAREN expression RPAREN statement  */
#line 516 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo("if(" + (yyvsp[-2].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName() , "statement");
			logout << "Line " << line_count << ": statement : IF LPAREN expression RPAREN statement\n\n";
			logout << "if(" << (yyvsp[-2].Symbol)-> getName() <<  ")" << (yyvsp[0].Symbol)->getName() << "\n\n";
		}
#line 1924 "y.tab.c"
    break;

  case 36: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 522 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo("if(" + (yyvsp[-4].Symbol)->getName() + ")" + (yyvsp[-2].Symbol)->getName() + "else" + (yyvsp[0].Symbol)-> getName() , "statement");
			logout << "Line " << line_count << ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n";
			logout << "if(" << (yyvsp[-4].Symbol)-> getName() <<  ")" << (yyvsp[0].Symbol)->getName() << "else" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 1934 "y.tab.c"
    break;

  case 37: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 528 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo("while(" + (yyvsp[-2].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName() , "statement");
			logout << "Line " << line_count << ": statement : WHILE LPAREN expression RPAREN statement\n\n";
			logout << "while(" << (yyvsp[-2].Symbol)-> getName() <<  ")" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 1944 "y.tab.c"
    break;

  case 38: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 534 "parser.y"
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

			(yyval.Symbol) = new SymbolInfo("printf(" + (yyvsp[-2].Symbol)->getName() + ");", "statement");
			logout << "Line " << line_count << ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n";
			logout << "printf(" << (yyvsp[-2].Symbol)-> getName() <<  ");\n\n";
		}
#line 1968 "y.tab.c"
    break;

  case 39: /* statement: RETURN expression SEMICOLON  */
#line 554 "parser.y"
                {
			string returnTypeFound = (yyvsp[-1].Symbol)->getReturn_type();
			if(returnTypeFound == "void"){
				error ++ ;
				errorout << "Error at line " << line_count << ": void doesnt have return types\n\n";
			}
			(yyval.Symbol) = new SymbolInfo("return " + (yyvsp[-1].Symbol)->getName() + ";", "statement");
			logout << "Line " << line_count << ": statement : RETURN expression SEMICOLON\n\n";
			logout << "return " << (yyvsp[-1].Symbol)-> getName() <<  ";\n\n";
		}
#line 1983 "y.tab.c"
    break;

  case 40: /* expression_statement: SEMICOLON  */
#line 567 "parser.y"
                        {
				(yyval.Symbol) = new SymbolInfo(";", "statement");
			}
#line 1991 "y.tab.c"
    break;

  case 41: /* expression_statement: expression SEMICOLON  */
#line 571 "parser.y"
                        {
				(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + ";", "expression_statement");
				logout << "Line " << line_count << ": expression_statement : expression SEMICOLON \n\n";
				logout << (yyvsp[-1].Symbol)-> getName() <<  ";\n\n";
			}
#line 2001 "y.tab.c"
    break;

  case 42: /* variable: ID  */
#line 579 "parser.y"
        {
		string nameFound = (yyvsp[0].Symbol)->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, ""));

		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": ID is not declared : " << nameFound << "\n\n";
			(yyval.Symbol) = new SymbolInfo(nameFound , "INVALID");
		}else{
			if(ifExists->getId() == "array"){
				error ++ ;
				errorout << "Error at line " << line_count << ": ID is not a variable : " << nameFound << "\n\n";
				(yyval.Symbol) = new SymbolInfo(nameFound, "INVALID");

			}else{
				(yyval.Symbol) = (yyvsp[0].Symbol);
			}
		}
		logout << "Line " << line_count << ": variable : ID\n\n";
		logout << (yyvsp[0].Symbol)-> getName() <<  "\n\n";

	}
#line 2028 "y.tab.c"
    break;

  case 43: /* variable: ID LTHIRD expression RTHIRD  */
#line 602 "parser.y"
        {
		string nameFound = (yyvsp[-3].Symbol)->getName();
		string indexType = (yyvsp[-1].Symbol)->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, "" ));
		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": ID is not declared : " << nameFound << "\n\n";
			(yyval.Symbol) = new SymbolInfo(nameFound , "INVALID");
		}else{
			if(ifExists->getId() == "array"){
				if(indexType != "int"){
					error ++ ;
					errorout << "Error at line " << line_count << ": Index is not integer : " << (yyvsp[-1].Symbol)-> getName() << "\n\n";
				}
				(yyval.Symbol) = new SymbolInfo(nameFound + "[" + (yyvsp[-1].Symbol)->getName() + "]", ifExists->getType());

			}else{
				error ++ ;
				errorout << "Error at line " << line_count << ": ID declared is not an array : " << nameFound << "\n\n";
				(yyval.Symbol) =  new SymbolInfo(nameFound + "[" + (yyvsp[-1].Symbol)->getName() + "]", "INVALID");
			}
		}
		logout << "Line " << line_count << ": variable : ID LTHIRD expression RTHIRD\n\n";
		logout << (yyvsp[-3].Symbol)-> getName() << "[" << (yyvsp[-1].Symbol)->getName() << "]\n\n";
	}
#line 2058 "y.tab.c"
    break;

  case 44: /* expression: logic_expression  */
#line 630 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": expression : logic_expression\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 2068 "y.tab.c"
    break;

  case 45: /* expression: variable ASSIGNOP logic_expression  */
#line 636 "parser.y"
           {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + "=" + (yyvsp[0].Symbol)->getName() , "expression");
			logout << "Line " << line_count << ": expression : variable ASSIGNOP logic_expression\n\n";
			logout << (yyvsp[-2].Symbol)->getName() << "=" << (yyvsp[0].Symbol)->getName() <<"\n\n";
	   }
#line 2078 "y.tab.c"
    break;

  case 46: /* logic_expression: rel_expression  */
#line 645 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": logic_expression : rel_expression \n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2088 "y.tab.c"
    break;

  case 47: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 651 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)-> getName() + (yyvsp[0].Symbol)->getName() , "logic");
			logout << "Line " << line_count << ": logic_expression : rel_expression LOGICOP rel_expression \n\n";
			logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2098 "y.tab.c"
    break;

  case 48: /* rel_expression: simple_expression  */
#line 659 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": rel_expression : simple_expression \n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2108 "y.tab.c"
    break;

  case 49: /* rel_expression: simple_expression RELOP simple_expression  */
#line 665 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)-> getName() + (yyvsp[0].Symbol)->getName() , "rel");
			logout << "Line " << line_count << ": rel_expression : simple_expression RELOP simple_expression\n\n";
			logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2118 "y.tab.c"
    break;

  case 50: /* simple_expression: term  */
#line 673 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": simple_expression : term \n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2128 "y.tab.c"
    break;

  case 51: /* simple_expression: simple_expression ADDOP term  */
#line 679 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)->getName() + (yyvsp[0].Symbol)->getName(), "simple");
			logout << "Line " << line_count << ": simple_expression : simple_expression ADDOP term \n\n";
			logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2138 "y.tab.c"
    break;

  case 52: /* term: unary_expression  */
#line 687 "parser.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": term : unary_expression\n\n";
		logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
	}
#line 2148 "y.tab.c"
    break;

  case 53: /* term: term MULOP unary_expression  */
#line 693 "parser.y"
        {
		(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)->getName() + (yyvsp[0].Symbol)->getName() , "term");
		logout << "Line " << line_count << ": term : term MULOP unary_expression\n\n";
		logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
	}
#line 2158 "y.tab.c"
    break;

  case 54: /* unary_expression: ADDOP unary_expression  */
#line 701 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName()  + (yyvsp[0].Symbol)->getName(), "unary");
			logout << "Line " << line_count << ": unary_expression : ADDOP unary_expression \n\n";
			logout << (yyvsp[-1].Symbol)-> getName()  << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2168 "y.tab.c"
    break;

  case 55: /* unary_expression: NOT unary_expression  */
#line 707 "parser.y"
                {
			(yyval.Symbol) = new SymbolInfo("!" + (yyvsp[0].Symbol)->getName(), "unary");
			logout << "Line " << line_count << ": unary_expression : NOT unary_expression \n\n";
			logout << "!"  << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2178 "y.tab.c"
    break;

  case 56: /* unary_expression: factor  */
#line 713 "parser.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": unary_expression : factor\n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2188 "y.tab.c"
    break;

  case 57: /* factor: variable  */
#line 721 "parser.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": factor : variable\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
	}
#line 2198 "y.tab.c"
    break;

  case 59: /* factor: LPAREN expression RPAREN  */
#line 728 "parser.y"
        {
		(yyval.Symbol) = new SymbolInfo("(" + (yyvsp[-1].Symbol)->getName() + ")", "factor");
		logout << "Line " << line_count << ": factor : LPAREN expression RPAREN\n\n";
		logout << "(" << (yyvsp[-1].Symbol)-> getName() << ")" << "\n\n";
	}
#line 2208 "y.tab.c"
    break;

  case 60: /* factor: CONST_INT  */
#line 734 "parser.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": factor : CONST_INT\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
	}
#line 2218 "y.tab.c"
    break;

  case 61: /* factor: CONST_FLOAT  */
#line 740 "parser.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": factor : CONST_FLOAT\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
	}
#line 2228 "y.tab.c"
    break;

  case 62: /* factor: variable INCOP  */
#line 746 "parser.y"
        {
		(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + "++" , "factor");
		logout << "Line " << line_count << ": factor : variable INCOP \n\n";
		logout << (yyvsp[-1].Symbol)-> getName() << "++\n\n";
	}
#line 2238 "y.tab.c"
    break;

  case 63: /* factor: variable DECOP  */
#line 753 "parser.y"
        {
		(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + "--" , "factor");
		logout << "Line " << line_count << ": factor : variable DECOP\n\n";
		logout << (yyvsp[-1].Symbol)-> getName() << "--\n\n";
	}
#line 2248 "y.tab.c"
    break;

  case 64: /* argument_list: arguments  */
#line 761 "parser.y"
                                {
					(yyval.Symbol) = (yyvsp[0].Symbol);
					logout << "Line " << line_count << ": argument_list : arguments\n\n";
					logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
				}
#line 2258 "y.tab.c"
    break;

  case 65: /* argument_list: %empty  */
#line 767 "parser.y"
                                {
					(yyval.Symbol) = new SymbolInfo("", "void");
					logout << "Line " << line_count << ": argument_list : \n\n";
					logout << "\n\n";
				}
#line 2268 "y.tab.c"
    break;


#line 2272 "y.tab.c"

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

#line 779 "parser.y"

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
