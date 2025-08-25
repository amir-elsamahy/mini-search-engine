#include<iostream>
#include"../include/Utils.h"
#include"../include/InvertedIndex.h"

using namespace std;


int main(){
InvertedIndex index;
string content3 = readfile("../docs/doc3.txt");
string content2 = readfile("../docs/doc2.txt");

index.addDocument(3,content3);
index.addDocument(2,content2);


index.Gsearch("the is a test");

unordered_set<int> result= index.search("the");


}