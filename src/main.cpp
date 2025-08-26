#include<iostream>
#include"../include/Utils.h"
#include"../include/InvertedIndex.h"

using namespace std;


int main(){
InvertedIndex index;
string content1 = readfile("../docs/doc1.txt");
string content2 = readfile("../docs/doc2.txt");
string content3 = readfile("../docs/doc3.txt");
string content4 = readfile("../docs/doc4.txt");
string content5 = readfile("../docs/doc5.txt");

index.addDocumentwithfreq(1,content1);
index.addDocumentwithfreq(2,content2);
index.addDocumentwithfreq(3,content3);
index.addDocumentwithfreq(4,content4);
index.addDocumentwithfreq(5,content5);

auto search=index.searchwithfreq("c++");

cout<<"*************************************"<<endl;

for(auto&[docid,freq]:search){
    cout<<"DOC "<<docid<<" → "<<freq<<" times\n";
}








// index.addDocumentsimple(3,content3);
// index.addDocumentsimple(2,content2);
// index.addDocumentsimple(1,content1);


// index.Gsearch("AI search");

// unordered_set<int> result= index.search("AI");


}