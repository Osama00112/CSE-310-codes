//
// Created by Osama Haque on 5/19/2022.
//

#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <ctime>

#include "SymbolInfo.h"

using namespace std;

#ifndef ASSIGNMENT_1_SCOPETABLE_H
#define ASSIGNMENT_1_SCOPETABLE_H
#endif //ASSIGNMENT_1_SCOPETABLE_H


class ScopeTable{
    int total_buckets;

    string id;
    ScopeTable *parentScopeTable;
    int childScopeCount;

    vector<SymbolInfo*> *table;


public:
    ScopeTable(){

    }
    ScopeTable(int bucket, int globalScopeCount){
        total_buckets = bucket;
        parentScopeTable = nullptr;
        childScopeCount = 0;
        //parentScopeTable->setChildScopeCount(parentScopeTable->getChildScopeCount()+1);
        id = to_string(globalScopeCount);

        table = new vector<SymbolInfo*>[total_buckets];

        for (int i =0; i< total_buckets ; i++){
            //vector<SymbolInfo*> v;
            table[i] = vector<SymbolInfo*>();
        }

        //cout << "New ScopeTable with id " << id << " created" << endl;
    }

    ScopeTable(int bucket, ScopeTable* parent){
        total_buckets = bucket;
        parentScopeTable = parent;
        childScopeCount = 0;
        parentScopeTable->setChildScopeCount(parentScopeTable->getChildScopeCount()+1);
        if(parent != nullptr)
            id = parentScopeTable->getId() + "." + to_string(parentScopeTable->getChildScopeCount());
        else{
            cout << "error, parent null" << endl;
        }

        table = new vector<SymbolInfo*>[total_buckets];
        for (int i =0; i< total_buckets ; i++){
            //vector<SymbolInfo*> v;
            table[i] = vector<SymbolInfo*>();
        }

        cout << "New ScopeTable with id " << id << " created"<< "\n"  << endl;
    }


    bool insertEntry(SymbolInfo* entry){
        string entry_Name = entry->getName();
        string entry_Type = entry->getType();

        int hashIndex = sdbm(entry_Name) % total_buckets;

        int existIndex = ifExists(entry);

        if(existIndex == -1){
            table[hashIndex].push_back(entry);
            cout << "Inserted in ScopeTable# "<< id << " at position " << hashIndex << ", " << table[hashIndex].size() - 1 << "\n" << endl;
            return true;
        }
        else{
            cout << "<" << entry_Name << "," << entry_Type << ">" << " already exists in current ScopeTable\n" << endl;
            return false;
        }

    }

    int ifExists(SymbolInfo* entry){
        string entry_Name = entry->getName();
        string entry_Type = entry->getType();
        int hashIndex = sdbm(entry_Name) % total_buckets;

        int count = 0;
        for (auto x : table[hashIndex]){
            string searched_Name = x->getName();
            string searched_Type = x->getType();

            if(searched_Name == entry_Name){
                return count;
            }
            count ++;
        }
        return -1;
    }

    SymbolInfo* lookUp(SymbolInfo* entry){
        string entry_Name = entry->getName();
        string entry_Type = entry->getType();
        SymbolInfo *temp = nullptr;

        int hashIndex = sdbm(entry_Name) % total_buckets;
        int count = 0;
        for (auto x : table[hashIndex]){
            string searched_Name = x->getName();
            string searched_Type = x->getType();
            //cout << "table content in hash is " << searched_Name << endl;

            if(searched_Name == entry_Name){
                temp = x;
                cout << "Found in ScopeTable# " << getId() << " at position " << hashIndex << ", " << count << "\n"  << endl;
                break;
            }
            count++ ;
        }

        //cout << "Not Found" << endl;
        return temp;
    }

    bool deleteEntry(SymbolInfo* entry){
        string entry_Name = entry->getName();

        SymbolInfo *temp;

        int hashIndex = sdbm(entry_Name) % total_buckets;
        int index = ifExists(entry);
        temp = lookUp(entry);

        if(index != -1){
            table[hashIndex].erase(table[hashIndex].begin() + index);
            cout << "Deleted Entry "<< temp->getName() << ", " << temp->getType()  <<" from current ScopeTable\n" << endl;
            return true;
        } else
            return false;

    }

    void printScopeTable(){
        cout << "ScopeTable # " << getId() << endl;
        for (int i = 0;i < total_buckets;i++) {
            cout << i<< " --> ";
            for (auto x : table[i]){
                x->printTable();
            }
            cout << endl;
        }
    }



    ~ScopeTable(){
        table->clear();
    }

    // hash function
    static unsigned long sdbm(string const & str){
        unsigned long hash = 0;
        int c;
        int i = 0;
        while (c = str[i++])
            hash = c + (hash << 6) + (hash << 16) - hash;
        return hash;
    }

    int getChildScopeCount() const {
        return childScopeCount;
    }
    void setChildScopeCount(int childScopeCount) {
        ScopeTable::childScopeCount = childScopeCount;
    }

    const string &getId() const {
        return id;
    }
    void setId(const string &id) {
        ScopeTable::id = id;
    }

    ScopeTable *getParentScopeTable() const {
        return parentScopeTable;
    }
    void setParentScopeTable(ScopeTable *parentScopeTable) {
        ScopeTable::parentScopeTable = parentScopeTable;
    }

};