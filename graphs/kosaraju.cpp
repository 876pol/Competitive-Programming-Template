#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct kosaraju {
    ll size;
    vector<vector<ll>> graph, graph_rev, scc_graph;
    vector<bool> used;
    vector<ll> order, component, root, root_nodes;

    kosaraju(const vvll &graph) {
        size = graph.size();
        this->graph = graph;
        graph_rev.assign(size, vector<ll>());
        for (ll i = 0; i < size; i++) {
            for (auto e : graph[i]) {
                graph_rev[e].push_back(i);
            }
        }
        used.assign(size, false);
        for (ll i = 0; i < size; i++) {
            if (!used[i]) {
                dfs1(i);
            }
        }
        used.assign(size, false);
        reverse(order.begin(), order.end());
        root.assign(size, 0);
        scc_graph.assign(size, vector<ll>());
        for (auto curr : order) {
            if (!used[curr]) {
                dfs2(curr);
                ll root = component.front();
                for (auto u : component) {
                    root[u] = root;
                }
                root_nodes.push_back(root);
                component.clear();
            }
        }
        for (ll curr = 0; curr < size; curr++) {
            for (auto sub : graph[curr]) {
                ll rcurr = root[curr];
                ll rsub = root[sub];
                if (rsub != rcurr) {
                    scc_graph[rcurr].push_back(rsub);
                }
            }
        }
    }

    void dfs1(ll curr) {
        used[curr] = true;
        for (auto sub : graph[curr]) {
            if (!used[sub]) {
                dfs1(sub);
            }
        }
        order.push_back(curr);
    }

    void dfs2(ll curr) {
        used[curr] = true;
        component.push_back(curr);
        for (auto sub : graph_rev[curr]) {
            if (!used[sub]) {
                dfs2(sub);
            }
        }
    }
};