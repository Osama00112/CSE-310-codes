#include <bits/stdc++.h>
#include <string>
#include "SymbolTable.h"

using namespace std;

int main(){

    ifstream myfile;
    int global = 1;
    myfile.open("input.txt");

    if(myfile.fail())
        cout << "failed " << endl;
    else{
        int n,m;
        string s;
        int bucket;
        int count = 0;
        SymbolTable *newTable = nullptr;
        SymbolInfo *newInfo = nullptr;
        while(!myfile.eof()){
            if(count == 0){
                myfile >> bucket;
                //newTable = SymbolTable(bucket, global);
                newTable = new SymbolTable(bucket, global);
            }else{
                myfile >> s;

                if(s == "I"){
                    string s1, s2;
                    myfile >> s1 >> s2;
                    cout << s << " " << s1 << " " << s2 << "\n" << endl;
                    //SymbolInfo temp(s1,s2);
                    newInfo = new SymbolInfo(s1, s2);
                    newTable->insertSymbol(newInfo);
                }
                else if(s == "L"){
                    string s3;
                    myfile >> s3;
                    cout << s << " " << s3 << "\n" << endl;
                    SymbolInfo temp(s3, "");
                    newTable->lookUpSymbol(&temp);
                }
                else if(s == "S"){
                    cout << s << "\n" << endl;
                    newTable->EnterScope();

                }
                else if(s == "D"){
                    string s4;
                    myfile >> s4;
                    cout << s << " " << s4<< "\n"  << endl;
                    SymbolInfo temp(s4,"");
                    newTable->removeSymbol(&temp);
                }
                else if(s == "P"){
                    string s5;
                    myfile >> s5;
                    cout << s << " " << s5 << "\n" << endl;
                    if(s5 == "C"){
                        newTable->printCurrent();
                    }
                    else if(s5 == "A"){
                        newTable->printAllScopes();
                    }
                    else{
                        cout << R"(Invalid command. Only "A" or "C" allowed)" << endl;
                    }
                }
                else if(s == "E"){
                    cout << s<< "\n"  << endl;
                    newTable->ExitScope();
                }
                else{
                    cout << s << "\n" << endl;
                    cout << "invalid command\n" << endl;
                }

            //free(newInfo);
            }
            count ++;
        }

        delete newTable;
        //delete newInfo;
    }
    

    return 0;
}