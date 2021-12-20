#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Utility Function for `ll edmonds_karp(ll source, ll sink, vector<vector<pair<ll, ll>>> &graph)`
 */
ll bfs(ll source, ll sink, vector<ll> &parent, vector<vector<ll>> &capacity,
       vector<set<ll>> &adj) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<ll, ll>> q;
    q.push(make_pair(source, LLONG_MAX));
    while (!q.empty()) {
        ll curr = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (ll next : adj[curr]) {
            if (parent[next] == -1 && capacity[curr][next]) {
                parent[next] = curr;
                ll new_flow = min(flow, capacity[curr][next]);
                if (next == sink) {
                    return new_flow;
                }
                q.push(make_pair(next, new_flow));
            }
        }
    }
    return 0;
}

/**
 * Performs Edmonds Karp's algorithm
 *
 * @param source, sink source and sink for maximum flow.
 * @param graph adjacency list representation of a graph where each edge is
 * represented as a `pair<ll, ll>`, where the first pair is the
 * weight and the second pair is the destination.
 * @returns an integer that represents the maximum flow of the graph.
 */
ll edmonds_karp(ll source, ll sink, vector<vector<pair<ll, ll>>> &graph) {
    ll n = graph.size();
    vector<vector<ll>> capacity(n, vector<ll>(n));
    vector<set<ll>> adj(n);
    for (ll i = 0; i < n; i++) {
        for (auto e : graph[i]) {
            adj[i].insert(e.second);
            adj[e.second].insert(i);
            capacity[i][e.second] += e.first;
        }
    }
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;
    while ((new_flow = bfs(source, sink, parent, capacity, adj))) {
        flow += new_flow;
        ll curr = sink;
        while (curr != source) {
            ll prev = parent[curr];
            capacity[prev][curr] -= new_flow;
            capacity[curr][prev] += new_flow;
            curr = prev;
        }
    }
    return flow;
}