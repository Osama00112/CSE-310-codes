#include <bits/stdc++.h>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class myHashTable{
    public:
    int tableSize;
    int order;
    int chainCollision1;
    vector<pair<string,int>> *tableList1; 

    //vector<unsigned char *> *table;

    public:
    myHashTable(int size){
        tableSize = size;
        order = 0;
        chainCollision1 = 0;

        tableList1 = new vector<pair<string,int>>[size];
    }

    void insertValue(string str, int key){
        order ++;
        int hashIndex1 = hash1(str) % tableSize;

        //cout << str << " ->" <<  hashIndex <<endl;
        if(tableList1[hashIndex1].size() > 0){
            
            seperateChain1(hashIndex1,str,order);            
        } else
            tableList1[hashIndex1].push_back({str,order});
    }

    void seperateChain1(int hashIndex, string str, int order){
        chainCollision1 ++;
            tableList1[hashIndex].push_back({str,order});
    }
    
    void deleteValue(int key){

    }

    int searchChain1(string const & str){
        int index1 = hash2(str) %tableSize;
        int count = 1;
        for(auto it = begin (tableList1[index1]); it != end (tableList1[index1]); ++it){
            if(it->first == str)
                break;
            count ++;
        }

        return count;
        //auto k = tableList1[index1];
        
    }

    unsigned int auxhash(string const & str){
        unsigned int hash = 0;
	    int c;
        int i =0;
	    while (c = str[i++])
	        hash += c;

	    return hash;
    }
    unsigned long hash2(string const & str){
        unsigned long hash = 0;
        int c;
        int i = 0;

        while (c = str[i++])
            hash = c + (hash << 6) + (hash << 16) - hash;

        return hash;
    }
    unsigned long hash1(string const & str)
    {
        unsigned long hash = 5381;
        int c;
        int i = 0;

        while (c =  str[i++])
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }

    void printTable(){
       for (int i = 0; i < tableSize; i++) {
        cout << i;
        for (auto x : tableList1[i])
            cout << "(" <<  x.first << " , " << x.second << ")";
        cout << endl;
        }
    }
    int getChainCollisions1(){
        return chainCollision1;
    }

};