#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Utility Function for `vector<vector<ll>> kosaraju(vector<vector<ll>> &adj)`
 */
void dfs1(ll v, vector<vector<ll>> &adj, vector<bool> &used,
          vector<ll> &order) {
    used[v] = true;
    for (auto u : adj[v]) {
        if (!used[u]) {
            dfs1(u, adj, used, order);
        }
    }
    order.push_back(v);
}

/**
 * Utility Function for `vector<vector<ll>> kosaraju(vector<vector<ll>> &adj)`
 */
void dfs2(ll v, vector<vector<ll>> &adj_rev, vector<bool> &used,
          vector<ll> &component) {
    used[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v]) {
        if (!used[u]) {
            dfs2(u, adj_rev, used, component);
        }
    }
}

/**
 * Performs Kosaraju's SCC Algorithm
 *
 * @param adj adjacency list representation of a graph
 * @returns an array of vectors that represent the nodes that are in each SCC
 */
vector<vector<ll>> kosaraju(vector<vector<ll>> &adj) {
    ll n = adj.size();
    vector<vector<ll>> adj_rev(n);
    for (ll i = 0; i < n; i++) {
        for (auto e : adj[i]) {
            adj_rev[e].push_back(i);
        }
    }
    vector<bool> used(n, false);
    vector<ll> order, component;
    vector<vector<ll>> components;
    for (ll i = 0; i < n; i++) {
        if (!used[i]) {
            dfs1(i, adj, used, order);
        }
    }
    used.assign(n, false);
    reverse(order.begin(), order.end());
    for (auto v : order) {
        if (!used[v]) {
            dfs2(v, adj_rev, used, component);
            components.push_back(component);
            component.clear();
        }
    }
    return components;
}