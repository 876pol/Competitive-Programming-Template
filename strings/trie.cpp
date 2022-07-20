#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Trie {
    vector<vector<ll>> graph;
    vector<bool> end;

    Trie() {
        graph.assign(1, vector<ll>(26, -1));
        end.assign(1, false);
    }

    void insert(string s) {
        ll curr = 0;
        for (ll i = 0; i < s.size(); i++) {
            if (graph[curr][s[i] - 'a'] == -1) {
                graph[curr][s[i] - 'a'] = graph.size();
                curr = graph.size();
                graph.push_back(vector<ll>(26, -1));
                end.push_back(false);
            } else {
                curr = graph[curr][s[i] - 'a'];
            }
        }
        end[curr] = true;
    }

    bool search(string s) {
        ll curr = 0;
        for (ll i = 0; i < s.size(); i++) {
            if (graph[curr][s[i] - 'a'] == -1) {
                return false;
            }
            curr = graph[curr][s[i] - 'a'];
        }
        return end[curr];
    }

    bool starts_with(string s) {
        ll curr = 0;
        for (ll i = 0; i < s.size(); i++) {
            if (graph[curr][s[i] - 'a'] == -1) {
                return false;
            }
            curr = graph[curr][s[i] - 'a'];
        }
        return true;
    }
};