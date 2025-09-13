#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <vector>
#include <string>
#include "../include/Utils.h"  // for tokenization()

// Node for Trie
struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
};

class Trie {
private:
    TrieNode* root;

    // Helper to collect words recursively
    void collectAll(TrieNode* node, std::string prefix, std::vector<std::string>& results);

public:
    Trie();
    void insert(const std::string& word);
    void insertDocument(const std::string& text);  // uses tokenization()
    std::vector<std::string> getSuggestions(const std::string& prefix);
};

#endif
