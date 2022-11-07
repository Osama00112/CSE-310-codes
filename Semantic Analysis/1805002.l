
%x charState
%x stringState
%x multiCommentState
%x singleCommentState

%{
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include "1805002_SymbolTable.h"
#define YYSTYPE SymbolInfo*
#include "y.tab.h"


using namespace std;

//extern YYSTYPE yylval;
extern ofstream logout;
extern ofstream errorout;
extern SymbolTable *table;
void yyerror(char *);

int line_count=1;
int error=0;
int string_lines = 0;
int errorCount = 0;
string comment = "";
string chr = "";

//extra rules
//integer {digit}+
//number {digit}*(\.{digit}+)?(E[+-]?{digit}+)?

char charRule(string str){
	char token;
    if(str.length() == 2){
        errorCount ++;
		//logout2 << "\nError at line no " << line_count << ": Empty character constant " << str << "\n";
        return 'a';   
    }
	else if(str.length() == 3){
        if (str[1] == '\\'){
            errorCount ++;
		    //logout2 << "\nError at line no " << line_count << ": Unterminated character " << str << "\n";
            return 'a';
        }
        else if(str[1] == '\''){
            errorCount ++;
		    //logout2 << "\nError at line no " << line_count << ": Invalid character " << str << "\n";
            return 'a';
        }

        else if(str[1] >= ' ' && str[1] <= '~')
		    token = str[1];
	}
	else if(str.length() == 4 && str[1] == '\\'){
        if(str[2] == 'a')
            token = '\a';
        else if(str[2] == 'b')
            token = '\b';
        else if(str[2] == 'f')
            token = '\f';
        else if(str[2] == 'n')
            token = '\n';
        else if(str[2] == 'r')
            token = '\r';
        else if(str[2] == 't')
            token = '\t';
        else if(str[2] == 'v')
            token = '\v';
        else if(str[2] == '\\')
            token = '\\';
        else if(str[2] == '\'')
            token = '\'';
        else if(str[2] == '\"')
            token = '\"';
        else if(str[2] == '\0')
            token = '\0';
	}
    else if(str.length() > 3){
        errorCount ++;
		//logout2 << "\nError at line no " << line_count << ": Multi character constant error " << str << "\n";
        return 'a'; 
    }
	else{
        errorCount ++;
		//logout2 << "\nError found at line no " << line_count << ": Invalid character\n";
        return 'a';
	}
    //tokenout2 << "<CONST_CHAR," <<  token << " > ";
    //logout2 << "\nLine no " << line_count << ": TOKEN <CONST_CHAR> Lexeme " << str << " found --> " << "<CONST_CHAR," <<  token << " > \n";
    //newInfo = new SymbolInfo(str, "CONST_CHAR");
    // if(newTable->insertSymbol(newInfo)){
    //     newTable->printAllShorts(logout2); 
    // }else{
    //     logout2 << str << " already exists in current ScopeTable\n";
    // }

	// SymbolInfo *s= new  SymbolInfo(str, "CONST_CHAR");
	// yylval = (YYSTYPE)s;
	// return CONST_CHAR;
    return token;
}

void stringRule(string str){
	string token = "";
	for(int i = 0; i<str.length(); i++){
        if(str[i] == '\\'){
            if(str[i+1] == 'n')
                {token += '\n';
                i++;}    
            else if(str[i+1] == 'a')
                {token += '\a';
                i++;}
            else if(str[i+1] == 'b')
                {token += '\b';
                i++;}
            else if(str[i+1] == 'e')
                {token += '\e';
                i++;}
            else if(str[i+1] == 'f')
                {token += '\f';
                i++;}
            else if(str[i+1] == 't')
                {token += '\t';
                i++;}
            else if(str[i+1] == 'r')
                {token += '\r';
                i++;}
            else if(str[i+1] == 'v')
                {token += '\v';
                i++;}
            else if(str[i+1] == '\0')
                {token += '\0';
                i++;}
            else if(str[i+1] == '\\')
                {token += "";
                i++;}
            else if(str[i+1]== '\'')
                {token += '\'';
                i++;}
            else if(str[i+1]== '\"')
                {token += '\"';
                i++;}
            else if(str[i+1] == '\n'){
                i++;
            }
        
        }
        else if(str[i] == '\n'){
            //continue;
        }
        else
            token += str[i];
    }
    //tokenout2 << "<STRING," <<  token << " > ";
    //logout2 << "\nLine no " << line_count << ": TOKEN <STRING> Lexeme " << str << " found --> " << "<STRING," <<  token << " > \n";
}


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
NEWLINE 		[\n]
RELOP 			(">"|">="|"<"|"<="|"=="|"!=")
BITOP 			("|"|"&"|"^"|"<<"|">>") 
NORMAL_CHAR 	'([ -~]{-}['\\])'
SPECIAL_CHAR 	'(\\['nt\\afrbv0\"])'
CHAR_LITERAL 	{NORMAL_CHAR}|{SPECIAL_CHAR}
STRING 			\"((\\[\n])|(\")|[^\n])*\"
ID     			[_a-zA-Z][_a-zA-Z0-9]*
COMB1           (({NUMBER}*)\.({NUMBER}*))
COMB2           ({EXPONEN}{COMB1})
TOO_MANY_DEC    {COMB1}{COMB1}+
ILL_FORMED      {FLOAT}{COMB2}
INVALID_PREF_SUFF  {NUMBER}{ID}


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
"printf"	{return PRINTLN;}

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
				SymbolInfo *s= new  SymbolInfo(yytext, "int");
				yylval = (YYSTYPE)s;
				return CONST_INT;
			}
{FLOAT} 	{	
				SymbolInfo *s= new  SymbolInfo(yytext, "float");
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

\'			{
			chr += yytext;
			BEGIN charState;
			}
<charState>\' {
			chr += yytext;
			//logout2 << "after char state string found " << chr << "\n";
			char mid = charRule(chr);
			SymbolInfo *s= new  SymbolInfo(yytext, "CONST_FLOAT");
				yylval = (YYSTYPE)s;
				return CONST_FLOAT; 
			chr = "";
			BEGIN INITIAL;
			}
<charState>\n {
            errorCount ++;
            //logout2 << "\nError at line no " << line_count << ": Unterminated character " <<  chr <<"\n";
            chr = "";
            line_count ++;
            BEGIN INITIAL;
            }
<charState>. {
			chr += yytext;

			}			
<charState><<EOF>> {
            error++;

            //logout << "\nError at line no " << line_count << ": Unterminated character " <<  chr <<"\n";
            chr = "";
            //printFinalLog();
            return 0;
            }
"/*"        {
            BEGIN multiCommentState;
            comment += yytext;
            }

<multiCommentState>"*/" {
            comment += yytext;
            //tokenout2 << "<COMMENT," <<  comment << "> ";
            //logout2 << "\nLine no " << line_count << ": TOKEN <COMMENT> Lexeme " << comment << " found\n";
            line_count += string_lines;
            string_lines = 0;
            comment = "";
            BEGIN INITIAL;
            }                      
<multiCommentState>\n {
            comment += yytext;
            string_lines++;
            }
<multiCommentState>. {
            comment += yytext;
            }
<multiCommentState><<EOF>> {
            error ++;
            logout << "Error at line no " << line_count << ": Unterminated comment " <<  comment <<"\n";
            errorout << "Error at line no " << line_count << ": Unterminated comment " <<  comment <<"\n";
            comment = "";
            line_count += string_lines;
            string_lines ++;
            return 0;
            }

"//"        {
            BEGIN singleCommentState;
            comment += yytext;
            }

<singleCommentState>\n {
            //tokenout2 << "<COMMENT," <<  comment << "> ";
            //logout2 << "\nLine no " << line_count << ": TOKEN <COMMENT> Lexeme " << comment << " found\n";
            string_lines ++;
            line_count += string_lines;
            string_lines = 0;
            comment = "";
            BEGIN INITIAL;
            }                      
<singleCommentState>\\\n {
            comment += yytext;
            string_lines++;
            }
<singleCommentState>. {
            comment += yytext;
            }
<singleCommentState><<EOF>> {
            error ++;
            errorout << "\nError found at line : " << line_count << ", Incomplete multi comment statement\n";
            logout << "\nError found at line : " << line_count << ", Incomplete multi comment statement\n";
            comment = "";
            line_count += string_lines;
            string_lines = 0;
            return 0;
            }


[^\n]       {
	        error++;
            errorout << "Error at line " << line_count << ": Unrecgnized character " << yytext << "\n\n";
            logout << "Error at line " << line_count << ": Unrecgnized character " << yytext << "\n\n";
            }
%%

int yywrap(void)
{
	return 1;
}






