#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

    Trie() { 
        root = new node(' '); 
    }

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

    bool search(string word) {
        node* curr = root;
        for (auto& c : word) {
            if (curr->m[c] == NULL) return false;
            curr = curr->m[c];
        }
        return curr->is_word;
    }

    bool starts_with(string prefix) {
        node* curr = root;
        for (auto& c : prefix) {
            if (curr->m[c] == NULL) return false;
            curr = curr->m[c];
        }
        return true;
    }
};