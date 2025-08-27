#include<iostream>
#include"../include/Utils.h"
#include"../include/InvertedIndex.h"

using namespace std;


int main(){

///// loading files //////

InvertedIndex index;
string content1 = readfile("../docs/doc1.txt");
string content2 = readfile("../docs/doc2.txt");
string content3 = readfile("../docs/doc3.txt");
string content4 = readfile("../docs/doc4.txt");
string content5 = readfile("../docs/doc5.txt");

//// testing day1/2//////

// index.addDocumentsimple(2,content2);
// index.addDocumentsimple(1,content1);
// index.addDocumentsimple(3,content3);



// index.Gsearch("amir");

// unordered_set<int> result= index.search("AI");
// index.printSearch(result);



/////// testing day3/4///////


index.addDocumentwithfreq(1,content1);
index.addDocumentwithfreq(2,content2);
index.addDocumentwithfreq(3,content3);
index.addDocumentwithfreq(4,content4);
index.addDocumentwithfreq(5,content5);

auto search=index.Gsearchwithfreq("c++ ai");
auto search2=index.searchwithfreq("data");



index.printGsearchwithfreq(search);
index.printGsearchwithfreq(search2);























}