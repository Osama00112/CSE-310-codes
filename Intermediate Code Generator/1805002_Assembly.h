#include <bits/stdc++.h>
#include<iostream>

#include<cstring>

using namespace std;

bool findGlobal(vector<pair<string,int>> globals, string name){
    for(int i = 0; i< globals.size(); i++){
        if(globals[i].first == name){
            return true;
        }
    }
    return false;
}

void startAssemble(ofstream &f, vector<pair<string,int>> globals){
    string temp = ".MODEL SMALL\n.STACK 1000H\n\n";
    
    temp += "\n.CODE\n";
    f << temp;
}

void newLine(ofstream &assembly){
    assembly << "\n\t;FOR NEW LINE\n\tMOV DX, CR\n\tMOV AH, 2\n\tINT 21H\n\tMOV DX, LF\n\tMOV AH, 2\n\tINT 21H\n\n";
}

void pushAction(ofstream &assembly){
	//assembly << "\tPUSH AX\n\tPUSH BX\n\tPUSH CX\n\tPUSH DX\n";
}

void popAction(ofstream &assembly){
	assembly << "\n\tPOP BP\n";
    //assembly << "\tPOP DX\n\tPOP CX\n\tPOP BX\n\tPOP AX\n";
}
void mulAssembly(ofstream &assembly){
    assembly << "\tPOP AX\n\tIMUL CX\n\tMOV CX, AX\n\n";
}

void addAssembly(ofstream &assembly){
    assembly << "\tPOP AX\n\tADD AX, CX\n\tMOV CX, AX\n\n";
}

void subAssembly(ofstream &assembly){
    assembly << "\tPOP AX\n\tSUB AX, CX\n\tMOV CX, AX\n\n";
}

void divAssembly(ofstream &assembly){
    assembly << "\tPOP AX\n\tIMUL CX\n\tMOV CX, AX\n\n";
}

void modAssembly(ofstream &assembly){
    assembly << "\tPOP AX\n\tCWD\n\tIDIV CX\n\tMOV CX, DX\n\n";
}

void relopAssembly(ofstream &assembly, string op, int count){
    assembly << "\t;Relational Operator:\n";
    assembly << "\t\tPOP AX\n\t\tCMP AX, CX\n";
    if (op == "<"){
        assembly << "\t\tJL relop_is_ok" << count <<"\n";
       
    }else if (op == ">"){
        assembly << "\t\tJG relop_is_ok" << count << "\n";
    }
    else if (op == "<="){
        assembly << "\t\tJLE relop_is_ok" << count <<"\n";
    }
    else if (op == ">="){
        assembly << "\t\tJLE relop_is_ok" << count <<"\n";
    }else if (op == "!="){
        assembly << "\t\tJNE relop_is_ok" << count <<"\n";
    }else if (op == "=="){
        assembly << "\t\tJE relop_is_ok" << count <<"\n";
    }
    assembly << "\t\tMOV CX, 0\n\t\tJMP relop_end" << count << "\n";
    assembly << "\t\trelop_is_ok" << count << ":\n\t\t\tMOV CX, 1\n";
    assembly << "\t\trelop_end" << count << ":\n";
}

string logicOpAssembly(ofstream &assembly,string operatorFound, int offset1, int offset2, int count){
    string temp = "";
    assembly << "\t;Logical Operator:\n";
    if(operatorFound == "&&"){
        temp += "\t\tMOV CX, -" + to_string(offset1) + "[BP]\n";
        temp += "\t\tJCXZ after_and_" + to_string(count) + "\n";
        temp += "\t\tMOV CX, -" + to_string(offset2) + "[BP]\n";
        temp += "\t\tafter_and_" + to_string(count) + ":\n";
    }else if(operatorFound == "||"){
        temp += "\t\tMOV CX, -" + to_string(offset1) + "[BP]\n";
        temp += "\t\tCMP CX, 0\n";
        temp += "\t\tJNZ after_or_" + to_string(count) + "\n";
        temp += "\t\tMOV CX, -" + to_string(offset2) + "[BP]\n";
        temp += "\t\tafter_or_" + to_string(count) + ":\n";
    }
    return temp;
    //assembly << "\t\tJCXZ if_false1\n";
}

void putInArray(ofstream &assembly, int offset){
    assembly << "\t\t;put element to stack array\n";
    assembly << "\t\tPUSH BP\n";
    assembly << "\t\tSAL CX, 1\n";
    assembly << "\t\tADD CX, -" << offset <<"\n";
    assembly << "\t\tADD BP, CX\n";
    assembly << "\t\tMOV PTR WORD [BP], AX\n";
    assembly << "\t\tMOV CX, AX\n";
    assembly << "\t\tPOP BP\n";    
}

void putInGlobalArray(ofstream &assembly, string name){
    assembly << "\t\t;put element to global array\n";
    //assembly << "\t\tPUSH BP\n";
    assembly << "\t\tSAL CX, 1\n";
    assembly << "\t\tMOV BX, CX\n";
    assembly << "\t\tMOV PTR WORD " << name << "[BX], AX\n";
    assembly << "\t\tMOV CX, AX\n";
}

void fetchFromArray(ofstream &assembly, int offset){
    assembly << "\t\t;get array element from stack\n";
    assembly << "\t\tPUSH BP\n";
    assembly << "\t\tSAL CX, 1\n";
    assembly << "\t\tADD CX, -" << offset <<"\n";
    assembly << "\t\tADD BP, CX\n";
    assembly << "\t\tMOV CX, PTR WORD [BP]\n";
    assembly << "\t\tPOP BP\n";  
}

void fetchFromGlobalArray(ofstream &assembly, string name){
    assembly << "\t\t;get array element from stack\n";
    assembly << "\t\tSAL CX, 1\n";
    assembly << "\t\tMOV BX, CX\n";
    assembly << "\t\tMOV CX, PTR WORD " << name << "[BX]\n";
}

void parameterSetting(ofstream &assembly, int offset){
    assembly << "\t\t;parameters settings\n";
    assembly << "\t\tPUSH BP\n";
    assembly << "\t\tSAL CX, 1\n";
    assembly << "\t\tADD CX, -" << offset <<"\n";
    assembly << "\t\tADD BP, CX\n";
    assembly << "\t\tMOV PTR WORD [BP], AX\n";
    assembly << "\t\tMOV CX, AX\n";
    assembly << "\t\tPOP BP\n";    
}


void printProc(ofstream &assembly){
    string temp = "";
    temp += "print PROC\n\t;check neg\n\tcmp ax, 8000H\n\tjb positive\n";
    temp += "negative:\n";
    temp += "\tneg ax\n\tpush ax\n\tmov ah, 2\n\tmov dl, '-'\n\tint 21h\n\tpop ax\n";
    temp += "positive:\n";
	temp += "\tmov bx, 10\n\tmov cx, 0\n";
    temp += "getVals:\n";
	temp += "\tmov dx, 0\n\tdiv bx\n\tpush dx\n\tinc cx\n\tcmp ax, 0\n\tjne getVals\n";
    temp += "printing:\n";
	temp += "\tmov ah, 2\n\tpop dx\n\tadd dl, '0'\n\tint 21h\n\tdec cx\n\tcmp cx, 0\n\tjne printing\n\tmov dl, 0Ah\n\tint 21h\n\tmov dl, 0Dh\n";
	
    temp += "\tint 21h\n\tret\n"; 
    temp += "print ENDP\n\n";
    assembly << temp ;
}

void unaryNOT(ofstream &assembly, int count){
    string temp = "";
    temp += ("\tJCXZ not_one" + to_string(count) + "\n");
    temp += "\tMOV CX, 0\n";
    temp += ("\tJMP not_end" + to_string(count) + "\n");
    temp += ("\tnot_one" + to_string(count) + ":\n");
    temp += "\tMOV CX, 1\n";
    temp += ("\tnot_end" + to_string(count) + ":\n");
 
    assembly << temp;

}

void printDataSegment(ofstream &assembly, vector<pair<string,int>> globals){
    string temp = "";
    for (pair<string,int> str : globals){
        if(str.second == 0){
            temp += (str.first + " DW ?\n");
        }
        else{
            temp += (str.first + " DW " + to_string(str.second) + " DUP(?)\n");
        }
    }
    assembly << ".DATA\nCR EQU 0DH\nLF EQU 0AH\nVAR_PRINT DW ?\n";
    assembly << temp;
}

bool similarCommand(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();
    int index1, index2;

    int j = 0;

    for(;j<l1;j++){
        if(s1[j] == 'M')
            break;
    }

    if(j == l1)
        return false;
    if(s1.substr(j,3) != "MOV")
        return false;
    index1 = j;
    j = 0;

    for(;j<l1;j++){
        if(s1[j] == 'M')
            break;
    }

    if(j == l2)
        return false;
    if(s2.substr(j,3) != "MOV")
        return false;
    index2 = j;

    if(s1.substr(index1+8, 2) == s2.substr(index2+4, 2) and s1.substr(index1+4, 2) == s2.substr(index2+8, 2))
        return true;
    else 
        return false; 
    
}

int findM(string s){
    int l = s.size();
    int index1, index2;

    int j = 0;

    for(;j<l;j++){
        if(s[j] == 'M')
            break;
    }

    if(j == l)
        return -1;
    if(s.substr(j,3) != "MOV")
        return -1;
    return j;
}
void optimize(ofstream &asm2){
    ifstream inputFile("1805002_code.asm");
    vector<string> codeLines;
    
    string tempstr;
    int lineCount;

    vector<string> prevLineWords;
    vector<string> currentLineWords;

    while(getline(inputFile, tempstr)){
        codeLines.push_back(tempstr);
    }

    string prevLine = "";
    string currentLine = "";
    for(int i=0; i<codeLines.size(); i++){
        codeLines[i].erase(std::remove(codeLines[i].begin(), codeLines[i].end(), '\t'), codeLines[i].end());
        //codeLines[i].erase(std::remove(codeLines[i].begin(), codeLines[i].end(), '\n'), codeLines[i].end());
        if(codeLines[i].find("--") !=string::npos){
            codeLines[i].erase(codeLines[i].find("--"), 2);         
        }
        // if(codeLines[i].find(",") !=string::npos){
        //     codeLines[i].erase(codeLines[i].find(","), 1);         
        // }
        prevLine = currentLine;
        currentLine = codeLines[i];
        string line = codeLines[i];
     

        vector <string> tokens;
        stringstream check1(line);
     
        string intermediate;
     
        while(getline(check1, intermediate, ' '))
        {
        tokens.push_back(intermediate);
        }
     
    line = prevLine;
     
    vector <string> tokens2;
     
    stringstream check2(line);
     
    string intermediate2;
     
    while(getline(check2, intermediate2, ' '))
    {
        tokens2.push_back(intermediate2);
    }


    if(prevLine != "" && currentLine != "" && tokens.size()>=3 && tokens2.size() >= 3){
        if(tokens[0] == tokens2[0] && tokens[1] == tokens2[1] && tokens[0] == "MOV")
            continue;
        else if(tokens[0] == tokens2[0] && tokens[1] == (tokens2[2]+",") && tokens2[1] == (tokens[2]+",") && tokens[0] == "MOV"){
            if(tokens2[0] == "AX" || tokens2[0] == "CX" || tokens2[0] == "DX" || tokens2[0] == "BX" ){
                currentLine = "";
                continue;
            }
        }    
        else if(tokens2[0] == "PUSH" && tokens[0] == "POP" && tokens[1] == tokens2[1]){
            currentLine = "";
            continue;
        }else if(tokens2[0] == "ADD" && tokens[2] == "0")
            continue;
        
    }
   


        asm2 << prevLine << endl;
    }    
    asm2 <<  currentLine << endl; 
    
    

}


