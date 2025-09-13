#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "../include/InvertedIndex.h"
#include "../include/Trie.h"
#include "../include/Utils.h"

class SearchEngine {
private:
    InvertedIndex index;
    InvertedIndex index2;                       // word -> docIDs/frequencies
    Trie trie;                                 // for autocomplete
    std::unordered_map<int, std::string> documents; // store original docs by ID

public:
    // Add document to both index and trie
    void addDocument(int id, const std::string& text);

    // Search single word
    void searchWord(const std::string& word);

    // Search ranked (frequency)
    void searchRanked(const std::string& word);

    // Autocomplete
    void searchPrefix(const std::string& prefix);
};

#endif // SEARCHENGINE_H
