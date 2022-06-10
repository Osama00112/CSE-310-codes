%option noyywrap

%{
#include<bits/stdc++.h>

using namespace std;
%}

AlphaNumeric [a-zA-Z0-9]
Digit [0-9]
Number {Digit}+


%%
[ \t\n]+ 			{}
[A-Z]{3}			{printf("%s matched in [A-Z]{3} rule\n",yytext);}
a* 					{printf("%s matched in a* rule\n",yytext);}
A* 					{printf("%s matched in A* rule\n",yytext);}
{Number}            {cout<< yytext << "matched in some rule\n";}
{AlphaNumeric}+ 	{printf("%s matched in Alphanumeric rule\n",yytext);}


. 					{printf("Mysterious character %s found\n",yytext);}
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
	

	yyin= fin;
	yylex();
	fclose(yyin);
	return 0;
}