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

#line 141 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
