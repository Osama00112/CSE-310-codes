#include<bits/stdc++.h>


using namespace std;
char charRule(string str){
	char token;
	if(str.length() == 3){
		token = str[1];
	}
	else if(str.length() == 4 && str[1] == '\\'){
        if(str[2] == 'a')
            token = '\a';
        else if(str[2] == 'b')
            token = '\b';
        else if(str[2] == 'f')
            token = '\f';
        else if(str[2] == 'n')
            token = '\n';
        else if(str[2] == 'r')
            token = '\r';
        else if(str[2] == 't')
            token = '\t';
        else if(str[2] == 'v')
            token = '\v';
        else if(str[2] == '\\')
            token = '\\';
        else if(str[2] == '\'')
            token = '\'';
        else if(str[2] == '\"')
            token = '\"';
        else if(str[2] == '\0')
            token = '\0';
	}
	else{
        
	}
    return token;
}
int main(){
    string s = "adfsaf \
    sadfsdfas";
    
    //jsfkljadsiopfhaiophfipoawe

    char ch = charRule("'\n'");

    float a = 2E2.3;
    cout << a << "\n";

    cout << "character is " << ch ;
    cout << "afsdfads\
    asdfas\0'fsdf";
    /**sdafsdfasdfadsfsa*/
    return 0;
}

