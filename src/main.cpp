#include<iostream>
#include"../include/Utils.h"
#include"../include/InvertedIndex.h"
#include"../include/Trie.h" 
#include "../include/SearchEngine.h"


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


// index.addDocumentwithfreq(1,content1);
// index.addDocumentwithfreq(2,content2);
// index.addDocumentwithfreq(3,content3);
// index.addDocumentwithfreq(4,content4);
// index.addDocumentwithfreq(5,content5);

// auto search=index.Gsearchwithfreq("c++ ai");
// auto search2=index.searchwithfreq("data");



// index.printGsearchwithfreq(search);
// index.printGsearchwithfreq(search2);





//////////////// test day 4//////////////

//  Trie trie;

// trie.insertDocument(content1);
// trie.insertDocument(content2);
// trie.insertDocument(content3);
// trie.insertDocument(content4);
// trie.insertDocument(content5);



// string prefix;
// cout << "Enter prefix: ";
// cin >> prefix;

// vector<string> suggestions = trie.getSuggestions(prefix);

// if (suggestions.empty()) {
//     cout << "No suggestions for '" << prefix << "'\n";
// } else {
//     cout << "Suggestions for '" << prefix << "':\n";
//     for (auto& w : suggestions) {
//         cout << " - " << w << endl;
//     }
// }


// }





//////////////// test day 5//////////////

    SearchEngine engine;

    engine.addDocument(1, content1);
    engine.addDocument(2, content2);
    engine.addDocument(3, content3);
    engine.addDocument(4, content4);
    engine.addDocument(5, content5);

    while (true){
    cout<<"*************************************"<<endl;
    cout<<"Choose an option:\n1. Autocomplete\n2. Search Word\n3. Search Ranked\n4. Exit\n";
    int option;
    cout<<"Enter your choice: ";
    cin>>option;
    if (option==1){
    string prefix;
    cout << "Enter prefix: ";
    cin >> prefix;
    engine.searchPrefix(prefix); 
    }
    else if (option==2){
        cin.ignore(); // to clear the newline character from the buffer
        string data;
        cout<<"Enter your search word: ";
        getline(cin,data);
        engine.searchWord(data);
    }

    else if (option==3){
        cin.ignore(); // to clear the newline character from the buffer
        string data;
        cout<<"Enter your search word: ";
        getline(cin,data);
        engine.searchRanked(data);
    }
    else{
        break;


    }





}
    return 0;
}
