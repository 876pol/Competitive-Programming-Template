#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Data class for Trie.
 */
struct node {
    char val;
    map<char, node*> m;
    bool is_word;

    node(char c) {
        val = c;
        is_word = false;
    }
};

struct Trie {
    node* root;

    /**
     * Builds Trie.
     */
    Trie() { root = new node(' '); }

    /**
     * Inserts a word into the trie.
     */
    void insert(string word) {
        node* curr = root;
        for (auto& c : word) {
            if (curr->m[c] == NULL) {
                node* next = new node(c);
                curr->m[c] = next;
            }
            curr = curr->m[c];
        }
        curr->is_word = true;
    }

    /**
     * Checks if a word is present in the trie.
     */
    bool search(string word) {
        node* curr = root;
        for (auto& c : word) {
            if (curr->m[c] == NULL) return false;
            curr = curr->m[c];
        }
        return curr->is_word;
    }

    /**
     * Checks if there are words that begin with a prefix.
     */
    bool starts_with(string prefix) {
        node* curr = root;
        for (auto& c : prefix) {
            if (curr->m[c] == NULL) return false;
            curr = curr->m[c];
        }
        return true;
    }
};