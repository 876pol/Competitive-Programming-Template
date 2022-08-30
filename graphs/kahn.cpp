#include <bits/stdc++.h>
using namespace std;

using ll = long long;


vector<vector<ll>> graph;
vector<ll> in_degree, top_order;
bool has_cycle;

void kahn() {
    ll n = graph.size();
    in_degree.assign(n, 0);
    for (ll u = 0; u < n; u++) {
        for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
            in_degree[*it]++;
        }
    }
    queue<ll> q;
    for (ll i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    ll cnt = 0;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        top_order.push_back(u);
        for (auto it = graph[u].begin(); it != graph[u].end(); it++) {
            if (--in_degree[*it] == 0) {
                q.push(*it);
            }
        }
        cnt++;
    }
    if (cnt != n) {
        has_cycle = true;
    }
}