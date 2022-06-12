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

};