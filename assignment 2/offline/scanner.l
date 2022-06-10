%option noyywrap

%x charState
%x multiCommentState

%{
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>

#include "1805002_SymbolTable.h"

using namespace std;

int line_count=1;
int errorCount = 0;
string comment = "";
string chr = "";

FILE *logout;
FILE *tokenout;
ofstream logout2;
ofstream tokenout2;

SymbolTable *newTable = new SymbolTable(7,1);
SymbolInfo *newInfo = nullptr;

void charRule(string str){
	char token;
	if(str.length() == 3){
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
	else{
        errorCount ++;
		logout2 << "Error found at line " << line_count << ". Invalid character\n";
	}
    tokenout2 << "<CONST_CHAR," <<  token << "> ";
    logout2 << "\nLine no " << line_count << ": TOKEN <CONST_CHAR> Lexeme " << str << " found --> " << "<CONST_CHAR," <<  token << "> \n";
    newInfo = new SymbolInfo(str, "CONST_CHAR");
    newTable->insertSymbol(newInfo);
    newTable->printAllShorts(logout2); 
}

%}

WHITESPACE 		[ \t\v]+ 
LETTER 			[a-zA-Z]
DIGIT 			[0-9]
NUMBER 			{DIGIT}+
EXPONEN 		([Ee][+-]?{DIGIT}+)
FLOAT  			({NUMBER}{EXPONEN}?)|({NUMBER}\.{NUMBER}?{EXPONEN}?)|(\.{NUMBER}{EXPONEN}?)
ID     			[_a-zA-Z][_a-zA-Z0-9]*
NEWLINE 		[\n]
RELOP 			[">"|">="|"<"|"<="|"=="|"!="]
BITOP 			["|"|"&"|"^"|"<<"|">>"] 
STRING 			\"((\\[\n])|(\")|[^\n])*\"
CHARACTER_T1	'([ -~]{-}['\\])'
ESCAPE_CHAR  	'(\\[\\0abfnrtv'\"])'
CHARACTERS      [{CHARACTER_T1}|{ESCAPE_CHAR}]


%%
{NEWLINE}   {line_count++;}
"int"       {
                tokenout2 << "<INT, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <INT> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<INT> ");
			    fprintf(logout,"\nLine no %d: TOKEN <INT> Lexeme %s found\n",line_count,yytext);
		    }
"float"     {
                tokenout2 << "<FLOAT, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <FLOAT> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<FLOAT> ");
			    fprintf(logout,"\nLine no %d: TOKEN <FLOAT> Lexeme %s found\n",line_count,yytext);
		    }
"char"      {
                tokenout2 << "<CHAR, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <CHAR> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<CHAR> ");
			    fprintf(logout,"\nLine no %d: TOKEN <CHAR> Lexeme %s found\n",line_count,yytext);
		    }
"double"    {
                tokenout2 << "<DOUBLE, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <DOUBLE> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<DOUBLE> ");
			    fprintf(logout,"\nLine no %d: TOKEN <DOUBLE> Lexeme %s found\n",line_count,yytext);
		    }           
","         {
                tokenout2 << "<COMMA," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <COMMA> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<COMMA> ");
			    fprintf(logout,"\nLine no %d: TOKEN <COMMA> Lexeme %s found\n",line_count,yytext);
		    }
";"         {
                tokenout2 << "<SEMICOLON," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <SEMICOLON> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<SEMICOLON> ");
			    fprintf(logout,"\nLine no %d: TOKEN <SEMICOLON> Lexeme %s found\n",line_count,yytext);
		    }
"if"	    {
                tokenout2 << "<IF," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <IF> Lexeme " << yytext << " found\n";
			    fprintf(tokenout,"<IF> ");
			    fprintf(logout,"\nLine no %d: TOKEN <IF> Lexeme %s found\n",line_count,yytext);
		    }	
"else"	    {
                tokenout2 << "<ELSE," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <ELSE> Lexeme " << yytext << " found\n";
			    fprintf(tokenout,"<ELSE> ");
			    fprintf(logout,"\nLine no %d: TOKEN <ELSE> Lexeme %s found\n",line_count,yytext);
		    }
"for"	    {
                tokenout2 << "<FOR," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <FOR> Lexeme " << yytext << " found\n";
			    fprintf(tokenout,"<FOR> ");
			    fprintf(logout,"\nLine no %d: TOKEN <FOR> Lexeme %s found\n",line_count,yytext);
		    }
"while"     {
                tokenout2 << "<WHILE, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <WHILE> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<WHILE> ");
			    fprintf(logout,"\nLine no %d: TOKEN <WHILE> Lexeme %s found\n",line_count,yytext);
		    }
"do"        {
                tokenout2 << "<DO, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <DO> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<DO> ");
			    fprintf(logout,"\nLine no %d: TOKEN <DO> Lexeme %s found\n",line_count,yytext);
		    }              
"break"     {
                tokenout2 << "<BREAK, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <BREAK> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<BREAK> ");
			    fprintf(logout,"\nLine no %d: TOKEN <BREAK> Lexeme %s found\n",line_count,yytext);
		    }
"continue"  {
                tokenout2 << "<CONTINUE, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <CONTINUE> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<CONTINUE> ");
			    fprintf(logout,"\nLine no %d: TOKEN <CONTINUE> Lexeme %s found\n",line_count,yytext);
		    }            
"switch"    {
                tokenout2 << "<SWITCH, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <SWITCH> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<SWITCH> ");
			    fprintf(logout,"\nLine no %d: TOKEN <SWITCH> Lexeme %s found\n",line_count,yytext);
		    }  
"case"      {
                tokenout2 << "<CASE, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <CASE> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<CASE> ");
			    fprintf(logout,"\nLine no %d: TOKEN <CASE> Lexeme %s found\n",line_count,yytext);
		    }  
"default"   {
                tokenout2 << "<DEFAULT, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <DEFAULT> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<DEFAULT> ");
			    fprintf(logout,"\nLine no %d: TOKEN <DEFAULT> Lexeme %s found\n",line_count,yytext);
		    }                                                      
"return"    {
                tokenout2 << "<RETURN, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <RETURN> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<RETURN> ");
			    fprintf(logout,"\nLine no %d: TOKEN <RETURN> Lexeme %s found\n",line_count,yytext);
		    }
"void"      {
                tokenout2 << "<VOID, " <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <VOID> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<VOID> ");
			    fprintf(logout,"\nLine no %d: TOKEN <VOID> Lexeme %s found\n",line_count,yytext);
		    }
"+"|"-"     {
                tokenout2 << "<ADDOP," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <ADDOP> Lexeme " << yytext << " found\n";
	    		fprintf(tokenout,"<ADDOP,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <ADDOP> Lexeme %s found\n",line_count,yytext);
			    //insert in symbol table and print symbol table content(only non empty buckets)
		    	// There is a '|' in "+"'s rule, this means match execute the action for following rule
		    }           
"*"|"/"|"%" {
                tokenout2 << "<MULOP," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <MULOP> Lexeme " << yytext << " found\n";
	    		fprintf(tokenout,"<MULOP,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <MULOP> Lexeme %s found\n",line_count,yytext);
		    }  
"++"|"--"   {
                tokenout2 << "<INCOP," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <INCOP> Lexeme " << yytext << " found\n";
	    		fprintf(tokenout,"<INCOP,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <INCOP> Lexeme %s found\n",line_count,yytext);

            }
"||"|"&&"   {
                tokenout2 << "<LOGICOP," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <LOGICOP> Lexeme " << yytext << " found\n";
	    		fprintf(tokenout,"<LOGICOP,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <LOGICOP> Lexeme %s found\n",line_count,yytext);

            }            
"="		    {
                tokenout2 << "<ASSIGNOP," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <ASSIGNOP> Lexeme " << yytext << " found\n";
	    		fprintf(tokenout,"<ASSIGNOP,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
		    }
"!"		    {
                tokenout2 << "<NOT," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <NOT> Lexeme " << yytext << " found\n";
	    		fprintf(tokenout,"<NOT,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <NOT> Lexeme %s found\n",line_count,yytext);
		    }
"("         {
                tokenout2 << "<LPAREN," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <LPAREN> Lexeme " << yytext << " found\n";
		    	fprintf(tokenout,"<LPAREN,%s> ",yytext);
		    	fprintf(logout,"\nLine no %d: TOKEN <LPAREN> Lexeme %s found\n",line_count,yytext);
	    	}
")"         {
                tokenout2 << "<RPAREN," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <RPAREN> Lexeme " << yytext << " found\n";
			    fprintf(tokenout,"<RPAREN,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <RPAREN> Lexeme %s found\n",line_count,yytext);
		    }		
"{"         {
                tokenout2 << "<LCURL," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <LCURL> Lexeme " << yytext << " found\n";
			    fprintf(tokenout,"<LCURL,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <LCURL> Lexeme %s found\n",line_count,yytext);
                newTable->EnterScope();
		    }
"}"         {
                tokenout2 << "<RCURL," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <RCURL> Lexeme " << yytext << " found\n";
			    fprintf(tokenout,"<RCURL,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <RCURL> Lexeme %s found\n",line_count,yytext);
                newTable->ExitScope();
		    }
"["         {
                tokenout2 << "<LTHIRD," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <LTHIRD> Lexeme " << yytext << " found\n";
			    fprintf(tokenout,"<LTHIRD,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <LTHIRD> Lexeme %s found\n",line_count,yytext);
                newTable->EnterScope();
		    }
"]"         {
                tokenout2 << "<RTHIRD," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <RTHIRD> Lexeme " << yytext << " found\n";
			    fprintf(tokenout,"<RTHIRD,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <RTHIRD> Lexeme %s found\n",line_count,yytext);
                newTable->ExitScope();
		    }    
{RELOP}     {
                tokenout2 << "<RELOP," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <RELOP> Lexeme " << yytext << " found\n";
	    		fprintf(tokenout,"<RELOP,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <RELOP> Lexeme %s found\n",line_count,yytext);
		    }
{BITOP}     {
                tokenout2 << "<BITOP," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <BITOP> Lexeme " << yytext << " found\n";
	    		fprintf(tokenout,"<BITOP,%s> ",yytext);
			    fprintf(logout,"\nLine no %d: TOKEN <BITOP> Lexeme %s found\n",line_count,yytext);
		    } 
{NUMBER}    { 
                tokenout2 << "<CONST_INT," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <CONST_INT> Lexeme " << yytext << " found\n";
				fprintf(tokenout,"<CONST_INT,%s> ",yytext);
				fprintf(logout,"\nLine no %d: TOKEN <CONST_INT> Lexeme %s found\n",line_count,yytext);
                newInfo = new SymbolInfo(yytext, "CONST_INT");
                newTable->insertSymbol(newInfo);
                //logout << newTable->printAllShorts();
                
                newTable->printAllShorts(logout2);
				//insert in symbol table and print symbol table content(only non empty buckets)
		    }
{FLOAT}     { 
                tokenout2 << "<CONST_FLOAT," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <CONST_FLOAT> Lexeme " << yytext << " found\n";
				fprintf(tokenout,"<CONST_FLOAT,%s> ",yytext);
				fprintf(logout,"\nLine no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);
                newInfo = new SymbolInfo(yytext, "CONST_FLOAT");
                newTable->insertSymbol(newInfo);
                newTable->printAllShorts(logout2);
		    }
{STRING}	{
                tokenout2 << "<STRING," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <STRING> Lexeme " << yytext << " found\n";
            }
{ID}	    {
                tokenout2 << "<ID," <<  yytext << "> ";
                logout2 << "\nLine no " << line_count << ": TOKEN <ID> Lexeme " << yytext << " found\n";
                fprintf(tokenout,"<ID,%s> ",yytext);
				fprintf(logout,"\nLine no %d: TOKEN <ID> Lexeme %s found\n",line_count,yytext);
                newInfo = new SymbolInfo(yytext, "ID");
                newTable->insertSymbol(newInfo);
                newTable->printAllShorts(logout2);
            }
"/*"        {
            BEGIN multiCommentState;
            comment += yytext;
            }
<multiCommentState>"*/" {
            comment += yytext;
            tokenout2 << "<COMMENT," <<  comment << "> ";
            logout2 << "\nLine no " << line_count << ": TOKEN <COMMENT> Lexeme " << comment << " found\n";
            //fprintf(tokenout,"<COMMENT,%s> ",comment);
			//fprintf(logout,"\nLine no %d: TOKEN <COMMENT> Lexeme %s found\n",line_count,comment);
            comment = "";
            BEGIN INITIAL;
            }            
<multiCommentState>\n {
            comment += yytext;
            line_count++;
            }
<multiCommentState>. {
            comment += yytext;
            }
<multiCommentState><<EOF>> {
            errorCount ++;

            logout2 << "\nError found at line : " << line_count << ", Incomplete multi comment statement\n";
            }
\'			{
			chr += yytext;
			BEGIN charState;
			}
<charState>\' {
			chr += yytext;
			//logout2 << "after char state string found " << chr << "\n";
			charRule(chr);
			chr = "";
			BEGIN INITIAL;
			}
<charState>\n {
            errorCount ++;
            logout2 << "\nError found at line : " << line_count << ", Invalid character initialization\n";
            }
<charState>. {
			chr += yytext;

			}			
<charState><<EOF>> {
            errorCount ++;

            logout2 << "\nError found at line : " << line_count << ", Incomplete statement\n";
            }



%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("log.txt","w");
	tokenout= fopen("token.txt","w");
    logout2.open("log2.txt");
    tokenout2.open("token2.txt");

	yyin= fin;
	yylex();
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);

    delete newTable;
	return 0;
}