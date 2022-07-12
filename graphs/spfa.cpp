#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
vector<vector<pair<ll, ll>>> graph;  // weight, dest
vector<ll> dist;
bool negative_cycle;

void spfa(ll start) {
    dist.assign(n + 1, INT_MAX);
    dist[start] = 0;
    queue<ll> to_search;
    to_search.push(start);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0, t = to_search.size(); j < t; j++) {
            ll node = to_search.front();
            to_search.pop();
            for (auto sub : graph[node]) {
                if (dist[node] + sub.first < dist[sub.second]) {
                    dist[sub.second] = dist[node] + sub.first;
                    to_search.push(sub.second);
                }
            }
        }
        if (to_search.empty()) return;
    }
    for (ll j = 0, t = to_search.size(); j < t; j++) {
        ll node = to_search.front();
        to_search.pop();
        for (auto sub : graph[node]) {
            if (dist[node] + sub.first < dist[sub.second]) {
                negative_cycle = true;
                return;
            }
        }
    }
}