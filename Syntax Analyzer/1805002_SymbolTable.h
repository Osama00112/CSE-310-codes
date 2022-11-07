//
// Created by Osama Haque on 5/19/2022.
//
#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <ctime>

#include "1805002_ScopeTable.h"

#ifndef ASSIGNMENT_1_SYMBOLTABLE_H
#define ASSIGNMENT_1_SYMBOLTABLE_H

#endif //ASSIGNMENT_1_SYMBOLTABLE_H

using namespace std;

class SymbolTable{
    ScopeTable *current;
    int total_bucket;
    int global;
    stack<ScopeTable> ScopeList;

public:
    SymbolTable()= default;
    SymbolTable(int buckets, int global){
        total_bucket = buckets;
        this->global = global;
        ScopeTable *scope = new ScopeTable(total_bucket, global);
        current = scope;
        ScopeList.push(*current);
    }

    ~SymbolTable(){
        ScopeTable *temp = current;
        ScopeTable *parent = temp;
        while(temp!= nullptr){
            parent = temp->getParentScopeTable();
            delete temp;
            temp = parent;
        }
    }

    void EnterScope(){
        if(current == nullptr){
            cout << "no current found " << endl;
        }
        else{
            ScopeTable *newScope = new ScopeTable(total_bucket, current);
            ScopeList.push(*newScope);
            current = newScope;
        }
    }

    void ExitScope(){
        if(current->getId() == "1"){
            cout << "Main Scope. Terminates program if exits\n";
        }
        else{
            ScopeList.pop();
            ScopeTable *parent = current->getParentScopeTable();
            cout << "ScopeTable with id "<< current->getId() << " removed"<< "\n"  << endl;
            if(current->getId() == "1"){
                cout << "Main Scope. Terminates program if exits\n";
            }
            delete current;
            current = parent;
        }
    }

    bool insertSymbol(SymbolInfo* entry){
        if(current == nullptr){
            cout << "No Current scope found\n";
            return false;
        }
            
        else{
            return current->insertEntry(entry);
        }
    }

    void removeSymbol(SymbolInfo* entry){
        if(current == nullptr)
            cout << "NO current scope found\n";
        else{
            current->deleteEntry(entry);
        }
    }

    SymbolInfo* lookUpSymbol(SymbolInfo* entry){
        //printAllScopes();
        ScopeTable *temp = current;

        SymbolInfo *searched = nullptr;

        while(temp != nullptr){
            int found;
            found = temp->ifExists(entry);
            
            int hashIndex = temp->sdbm(entry->getName()) % total_bucket;

            if (found != -1){
                searched = temp->lookUp(entry);
                return searched;
            }
            temp = temp->getParentScopeTable();
        }
        cout << "Not Found \n" << endl;
        return searched;
    }

    void printCurrent(){
        if (current == nullptr){
            cout << "No Scope found"<< "\n"  << endl;
        }
        else{
            current -> printScopeTable();
        }
    }

    void printAllScopes(){
        cout << "\n" ;
        ScopeTable *temp = current;
        while(temp != nullptr){
            temp->printScopeTable();
            temp = temp->getParentScopeTable();
            cout << endl;
        }
    }
    void printAllShorts(ofstream &f){
        //cout << "\n" ;
        //fprintf(f, "\n");
        f << "\n";
        ScopeTable *temp = current;
        while(temp != nullptr){
            temp->printShortScopeTable(f);
            temp = temp->getParentScopeTable();
            //cout << endl;
            //fprintf(f, "\n");
            f << "\n";
        }
    }
    int getTotalBucket() const {
        return total_bucket;
    }


};