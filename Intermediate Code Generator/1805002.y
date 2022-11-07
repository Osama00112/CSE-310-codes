%{
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include "1805002_SymbolTable.h"
#include "1805002_Assembly.h"

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE *yyin;
FILE *fp;

ofstream logout;
ofstream errorout;
ofstream assembly;
ofstream assembly2;

extern int line_count;
extern int error;

string currentFunctionName = "";
int currentFuncParamCount = 0;

int labelCount=0;
int tempCount=0;
int logicOpCount = 0;
int relopCount = 0;

int forLoopCount = 0;
stack<int> loopStack;
int whileCount = 0;
stack<int> whileStack;

int ifCount = 0;
int ifTrueCount = 0;
int elseIfFalseCount = 0;
stack<int> ifStack;

int NOTCount = 0;

int stackIncease = -2;
int stackDecrease = 0;
int offsetCheck;
vector<pair<string, int>> globalList;


string newLabel(){
	return "L"+ to_string(labelCount++);
}

string newTemp(){
	string temp = "t" + to_string(tempCount++);
	globalList.push_back({temp, 0});
	return temp;
}


//temporary variables
variable tempVar;
vector<variable> variableList;
myfunction tempFunction;
vector<myfunction> functionList;



SymbolTable *table = new SymbolTable(30,1);
int getIndex(vector<variable> v, string k)
{
	offsetCheck = 0;
    for(int i = 0; i< v.size(); i++){
		//cout << "list " << i << ": " << v[i].name << " ifarray " << v[i].ifArray << endl;
		if(v[i].ifArray == 0)
			offsetCheck += 2;
		else	
			offsetCheck += (2*v[i].ifArray);
		if(v[i].name == k)
			return i;
		
	}
	return -1;
}

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


%}

%union {
	SymbolInfo *Symbol;
}

%token LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD SEMICOLON COMMA 
%token INT FLOAT CHAR DOUBLE VOID 
%token IF ELSE FOR WHILE RETURN PRINTLN NEWLINE
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
%type<Symbol> if_condition

%nonassoc LOWER_THAN_ELSE 
%nonassoc ELSE 


%%

start :
	{
		startAssemble(assembly, globalList);
	}
	program
	{
		// if(error == 0){
		// 	startAssemble(assembly, globalList);
		// }
		//write your code in this block in all the similar blocks below
		line_count --;
		logout << "Line " << line_count << ": start : program\n\n";
		table->printAllShorts(logout);
		printProc(assembly);
		printDataSegment(assembly, globalList);
		assembly << "END main\n";
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
			vector<parameter> parametersFound = $4-> parameterList;

			SymbolInfo *temp = table->lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));
			if(temp != nullptr){
				error ++;
				errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
				logout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
			}else{
				SymbolInfo *tempFunc = new SymbolInfo($2-> getName(), "ID");
				tempFunc->setIsFunc(true); tempFunc->setReturn_type($1->getName()); tempFunc->setIfDefined(false); tempFunc-> parameterList = $4-> parameterList;
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
		| type_specifier ID LPAREN RPAREN SEMICOLON
		{
			logout << "Line " << line_count << ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON\n\n";
			logout << $1-> getName() << " " << $2-> getName() << "();\n\n";
			$$ = new SymbolInfo($1-> getName() + " " +  $2-> getName() + "();\n", "nonterm");

			SymbolInfo *temp = table->lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));
			if(temp != nullptr){
				error ++;
				errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
				logout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
			}else{
				SymbolInfo *tempFunc = new SymbolInfo($2-> getName(), "ID");
				tempFunc->setIsFunc(true); tempFunc->setReturn_type($1->getName()); tempFunc->setIfDefined(false);
				if(table->insertSymbol(tempFunc)){
					//cout << "inserted in func_declaration " << $2->getName()<< endl;
					}
				else{cout << "unsuccessful insertion in func_declaration";}

				//SymbolInfo *newTemp = table-> lookUpSymbol_currentScope(new SymbolInfo($2-> getName(), ""));

			}
		}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN 
		{
			string funcNameFound = $2-> getName();
			string returnTypeFound = $1-> getName();
			currentFunctionName = funcNameFound;
			
			assembly << funcNameFound << " PROC\n";
			if (funcNameFound == "main"){
				assembly << "\tMOV DX, @DATA\n\tMOV DS, DX\n";
			}
			pushAction(assembly);
			assembly << "\tPUSH BP\n\tMOV BP, SP\n";

			vector<parameter> parametersFound = $4-> parameterList;
			currentFuncParamCount = parametersFound.size();
			//cout << "parameters found in func def " << currentFuncParamCount << endl;
			SymbolInfo *ifExists = table-> lookUpSymbol(new SymbolInfo(funcNameFound, ""));

			for(int i=0; i< parametersFound.size(); i++){
				stackIncease -= 2;
				parametersFound[i].offset = stackIncease;
				//cout << "offset increased for parameter " << parametersFound[i].name << " offset now " << stackIncease << endl;
			}	
			
			//Error
			if(ifExists != nullptr){
				if(ifExists-> getIsFunc()){
					
					if(ifExists-> getIfDefined()){
						
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
						logout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
					}
					else{
						
						bool validity = true;
						string declaredReturnType = ifExists-> getReturn_type();
						int parameterCount1 = ifExists-> parameterList.size();
						int parameterCount2 = parametersFound.size();
						if(parameterCount1 != parameterCount2){
							error ++;
							errorout << "Error at line " << line_count << ": Total number of arguments mismatch with declaration in function " << $2->getName() << "\n\n";
							logout << "Error at line " << line_count << ": Total number of arguments mismatch with declaration in function " << $2->getName() << "\n\n";
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
							errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << $2->getName() << "()\n\n";
							logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << $2->getName() << "()\n\n";
							validity = false;
						}
						

						// pushAction(assembly);
						// assembly << funcNameFound << " PROC\n";
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
							tempFunc->offset = parametersFound[i].offset;
							//cout << tempFunc->offset << endl;
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
					errorout << "Error at line " << line_count << ": ID is not a function : " << $2->getName()  << "()\n\n";
					logout << "Error at line " << line_count << ": ID is not a function : " << $2->getName()  << "()\n\n";

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
				
				// pushAction(assembly);
				// assembly << funcNameFound << " PROC\n";

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
					tempFunc->offset = parametersFound[i].offset;
					if(table->insertSymbol(tempFunc)){}
					else{
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of variable " << parametersFound[i].name <<" in parameter\n\n";
						logout << "Error at line " << line_count << ": Multiple declaration of variable " << parametersFound[i].name <<" in parameter\n\n";
					}
				}

			}
		}
		compound_statement
		{	
			assembly << $2->getName() << "_exit:\n";
			assembly << "\n\tADD SP, " << stackDecrease << "\n";
			stackDecrease = 0;
			stackIncease = -2;
			popAction(assembly);
			if ($2->getName() == "main"){
				assembly << "\n\tMOV AH, 4CH\n\tINT 21H\n";
			}else{
				assembly << "\n\tRET " << currentFuncParamCount*2 << "\n";
			}

			assembly << $2->getName()  << " ENDP\n";
			currentFunctionName = "";
			currentFuncParamCount = 0;
			$$ = new SymbolInfo($1->getName()+ " "  + $2->getName() + "(" + $4->getName() + ")" + $7->getName(), "func_def");
			logout << "Line " << line_count << ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n\n";
			logout << $1-> getName() << " " << $2-> getName() << "(" << $4->getName() << ")" << $7->getName() <<"\n\n";
		} 
		
		| type_specifier ID LPAREN RPAREN
		{
			string funcNameFound = $2-> getName();
			string returnTypeFound = $1-> getName();
			
			currentFunctionName = funcNameFound;
			assembly << funcNameFound << " PROC\n";			
			if (funcNameFound == "main"){
				assembly << "\tMOV DX, @DATA\n\tMOV DS, DX\n";
			}
			pushAction(assembly);
			assembly << "\tPUSH BP\n\tMOV BP, SP\n";

			// for(int i=0; i< parametersFound.size(); i++){
			// 	stackIncease -= 2;
			// 	parametersFound[i].offset = stackIncease;
			// }	

			SymbolInfo *ifExists = table-> lookUpSymbol(new SymbolInfo(funcNameFound, ""));

			//Error
			if(ifExists != nullptr){
				if(ifExists-> getIsFunc()){
					if(ifExists-> getIfDefined()){
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
						logout << "Error at line " << line_count << ": Multiple declaration of " << $2->getName() << "\n\n";
					}
					else{
						bool validity = true;
						string declaredReturnType = ifExists-> getReturn_type();
						//cout << returnTypeFound << " " << declaredReturnType << endl;
						if(returnTypeFound != declaredReturnType){
							error ++;
							errorout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << $2->getName() << "\n\n";
							logout << "Error at line " << line_count << ": Return type mismatch with function declaration in function " << $2->getName() << "\n\n";
							validity = false;
						}
						//table-> EnterScope();

					}
				}else{
					//table-> EnterScope();
					error ++;
					errorout << "Error at line " << line_count << ": ID is not a function : " << $2->getName()  << "()\n\n";
					logout << "Error at line " << line_count << ": ID is not a function : " << $2->getName()  << "()\n\n";

				}
			}else{
				// pushAction(assembly);
				// assembly << funcNameFound << " PROC\n";
				SymbolInfo *tempFunc = new SymbolInfo(funcNameFound, "ID");
				tempFunc-> setIfDefined(true);
				tempFunc-> setIsFunc(true);
				tempFunc-> setReturn_type(returnTypeFound);
				table-> insertSymbol(tempFunc);

				//table-> EnterScope();

			}
			table-> EnterScope();
		}
		compound_statement
		{
			assembly << $2->getName() << "_exit:\n";
			assembly << "\n\tADD SP, " << stackDecrease << "\n";
			stackDecrease = 0;
			stackIncease = -2;
			popAction(assembly);
			if ($2->getName() == "main"){
				assembly << "\n\tMOV AH, 4CH\n\tINT 21H\n";
			}
			assembly << "\n\tRET " << currentFuncParamCount*2 << "\n";
			assembly << $2->getName()  << " ENDP\n";
			currentFunctionName  = "";
			currentFuncParamCount = 0;
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
				logout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
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

			//cout << "in param list " << $1->getName() + " " + $2-> getName() << " and type " << $1->getType() + " " + $2-> getType()<< endl;
			//Error
			if($1-> getName() == "void"){
				error ++;
				errorout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
				logout << "Error at line " << line_count << ": Variable type cannot be void\n\n";
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
		| type_specifier error
		{
			//logout << "paisi\n\n";
			logout << $1-> getName() << "\n\n";
			$$ = $1;
			$$-> parameterListAdd("", $1-> getName());
			yyclearin;
			yyerrok;
		}
 		;

 		
compound_statement : LCURL statements RCURL
			{
				$$ = new SymbolInfo("{\n" + $2->getName() +  "\n}\n", "compound");
				logout << "Line " << line_count << ": compound_statement : LCURL statements RCURL\n\n";
				logout << "{\n" << " " << $2->getName() << "\n}\n\n";
				table-> printAllShorts(logout);
				table-> ExitScope();
				variableList.clear();
			}
 		    | LCURL RCURL
			{
				$$ = new SymbolInfo("{}\n", "compound");
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
			int tempDiff;
			string tempStackDiff;
			logout << "Line " << line_count << ": var_declaration : type_specifier declaration_list SEMICOLON\n\n";
			logout << Type_found << " " << Var_found << ";\n\n";
			$$ = new SymbolInfo(Type_found + " " + Var_found + ";\n", "nonterm");
			variableList = $2->varList;

			$$->setVariable_type(Type_found);
			for(int i=0; i< $2->varList.size(); i++){

				//offset added
				

				$2->varList[i].type = Type_found;
				//if($2->varList[i].ifArray == 0){
					
					//table->updateSymbol($2->varList[i].name, stackDecrease);
					//assembly << "\tSUB SP, " << $1->offset << "\n";	
				//}else{
					// tempDiff = $2->varList[i].ifArray;
					// tempDiff *= $1->offset;
					// tempStackDiff = to_string(tempDiff);
					// assembly << "\tSUB SP, " << tempStackDiff << "\n";
					// stackDecrease += tempDiff;
					//table->updateSymbol($2->varList[i].name, stackDecrease);
				//}
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
				for(int i=0; i< $2->varList.size(); i++){
					temp = table->lookUpSymbol_currentScope(new SymbolInfo($2->varList[i].name, ""));

					//Error
					if(temp != nullptr){
						error ++;
						errorout << "Error at line " << line_count << ": Multiple declaration of " << $2->varList[i].name << "\n\n";
						logout << "Error at line " << line_count << ": Multiple declaration of " << $2->varList[i].name << "\n\n";
					}

					//not_error
					else{
						temp = new SymbolInfo($2->varList[i].name, "ID");
						temp->setVariable_type(Type_found);
						temp->setReturn_type(Type_found);
						string currentID = table->currentScopeID();

						if(currentID != "1"){
							if($2->varList[i].ifArray != 0){					
								temp->setId("array");
								tempDiff = $2->varList[i].ifArray;
								tempDiff *= $1->offset;
								tempStackDiff = to_string(tempDiff);
								stackDecrease += tempDiff;
								assembly << "\tSUB SP, " << tempStackDiff << "\n";
								temp->offset = stackDecrease;
							
							}else{
								temp->setId("variable");
								stackDecrease += $1->offset;
								assembly << "\tSUB SP, " << $1->offset << "\n";	
								temp->offset = stackDecrease;
							}
						}

						if(currentID == "1"){
							//cout << "in var decaration global found " << $2->varList[i].name << "\n";
							globalList.push_back({$2->varList[i].name, $2->varList[i].ifArray});
							if($2->varList[i].ifArray != 0){					
								temp->setId("array");
							}else{
								temp->setId("variable");
							}
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
		| error SEMICOLON
		{
			yyclearin;
			yyerrok;
		}
 		;

 		 
type_specifier	: INT
		{
			logout << "Line " << line_count << ": type_specifier : INT\n\nint\n\n";
			$$ = new SymbolInfo("int" , "int");
			$$->offset = 2;
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
		| declaration_list error
		{
			yyclearin;
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
			$$ = new SymbolInfo($1->getName() + " " + $2->getName()+"\n", "statements");
			logout << "Line " << line_count << ": statements : statements statement\n\n";
			logout << $1-> getName() << " " << $2->getName() << "\n\n";
		}
	   	;

if_condition : IF LPAREN expression 
		{
			ifCount++;
			ifStack.push(ifCount);
			assembly<<"JCXZ if_false"<<ifCount<<"\n";
		}
		RPAREN statement
		{
			$$ = new SymbolInfo("if(" + $3->getName() + ")" + $6->getName() , "statement");
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
	  	| FOR LPAREN expression_statement 
		{			
			forLoopCount++;
			loopStack.push(forLoopCount);
			assembly << "\n\t;FOR LOOP start\n\tfor_loop" << forLoopCount << ":\n\n";			
		}
		expression_statement
		{
			assembly << "\tJCXZ for_end" << forLoopCount << "\n";
			assembly << "\tJMP stmt_start" << forLoopCount << "\n";
			assembly << "\tinc_start"<< forLoopCount <<":\n";
		}
		expression RPAREN
		{
			assembly << "\tJMP stmt2_start" << forLoopCount << "\n";
			assembly << "\tstmt_start" << forLoopCount << ":\n";
		}
		statement
		{
			int poppedInt = loopStack.top();
			loopStack.pop();
			
			assembly << "\tJMP inc_start"<< poppedInt << "\n";
			assembly << "\tstmt2_start"<< poppedInt <<":\n";
			assembly << "\tJMP for_loop" << poppedInt << "\n";
			assembly << "\tfor_end" << poppedInt << ":\n";
			$$ = new SymbolInfo("for(" + $3->getName() + $5->getName() + $7->getName() + ")" + $10->getName() , "statement");
			logout << "Line " << line_count << ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n\n";
			logout << "for(" << $3-> getName() << " " <<  $5->getName() << " " << $7->getName() << ")" << $10->getName() << "\n\n";
		}
	  	| if_condition %prec LOWER_THAN_ELSE
		{
			int poppedInt = ifStack.top();
			ifStack.pop();
			assembly << "\tJMP if_end" << poppedInt<< "\nif_false" << poppedInt << ":\n";
			assembly << "if_end" << poppedInt << ":\n";
			//ifCount ++;
			//elseIfFalseCount++;
			//$$ = new SymbolInfo("if(" + $3->getName() + ")" + $6->getName() , "statement");
			$$ = $1;
			logout << "Line " << line_count << ": statement : IF LPAREN expression RPAREN statement\n\n";
			//logout << "if(" << $3-> getName() <<  ")" << $6->getName() << "\n\n";
			logout << $1->getName() << "\n\n";
		}
	  	| if_condition ELSE 
		{
			int poppedInt = ifStack.top();
			assembly << "\tJMP if_end" << poppedInt << "\nif_false" << poppedInt << ":\n";
		}
		statement
		{
			//assembly << "JCXZ if_false" << elseIfFalseCount << "\n" << $3->code;
			//assembly << "if_false" << elseIfFalseCount <<":\n";
			int poppedInt = ifStack.top();
			ifStack.pop();
			assembly << "if_end" << poppedInt << ":\n";
			//ifCount ++;
			//elseIfFalseCount++;
			//$$ = new SymbolInfo("if(" + $3->getName() + ")\n" + $6->getName() + "else\n" + $9-> getName() , "statement");
			$$ = new SymbolInfo($1->getName() + "else\n" + $4-> getName() , "statement");
			logout << "Line " << line_count << ": statement : IF LPAREN expression RPAREN statement ELSE statement\n\n";
			//logout << "if(" << $3-> getName() <<  ")\n" << $6->getName() << "else\n" << $9->getName() <<"\n\n";
			logout << $1->getName() << "else\n" << $4->getName() <<"\n\n";
			//elseIfFalseCount ++;
		}
	  	| WHILE 
		{
			whileCount++;
			whileStack.push(whileCount);
			assembly << "\n\t;WHILE LOOP start\n\twhile_loop" << whileCount << ":\n\n";
		}
		LPAREN expression RPAREN
		{
			assembly << "\tJCXZ while_end" << whileCount << "\n";
		}
		statement
		{
			int poppedInt = whileStack.top();
			whileStack.pop();
			assembly << "\tJMP while_loop" << poppedInt << "\n";
			assembly << "\twhile_end" << poppedInt << ":\n";
			$$ = new SymbolInfo("while(" + $4->getName() + ")" + $7->getName() , "statement");
			logout << "Line " << line_count << ": statement : WHILE LPAREN expression RPAREN statement\n\n";
			logout << "while(" << $4-> getName() <<  ")" << $7->getName() <<"\n\n";
		}
	  	| PRINTLN LPAREN ID RPAREN SEMICOLON
		{
			string nameFound = $3-> getName();
			SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, ""));
			string currentScopeID = table->lookUpScopeID(new SymbolInfo(nameFound, ""));
			if(currentScopeID == "1"){
				assembly << "MOV AX, " << nameFound << "\n";
				assembly << "CALL print\n";

			}else{
				assembly << "MOV AX, -" << ifExists->offset << "[BP]\n";
				assembly << "CALL print\n";
			}

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

			$$ = new SymbolInfo("printf(" + $3->getName() + ");\n", "statement");
			logout << "Line " << line_count << ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n\n";
			logout << "printf(" << $3-> getName() <<  ");\n\n";
		}
	  	| RETURN expression SEMICOLON
		{
			string returnTypeFound = $2->getReturn_type();
			assembly << "\tJMP " << currentFunctionName << "_exit\n";
			if(returnTypeFound == "void"){
				error ++ ;
				errorout << "Error at line " << line_count << ": void doesnt have return types\n\n";
				logout << "Error at line " << line_count << ": void doesnt have return types\n\n";
			}
			$$ = new SymbolInfo("return " + $2->getName() + ";\n", "statement");
			
			logout << "Line " << line_count << ": statement : RETURN expression SEMICOLON\n\n";
			logout << "return " << $2-> getName() <<  ";\n\n";
		}
	  	;
	  
expression_statement 	: SEMICOLON		
			{
				$$ = new SymbolInfo(";", "statement");
			}	
			| expression SEMICOLON 
			{
				$$ = new SymbolInfo($1->getName() + ";", "expression_statement");
				logout << "Line " << line_count << ": expression_statement : expression SEMICOLON \n\n";
				logout << $1-> getName() <<  ";\n\n";
			}
			| expression error
			{
				yyclearin;
				//yyerrok;
			}
			;
	  
variable : ID 	
	{
		string nameFound = $1->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, ""));

		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			logout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			$$ = new SymbolInfo(nameFound , "INVALID");
		}else{
			//cout << nameFound << " exists and has return type " << ifExists->getReturn_type() << endl;
			if(ifExists->getId() == "array"){
				error ++ ;
			
				errorout << "Error at line " << line_count << ": Type mismatch, "<< nameFound  <<" is an array\n\n";
				logout << "Error at line " << line_count << ": Type mismatch, "<< nameFound  <<" is an array\n\n";
				$$ = new SymbolInfo(nameFound, "INVALID");

			}else{
				$$ = new SymbolInfo(nameFound, ifExists->getReturn_type());
				$$->offset = ifExists->offset;
			}
		}
		logout << "Line " << line_count << ": variable : ID\n\n";
		logout << $1-> getName() <<  "\n\n";

	}	
	| ID LTHIRD expression RTHIRD 
	{
		assembly << "\tPUSH CX\n";
		string nameFound = $1->getName();
		string typeFound;
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo(nameFound, "" ));
		
		string indexType = $3->getType();
		//cout << "inside var rule: " << ifExists->getName() << " " << ifExists->getType() << " " << ifExists->getReturn_type() << " " << ifExists->getId() << endl;
		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			logout << "Error at line " << line_count << ": Undeclared variable " << nameFound << "\n\n";
			$$ = new SymbolInfo(nameFound , "INVALID");
		}else{
			typeFound = ifExists->getReturn_type();
			if(ifExists->getId() == "array"){
				string finalType = typeFound;
				if(indexType != "int"){
					error ++ ;
					errorout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
					logout << "Error at line " << line_count << ": Expression inside third brackets not an integer\n\n";
					//cout << "index type for " << $3->getName() << " is " << indexType << "\n";
					finalType = "INVALID";
				}
				else if(stoi($3->getName()) < 0){
					error ++ ;
					errorout << "Error at line " << line_count << ": Expression inside third brackets is negative :" << $3-> getName() << "\n\n";
					logout << "Error at line " << line_count << ": Expression inside third brackets is negative :" << $3-> getName() << "\n\n";
					finalType = "INVALID";
				}
				SymbolInfo *temp = new SymbolInfo(nameFound + "[" + $3->getName() + "]", finalType);
				$$ = temp;
				$$->setId("array");
				$$->cleanVarName = nameFound;
				$$->cleanVarIndex = $3->getName();
				$$->offset = ifExists->offset;
				//cout << $1->offset << endl;

			}else{
				error ++ ;
				errorout << "Error at line " << line_count << ": "<< nameFound  <<" not an array\n\n";
				logout << "Error at line " << line_count << ": "<< nameFound  <<" not an array\n\n";
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
			int found;
			int expressionOffset;
			string returnType1 = $1-> getReturn_type();
			string variableScopeID;
			if($1->getId() == "array")
				variableScopeID = table->lookUpScopeID(new SymbolInfo($1->cleanVarName,""));
			else
				variableScopeID = table->lookUpScopeID(new SymbolInfo(operand1,""));
			
			
			if(variableScopeID == "1"){
				//cout << operand1 << " global found\n";
				if($1->getId() == "array"){
					assembly << "\tPOP AX\n\tXCHG AX, CX\n\t; Cx -> index, ax -> value\n";
					putInGlobalArray(assembly,$1->cleanVarName);
				}
				else{
					assembly << "\tMOV " << operand1 << ", CX\n";
				}
			}

			else{
				//cout << operand1 << " found\n";
				if($1->getId() == "array"){
					assembly << "\tPOP AX\n\tXCHG AX, CX\n\t; Cx -> index, ax -> value\n";
					putInArray(assembly,$1->offset);
				}else{
					assembly << "\tMOV -" << $1->offset << "[BP], CX\n";
				}	
			}

			if(type1 == type2 && type1 != "INVALID" && type2 != "INVALID"){

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
					//cout << "mismatched for var " << operand1 << " type: " << type1 << " ret_type: " << $1->getReturn_type() << " and logic expr: " << operand1 << " type: " << type2 << endl; 
					errorout << "Error at line " << line_count << ": Type mismatch for variable "<< $1->getName()  <<"\n\n";
					logout << "Error at line " << line_count << ": Type mismatch for variable "<< $1->getName()  <<"\n\n";
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
			string operatorFound = $2-> getName();
			string type2 = $3->getType();
			string logicOp = $2-> getName();
			string finalType = "int";
			string temp;

			int found1 = getIndex(variableList, $1->getName());
			int found2 = getIndex(variableList, $3->getName());
			temp = logicOpAssembly(assembly, operatorFound, $1->offset, $3->offset, logicOpCount);
			logicOpCount++;
			

			if(type1 == type2){}
			else{
				if(type1 != "int" || type2!= "int"){
					//cout << "rel express types are " << type1 << " " << type2 << endl;
					error ++ ;
					errorout << "Error at line " << line_count << ": not integer type found : " << "\n\n";
					logout << "Error at line " << line_count << ": not integer type found : " << "\n\n";
					//todo
					//finalType = "INVALID";
				}
			}
			$$ = new SymbolInfo($1->getName() + $2-> getName() + $3->getName() , finalType);
			$$->code = temp;
			assembly << temp;
			logout << "Line " << line_count << ": logic_expression : rel_expression LOGICOP rel_expression \n\n";
			logout << $1->getName() << $2->getName() << $3->getName() <<"\n\n";
		}
		;
			
rel_expression	: simple_expression 
		{
			$$ = $1;
			logout << "Line " << line_count << ": rel_expression : simple_expression \n\n";
			logout << $1->getName() <<"\n\n";
			//cout << $$->getName() << " " << $1->getType() << endl; 
		}
		| simple_expression RELOP {assembly << "\tPUSH CX\n";} simple_expression	
		{
			string operatorFound = $2->getName();
			//cout << "found "<< $2->getName() << endl;
			relopAssembly(assembly, operatorFound, relopCount);
			relopCount++;
			$$ = new SymbolInfo($1->getName() + $2-> getName() + $4->getName() , "int");
			logout << "Line " << line_count << ": rel_expression : simple_expression RELOP simple_expression\n\n";
			logout << $1->getName() << $2->getName() << $4->getName() <<"\n\n";
		}
		;
				
simple_expression : term 
		{
			$$ = $1;
			logout << "Line " << line_count << ": simple_expression : term \n\n";
			logout << $1->getName() <<"\n\n";
			//cout << "simple expression "<< $1->getName() << " offset " << $1->offset << endl; 
		}
		| simple_expression ADDOP {assembly << "\tPUSH CX\n";} term
		{
			string type1 = $1->getType();
			string type2 = $4->getType();
			string operatorFound = $2->getName();

			if(operatorFound == "+")
				addAssembly(assembly);
			else if(operatorFound == "-")
				subAssembly(assembly);

			string code = "";
			code += ($1->code + $4->code);


			if(type1 == "float" || type2 == "float")
				$$ = new SymbolInfo($1->getName() + $2->getName() + $4->getName(), "float");
			else
				$$ = new SymbolInfo($1->getName() + $2->getName() + $4->getName(), "int");
			logout << "Line " << line_count << ": simple_expression : simple_expression ADDOP term \n\n";
			logout << $1->getName() << $2->getName() << $4->getName() <<"\n\n";
		} 
		;
					
term :	unary_expression
	{
		$$ = $1;
		logout << "Line " << line_count << ": term : unary_expression\n\n";
		//cout << $1->getName() << " " << $1->getType() << endl; 
		logout << $1->getName() <<"\n\n";
	}
    |  term MULOP {assembly << "\tPUSH CX\n";} unary_expression
	{
		//asm after oprators
		//assembly << "\tPUSH CX\n";
		string operand1 = $1-> getName();
		string operand2 = $4-> getName();
		string type1 = $1-> getType();
		string type2 = $4-> getType();
		string operatorFound = $2->getName();
		string finalType = "int";
			// POP AX
			// IMUL CX
			// MOV CX , AX
		if(operatorFound == "/" || operatorFound == "*"){

			if(operatorFound == "*")
				mulAssembly(assembly);
			else if(operatorFound == "/")
				divAssembly(assembly);


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
			modAssembly(assembly);
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
		$$ = new SymbolInfo($1->getName() + $2->getName() + $4->getName() , finalType);
		logout << "Line " << line_count << ": term : term MULOP unary_expression\n\n";
		logout << $1->getName() << $2->getName() << $4->getName() <<"\n\n";
	}
    ;

unary_expression : ADDOP unary_expression  
		{
			//assembly << "\tMOV CX, -" << $2->offset <<"[BP]\n";
			if($1->getName() == "+"){

			}else if($1->getName() == "-"){
				assembly << "\tNEG CX\n";
			}
			$$ = new SymbolInfo($1->getName()  + $2->getName(), $2->getType());
			logout << "Line " << line_count << ": unary_expression : ADDOP unary_expression \n\n";
			logout << $1-> getName()  << $2->getName() <<"\n\n";
		}
		| NOT unary_expression 
		{
			unaryNOT(assembly, NOTCount);
			NOTCount++;
			$$ = new SymbolInfo("!" + $2->getName(), $2->getType());
			logout << "Line " << line_count << ": unary_expression : NOT unary_expression \n\n";
			logout << "!"  << $2->getName() <<"\n\n";
		}
		| factor
		{
			$$ = $1;
			
			SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo($1->getName(),""));
			//cout << "factor: " << $1->getName() << " type " << ifExists->getType() << endl;
			if(ifExists != nullptr &&  ifExists->getType() == "ID"){
				assembly << "\tMOV CX, -" << $1->offset << "[BP]\n";
			}
			logout << "Line " << line_count << ": unary_expression : factor\n\n";
			logout << $1->getName() <<"\n\n";
		} 
		;
	
factor	: variable 
	{	
		//improvised asm
		
		int found;
		int expressionOffset;
		string currentScopeID = table->lookUpScopeID(new SymbolInfo($1->cleanVarName,""));
		if(currentScopeID != "1"){
			if($1->getId() == "array"){
				//cout << "array found " << $1->cleanVarName << " " << currentScopeID  <<"\n";
				assembly << "\tPOP CX\n";
				//assembly << "\tPOP AX\n\tXCHG AX, CX\n\t; Cx -> index, ax -> value\n";
				found = getIndex(variableList, $1->cleanVarName);
				fetchFromArray(assembly,offsetCheck);
			}
		}else{
			if($1->getId() == "array"){
				//cout << "1: array found " << $1->cleanVarName << "\n";
				assembly << "\tPOP CX\n";
				fetchFromGlobalArray(assembly,$1->cleanVarName);
			}
		}
		$$ = $1;
		logout << "Line " << line_count << ": factor : variable\n\n";
		logout << $1-> getName() << "\n\n";
	}
	| ID LPAREN argument_list RPAREN
	{
		string nameFound = $1->getName();
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo($1->getName(),""));
		string returnTypeDeclared = "";

		// for(int i=0; i< $3->argumentList.size(); i++){
		// 	cout << $3->argumentList[i].name << " type " << $3->argumentList[i].type << " size " << $3->argumentList[i].size << endl;
		// }

		SymbolInfo *ifArguExists; 
		for(int i=$3->argumentList.size()-1; i>= 0; i--){

			ifArguExists = table->lookUpSymbol(new SymbolInfo($3->argumentList[i].name, ""));
			if (ifArguExists == nullptr) {
				//cout << "oh no, argu dont exist " << $3->argumentList[i].name << " and type " <<  $3->argumentList[i].type <<  "\n";
				if($3->argumentList[i].type == "int")
					assembly << "\tMOV CX, " << $3->argumentList[i].name << "\n";
				
			}
			else{
				//cout << "ifexists " << ifArguExists->getName() << " offset " << ifArguExists->offset <<endl;
				//cout << $3->argumentList[i].name << " type " << $3->argumentList[i].type << " size " << $3->argumentList[i].size << endl;
				assembly << "\tMOV CX, -" << ifArguExists->offset << "[BP]\n";
			}

			assembly << "\tPUSH CX\n";

		}
		assembly << "\t;calling defined function\n";
		assembly << "\tCALL " << nameFound << "\n";

		if(ifExists == nullptr){
			error ++ ;
			errorout << "Error at line " << line_count << ": Undeclared function : " << nameFound << "\n\n";
			logout << "Error at line " << line_count << ": Undeclared function : " << nameFound << "\n\n";
		}else{
			returnTypeDeclared = ifExists->getReturn_type();
			if(ifExists->getIsFunc()){
				//todo
			
				/*if(returnTypeDeclared == "void"){
					error ++ ;
					errorout << "Error at line " << line_count << ": Void function used in expression\n\n";
					logout << "Error at line " << line_count << ": Void function used in expression\n\n";
				}else */
				if(ifExists->parameterList.size() != $3->argumentList.size()){
					error ++ ;
					errorout << "Error at line " << line_count << ": Total number of arguments mismatch in function " << nameFound << "\n\n";
					logout << "Error at line " << line_count << ": Total number of arguments mismatch in function " << nameFound << "\n\n";
					//cout << "argument size " << $3->argumentList.size() << " parameter size " << ifExists->parameterList.size() << endl;
				}else{
					for(int i=0; i < $3->argumentList.size(); i++){
						if($3->argumentList[i].type != ifExists->parameterList[i].type && $3->argumentList[i].type != "INVALID"){
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

		$$ = new SymbolInfo($1-> getName() + "(" + $3->getName() + ")", returnTypeDeclared);
		logout << "Line " << line_count << ": factor : ID LPAREN argument_list RPAREN\n\n";
		logout << $1-> getName() << "(" << $3-> getName() << ")\n\n";
	}
	| LPAREN expression RPAREN
	{
		$$ = new SymbolInfo("(" + $2->getName() + ")", $2->getType());
		logout << "Line " << line_count << ": factor : LPAREN expression RPAREN\n\n";
		logout << "(" << $2-> getName() << ")" << "\n\n";
	}
	| CONST_INT 
	{
		//asm after const int
		$$->code = "\n\tMOV CX, " + $1->getName() + "\n";
		assembly << $$->code;
		$$ = $1;
		$$->isConstantInt = true;
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
		int found;
		string temp = "";
		int offsetFound;
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo($1->getName(), ""));
		if(ifExists != nullptr)
			offsetFound = ifExists->offset;

		if($1->getId() != "array"){
			found = getIndex(variableList, $1->getName());
			found = 2*(found + 1);
			temp += "\t\tMOV CX, -" + to_string(offsetFound) + "[BP]\n";
			temp += "\t\tMOV AX, CX\n";
			temp += "\t\tADD AX, 1\n";		
			temp += "\t\tMOV -" + to_string(offsetFound) + "[BP], AX\n"; 
		}else{
			found = getIndex(variableList, $1->cleanVarName);
			temp += "\tPOP CX\n";
			temp +=  "\t\t;put element to stack array\n";
    		temp += "\t\tPUSH BP\n";
    		temp += "\t\tSAL CX, 1\n";
    		temp += "\t\tADD CX, -" + to_string(offsetCheck) + "\n";
			temp += "\t\tADD BP, CX\n";
			temp += "\t\tMOV CX, PTR WORD [BP]\n";
			temp += "\t\tMOV AX, CX\n";
			temp += "\t\tADD AX, 1\n";
			temp += "\t\tMOV PTR WORD [BP], AX\n";
			temp += "\t\tPOP BP\n";
		}

		$$ = new SymbolInfo($1->getName() + "++" , $1->getType());
		$$-> code = temp;
		assembly << temp;
		logout << "Line " << line_count << ": factor : variable INCOP \n\n";
		logout << $1-> getName() << "++\n\n";
	}

	| variable DECOP
	{
		int found;
		string temp = "";
		SymbolInfo *ifExists = table->lookUpSymbol(new SymbolInfo($1->getName(), ""));
		int offsetFound = ifExists->offset;
		if($1->getId() != "array"){
			found = getIndex(variableList, $1->getName());
			found = 2*(found + 1);
			temp += "\t\tMOV CX, -" + to_string(offsetFound) + "[BP]\n";
			temp += "\t\tMOV AX, CX\n";
			temp += "\t\tSUB AX, 1\n";		
			temp += "\t\tMOV -" + to_string(offsetFound) + "[BP], AX\n"; 
		}else{
			found = getIndex(variableList, $1->cleanVarName);
			temp += "\tPOP CX\n";
			temp +=  "\t\t;put element to stack array\n";
    		temp += "\t\tPUSH BP\n";
    		temp += "\t\tSAL CX, 1\n";
    		temp += "\t\tADD CX, -" + to_string(offsetCheck) + "\n";
			temp += "\t\tADD BP, CX\n";
			temp += "\t\tMOV CX, PTR WORD [BP]\n";
			temp += "\t\tMOV AX, CX\n";
			temp += "\t\tSUB AX, 1\n";
			temp += "\t\tMOV PTR WORD [BP], AX\n";
			temp += "\t\tPOP BP\n";
		}
		$$ = new SymbolInfo($1->getName() + "--" , "factor");
		$$-> code = temp;
		assembly << temp;
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
					$$->argumentListAdd(varNameFound, $1->getType(), 0);
		  		}	
	      		;
 

%%
int main(int argc,char *argv[])
{
	logout.open("1805002_log.txt");
	errorout.open("1805002_error.txt");
	assembly.open("1805002_code.asm");
	assembly2.open("1805002_optimized_code.asm");


	if((fp=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	yyin=fp;
	yyparse();
	printFinalLog();
	assembly.close();
	optimize(assembly2);

	if(error > 0){
		assembly2.close();
		assembly.open("1805002_code.asm");
		assembly2.open("1805002_optimized_code.asm");
	}
	assembly.close();
	assembly2.close();
	fclose(fp);
	
	return 0;
}

