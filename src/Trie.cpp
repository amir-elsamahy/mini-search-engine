#include "../include/Trie.h"
#include <algorithm>  // for sort

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->isEndOfWord = true;
}

void Trie::insertDocument(const std::string& text) {
    std::vector<std::string> words = tokenization(text);  // from Utils
    for (const std::string& word : words) {
        insert(word);
    }
}

std::vector<std::string> Trie::getSuggestions(const std::string& prefix) {
    TrieNode* node = root;
    for (char ch : prefix) {
        if (node->children.find(ch) == node->children.end()) {
            return {}; // no suggestions
        }
        node = node->children[ch];
    }

    std::vector<std::string> results;
    collectAll(node, prefix, results);

    // optional: sort alphabetically
    std::sort(results.begin(), results.end());
    return results;
}

void Trie::collectAll(TrieNode* node, std::string prefix, std::vector<std::string>& results) {
    if (node->isEndOfWord) {
        results.push_back(prefix);
    }
    for (auto& [ch, child] : node->children) {
        collectAll(child, prefix + ch, results);
    }
}
