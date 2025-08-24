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
        tokens.push_back(word);
    }
    return tokens;
}


int main(){
// string filenam;
// cout<<"enter : ";
// getline(cin,filenam);
string content = readfile("../docs/doc1.txt");
vector<string> words=tokenization(content);
 for(const string& word : words){
    cout<<word<<endl;
 }

}