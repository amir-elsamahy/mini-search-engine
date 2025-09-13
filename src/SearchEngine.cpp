#include "../include/SearchEngine.h"
#include <iostream>
#include <algorithm>

using namespace std;

void SearchEngine::addDocument(int id, const string& text) {
    documents[id] = text;
    index.addDocumentsimple(id, text);                     // store doc text
    index2.addDocumentwithfreq(id, text);    // update inverted index
    trie.insertDocument(text);            // update trie
}

void SearchEngine::searchWord(const string& word) {
    auto results = index.search(word);
    index.printSearch(results);
}

void SearchEngine::searchRanked(const string& word) {
    auto results = index2.searchwithfreq(word);
    index.printGsearchwithfreq(results);
}

void SearchEngine::searchPrefix(const string& prefix) {
    auto suggestions = trie.getSuggestions(prefix);
    if (suggestions.empty()) {
        cout << "No suggestions for \"" << prefix << "\"" << endl;
    } else {
        cout << "Suggestions for \"" << prefix << "\":" << endl;
        for (auto& w : suggestions) {
            cout << " - " << w << endl;
        }
    }
}
