%{
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include "1805002_SymbolTable.h"
//#include "1805002_SymbolInfo.h"
#define YYSTYPE SymbolInfo*
#include "y.tab.h"


using namespace std;

//extern YYSTYPE yylval;
extern SymbolTable *table;
void yyerror(char *);

int line_count=1;
int error=0;

//extra rules
//integer {digit}+
//number {digit}*(\.{digit}+)?(E[+-]?{digit}+)?

%}


ADDOP [+-] 
MULOP [*/%]

DELIM 			[ \t\r\f\v]
WHITESPACE 		[DELIM]+ 
LETTER 			[a-zA-Z]
DIGIT 			[0-9]
NUMBER 			{DIGIT}+
EXPONEN 		([Ee][+-]?{DIGIT}+)
FLOAT  			({NUMBER}{EXPONEN}?)|({NUMBER}\.{NUMBER}?{EXPONEN}?)|(\.{NUMBER}{EXPONEN}?)
ID     			[_a-zA-Z][_a-zA-Z0-9]*
NEWLINE 		[\n]
RELOP 			(">"|">="|"<"|"<="|"=="|"!=")
BITOP 			("|"|"&"|"^"|"<<"|">>") 
STRING 			\"((\\[\n])|(\")|[^\n])*\"
CHARACTER_T1	'([ -~]{-}['\\])'
ESCAPE_CHAR  	'(\\[\\0abfnrtv'\"])'
CHARACTERS      [{CHARACTER_T1}|{ESCAPE_CHAR}]
COMB1           (({NUMBER}*)\.({NUMBER}*))
COMB2           ({EXPONEN}{COMB1})
TOO_MANY_DEC    {COMB1}{COMB1}+
ILL_FORMED      {FLOAT}{COMB2}
INVALID_PREF_SUFF  {NUMBER}{ID}
UNRECOGNIZED     [`]

%%

{DELIM}+	{}
{NEWLINE} 	{line_count++;}

"if" 		{return IF;}
"else" 		{return ELSE;}
"for" 		{return FOR;}
"while" 	{return WHILE;}
"int" 		{return INT;}
"float" 	{return FLOAT;}
"double" 	{return DOUBLE;}
"char" 		{return CHAR;}
"return" 	{return RETURN;}
"void" 		{return VOID;}
"main"		{return MAIN;}
"println"	{return PRINTLN;}

{ADDOP} { 
			SymbolInfo *s= new  SymbolInfo(yytext, "ADDOP");
			yylval = (YYSTYPE)s;
			return ADDOP;
		}

{MULOP}	{
			SymbolInfo *s= new  SymbolInfo(yytext, "MULOP");
			yylval = (YYSTYPE)s;
			return MULOP;
		}

{RELOP} {
			SymbolInfo *s= new  SymbolInfo(yytext, "RELOP");
			yylval = (YYSTYPE)s;
			return RELOP;
		}

{BITOP} {
			SymbolInfo *s= new  SymbolInfo(yytext, "BITOP");
			yylval = (YYSTYPE)s;
			return BITOP;
		}


"=" 	{return ASSIGNOP;}
"&&"	|
"||"	{
			SymbolInfo *s= new  SymbolInfo(yytext, "LOGICOP");
			yylval = (YYSTYPE)s;
			return LOGICOP;
		}
"!"		{return NOT; }


";" 	{return SEMICOLON;}
"," 	{return COMMA;}
"(" 	{return LPAREN;}
")" 	{return RPAREN;}
"{" 	{return LCURL;}
"}" 	{return RCURL;}
"[" 	{return LTHIRD;}
"]" 	{return RTHIRD;}
"++" 	{return INCOP;}
"--" 	{return DECOP;}



{NUMBER}	{
				SymbolInfo *s= new  SymbolInfo(yytext, "CONST_INT");
				yylval = (YYSTYPE)s;
				return CONST_INT;
			}
{FLOAT} 	{	
				SymbolInfo *s= new  SymbolInfo(yytext, "CONST_FLOAT");
				yylval = (YYSTYPE)s;
				return CONST_FLOAT; 
			}

{ID} 		{	 
				
				SymbolInfo *s;  //= table->lookUpSymbol(new SymbolInfo(yytext,"ID"));
				//if(s==NULL)
				{					
					s= new SymbolInfo(yytext,"ID");
				}
				yylval = (YYSTYPE)s;
							
				return ID;
			}


%%

int yywrap(void)
{
	return 1;
}






