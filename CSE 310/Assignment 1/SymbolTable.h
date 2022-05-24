//
// Created by Osama Haque on 5/19/2022.
//
#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <ctime>

#include "ScopeTable.h"

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
        //printCurrent();
    }
    void EnterScope(){
        if(current == nullptr){
//            ScopeTable *newScope = new ScopeTable(total_bucket, global);
//            ScopeList.push(*newScope);
//            current = newScope;
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

    void insertSymbol(SymbolInfo* entry){
        if(current == nullptr)
            cout << "No Current scope found\n";
        else{
            current->insertEntry(entry);
        }
    }

    void removeSymbol(SymbolInfo* entry){
        if(current == nullptr)
            cout << "NO current scope found\n";
        else{
            current->deleteEntry(entry);
        }
    }
    void whatisCurrent(){
        cout << "right now current id is " << current->getId() << endl;
    }

    SymbolInfo* lookUpSymbol(SymbolInfo* entry){
        //printAllScopes();
        ScopeTable *temp = current;

        SymbolInfo *searched = nullptr;

        while(temp != nullptr){
            //cout << "now looking at id " << temp->getId() << endl;
            int found;
            found = temp->ifExists(entry);
            searched = temp->lookUp(entry);
            int hashIndex = temp->sdbm(entry->getName()) % total_bucket;

            if (searched != nullptr){
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
            //cout << "current id is " << current->getId() << endl;
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
    int getTotalBucket() const {
        return total_bucket;
    }


};