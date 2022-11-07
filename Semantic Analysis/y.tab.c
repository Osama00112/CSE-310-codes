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
#line 1 "1805002.y"

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "1805002_SymbolTable.h"

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE *yyin;
FILE *fp;

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

void printFinalLog(){
    logout << "\nTotal lines: " << line_count <<"\n"; 
    logout << "Total errors: " << error <<"\n"; 
}

void yyerror(char *s)
{
	//write your code
	error ++;
	errorout << "Error at line " << line_count << ": syntax error\n\n";
	logout << "Error at line " << line_count << ": syntax error\n\n";
}



#line 117 "y.tab.c"

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
    NEWLINE = 277,                 /* NEWLINE  */
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
    LOGICOP = 290,                 /* LOGICOP  */
    LOWER_THAN_ELSE = 291          /* LOWER_THAN_ELSE  */
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
#define NEWLINE 277
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
#define LOWER_THAN_ELSE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "1805002.y"

	SymbolInfo *Symbol;

#line 246 "y.tab.c"

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
  YYSYMBOL_NEWLINE = 22,                   /* NEWLINE  */
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
  YYSYMBOL_LOWER_THAN_ELSE = 36,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_start = 38,                     /* start  */
  YYSYMBOL_program = 39,                   /* program  */
  YYSYMBOL_unit = 40,                      /* unit  */
  YYSYMBOL_func_declaration = 41,          /* func_declaration  */
  YYSYMBOL_func_definition = 42,           /* func_definition  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_parameter_list = 45,            /* parameter_list  */
  YYSYMBOL_compound_statement = 46,        /* compound_statement  */
  YYSYMBOL_var_declaration = 47,           /* var_declaration  */
  YYSYMBOL_type_specifier = 48,            /* type_specifier  */
  YYSYMBOL_declaration_list = 49,          /* declaration_list  */
  YYSYMBOL_statements = 50,                /* statements  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_expression_statement = 53,      /* expression_statement  */
  YYSYMBOL_variable = 54,                  /* variable  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_logic_expression = 56,          /* logic_expression  */
  YYSYMBOL_rel_expression = 57,            /* rel_expression  */
  YYSYMBOL_simple_expression = 58,         /* simple_expression  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_unary_expression = 60,          /* unary_expression  */
  YYSYMBOL_factor = 61,                    /* factor  */
  YYSYMBOL_argument_list = 62,             /* argument_list  */
  YYSYMBOL_arguments = 63                  /* arguments  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    75,    75,    84,    90,    98,   104,   110,   118,   156,
     182,   181,   322,   321,   377,   393,   402,   417,   426,   438,
     447,   458,   520,   528,   533,   538,   545,   559,   577,   590,
     607,   613,   619,   627,   633,   640,   640,   646,   652,   658,
     664,   670,   692,   706,   710,   716,   723,   750,   793,   799,
     835,   841,   864,   871,   879,   885,   899,   906,   951,   957,
     963,   971,   977,  1023,  1029,  1035,  1041,  1048,  1056,  1063,
    1070,  1100
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
  "RETURN", "PRINTLN", "NEWLINE", "ASSIGNOP", "BITOP", "NOT", "INCOP",
  "DECOP", "ID", "CONST_INT", "CONST_FLOAT", "CONST_CHAR", "ADDOP",
  "MULOP", "RELOP", "LOGICOP", "LOWER_THAN_ELSE", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition", "$@1", "$@2",
  "parameter_list", "compound_statement", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement", "$@3",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      83,    -7,   -72,   -72,   -72,    41,   153,   -72,   -72,   -72,
     -72,    23,   -72,   -72,   -72,    53,    44,   133,    29,   -72,
     -72,    45,    37,    10,    12,    61,    74,   -72,    80,    79,
     103,   -72,   -72,   -72,    64,    71,   -72,   -72,    80,    69,
      97,     0,   -72,   -72,   108,   120,   121,     0,   122,     0,
      58,   -72,   -72,     0,   -72,    99,   101,   -72,    80,   -72,
      52,    18,   -72,    93,    -8,   102,   -72,   -72,   -72,   -72,
     -72,   134,     0,    34,     0,   130,   113,    82,   -72,     0,
       0,   -72,   148,   -72,   -72,   -72,     0,   -72,   -72,   -72,
     -72,     0,     0,     0,     0,   -72,   154,    34,   158,   -72,
     162,   -72,   163,   147,   161,   -72,   -72,   102,   138,   -72,
     131,     0,   131,   164,   -72,     0,   -72,   155,   167,   -72,
     -72,   -72,   131,   131,   -72,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    23,    24,    25,     0,     0,     4,     6,     7,
       5,     0,    22,     1,     3,    28,     0,     0,     0,    30,
      21,     0,    12,     0,     0,     0,    26,     9,     0,    10,
       0,    18,    16,    29,     0,     0,    13,     8,     0,    15,
       0,     0,    20,    43,     0,     0,     0,     0,     0,     0,
      46,    64,    65,     0,    33,     0,     0,    31,     0,    34,
      61,     0,    48,    50,    52,    54,    56,    60,    11,    14,
      27,     0,     0,     0,     0,     0,     0,    61,    59,    69,
       0,    58,    28,    19,    32,    36,     0,    66,    67,    45,
      44,     0,     0,     0,     0,    63,     0,     0,     0,    42,
       0,    71,     0,    68,     0,    49,    51,    55,    53,    57,
       0,     0,     0,     0,    62,     0,    47,    38,     0,    40,
      41,    70,     0,     0,    39,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   168,   -72,   -72,   -72,   -72,   -72,   -20,
      17,     4,   -72,   -72,   -55,   -72,   -61,   -44,   -41,   -71,
      84,    85,    87,   -42,   -72,   -72,   -72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    38,    28,    23,    36,
      54,    55,    16,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   102,   103
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      71,    84,    12,    41,    11,    77,    75,    78,   101,    77,
      11,    81,    97,    31,    29,   105,   -17,    10,    68,    89,
      30,    24,   -17,    10,    92,    49,    93,    90,    50,    51,
      52,    96,    53,    98,    39,    77,   111,    41,    85,   104,
      32,    13,    77,    43,   121,    19,    27,    77,    77,    77,
      77,    15,   109,    20,    21,   117,    17,   119,    25,    49,
      18,    79,    50,    51,    52,    80,    53,   124,   125,    33,
     118,    77,     1,    26,    41,    86,   -35,    42,    87,    88,
      43,    34,     2,     3,     1,    35,     4,    44,    37,    45,
      46,    47,    48,    40,     2,     3,    49,    69,     4,    50,
      51,    52,     1,    53,    41,    70,   -35,    83,    87,    88,
      43,    72,     2,     3,     2,     3,     4,    44,     4,    45,
      46,    47,    48,    73,    74,    76,    49,    82,    91,    50,
      51,    52,     1,    53,    41,    94,   -35,    22,    95,    99,
      43,   100,     2,     3,     2,     3,     4,    44,     4,    45,
      46,    47,    48,    -2,     1,    18,    49,   115,   110,    50,
      51,    52,   112,    53,     2,     3,   113,   114,     4,   116,
      92,   123,   122,   120,    14,   106,     0,     0,   108,   107
};

static const yytype_int8 yycheck[] =
{
      41,    56,     9,     3,     0,    49,    47,    49,    79,    53,
       6,    53,    73,     1,     4,    86,     4,     0,    38,     1,
      10,    17,    10,     6,    32,    25,    34,     9,    28,    29,
      30,    72,    32,    74,    30,    79,    97,     3,    58,    80,
      28,     0,    86,     9,   115,     1,     9,    91,    92,    93,
      94,    28,    94,     9,    10,   110,     3,   112,    29,    25,
       7,     3,    28,    29,    30,     7,    32,   122,   123,     8,
     111,   115,     1,    28,     3,    23,     5,     6,    26,    27,
       9,     7,    11,    12,     1,     5,    15,    16,     9,    18,
      19,    20,    21,    29,    11,    12,    25,    28,    15,    28,
      29,    30,     1,    32,     3,     8,     5,     6,    26,    27,
       9,     3,    11,    12,    11,    12,    15,    16,    15,    18,
      19,    20,    21,     3,     3,     3,    25,    28,    35,    28,
      29,    30,     1,    32,     3,    33,     5,     4,     4,     9,
       9,    28,    11,    12,    11,    12,    15,    16,    15,    18,
      19,    20,    21,     0,     1,     7,    25,    10,     4,    28,
      29,    30,     4,    32,    11,    12,     4,     4,    15,     8,
      32,     4,    17,     9,     6,    91,    -1,    -1,    93,    92
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    11,    12,    15,    38,    39,    40,    41,    42,
      47,    48,     9,     0,    40,    28,    49,     3,     7,     1,
       9,    10,     4,    45,    48,    29,    28,     9,    44,     4,
      10,     1,    28,     8,     7,     5,    46,     9,    43,    48,
      29,     3,     6,     9,    16,    18,    19,    20,    21,    25,
      28,    29,    30,    32,    47,    48,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    46,    28,
       8,    55,     3,     3,     3,    55,     3,    54,    60,     3,
       7,    60,    28,     6,    51,    46,    23,    26,    27,     1,
       9,    35,    32,    34,    33,     4,    55,    53,    55,     9,
      28,    56,    62,    63,    55,    56,    57,    59,    58,    60,
       4,    53,     4,     4,     4,    10,     8,    51,    55,    51,
       9,    56,    17,     4,    51,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    41,    41,
      43,    42,    44,    42,    45,    45,    45,    45,    45,    46,
      46,    47,    47,    48,    48,    48,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    52,    51,    51,    51,    51,
      51,    51,    51,    53,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     2,     3,
       2,     3,     2,     1,     1,     1,     3,     6,     1,     4,
       2,     1,     2,     1,     1,     0,     2,     7,     5,     7,
       5,     5,     3,     1,     2,     2,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     2,     2,     1,     0,
       3,     1
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
#line 76 "1805002.y"
        {
		//write your code in this block in all the similar blocks below
		line_count --;
		logout << "Line " << line_count << ": start : program\n\n";
		table->printAllShorts(logout);
	}
#line 1388 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 85 "1805002.y"
        {
		logout << "Line " << line_count << ": program : program unit\n\n";
		logout << (yyvsp[-1].Symbol)-> getName() << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)-> getName() + (yyvsp[0].Symbol)-> getName(), "nonterm");
	}
#line 1398 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 91 "1805002.y"
        {
		logout << "Line " << line_count << ": program : unit\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	}
#line 1408 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 99 "1805002.y"
        {
		logout << "Line " << line_count << ": unit : var_declaration\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	}
#line 1418 "y.tab.c"
    break;

  case 6: /* unit: func_declaration  */
#line 105 "1805002.y"
         {
		logout << "Line " << line_count << ": unit : func_declaration\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	 }
#line 1428 "y.tab.c"
    break;

  case 7: /* unit: func_definition  */
#line 111 "1805002.y"
         {
		logout << "Line " << line_count << ": unit : func_definition\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		(yyval.Symbol) = (yyvsp[0].Symbol);
	 }
#line 1438 "y.tab.c"
    break;

  case 8: /* func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 119 "1805002.y"
                {
			logout << "Line " << line_count << ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n";
			logout << (yyvsp[-5].Symbol)-> getName() << " " << (yyvsp[-4].Symbol)-> getName() << "(" << (yyvsp[-2].Symbol)-> getName() << ");\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-5].Symbol)-> getName() + " " +  (yyvsp[-4].Symbol)-> getName() + "(" + (yyvsp[-2].Symbol)-> getName() + ");\n", "nonterm");
			//$$->parameterList = $4-> parameterList;
			vector<parameter> parametersFound = (yyvsp[-2].Symbol)-> parameterList;

			SymbolInfo *temp = table->lookUpSymbol_currentScope(new SymbolInfo((yyvsp[-4].Symbol)-> getName(), ""));
			if(temp != nullptr){
				error ++;
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-4].Symbol)->getName() << "\n\n";
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-4].Symbol)->getName() << "\n\n";
			}else{
				SymbolInfo *tempFunc = new SymbolInfo((yyvsp[-4].Symbol)-> getName(), "ID");
				tempFunc->setIsFunc(true); tempFunc->setReturn_type((yyvsp[-5].Symbol)->getName()); tempFunc->setIfDefined(false); tempFunc-> parameterList = (yyvsp[-2].Symbol)-> parameterList;
				if(table->insertSymbol(tempFunc)){
					table-> EnterScope();
						for(int i=0; i< parametersFound.size(); i++){
							tempFunc = new SymbolInfo(parametersFound[i].name, "ID");
							tempFunc->setReturn_type(parametersFound[i].type);
							if(table->insertSymbol(tempFunc)){
								//cout << "inserted in func def, param list " << 	parametersFound[i].name << "," << parametersFound[i].type<<endl;
							}
							else{
								error ++;
								errorout << "Error at line " << line_count << ": Multiple declaration of variable " << parametersFound[i].name <<" in parameter\n\n";
								logout << "Error at line " << line_count << ": Multiple declaration of variable " << parametersFound[i].name <<" in parameter\n\n";
							}
						}
						table-> ExitScope();
				}
				else{cout << "unsuccessful insertion in func_declaration";}

				//SymbolInfo *newTemp = table-> lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));

			}
		}
#line 1480 "y.tab.c"
    break;

  case 9: /* func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 157 "1805002.y"
                {
			logout << "Line " << line_count << ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n";
			logout << (yyvsp[-4].Symbol)-> getName() << " " << (yyvsp[-3].Symbol)-> getName() << "();\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-4].Symbol)-> getName() + " " +  (yyvsp[-3].Symbol)-> getName() + "();\n", "nonterm");

			SymbolInfo *temp = table->lookUpSymbol_currentScope(new SymbolInfo((yyvsp[-3].Symbol)-> getName(), ""));
			if(temp != nullptr){
				error ++;
				errorout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].Symbol)->getName() << "\n\n";
				logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].Symbol)->getName() << "\n\n";
			}else{
				SymbolInfo *tempFunc = new SymbolInfo((yyvsp[-3].Symbol)-> getName(), "ID");
				tempFunc->setIsFunc(true); tempFunc->setReturn_type((yyvsp[-4].Symbol)->getName()); tempFunc->setIfDefined(false);
				if(table->insertSymbol(tempFunc)){
					//cout << "inserted in func_declaration " << $2->getName()<< endl;
					}
				else{cout << "unsuccessful insertion in func_declaration";}

				//SymbolInfo *newTemp = table-> lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));

			}
		}
#line 1507 "y.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 182 "1805002.y"
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
						logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-3].Symbol)->getName() << "\n\n";
					}
					else{
						bool validity = true;
						string declaredReturnType = ifExists-> getReturn_type();
						int parameterCount1 = ifExists-> parameterList.size();
						int parameterCount2 = parametersFound.size();
						if(parameterCount1 != parameterCount2){
							error ++;
							errorout << "Error at line " << line_count << ": Total number of arguments mismatch with declaration in function " << (yyvsp[-3].Symbol)->getName() << "\n\n";
							logout << "Error at line " << line_count << ": Total number of arguments mismatch with declaration in function " << (yyvsp[-3].Symbol)->getName() << "\n\n";
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
										logout << "Error at line " << line_count << ": Return type does not match for parameter" << parametersFound[i].name << "\n\n";
										validity = false;
									}
								}
							}
						}
						if(returnTypeFound != declaredReturnType){
							error ++;
							errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-3].Symbol)->getName() << "()\n\n";
							logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-3].Symbol)->getName() << "()\n\n";
							validity = false;
						}


						table-> removeSymbol(new SymbolInfo(funcNameFound, ""));
						SymbolInfo *tempFunc = new SymbolInfo(funcNameFound, "ID");
						tempFunc->parameterList = parametersFound;
						tempFunc-> setIfDefined(true);
						tempFunc-> setIsFunc(true);
						tempFunc->setReturn_type(returnTypeFound);
						//cout << "inserted in func_definition " << $2->getName()<< endl;}
						table-> insertSymbol(tempFunc);

						table-> EnterScope();
						for(int i=0; i< parametersFound.size(); i++){
							tempFunc = new SymbolInfo(parametersFound[i].name, "ID");
							tempFunc->setReturn_type(parametersFound[i].type);
							if(parametersFound[i].name == ""){
								error ++ ;
								errorout << "Error at line " << line_count << ": "<< i+1 <<"th parameter's name not given in function definition of " << funcNameFound <<"\n\n";
								logout << "Error at line " << line_count << ": "<< i+1 << "th parameter's name not given in function definition of " << funcNameFound <<"\n\n";
							}
							if(table->insertSymbol(tempFunc)){
								//cout << "inserted in func def, param list " << 	parametersFound[i].name << "," << parametersFound[i].type<<endl;
							}
							else{
								error ++;
								errorout << "Error at line " << line_count << ": Multiple declaration of variable " << parametersFound[i].name <<" in parameter\n\n";
								logout << "Error at line " << line_count << ": Multiple declaration of variable " << parametersFound[i].name <<" in parameter\n\n";
							}
						}

					}
				}else{
					table-> EnterScope();
					error ++;
					errorout << "Error at line " << line_count << ": ID is not a function : " << (yyvsp[-3].Symbol)->getName()  << "()\n\n";
					logout << "Error at line " << line_count << ": ID is not a function : " << (yyvsp[-3].Symbol)->getName()  << "()\n\n";

					SymbolInfo *tempFunc;
					for(int i=0; i< parametersFound.size(); i++){
							tempFunc = new SymbolInfo(parametersFound[i].name, "ID");
							tempFunc->setReturn_type(parametersFound[i].type);
							if(parametersFound[i].name == ""){
								error ++ ;
								errorout << "Error at line " << line_count << ": "<< i <<"th parameter's name not given in function definition of " << funcNameFound <<"\n\n";
								logout << "Error at line " << line_count << ": "<< i << "th parameter's name not given in function definition of " << funcNameFound <<"\n\n";
							}
							if(table->insertSymbol(tempFunc)){
								//cout << "inserted in func def, param list " << 	parametersFound[i].name << "," << parametersFound[i].type<<endl;
							}
							else{
								error ++;
								errorout << "Error at line " << line_count << ": Multiple declaration of variable " << parametersFound[i].name <<" in parameter\n\n";
								logout << "Error at line " << line_count << ": Multiple declaration of variable " << parametersFound[i].name <<" in parameter\n\n";
							}
						}
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
					//cout << parametersFound[i].name << endl;
					if(parametersFound[i].name == ""){
						error ++ ;
						errorout << "Error at line " << line_count << ": "<< i <<"th parameter's name not given in function definition of " << funcNameFound <<"\n\n";
						logout << "Error at line " << line_count << ": "<< i << "th parameter's name not given in function definition of " << funcNameFound <<"\n\n";
					}
					tempFunc = new SymbolInfo(parametersFound[i].name, "ID");
					tempFunc->setReturn_type(parametersFound[i].type);
					if(table->insertSymbol(tempFunc)){}
					else{
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of variable " << parametersFound[i].name <<" in parameter\n\n";
						logout << "Error at line " << line_count << ": Multiple declaration of variable " << parametersFound[i].name <<" in parameter\n\n";
					}
				}

			}
		}
#line 1644 "y.tab.c"
    break;

  case 11: /* func_definition: type_specifier ID LPAREN parameter_list RPAREN $@1 compound_statement  */
#line 315 "1805002.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-6].Symbol)->getName()+ " "  + (yyvsp[-5].Symbol)->getName() + "(" + (yyvsp[-3].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName(), "func_def");
			logout << "Line " << line_count << ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n";
			logout << (yyvsp[-6].Symbol)-> getName() << " " << (yyvsp[-5].Symbol)-> getName() << "(" << (yyvsp[-3].Symbol)->getName() << ")" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 1654 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 322 "1805002.y"
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
						logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-2].Symbol)->getName() << "\n\n";
					}
					else{
						bool validity = true;
						string declaredReturnType = ifExists-> getReturn_type();
						//cout << returnTypeFound << " " << declaredReturnType << endl;
						if(returnTypeFound != declaredReturnType){
							error ++;
							errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-2].Symbol)->getName() << "\n\n";
							logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << (yyvsp[-2].Symbol)->getName() << "\n\n";
							validity = false;
						}
						//table-> EnterScope();

					}
				}else{
					//table-> EnterScope();
					error ++;
					errorout << "Error at line " << line_count << ": ID is not a function : " << (yyvsp[-2].Symbol)->getName()  << "()\n\n";
					logout << "Error at line " << line_count << ": ID is not a function : " << (yyvsp[-2].Symbol)->getName()  << "()\n\n";

				}
			}else{
				SymbolInfo *tempFunc = new SymbolInfo(funcNameFound, "ID");
				tempFunc-> setIfDefined(true);
				tempFunc-> setIsFunc(true);
				tempFunc-> setReturn_type(returnTypeFound);
				table-> insertSymbol(tempFunc);

				//table-> EnterScope();

			}
			table-> EnterScope();
		}
#line 1705 "y.tab.c"
    break;

  case 13: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 369 "1805002.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-5].Symbol)->getName()+ " "  + (yyvsp[-4].Symbol)->getName() + "()" + (yyvsp[0].Symbol)->getName(), "func_def");
			logout << "Line " << line_count << ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n";
			logout << (yyvsp[-5].Symbol)-> getName() << " " << (yyvsp[-4].Symbol)-> getName() << "()" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 1715 "y.tab.c"
    break;

  case 14: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 378 "1805002.y"
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
				logout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
			}
		}
#line 1735 "y.tab.c"
    break;

  case 15: /* parameter_list: parameter_list COMMA type_specifier  */
#line 394 "1805002.y"
                {
			logout << "Line " << line_count << ": parameter_list  : parameter_list COMMA type_specifier\n\n";
			logout << (yyvsp[-2].Symbol)-> getName() << " , " << (yyvsp[0].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)-> getName() + "," +  (yyvsp[0].Symbol)-> getName(), "nonterm");

			(yyval.Symbol)-> parameterList = (yyvsp[-2].Symbol)-> parameterList;
			(yyval.Symbol)-> parameterListAdd("", (yyvsp[0].Symbol)-> getName());
		}
#line 1748 "y.tab.c"
    break;

  case 16: /* parameter_list: type_specifier ID  */
#line 403 "1805002.y"
                {
			logout << "Line " << line_count << ": parameter_list  : type_specifier ID\n\n";
			logout << (yyvsp[-1].Symbol)-> getName() << " " << (yyvsp[0].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)-> getName() + " " + (yyvsp[0].Symbol)-> getName() , "nonterm");

			//cout << "in param list " << $1->getName() + " " + $2-> getName() << " and type " << $1->getType() + " " + $2-> getType()<< endl;
			//Error
			if((yyvsp[-1].Symbol)-> getName() == "void"){
				error ++;
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
				logout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
			}
			(yyval.Symbol)-> parameterListAdd((yyvsp[0].Symbol)-> getName(), (yyvsp[-1].Symbol)-> getName());
		}
#line 1767 "y.tab.c"
    break;

  case 17: /* parameter_list: type_specifier  */
#line 418 "1805002.y"
                {
			logout << "Line " << line_count << ": parameter_list  : type_specifier\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = (yyvsp[0].Symbol);

			(yyval.Symbol)-> parameterListAdd("", (yyvsp[0].Symbol)-> getName());
			
		}
#line 1780 "y.tab.c"
    break;

  case 18: /* parameter_list: type_specifier error  */
#line 427 "1805002.y"
                {
			//logout << "paisi\n\n";
			logout << (yyvsp[-1].Symbol)-> getName() << "\n\n";
			(yyval.Symbol) = (yyvsp[-1].Symbol);
			(yyval.Symbol)-> parameterListAdd("", (yyvsp[-1].Symbol)-> getName());
			yyclearin;
			yyerrok;
		}
#line 1793 "y.tab.c"
    break;

  case 19: /* compound_statement: LCURL statements RCURL  */
#line 439 "1805002.y"
                        {
				(yyval.Symbol) = new SymbolInfo("{\n" + (yyvsp[-1].Symbol)->getName() +  "}\n", "compound");
				logout << "Line " << line_count << ": compound_statement : LCURL statements RCURL\n\n";
				logout << "{\n" << " " << (yyvsp[-1].Symbol)->getName() << "}\n\n";
				table-> printAllShorts(logout);
				table-> ExitScope();
				variableList.clear();
			}
#line 1806 "y.tab.c"
    break;

  case 20: /* compound_statement: LCURL RCURL  */
#line 448 "1805002.y"
                        {
				(yyval.Symbol) = new SymbolInfo("{}\n", "compound");
				logout << "Line " << line_count << ": compound_statement : LCURL RCURL\n\n";
				logout << "{\n}\n\n";
				table-> printAllShorts(logout);
				table-> ExitScope();
				variableList.clear();
			}
#line 1819 "y.tab.c"
    break;

  case 21: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 459 "1805002.y"
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
				logout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
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
						logout << "Error at line " << line_count << ": Multiple declaration of " << (yyvsp[-1].Symbol)->varList[i].name << "\n\n";
					}

					//not_error
					else{
						temp = new SymbolInfo((yyvsp[-1].Symbol)->varList[i].name, "ID");
						temp->setVariable_type(Type_found);
						temp->setReturn_type(Type_found);

						if((yyvsp[-1].Symbol)->varList[i].ifArray != 0){
							temp->setId("array");
						}else{
							temp->setId("variable");
						}
						if(table->insertSymbol(temp)){
							//cout << "inserted in var declaration " << $2->varList[i].name << ",type:" << temp->getType()<< ",ret_type:" << temp->getReturn_type() <<  endl;
							}
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
#line 1885 "y.tab.c"
    break;

  case 22: /* var_declaration: error SEMICOLON  */
#line 521 "1805002.y"
                {
			yyclearin;
			yyerrok;
		}
#line 1894 "y.tab.c"
    break;

  case 23: /* type_specifier: INT  */
#line 529 "1805002.y"
                {
			logout << "Line " << line_count << ": type_specifier : INT\n\nint\n\n";
			(yyval.Symbol) = new SymbolInfo("int" , "int");
		}
#line 1903 "y.tab.c"
    break;

  case 24: /* type_specifier: FLOAT  */
#line 534 "1805002.y"
                {
			logout << "Line " << line_count << ": type_specifier : FLOAT\n\nfloat\n\n";
			(yyval.Symbol) = new SymbolInfo("float" , "float");
		}
#line 1912 "y.tab.c"
    break;

  case 25: /* type_specifier: VOID  */
#line 539 "1805002.y"
                {
			logout << "Line " << line_count << ": type_specifier : VOID\n\nvoid\n\n";
			(yyval.Symbol) = new SymbolInfo("void" , "void");
		}
#line 1921 "y.tab.c"
    break;

  case 26: /* declaration_list: declaration_list COMMA ID  */
#line 546 "1805002.y"
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
#line 1939 "y.tab.c"
    break;

  case 27: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 560 "1805002.y"
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
#line 1961 "y.tab.c"
    break;

  case 28: /* declaration_list: ID  */
#line 578 "1805002.y"
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
#line 1978 "y.tab.c"
    break;

  case 29: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 591 "1805002.y"
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
#line 1999 "y.tab.c"
    break;

  case 30: /* declaration_list: declaration_list error  */
#line 608 "1805002.y"
                {
			yyclearin;
		}
#line 2007 "y.tab.c"
    break;

  case 31: /* statements: statement  */
#line 614 "1805002.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statements : statement\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 2017 "y.tab.c"
    break;

  case 32: /* statements: statements statement  */
#line 620 "1805002.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + " " + (yyvsp[0].Symbol)->getName(), "statements");
			logout << "Line " << line_count << ": statements : statements statement\n\n";
			logout << (yyvsp[-1].Symbol)-> getName() << " " << (yyvsp[0].Symbol)->getName() << "\n\n";
		}
#line 2027 "y.tab.c"
    break;

  case 33: /* statement: var_declaration  */
#line 628 "1805002.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statement : var_declaration\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 2037 "y.tab.c"
    break;

  case 34: /* statement: expression_statement  */
#line 634 "1805002.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statement : expression_statement\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 2047 "y.tab.c"
    break;

  case 35: /* $@3: %empty  */
#line 640 "1805002.y"
                  {table-> EnterScope();}
#line 2053 "y.tab.c"
    break;

  case 36: /* statement: $@3 compound_statement  */
#line 641 "1805002.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": statement : compound_statement\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 2063 "y.tab.c"
    break;

  case 37: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 647 "1805002.y"
                {
			(yyval.Symbol) = new SymbolInfo("for(" + (yyvsp[-4].Symbol)->getName() + (yyvsp[-3].Symbol)->getName() + (yyvsp[-2].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName() , "statement");
			logout << "Line " << line_count << ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n";
			logout << "for(" << (yyvsp[-4].Symbol)-> getName() << " " <<  (yyvsp[-3].Symbol)->getName() << " " << (yyvsp[-2].Symbol)->getName() << ")" << (yyvsp[0].Symbol)->getName() << "\n\n";
		}
#line 2073 "y.tab.c"
    break;

  case 38: /* statement: IF LPAREN expression RPAREN statement  */
#line 653 "1805002.y"
                {
			(yyval.Symbol) = new SymbolInfo("if(" + (yyvsp[-2].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName() , "statement");
			logout << "Line " << line_count << ": statement : IF LPAREN expression RPAREN statement\n\n";
			logout << "if(" << (yyvsp[-2].Symbol)-> getName() <<  ")" << (yyvsp[0].Symbol)->getName() << "\n\n";
		}
#line 2083 "y.tab.c"
    break;

  case 39: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 659 "1805002.y"
                {
			(yyval.Symbol) = new SymbolInfo("if(" + (yyvsp[-4].Symbol)->getName() + ")" + (yyvsp[-2].Symbol)->getName() + "else" + (yyvsp[0].Symbol)-> getName() , "statement");
			logout << "Line " << line_count << ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n";
			logout << "if(" << (yyvsp[-4].Symbol)-> getName() <<  ")" << (yyvsp[0].Symbol)->getName() << "else" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2093 "y.tab.c"
    break;

  case 40: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 665 "1805002.y"
                {
			(yyval.Symbol) = new SymbolInfo("while(" + (yyvsp[-2].Symbol)->getName() + ")" + (yyvsp[0].Symbol)->getName() , "statement");
			logout << "Line " << line_count << ": statement : WHILE LPAREN expression RPAREN statement\n\n";
			logout << "while(" << (yyvsp[-2].Symbol)-> getName() <<  ")" << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2103 "y.tab.c"
    break;

  case 41: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 671 "1805002.y"
                {
			string nameFound = (yyvsp[-2].Symbol)-> getName();
			SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, ""));

			if(ifExists == nullptr){
				error ++ ;
				errorout << "Error at line " << line_count << ": Undeclared variable :" << nameFound <<"\n\n";
				logout << "Error at line " << line_count << ": Undeclared variable :" << nameFound <<"\n\n";
			}else{
				if(ifExists-> getIsFunc()){
					error ++ ;
					errorout << "Error at line " << line_count << ": function can not be inside a print function : "<< nameFound << "\n\n";
					logout << "Error at line " << line_count << ": function can not be inside a print function : "<< nameFound << "\n\n";
				}

			}	

			(yyval.Symbol) = new SymbolInfo("printf(" + (yyvsp[-2].Symbol)->getName() + ");\n", "statement");
			logout << "Line " << line_count << ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n";
			logout << "printf(" << (yyvsp[-2].Symbol)-> getName() <<  ");\n\n";
		}
#line 2129 "y.tab.c"
    break;

  case 42: /* statement: RETURN expression SEMICOLON  */
#line 693 "1805002.y"
                {
			string returnTypeFound = (yyvsp[-1].Symbol)->getReturn_type();
			if(returnTypeFound == "void"){
				error ++ ;
				errorout << "Error at line " << line_count << ": void doesnt have return types\n\n";
				logout << "Error at line " << line_count << ": void doesnt have return types\n\n";
			}
			(yyval.Symbol) = new SymbolInfo("return " + (yyvsp[-1].Symbol)->getName() + ";\n", "statement");
			logout << "Line " << line_count << ": statement : RETURN expression SEMICOLON\n\n";
			logout << "return " << (yyvsp[-1].Symbol)-> getName() <<  ";\n\n";
		}
#line 2145 "y.tab.c"
    break;

  case 43: /* expression_statement: SEMICOLON  */
#line 707 "1805002.y"
                        {
				(yyval.Symbol) = new SymbolInfo(";\n", "statement");
			}
#line 2153 "y.tab.c"
    break;

  case 44: /* expression_statement: expression SEMICOLON  */
#line 711 "1805002.y"
                        {
				(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + ";\n", "expression_statement");
				logout << "Line " << line_count << ": expression_statement : expression SEMICOLON \n\n";
				logout << (yyvsp[-1].Symbol)-> getName() <<  ";\n\n";
			}
#line 2163 "y.tab.c"
    break;

  case 45: /* expression_statement: expression error  */
#line 717 "1805002.y"
                        {
				yyclearin;
				//yyerrok;
			}
#line 2172 "y.tab.c"
    break;

  case 46: /* variable: ID  */
#line 724 "1805002.y"
        {
		string nameFound = (yyvsp[0].Symbol)->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, ""));

		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			logout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			(yyval.Symbol) = new SymbolInfo(nameFound , "INVALID");
		}else{
			//cout << nameFound << " exists and has return type " << ifExists->getReturn_type() << endl;
			if(ifExists->getId() == "array"){
				error ++ ;
			
				errorout << "Error at line " << line_count << ": Type mismatch, "<< nameFound  <<" is an array\n\n";
				logout << "Error at line " << line_count << ": Type mismatch, "<< nameFound  <<" is an array\n\n";
				(yyval.Symbol) = new SymbolInfo(nameFound, "INVALID");

			}else{
				(yyval.Symbol) = new SymbolInfo(nameFound, ifExists->getReturn_type());
			}
		}
		logout << "Line " << line_count << ": variable : ID\n\n";
		logout << (yyvsp[0].Symbol)-> getName() <<  "\n\n";

	}
#line 2203 "y.tab.c"
    break;

  case 47: /* variable: ID LTHIRD expression RTHIRD  */
#line 751 "1805002.y"
        {
		string nameFound = (yyvsp[-3].Symbol)->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, "" ));
		string typeFound = ifExists->getReturn_type();
		string indexType = (yyvsp[-1].Symbol)->getType();
		//cout << "inside var rule: " << ifExists->getName() << " " << ifExists->getType() << " " << ifExists->getReturn_type() << " " << ifExists->getId() << endl;
		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			logout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			(yyval.Symbol) = new SymbolInfo(nameFound , "INVALID");
		}else{
			if(ifExists->getId() == "array"){
				string finalType = typeFound;
				if(indexType != "int"){
					error ++ ;
					errorout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
					logout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
					//cout << "index type for " << $3->getName() << " is " << indexType << "\n";
					finalType = "INVALID";
				}
				else if(stoi((yyvsp[-1].Symbol)->getName()) < 0){
					error ++ ;
					errorout << "Error at line " << line_count << ": Expression inside third brackets is negative :" << (yyvsp[-1].Symbol)-> getName() << "\n\n";
					logout << "Error at line " << line_count << ": Expression inside third brackets is negative :" << (yyvsp[-1].Symbol)-> getName() << "\n\n";
					finalType = "INVALID";
				}
				SymbolInfo *temp = new SymbolInfo(nameFound + "[" + (yyvsp[-1].Symbol)->getName() + "]", finalType);
				(yyval.Symbol) = temp;

			}else{
				error ++ ;
				errorout << "Error at line " << line_count << ": "<< nameFound  <<" not an array\n\n";
				logout << "Error at line " << line_count << ": "<< nameFound  <<" not an array\n\n";
				(yyval.Symbol) =  new SymbolInfo(nameFound + "[" + (yyvsp[-1].Symbol)->getName() + "]", "INVALID");
			}
		}
		logout << "Line " << line_count << ": variable : ID LTHIRD expression RTHIRD\n\n";
		logout << (yyvsp[-3].Symbol)-> getName() << "[" << (yyvsp[-1].Symbol)->getName() << "]\n\n";
	}
#line 2248 "y.tab.c"
    break;

  case 48: /* expression: logic_expression  */
#line 794 "1805002.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": expression : logic_expression\n\n";
			logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
		}
#line 2258 "y.tab.c"
    break;

  case 49: /* expression: variable ASSIGNOP logic_expression  */
#line 800 "1805002.y"
           {
			string operand1 = (yyvsp[-2].Symbol)-> getName();
			string operand2 = (yyvsp[0].Symbol)-> getName();
			string type1 = (yyvsp[-2].Symbol)-> getType();
			string type2 = (yyvsp[0].Symbol)-> getType();
			string returnType1 = (yyvsp[-2].Symbol)-> getReturn_type();


			if(type1 == type2 && type1 != "INVALID" && type2 != "INVALID"){

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
					//cout << "mismatched for var " << operand1 << " type: " << type1 << " ret_type: " << $1->getReturn_type() << " and logic expr: " << operand1 << " type: " << type2 << endl; 
					errorout << "Error at line " << line_count << ": Type mismatch for variable "<< (yyvsp[-2].Symbol)->getName()  <<"\n\n";
					logout << "Error at line " << line_count << ": Type mismatch for variable "<< (yyvsp[-2].Symbol)->getName()  <<"\n\n";
				}
			}

			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + "=" + (yyvsp[0].Symbol)->getName() , "expression");
			logout << "Line " << line_count << ": expression : variable ASSIGNOP logic_expression\n\n";
			logout << (yyvsp[-2].Symbol)->getName() << "=" << (yyvsp[0].Symbol)->getName() <<"\n\n";
	   }
#line 2295 "y.tab.c"
    break;

  case 50: /* logic_expression: rel_expression  */
#line 836 "1805002.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": logic_expression : rel_expression \n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2305 "y.tab.c"
    break;

  case 51: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 842 "1805002.y"
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
					logout << "Error at line " << line_count << ": not integer type found : " << "\n\n";
					//todo
					//finalType = "INVALID";
				}
			}
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)-> getName() + (yyvsp[0].Symbol)->getName() , finalType);
			logout << "Line " << line_count << ": logic_expression : rel_expression LOGICOP rel_expression \n\n";
			logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2330 "y.tab.c"
    break;

  case 52: /* rel_expression: simple_expression  */
#line 865 "1805002.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": rel_expression : simple_expression \n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
			//cout << $$->getName() << " " << $1->getType() << endl; 
		}
#line 2341 "y.tab.c"
    break;

  case 53: /* rel_expression: simple_expression RELOP simple_expression  */
#line 872 "1805002.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)-> getName() + (yyvsp[0].Symbol)->getName() , "int");
			logout << "Line " << line_count << ": rel_expression : simple_expression RELOP simple_expression\n\n";
			logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2351 "y.tab.c"
    break;

  case 54: /* simple_expression: term  */
#line 880 "1805002.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": simple_expression : term \n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2361 "y.tab.c"
    break;

  case 55: /* simple_expression: simple_expression ADDOP term  */
#line 886 "1805002.y"
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
#line 2377 "y.tab.c"
    break;

  case 56: /* term: unary_expression  */
#line 900 "1805002.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": term : unary_expression\n\n";
		//cout << $1->getName() << " " << $1->getType() << endl; 
		logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
	}
#line 2388 "y.tab.c"
    break;

  case 57: /* term: term MULOP unary_expression  */
#line 907 "1805002.y"
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
			if(operatorFound == "/"){
				if(operand2 == "0"){
					error ++ ;
					errorout << "Error at line " << line_count << ": Division by Zero\n\n";
					logout << "Error at line " << line_count << ": Division by Zero\n\n";
					finalType = "INVALID";
				}
			}

		}else if(operatorFound == "%"){
			if(type1 != "int" || type2 != "int"){
				error ++ ;
				errorout << "Error at line " << line_count << ": Non-Integer operand on modulus operator\n\n";
				logout << "Error at line " << line_count << ": Non-Integer operand on modulus operator\n\n";
				finalType = "INVALID";
			}else{
				if(operand2 == "0"){
					error ++ ;
					errorout << "Error at line " << line_count << ": Modulus by Zero\n\n";
					logout << "Error at line " << line_count << ": Modulus by Zero\n\n";
					finalType = "INVALID";
				}
			}
		}else{
			//todo
		}
		//cout << $1->getName() << " " << $1->getType() << " " << finalType << endl; 
		(yyval.Symbol) = new SymbolInfo((yyvsp[-2].Symbol)->getName() + (yyvsp[-1].Symbol)->getName() + (yyvsp[0].Symbol)->getName() , finalType);
		logout << "Line " << line_count << ": term : term MULOP unary_expression\n\n";
		logout << (yyvsp[-2].Symbol)->getName() << (yyvsp[-1].Symbol)->getName() << (yyvsp[0].Symbol)->getName() <<"\n\n";
	}
#line 2435 "y.tab.c"
    break;

  case 58: /* unary_expression: ADDOP unary_expression  */
#line 952 "1805002.y"
                {
			(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName()  + (yyvsp[0].Symbol)->getName(), (yyvsp[0].Symbol)->getType());
			logout << "Line " << line_count << ": unary_expression : ADDOP unary_expression \n\n";
			logout << (yyvsp[-1].Symbol)-> getName()  << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2445 "y.tab.c"
    break;

  case 59: /* unary_expression: NOT unary_expression  */
#line 958 "1805002.y"
                {
			(yyval.Symbol) = new SymbolInfo("!" + (yyvsp[0].Symbol)->getName(), (yyvsp[0].Symbol)->getType());
			logout << "Line " << line_count << ": unary_expression : NOT unary_expression \n\n";
			logout << "!"  << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2455 "y.tab.c"
    break;

  case 60: /* unary_expression: factor  */
#line 964 "1805002.y"
                {
			(yyval.Symbol) = (yyvsp[0].Symbol);
			logout << "Line " << line_count << ": unary_expression : factor\n\n";
			logout << (yyvsp[0].Symbol)->getName() <<"\n\n";
		}
#line 2465 "y.tab.c"
    break;

  case 61: /* factor: variable  */
#line 972 "1805002.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": factor : variable\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
	}
#line 2475 "y.tab.c"
    break;

  case 62: /* factor: ID LPAREN argument_list RPAREN  */
#line 978 "1805002.y"
        {
		string nameFound = (yyvsp[-3].Symbol)->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo((yyvsp[-3].Symbol)->getName(),""));
		string returnTypeDeclared = "";

		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": Undeclared function : " << nameFound << "\n\n";
			logout << "Error at line " << line_count << ": Undeclared function : " << nameFound << "\n\n";
		}else{
			returnTypeDeclared = ifExists->getReturn_type();
			if(ifExists->getIsFunc()){
				//todo
			
				if(returnTypeDeclared == "void"){
					error ++ ;
					errorout << "Error at line " << line_count << ": Void function used in expression\n\n";
					logout << "Error at line " << line_count << ": Void function used in expression\n\n";
				}else if(ifExists->parameterList.size() != (yyvsp[-1].Symbol)->argumentList.size()){
					error ++ ;
					errorout << "Error at line " << line_count << ": Total number of arguments mismatch in function " << nameFound << "\n\n";
					logout << "Error at line " << line_count << ": Total number of arguments mismatch in function " << nameFound << "\n\n";
					//cout << "argument size " << $3->argumentList.size() << " parameter size " << ifExists->parameterList.size() << endl;
				}else{
					for(int i=0; i < (yyvsp[-1].Symbol)->argumentList.size(); i++){
						if((yyvsp[-1].Symbol)->argumentList[i].type != ifExists->parameterList[i].type && (yyvsp[-1].Symbol)->argumentList[i].type != "INVALID"){
							//cout << "argument type and parameter type: " << $3->argumentList[i].type << " " << ifExists->parameterList[i].type << endl;
							error ++ ;
							errorout << "Error at line " << line_count << ": " << i+1 <<"th argument mismatch in function " << nameFound << "\n\n";
							logout << "Error at line " << line_count << ": " << i+1 <<"th argument mismatch in function " << nameFound << "\n\n";
						}
					}
				}

			}else{
				error ++ ;
				errorout << "Error at line " << line_count << ": non function accessed : " << nameFound << "\n\n";
				logout << "Error at line " << line_count << ": non function accessed : " << nameFound << "\n\n";
			}
		}

		(yyval.Symbol) = new SymbolInfo((yyvsp[-3].Symbol)-> getName() + "(" + (yyvsp[-1].Symbol)->getName() + ")", returnTypeDeclared);
		logout << "Line " << line_count << ": factor : ID LPAREN argument_list RPAREN\n\n";
		logout << (yyvsp[-3].Symbol)-> getName() << "(" << (yyvsp[-1].Symbol)-> getName() << ")\n\n";
	}
#line 2525 "y.tab.c"
    break;

  case 63: /* factor: LPAREN expression RPAREN  */
#line 1024 "1805002.y"
        {
		(yyval.Symbol) = new SymbolInfo("(" + (yyvsp[-1].Symbol)->getName() + ")", (yyvsp[-1].Symbol)->getType());
		logout << "Line " << line_count << ": factor : LPAREN expression RPAREN\n\n";
		logout << "(" << (yyvsp[-1].Symbol)-> getName() << ")" << "\n\n";
	}
#line 2535 "y.tab.c"
    break;

  case 64: /* factor: CONST_INT  */
#line 1030 "1805002.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": factor : CONST_INT\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
	}
#line 2545 "y.tab.c"
    break;

  case 65: /* factor: CONST_FLOAT  */
#line 1036 "1805002.y"
        {
		(yyval.Symbol) = (yyvsp[0].Symbol);
		logout << "Line " << line_count << ": factor : CONST_FLOAT\n\n";
		logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
	}
#line 2555 "y.tab.c"
    break;

  case 66: /* factor: variable INCOP  */
#line 1042 "1805002.y"
        {
		(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + "++" , (yyvsp[-1].Symbol)->getType());
		logout << "Line " << line_count << ": factor : variable INCOP \n\n";
		logout << (yyvsp[-1].Symbol)-> getName() << "++\n\n";
	}
#line 2565 "y.tab.c"
    break;

  case 67: /* factor: variable DECOP  */
#line 1049 "1805002.y"
        {
		(yyval.Symbol) = new SymbolInfo((yyvsp[-1].Symbol)->getName() + "--" , "factor");
		logout << "Line " << line_count << ": factor : variable DECOP\n\n";
		logout << (yyvsp[-1].Symbol)-> getName() << "--\n\n";
	}
#line 2575 "y.tab.c"
    break;

  case 68: /* argument_list: arguments  */
#line 1057 "1805002.y"
                                {
					(yyval.Symbol) = (yyvsp[0].Symbol);
					logout << "Line " << line_count << ": argument_list : arguments\n\n";
					logout << (yyvsp[0].Symbol)-> getName() << "\n\n";
				}
#line 2585 "y.tab.c"
    break;

  case 69: /* argument_list: %empty  */
#line 1063 "1805002.y"
                                {
					(yyval.Symbol) = new SymbolInfo("", "void");
					logout << "Line " << line_count << ": argument_list : \n\n";
					logout << "\n\n";
				}
#line 2595 "y.tab.c"
    break;

  case 70: /* arguments: arguments COMMA logic_expression  */
#line 1071 "1805002.y"
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
#line 2629 "y.tab.c"
    break;

  case 71: /* arguments: logic_expression  */
#line 1101 "1805002.y"
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
#line 2657 "y.tab.c"
    break;


#line 2661 "y.tab.c"

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

#line 1127 "1805002.y"

int main(int argc,char *argv[])
{
	logout.open("1805002_log.txt");
	errorout.open("1805002_error.txt");


	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	yyin=fp;
	yyparse();
	printFinalLog();

	fclose(fp);
	
	return 0;
}

