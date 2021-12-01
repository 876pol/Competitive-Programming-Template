#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Performs Topological Sort with Kahn's Algorithm
 *
 * @param graph adjacency list representation of a graph.
 * @returns the topological sorting of `graph`.
 */
vector<ll> kahn(vector<vector<ll>> &graph) {
    ll n = graph.size();
    vector<ll> in_degree(n, 0);
    for (ll u = 0; u < n; u++) {
        for (auto itr = graph[u].begin(); itr != graph[u].end(); itr++)
            in_degree[*itr]++;
    }
    queue<ll> q;
    for (ll i = 0; i < n; i++)
        if (in_degree[i] == 0) q.push(i);
    ll cnt = 0;
    vector<ll> top_order;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        top_order.push_back(u);
        for (auto itr = graph[u].begin(); itr != graph[u].end(); itr++)
            if (--in_degree[*itr] == 0) q.push(*itr);
        cnt++;
    }
    if (cnt != n) {
        return vector<ll>();
    }
    return top_order;
}