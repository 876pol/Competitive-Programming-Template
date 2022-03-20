#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<ll>> graph;
vector<ll> parent, colour, cycle;
ll cycle_start, cycle_end;

bool dfs(ll v) {
    colour[v] = 1;
    for (ll u : graph[v]) {
        if (colour[u] == 0) {
            parent[u] = v;
            if (dfs(u)) return true;
        } else if (colour[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    colour[v] = 2;
    return false;
}

void find_cycle() {
    ll n = graph.size();
    colour.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    for (ll v = 0; v < n; v++) {
        if (colour[v] == 0 && dfs(v)) break;
    }
    if (cycle_start != -1) {
        cycle.push_back(cycle_start);
        for (ll v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
    }
}