#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isRoot;

    TrieNode() : isRoot(false) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isRoot = true;
    }

    string getShortestRoot(const string& word) {
        TrieNode* node = root;
        string prefix = "";
        for (char ch : word) {
            if (!node->children.count(ch)) {
                break;
            }
            node = node->children[ch];
            prefix += ch;
            if (node->isRoot) {
                return prefix;
            }
        }
        return word;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string& root : dictionary) {
            trie.insert(root);
        }

        istringstream iss(sentence);
        ostringstream oss;
        string word;

        while (iss >> word) {
            if (oss.tellp() != 0) {
                oss << " ";
            }
            oss << trie.getShortestRoot(word);
        }

        return oss.str();
    }
};
