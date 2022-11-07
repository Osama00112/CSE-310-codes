#include <bits/stdc++.h>
#include "1805002_Extras.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class SymbolInfo{
private:
    string Name;
    string Type;
    string variable_type, return_type, id;
    SymbolInfo *next;
    bool isFunc;
    bool ifFuncDefined;
    bool paramValidity;

    

public:
    string code;
    int offset;
    int forLoopCount;
    int whileLoopCount;
    bool isConstantInt;
    string newInfo;
    
    vector<variable> varList;
    vector<parameter> parameterList;
    vector<argument> argumentList;

    //variable ID LTHIRD EXPRESSION RTHIRD specific attributes
    string cleanVarName;
    string cleanVarIndex;

    void varListAdd(string name, string type, int array){
        variable temp;
        temp.name = name;
        temp.type = type;
        temp.ifArray = array;
        varList.push_back(temp);
    }

    void parameterListAdd(string name, string type){
        parameter temp;
        temp.name = name;
        temp.type = type;
        temp.offset = 0;
        parameterList.push_back(temp);
    }

    void argumentListAdd(string name, string type, int size){
        argument temp;
        temp.name = name;
        temp.type = type;
        temp.size = size;
        argumentList.push_back(temp);
    }

    //getters and setters for new attributes

    string getVariable_type(){return variable_type;}
    void setVariable_type(string type){variable_type = type;}
    string getReturn_type(){return return_type;}
    void setReturn_type(string ret){return_type = ret;}
    string getId(){return id;}
    void setId(string newId){id = newId;}
    bool getIsFunc(){return isFunc;}
    void setIsFunc(bool decision){isFunc = decision;}
    bool getIfDefined(){return ifFuncDefined;}
    void setIfDefined(bool decision){ifFuncDefined = decision;}
    bool getparamValidity(){return paramValidity;}
    void setparamValidity(bool decision){paramValidity = decision;}


    SymbolInfo(){
        Name = "";
        Type = "";
        next = nullptr;
        code = "";
        offset = 0;
        isConstantInt = false;
    }

    SymbolInfo(string name, string type){
        Name = name;
        Type = type;
        next = nullptr;
        code = "";
        offset = 0;
        isConstantInt = false;
    }

    ~SymbolInfo(){
        next = nullptr;
        //cout << "symbol destroyed\n";
    }

    void printTable(){
        cout << "< "  << getName() << " : " << getType() << "> " ;
    }
    void printTable2(ofstream &f){
        char *char1, *char2;
        char1 = &getName()[0];
        char2 = &getType()[0];
        //cout << "< "  << getName() << " : " << getType() << " > " ;
        //fprintf(f, "< %s : %s> ", char1, char2);
        f << "< " << getName() << " : " << getType() << " > ";
        //fprintf(f, getName());
    }
    

    string getName(){
        return Name;
    }

    void setName(string name){
        Name = name;
    }

    string getType(){
        return Type;
    }
    void setType(string name){
        Type = name;
    }
    SymbolInfo *getNext() const {
        return next;
    }
    void setNext(SymbolInfo *next) {
        SymbolInfo::next = next;
    }
    int getOffset(){return offset;}
    void setOffset(int f){offset = f;};

};