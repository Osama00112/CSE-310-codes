#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class SymbolInfo{
private:
    string Name;
    string Type;
    SymbolInfo *next;

public:
    SymbolInfo(){
        Name = "";
        Type = "";
        next = nullptr;
    }

    SymbolInfo(string name, string type){
        Name = name;
        Type = type;
        next = nullptr;
    }

    void printTable(){
        cout << "< "  << getName() << " : " << getType() << "> " ;
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

};