#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct edge {
    ll s, d, w;
    edge() {}
    edge(ll s, ll d, ll w) {
        this->s = s;
        this->d = d;
        this->w = w;
    }
};

struct element {
    ll w, node;
    edge e;

    element(ll w, ll node, edge e) {
        this->w = w;
        this->node = node;
        this->e.s = e.s;
        this->e.d = e.d;
        this->e.w = e.w;
    }
};

struct comp {
    bool operator()(element e1, element e2) { return e1.w > e2.w; }
};

/**
 * Performs Prim's algorithm
 *
 * @param graph adjacency list representation of a graph where each edge is
 * represented as a `pair<ll, ll>`, where the first pair is the
 * weight and the second pair is the destination.
 * @param start start node of MST.
 * @returns a list of edges that are in the MST.
 */
vector<edge> prim(vector<vector<pair<ll, ll>>> &graph, ll start) {
    priority_queue<element, vector<element>, comp> queue;
    vector<bool> visited(graph.size());
    vector<edge> mst;
    queue.push(element(0, start, edge(-1, -1, -1)));
    while (!queue.empty()) {
        element e = queue.top();
        queue.pop();
        if (visited[e.node]) continue;
        visited[e.node] = true;
        if (e.e.s != -1 && e.e.d != -1 && e.e.w != -1) mst.push_back(e.e);
        for (auto u : graph[e.node]) {
            ll w = u.first, b = u.second;
            queue.push(element(w, b, edge(e.node, b, w)));
        }
    }
    return mst;
}