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
            ScopeTable *newScope = new ScopeTable(total_bucket, global);
            ScopeList.push(*newScope);
            current = newScope;
        }
        else{
            ScopeTable *newScope = new ScopeTable(total_bucket, current);
            ScopeList.push(*newScope);
            current = newScope;
        }
    }

    void ExitScope(){
        ScopeList.pop();
        ScopeTable *parent = current->getParentScopeTable();
        cout << "ScopeTable with id "<< current->getId() << " removed"<< "\n"  << endl;
        delete current;
        current = parent;
    }

    bool insertSymbol(SymbolInfo* entry){
        if(current == nullptr)
            return false;
        else{
            return current->insertEntry(entry);
        }
    }

    bool removeSymbol(SymbolInfo* entry){
        if(current == nullptr)
            return false;
        else{
            return current->deleteEntry(entry);
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
        cout << "\n";
    }
    int getTotalBucket() const {
        return total_bucket;
    }


};