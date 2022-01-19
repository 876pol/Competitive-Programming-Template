#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> graph, graph_rev, components;
vector<bool> used;
vector<ll> order, component;

void dfs1(ll v) {
    used[v] = true;
    for (auto u : graph[v]) {
        if (!used[u]) {
            dfs1(u);
        }
    }
    order.push_back(v);
}

void dfs2(ll v) {
    used[v] = true;
    component.push_back(v);
    for (auto u : graph_rev[v]) {
        if (!used[u]) {
            dfs2(u);
        }
    }
}

void kosaraju() {
    ll n = graph.size();
    graph_rev.assign(n, vector<ll>());
    for (ll i = 1; i < n; i++) {
        for (auto e : graph[i]) {
            graph_rev[e].push_back(i);
        }
    }
    used.assign(n, false);
    for (ll i = 1; i < n; i++) {
        if (!used[i]) {
            dfs1(i);
        }
    }
    used.assign(n, false);
    reverse(order.begin(), order.end());
    for (auto v : order) {
        if (!used[v]) {
            dfs2(v);
            components.push_back(component);
            component.clear();
        }
    }
}