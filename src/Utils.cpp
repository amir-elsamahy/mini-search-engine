#include"../include/utils.h"
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;


// takes file convert it to string and return it
string readfile(const string& filename){
    
    ifstream file(filename);

    if(file.fail()){
        cout<<"error to open "<<filename<<endl;
        return "";
    }
    // stringstream buffer;
    // buffer<<file.rdbuf();
    // return buffer.str();
    string line , content;
    while(getline(file,line)){
        content = content+line+"\n";

    }
    return content;

}


// takes string split it on any space or , then return it in a vector
vector<string> tokenization(const string& text){
    vector<string> tokens;
    stringstream ss(text);
    string word;
    while(ss>>word){
       string clearword;
       for(char c: word){
        if(isalnum(c)){
            clearword+= tolower(c);
        }
       }
        if(!clearword.empty()){
            tokens.push_back(clearword);
        }
    }
    return tokens;
}


