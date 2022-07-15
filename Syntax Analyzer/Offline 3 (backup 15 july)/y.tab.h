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
    LOGICOP = 289,                 /* LOGICOP  */
    LOWER_THAN_ELSE = 290          /* LOWER_THAN_ELSE  */
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
#define LOWER_THAN_ELSE 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "parser.y"

	SymbolInfo *Symbol;

#line 141 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
