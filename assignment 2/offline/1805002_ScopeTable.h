//
// Created by Osama Haque on 5/19/2022.
//

#include<bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <ctime>

#include "1805002_SymbolInfo.h"

using namespace std;

#ifndef ASSIGNMENT_1_SCOPETABLE_H
#define ASSIGNMENT_1_SCOPETABLE_H
#endif //ASSIGNMENT_1_SCOPETABLE_H


class ScopeTable{
    int total_buckets;
    string id;
    ScopeTable *parentScopeTable;
    int childScopeCount;

    vector<SymbolInfo*> table;


public:
    ScopeTable(){

    }
    ScopeTable(int bucket, int globalScopeCount){
        total_buckets = bucket;
        parentScopeTable = nullptr;
        childScopeCount = 0;
        id = to_string(globalScopeCount);
        table.assign(total_buckets, nullptr);
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
        table.assign(total_buckets, nullptr);
        cout << "New ScopeTable with id " << id << " created"<< "\n"  << endl;
    }

    void insert(SymbolInfo* entry){
        string entry_Name = entry->getName();
        string entry_Type = entry->getType();

        int hashIndex = sdbm(entry_Name) % total_buckets;
        int existIndex = ifExists(entry);
        SymbolInfo* temp = table[hashIndex];

        int count = 0;
        if(temp == nullptr){
            table[hashIndex] = entry;
            cout << "Inserted in ScopeTable# "<< id << " at position " << hashIndex << ", " << count << "\n" << endl;
            return;
        }
        while(temp->getNext() != nullptr){
            temp = temp->getNext();
            count ++;
        }
        temp->setNext(entry);
        cout << "Inserted in ScopeTable# "<< id << " at position " << hashIndex << ", " << count+1 << "\n" << endl;
    }


    bool insertEntry(SymbolInfo* entry){
        string entry_Name = entry->getName();
        string entry_Type = entry->getType();

        int hashIndex = sdbm(entry_Name) % total_buckets;
        int existIndex = ifExists(entry);

        SymbolInfo* temp = table[hashIndex];
        if(existIndex == -1){
            insert(entry);
            //cout << "Inserted in ScopeTable# "<< id << " at position " << hashIndex << ", " << existIndex << "\n" << endl;
            return true;
        }
        else{
            cout << "<" << entry_Name << "," << entry_Type << ">" << " already exists in current ScopeTable\n" << endl;
            delete entry;
            return false;
        }

    }

    int ifExists(SymbolInfo* entry){
        string entry_Name = entry->getName();
        string entry_Type = entry->getType();
        int hashIndex = sdbm(entry_Name) % total_buckets;

        SymbolInfo* temp = table[hashIndex];

        int count = 0;
        if(temp == nullptr){
            return -1;
        }

        while(temp->getNext()!= nullptr){
            if(temp->getName() == entry_Name){
                return count;
            }
            temp = temp->getNext();
            count++;
        }
        if(temp != nullptr){
            if(temp->getName() == entry_Name){
                return count;
            }
        }
        return -1;
    }

    SymbolInfo* lookUp(SymbolInfo* entry){
        string entry_Name = entry->getName();
        string entry_Type = entry->getType();

        int hashIndex = sdbm(entry_Name) % total_buckets;
        SymbolInfo *temp = table[hashIndex];
        int count = 0;

        if(temp == nullptr){
            return nullptr;
        }

        while(temp->getNext()!= nullptr){
            if(temp->getName() == entry_Name){
                cout << "Found in ScopeTable# " << getId() << " at position " << hashIndex << ", " << count << "\n"  << endl;
                return temp;
            }
            temp = temp->getNext();
            count++;
        }
        if(temp->getName() == entry_Name){
            cout << "Found in ScopeTable# " << getId() << " at position " << hashIndex << ", " << count << "\n"  << endl;
            return temp;
        }
        cout << "Not found\n\n";
        return nullptr;
    }

    void deleteUtil(int hash, int index){
        SymbolInfo* temp = table[hash];
        SymbolInfo* parent = temp;
        if(temp == nullptr){
            cout << "nothing to delete\n";
            return;
        }
        int position = 0;

        while(temp->getNext() != nullptr){
            if(position == index){
                if(position == 0){
                    table[hash] = temp->getNext();
                    delete temp;
                    return;
                }
                else{
                    parent->setNext(temp->getNext());
                    delete temp;
                    return;
                }
            }
            parent = temp;
            temp = temp->getNext();
            position++ ;
        }

        //now for the last element
        if(position == index){
            if(position == 0){
                table[hash] = temp->getNext();
                delete temp;
                return;
            }
            else{
                parent->setNext(temp->getNext());
                delete temp;
                return;
            }
        }
        return;
    }

    void deleteEntry(SymbolInfo* entry){
        string entry_Name = entry->getName();
        SymbolInfo *temp;

        int hashIndex = sdbm(entry_Name) % total_buckets;
        int index = ifExists(entry);
        temp = lookUp(entry);

        if(index != -1){
            deleteUtil(hashIndex, index);
            cout << "Deleted Entry "<< hashIndex << ", " << index  <<" from current ScopeTable\n" << endl;
        }
        else{
            cout << entry_Name <<" Not found\n" << endl;
        }
    }

    void printScopeTable(){
        SymbolInfo* temp;
        cout << "ScopeTable # " << getId() << endl;
        for (int i = 0;i < total_buckets;i++) {
            cout << i << " --> ";
            temp = table[i];
            while(temp != nullptr){
                temp->printTable();
                temp = temp->getNext();
            }
            cout << endl;
        }
        cout << "\n" ;
    }

    void printShortScopeTable(ofstream &f){
        SymbolInfo* temp;
        const char *char1;
        char1 = &getId()[0];
        //cout << "ScopeTable # " << getId() << endl;
        //fprintf(f, "ScopeTable # %s\n", char1);
        f  << "ScopeTable # " << getId() << endl;
        for (int i = 0;i < total_buckets;i++) {
            
            temp = table[i];
            if(temp == nullptr){
                continue;
            }
            
            //cout << i << " --> ";
            
            //char1 = &(to_string(i))[0];
            //fprintf(f, "%s --> ", char1);
            f << i << " --> ";

            while(temp != nullptr){
                temp->printTable2(f);
                temp = temp->getNext();
            }
            //cout << endl;
            //fprintf(f, "\n");
            f << "\n";
        }
        //cout << "\n" ;
        //fprintf(f, "\n");
        f << "\n";
    }



    ~ScopeTable(){
        SymbolInfo* temp;
        SymbolInfo* temp2;
        for (int i = 0;i < total_buckets;i++) {
            temp = table[i];
            while(temp != nullptr){
                temp2 = temp->getNext();
                delete temp;
                temp = temp2;
            }
            delete temp;
        }
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