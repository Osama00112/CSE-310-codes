#include <bits/stdc++.h>

using namespace std;

struct variable{
    string name;
    string type;
    int ifArray;
    int size;
};

struct parameter
{
    string name;
    string type;
    int offset;
};

struct argument
{
    string name;
    string type;
    int size;
    bool isConstantInt;
};

struct myfunction
{
    string funcName;
    string returnType;
    vector<parameter> funcParameters;

};

// vector<myfunction> funcListAdd(vector<myfunction> existingFuncList, string name, string type, vector<parameter> p){
//     myfunction temp;
//     temp.funcName = name;
//     temp.returnType = type;
//     for(parameter parm : p){
//         temp.funcParameters.push_back(parm);
//     }
//     existingFuncList.push_back(temp);
//     return existingFuncList;
// }

// vector<myfunction> funcListAdd(vector<myfunction> existingFuncList, string name, string type){
//     myfunction temp;
//     temp.funcName = name;
//     temp.returnType = type;
//     existingFuncList.push_back(temp);
//     return existingFuncList;
// }

// bool ifFuncExists(vector<myfunction> existingFuncList, string name){
//     for(myfunction temp : existingFuncList){
//         if(temp.funcName == name) return true;
//     }
//     return false;
// }