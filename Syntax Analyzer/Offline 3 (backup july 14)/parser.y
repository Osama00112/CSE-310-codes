%{
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


%}

%union {
	SymbolInfo *Symbol;
}

%token LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD SEMICOLON COMMA 
%token INT FLOAT CHAR DOUBLE VOID 
%token IF ELSE FOR WHILE RETURN PRINTLN 
%token ASSIGNOP BITOP 
%token NOT INCOP DECOP

%token<Symbol> ID 
%token<Symbol> CONST_INT 
%token<Symbol> CONST_FLOAT 
%token<Symbol> CONST_CHAR 
%token<Symbol> ADDOP 
%token<Symbol> MULOP 
%token<Symbol> RELOP 
%token<Symbol> LOGICOP

%type<Symbol> declaration_list type_specifier var_declaration func_declaration func_definition unit program parameter_list compound_statement
%type<Symbol> statement statements variable expression expression_statement unary_expression simple_expression logic_expression rel_expression term factor arguments argument_list 

//%nonassoc 


%%

start : program
	{
		//write your code in this block in all the similar blocks below
		logout << "Line " << line_count << ": start : program\n\n";
		table->printAllShorts(logout);
	}
	;

program : program unit 
	{
		logout << "Line " << line_count << ": program : program unit\n\n";
		logout << $1-> getName() << $2-> getName() << "\n\n";
		$$ = new SymbolInfo($1-> getName() + $2-> getName(), "nonterm");
	}
	| unit
	{
		logout << "Line " << line_count << ": program : unit\n\n";
		logout << $1-> getName() << "\n\n";
		$$ = $1;
	}
	;
	
unit : var_declaration
	{
		logout << "Line " << line_count << ": unit : var_declaration\n\n";
		logout << $1-> getName() << "\n\n";
		$$ = $1;
	}
     | func_declaration
	 {
		logout << "Line " << line_count << ": unit : func_declaration\n\n";
		logout << $1-> getName() << "\n\n";
		$$ = $1;
	 }
     | func_definition
	 {
		logout << "Line " << line_count << ": unit : func_definition\n\n";
		logout << $1-> getName() << "\n\n";
		$$ = $1;
	 }
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
		{
			logout << "Line " << line_count << ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n\n";
			logout << $1-> getName() << " " << $2-> getName() << "(" << $4-> getName() << ");\n\n";
			$$ = new SymbolInfo($1-> getName() + " " +  $2-> getName() + "(" + $4-> getName() + ");\n", "nonterm");
			//$$->parameterList = $4-> parameterList;

			SymbolInfo *temp = table->lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));
			if(temp != nullptr){
				error ++;
				errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
			}else{
				SymbolInfo *tempFunc = new SymbolInfo($2-> getName(), "ID");
				tempFunc->setIsFunc(true); tempFunc->setReturn_type($1->getName()); tempFunc->setIfDefined(false); tempFunc-> parameterList = $4-> parameterList;
				if(table->insertSymbol(tempFunc)){}
				else{cout << "unsuccessful insertion in func_declaration";}

				//SymbolInfo *newTemp = table-> lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));

			}
		}
		| type_specifier ID LPAREN RPAREN SEMICOLON
		{
			logout << "Line " << line_count << ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n";
			logout << $1-> getName() << " " << $2-> getName() << "();\n\n";
			$$ = new SymbolInfo($1-> getName() + " " +  $2-> getName() + "();\n", "nonterm");

			SymbolInfo *temp = table->lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));
			if(temp != nullptr){
				error ++;
				errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
			}else{
				SymbolInfo *tempFunc = new SymbolInfo($2-> getName(), "ID");
				tempFunc->setIsFunc(true); tempFunc->setReturn_type($1->getName()); tempFunc->setIfDefined(false);
				if(table->insertSymbol(tempFunc)){}
				else{cout << "unsuccessful insertion in func_declaration";}

				//SymbolInfo *newTemp = table-> lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));

			}
		}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN 
		{
			string funcNameFound = $2-> getName();
			string returnTypeFound = $1-> getName();
			

			vector<parameter> parametersFound = $4-> parameterList;
			SymbolInfo *ifExists = table-> lookUpSymbol(new SymbolInfo(funcNameFound, ""));

			//Error
			if(ifExists != nullptr){
				if(ifExists-> getIsFunc()){
					if(ifExists-> getIfDefined()){
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
					}
					else{
						bool validity = true;
						string declaredReturnType = ifExists-> getReturn_type();
						int parameterCount1 = ifExists-> parameterList.size();
						int parameterCount2 = parametersFound.size();
						if(parameterCount1 != parameterCount2){
							error ++;
							errorout << "Error at line " << line_count << ": The number of parameters are not the same for the function " << $2->getName() << "()\n\n";
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
							errorout << "Error at line " << line_count << ": Return type does not match for the function " << $2->getName() << "()\n\n";
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
					errorout << "Error at line " << line_count << ": ID is not a function : " << $2->getName()  << "()\n\n";

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
		compound_statement
		{
			$$ = new SymbolInfo($1->getName()+ " "  + $2->getName() + "(" + $4->getName() + ")" + $7->getName(), "func_def");
			logout << "Line " << line_count << ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n";
			logout << $1-> getName() << " " << $2-> getName() << "(" << $4->getName() << ")" << $7->getName() <<"\n\n";
		} 
		
		| type_specifier ID LPAREN RPAREN
		{
			string funcNameFound = $2-> getName();
			string returnTypeFound = $1-> getName();

			SymbolInfo *ifExists = table-> lookUpSymbol(new SymbolInfo(funcNameFound, ""));

			//Error
			if(ifExists != nullptr){
				if(ifExists-> getIsFunc()){
					if(ifExists-> getIfDefined()){
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
					}
					else{
						bool validity = true;
						string declaredReturnType = ifExists-> getReturn_type();
						//cout << returnTypeFound << " " << declaredReturnType << endl;
						if(returnTypeFound != declaredReturnType){
							error ++;
							errorout << "Error at line " << line_count << ": Return type does not match for the function " << $2->getName() << "()\n\n";
							validity = false;
						}
						table-> EnterScope();

					}
				}else{
					table-> EnterScope();
					error ++;
					errorout << "Error at line " << line_count << ": ID is not a function : " << $2->getName()  << "()\n\n";

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
		compound_statement
		{
			$$ = new SymbolInfo($1->getName()+ " "  + $2->getName() + "()" + $6->getName(), "func_def");
			logout << "Line " << line_count << ": func_definition : type_specifier ID LPAREN RPAREN compound_statement\n\n";
			logout << $1-> getName() << " " << $2-> getName() << "()" << $6->getName() <<"\n\n";
		} 
 		;				


parameter_list  : parameter_list COMMA type_specifier ID
		{
			logout << "Line " << line_count << ": parameter_list  : parameter_list COMMA type_specifier ID\n\n";
			logout << $1-> getName() << " , " << $3-> getName() << " " << $4->getName() << "\n\n";
			$$ = new SymbolInfo($1-> getName() + "," +  $3-> getName() + " " + $4->getName(), "nonterm");

			$$-> parameterList = $1-> parameterList;
			$$-> parameterListAdd($4-> getName(), $3-> getName());

			//Error
			if($3-> getName() == "void"){
				error ++;
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
			}
		}
		| parameter_list COMMA type_specifier
		{
			logout << "Line " << line_count << ": parameter_list  : parameter_list COMMA type_specifier\n\n";
			logout << $1-> getName() << " , " << $3-> getName() << "\n\n";
			$$ = new SymbolInfo($1-> getName() + "," +  $3-> getName(), "nonterm");

			$$-> parameterList = $1-> parameterList;
			$$-> parameterListAdd("", $3-> getName());
		}
 		| type_specifier ID
		{
			logout << "Line " << line_count << ": parameter_list  : type_specifier ID\n\n";
			logout << $1-> getName() << " " << $2-> getName() << "\n\n";
			$$ = new SymbolInfo($1-> getName() + " " + $2-> getName() , "nonterm");

			//cout << "in param list " << $1->getName() + " " + $2-> getName() << "and type " << $1->getType() + " " + $2-> getType()<< endl;
			//Error
			if($1-> getName() == "void"){
				error ++;
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
			}
			$$-> parameterListAdd($2-> getName(), $1-> getName());
		}
		| type_specifier
		{
			logout << "Line " << line_count << ": parameter_list  : type_specifier\n\n";
			logout << $1-> getName() << "\n\n";
			$$ = $1;

			$$-> parameterListAdd("", $1-> getName());
		}
 		;

 		
compound_statement : LCURL statements RCURL
			{
				$$ = new SymbolInfo("{\n" + $2->getName() +  "}", "compound");
				logout << "Line " << line_count << ": compound_statement : LCURL statements RCURL\n\n";
				logout << "{\n" << " " << $2->getName() << "}\n\n";
				table-> printAllShorts(logout);
				table-> ExitScope();
				variableList.clear();
			}
 		    | LCURL RCURL
			{
				$$ = new SymbolInfo("{\n}", "compound");
				logout << "Line " << line_count << ": compound_statement : LCURL RCURL\n\n";
				logout << "{\n}\n\n";
				table-> printAllShorts(logout);
				table-> ExitScope();
				variableList.clear();
			}
 		    ;
 		    
var_declaration : type_specifier declaration_list SEMICOLON
		{
			string Type_found = $1->getName();
			string Var_found = $2->getName();
			logout << "Line " << line_count << ": var_declaration : type_specifier declaration_list SEMICOLON\n\n";
			logout << Type_found << " " << Var_found << ";\n\n";
			$$ = new SymbolInfo(Type_found + " " + Var_found + ";\n", "nonterm");

			$$->setVariable_type(Type_found);
			for(int i=0; i< $2->varList.size(); i++){
				$2->varList[i].type = Type_found;
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
				for(int i=0; i< $2->varList.size(); i++){
					temp = table->lookUpSymbol_currentScope(new SymbolInfo($2->varList[i].name, ""));

					//Error
					if(temp != nullptr){
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->varList[i].name << "\n\n";
						//logout << "Error at line " << line_count << ": Multiple declaration of " << $2->varList[i].name << "\n\n";
					}

					//not_error
					else{
						temp = new SymbolInfo($2->varList[i].name, "ID");

						if($2->varList[i].ifArray != 0){
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
 		;
 		 
type_specifier	: INT
		{
			logout << "Line " << line_count << ": type_specifier : INT\n\nint\n\n";
			$$ = new SymbolInfo("int" , "int");
		}
 		| FLOAT
		{
			logout << "Line " << line_count << ": type_specifier : FLOAT\n\nfloat\n\n";
			$$ = new SymbolInfo("float" , "float");
		}
 		| VOID
		{
			logout << "Line " << line_count << ": type_specifier : VOID\n\nvoid\n\n";
			$$ = new SymbolInfo("void" , "void");
		}
 		;
 		
declaration_list : declaration_list COMMA ID
		{
			logout << "Line " << line_count << ": declaration_list : declaration_list COMMA ID\n\n";
			logout << $1->getName() << "," << $3->getName() << "\n\n";
			$$ = new SymbolInfo($1->getName() + "," + $3->getName(), "nonterm");
			$$->setId("variable");

			tempVar.name = $3-> getName();
			tempVar.size = -1;
			variableList.push_back(tempVar);
			$$->varList = $1->varList;
			$$->varListAdd($3->getName(),$3->getType() , 0);
			
		}
 		| declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
		{
			logout << "Line " << line_count << ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n\n";
			logout << $1->getName() << "," << $3->getName() << "[" << $5->getName() << "]\n\n";
			$$ = new SymbolInfo($1->getName() + "," + $3->getName() + "[" + $5->getName() + "]", "nonterm");
			$$->setId("array");

			tempVar.name = $3-> getName();
			stringstream tempStr($5-> getName());
			tempStr >> tempVar.size;
			variableList.push_back(tempVar);

			stringstream diff($5-> getName());
			int size = 0;
			diff >> size;
			$$->varList = $1->varList;
			$$->varListAdd($3->getName(), $3->getType() , size);
		}
 		| ID
		{
			logout << "Line " << line_count << ": declaration_list : ID\n\n";
			logout << $1->getName() << "\n\n";
			$$ = $1; //new SymbolInfo($1->getName(), "ID");
			$$->setId("variable");

			tempVar.name = $1-> getName();
			tempVar.size = -1;
			variableList.push_back(tempVar);
			$$->varList = $1->varList;
			$$->varListAdd($1->getName(), $1->getType(), 0);
		}
 	  	| ID LTHIRD CONST_INT RTHIRD
		{
			logout << "Line " << line_count << ": declaration_list : ID LTHIRD CONST_INT RTHIRD\n\n";
			logout << $1->getName() << "[" << $3->getName() << "]\n\n";
			$$ = new SymbolInfo($1->getName() + "[" + $3->getName() + "]", "nonterm");
			
			tempVar.name = $1-> getName();
			stringstream tempStr($3-> getName());
			tempStr >> tempVar.size;
			variableList.push_back(tempVar);

			stringstream diff($3-> getName());
			int size = 0;
			diff >> size;
			$$->varList = $1->varList;
			$$->varListAdd($1->getName(), "" , size);
		}
 		;
 		  
statements : statement
		{
			$$ = $1;
			logout << "Line " << line_count << ": statements : statement\n\n";
			logout << $1-> getName() << "\n\n";
		}
		| statements statement
		{
			$$ = new SymbolInfo($1->getName() + " " + $2->getName(), "statements");
			logout << "Line " << line_count << ": statements : statements statement\n\n";
			logout << $1-> getName() << " " << $2->getName() << "\n\n";
		}
	   	;
	   
statement : var_declaration
		{
			$$ = $1;
			logout << "Line " << line_count << ": statement : var_declaration\n\n";
			logout << $1-> getName() << "\n\n";
		}
	  	| expression_statement
		{
			$$ = $1;
			logout << "Line " << line_count << ": statement : expression_statement\n\n";
			logout << $1-> getName() << "\n\n";
		}
		
	  	| {table-> EnterScope();} compound_statement
		{
			$$ = $2;
			logout << "Line " << line_count << ": statement : compound_statement\n\n";
			logout << $2-> getName() << "\n\n";
		}
	  	| FOR LPAREN expression_statement expression_statement expression RPAREN statement
		{
			$$ = new SymbolInfo("for(" + $3->getName() + $4->getName() + $5->getName() + ")" + $7->getName() , "statement");
			logout << "Line " << line_count << ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n";
			logout << "for(" << $3-> getName() << " " <<  $4->getName() << " " << $5->getName() << ")" << $7->getName() << "\n\n";
		}
	  	| IF LPAREN expression RPAREN statement
		{
			$$ = new SymbolInfo("if(" + $3->getName() + ")" + $5->getName() , "statement");
			logout << "Line " << line_count << ": statement : IF LPAREN expression RPAREN statement\n\n";
			logout << "if(" << $3-> getName() <<  ")" << $5->getName() << "\n\n";
		}
	  	| IF LPAREN expression RPAREN statement ELSE statement
		{
			$$ = new SymbolInfo("if(" + $3->getName() + ")" + $5->getName() + "else" + $7-> getName() , "statement");
			logout << "Line " << line_count << ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n";
			logout << "if(" << $3-> getName() <<  ")" << $7->getName() << "else" << $7->getName() <<"\n\n";
		}
	  	| WHILE LPAREN expression RPAREN statement
		{
			$$ = new SymbolInfo("while(" + $3->getName() + ")" + $5->getName() , "statement");
			logout << "Line " << line_count << ": statement : WHILE LPAREN expression RPAREN statement\n\n";
			logout << "while(" << $3-> getName() <<  ")" << $5->getName() <<"\n\n";
		}
	  	| PRINTLN LPAREN ID RPAREN SEMICOLON
		{
			string nameFound = $3-> getName();
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

			$$ = new SymbolInfo("printf(" + $3->getName() + ");\n", "statement");
			logout << "Line " << line_count << ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n";
			logout << "printf(" << $3-> getName() <<  ");\n\n";
		}
	  	| RETURN expression SEMICOLON
		{
			string returnTypeFound = $2->getReturn_type();
			if(returnTypeFound == "void"){
				error ++ ;
				errorout << "Error at line " << line_count << ": void doesnt have return types\n\n";
			}
			$$ = new SymbolInfo("return " + $2->getName() + ";\n", "statement");
			logout << "Line " << line_count << ": statement : RETURN expression SEMICOLON\n\n";
			logout << "return " << $2-> getName() <<  ";\n\n";
		}
	  	;
	  
expression_statement 	: SEMICOLON		
			{
				$$ = new SymbolInfo(";\n", "statement");
			}	
			| expression SEMICOLON 
			{
				$$ = new SymbolInfo($1->getName() + ";\n", "expression_statement");
				logout << "Line " << line_count << ": expression_statement : expression SEMICOLON \n\n";
				logout << $1-> getName() <<  ";\n\n";
			}
			;
	  
variable : ID 	
	{
		string nameFound = $1->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, ""));

		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			$$ = new SymbolInfo(nameFound , "INVALID");
		}else{
			if(ifExists->getId() == "array"){
				error ++ ;
			
				errorout << "Error at line " << line_count << ": Type mismatch, "<< nameFound  <<" is an array\n\n";
				$$ = new SymbolInfo(nameFound, "INVALID");

			}else{
				$$ = new SymbolInfo(nameFound, ifExists->getType());
			}
		}
		logout << "Line " << line_count << ": variable : ID\n\n";
		logout << $1-> getName() <<  "\n\n";

	}	
	| ID LTHIRD expression RTHIRD 
	{
		string nameFound = $1->getName();
		string indexType = $3->getType();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, "" ));
		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			$$ = new SymbolInfo(nameFound , "INVALID");
		}else{
			if(ifExists->getId() == "array"){
				string finalType = indexType;
				if(indexType != "int"){
					error ++ ;
					errorout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
					//cout << "index type for " << $3->getName() << " is " << indexType << "\n";
					finalType = "INVALID";
				}
				else if(stoi($3->getName()) < 0){
					error ++ ;
					errorout << "Error at line " << line_count << ": Expression inside third brackets is negative :" << $3-> getName() << "\n\n";
					finalType = "INVALID";
				}
				SymbolInfo *temp = new SymbolInfo(nameFound + "[" + $3->getName() + "]", finalType);
				$$ = temp;

			}else{
				error ++ ;
				errorout << "Error at line " << line_count << ": Type mismatch, "<< nameFound  <<" is a variable\n\n";
				$$ =  new SymbolInfo(nameFound + "[" + $3->getName() + "]", "INVALID");
			}
		}
		logout << "Line " << line_count << ": variable : ID LTHIRD expression RTHIRD\n\n";
		logout << $1-> getName() << "[" << $3->getName() << "]\n\n";
	}
	;
	 
expression : logic_expression	
		{
			$$ = $1;
			logout << "Line " << line_count << ": expression : logic_expression\n\n";
			logout << $1-> getName() << "\n\n";
		}
	   | variable ASSIGNOP logic_expression 	
	   {
			string operand1 = $1-> getName();
			string operand2 = $3-> getName();
			string type1 = $1-> getType();
			string type2 = $3-> getType();

			if(type1 == type2){

			}else{
				if(type1 == "INVALID" || type2 == "INVALID"){
					if($1->getId() == "array"){
						error ++ ;
						errorout << "Error at line " << line_count << ": Type mismatch, "<< $1->getName()  <<" is an array\n\n";
					}else if($3->getName() == "array"){
						error ++ ;
						errorout << "Error at line " << line_count << ": Type mismatch, "<< $3->getName()  <<" is an array\n\n";
					}
				}else if(type1 == "float" && type2 == "int"){}
				else{
					error ++ ;
					//cout << "types mismatched for var " << operand1 << " type: " << type1 << " id: " << $1->getReturn_type() <<endl; 
					errorout << "Error at line " << line_count << ": Type mismatch for variable "<< $1->getName()  <<"\n\n";
				}
			}

			$$ = new SymbolInfo($1->getName() + "=" + $3->getName() , "expression");
			logout << "Line " << line_count << ": expression : variable ASSIGNOP logic_expression\n\n";
			logout << $1->getName() << "=" << $3->getName() <<"\n\n";
	   }

	   ;
			
logic_expression : rel_expression 	
		{
			$$ = $1;
			logout << "Line " << line_count << ": logic_expression : rel_expression \n\n";
			logout << $1->getName() <<"\n\n";
		}
		| rel_expression LOGICOP rel_expression 	
		{
			string type1 = $1->getType();
			string type2 = $3->getType();
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
			$$ = new SymbolInfo($1->getName() + $2-> getName() + $3->getName() , finalType);
			logout << "Line " << line_count << ": logic_expression : rel_expression LOGICOP rel_expression \n\n";
			logout << $1->getName() << $2->getName() << $3->getName() <<"\n\n";
		}
		;
			
rel_expression	: simple_expression 
		{
			$$ = $1;
			logout << "Line " << line_count << ": rel_expression : simple_expression \n\n";
			logout << $1->getName() <<"\n\n";
		}
		| simple_expression RELOP simple_expression	
		{
			$$ = new SymbolInfo($1->getName() + $2-> getName() + $3->getName() , "int");
			logout << "Line " << line_count << ": rel_expression : simple_expression RELOP simple_expression\n\n";
			logout << $1->getName() << $2->getName() << $3->getName() <<"\n\n";
		}
		;
				
simple_expression : term 
		{
			$$ = $1;
			logout << "Line " << line_count << ": simple_expression : term \n\n";
			logout << $1->getName() <<"\n\n";
		}
		| simple_expression ADDOP term
		{
			string type1 = $1->getType();
			string type2 = $3->getType();

			if(type1 == "float" || type2 == "float")
				$$ = new SymbolInfo($1->getName() + $2->getName() + $3->getName(), "float");
			else
				$$ = new SymbolInfo($1->getName() + $2->getName() + $3->getName(), "int");
			logout << "Line " << line_count << ": simple_expression : simple_expression ADDOP term \n\n";
			logout << $1->getName() << $2->getName() << $3->getName() <<"\n\n";
		} 
		;
					
term :	unary_expression
	{
		$$ = $1;
		logout << "Line " << line_count << ": term : unary_expression\n\n";
		logout << $1->getName() <<"\n\n";
	}
    |  term MULOP unary_expression
	{
		string operand1 = $1-> getName();
		string operand2 = $3-> getName();
		string type1 = $1-> getType();
		string type2 = $3-> getType();
		string operatorFound = $2->getName();
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

		$$ = new SymbolInfo($1->getName() + $2->getName() + $3->getName() , finalType);
		logout << "Line " << line_count << ": term : term MULOP unary_expression\n\n";
		logout << $1->getName() << $2->getName() << $3->getName() <<"\n\n";
	}
    ;

unary_expression : ADDOP unary_expression  
		{
			$$ = new SymbolInfo($1->getName()  + $2->getName(), "unary");
			logout << "Line " << line_count << ": unary_expression : ADDOP unary_expression \n\n";
			logout << $1-> getName()  << $2->getName() <<"\n\n";
		}
		| NOT unary_expression 
		{
			$$ = new SymbolInfo("!" + $2->getName(), "unary");
			logout << "Line " << line_count << ": unary_expression : NOT unary_expression \n\n";
			logout << "!"  << $2->getName() <<"\n\n";
		}
		| factor
		{
			$$ = $1;
			logout << "Line " << line_count << ": unary_expression : factor\n\n";
			logout << $1->getName() <<"\n\n";
		} 
		;
	
factor	: variable 
	{
		$$ = $1;
		logout << "Line " << line_count << ": factor : variable\n\n";
		logout << $1-> getName() << "\n\n";
	}
	| ID LPAREN argument_list RPAREN
	{
		string nameFound = $1->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo($1->getName(),""));
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
				}else if(ifExists->parameterList.size() != $3->argumentList.size()){
					error ++ ;
					errorout << "Error at line " << line_count << ": Number of arguments and parameters do not match for ID : " << nameFound << "\n\n";
					cout << "argument size " << $3->argumentList.size() << " parameter size " << ifExists->parameterList.size() << endl;
				}else{
					for(int i=0; i < $3->argumentList.size(); i++){
						if($3->argumentList[i].type != ifExists->parameterList[i].type && $3->argumentList[i].type != "INVALID"){
							cout << "argument type and parameter type: " << $3->argumentList[i].type << " " << ifExists->parameterList[i].type << endl;
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

		$$ = new SymbolInfo($1-> getName() + "(" + $3->getName() + ")", returnTypeDeclared);
		logout << "Line " << line_count << ": factor : ID LPAREN argument_list RPAREN\n\n";
		logout << $1-> getName() << "(" << $3-> getName() << ")\n\n";
	}
	| LPAREN expression RPAREN
	{
		$$ = new SymbolInfo("(" + $2->getName() + ")", "factor");
		logout << "Line " << line_count << ": factor : LPAREN expression RPAREN\n\n";
		logout << "(" << $2-> getName() << ")" << "\n\n";
	}
	| CONST_INT 
	{
		$$ = $1;
		logout << "Line " << line_count << ": factor : CONST_INT\n\n";
		logout << $1-> getName() << "\n\n";
	}
	| CONST_FLOAT
	{
		$$ = $1;
		logout << "Line " << line_count << ": factor : CONST_FLOAT\n\n";
		logout << $1-> getName() << "\n\n";
	}
	| variable INCOP 
	{
		$$ = new SymbolInfo($1->getName() + "++" , "factor");
		logout << "Line " << line_count << ": factor : variable INCOP \n\n";
		logout << $1-> getName() << "++\n\n";
	}

	| variable DECOP
	{
		$$ = new SymbolInfo($1->getName() + "--" , "factor");
		logout << "Line " << line_count << ": factor : variable DECOP\n\n";
		logout << $1-> getName() << "--\n\n";
	}
	;
	
argument_list : arguments
				{
					$$ = $1;
					logout << "Line " << line_count << ": argument_list : arguments\n\n";
					logout << $1-> getName() << "\n\n";
				}
			  	|
				{
					$$ = new SymbolInfo("", "void");
					logout << "Line " << line_count << ": argument_list : \n\n";
					logout << "\n\n";
				}
			  	;
	
arguments : arguments COMMA logic_expression
			{
				string nameFound = $1->getName()+","+$3->getName();
				string typeFound = $1->getType()+","+$3->getType();
				string finalType = $3->getType();

				$$ = new SymbolInfo(nameFound, typeFound);
				$$-> argumentList = $1-> argumentList;
				
				string varNameFound = $3-> getName();
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
				$$-> argumentListAdd(varNameFound, $3->getType(), 0);
				logout << "Line " << line_count << ": arguments : arguments COMMA logic_expression\n\n";
				logout << $1-> getName() << "," << $3->getName() << "\n\n";
			}
	      	| logic_expression
		  	{
					$$ = $1;
					logout << "Line " << line_count << ": arguments : logic_expression\n\n";
					logout << $1-> getName() << "\n\n";

					string varNameFound = $1-> getName();
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
					$$->argumentListAdd(varNameFound, $1->getType(), 0);
		  		}	
	      		;
 

%%
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

