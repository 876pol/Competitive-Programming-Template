#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<ll>> graph;
vector<bool> visited;
vector<ll> parent, cycle;
ll cycle_start, cycle_end;

bool dfs(ll curr, ll prev) {
    visited[curr] = true;
    for (ll u : graph[curr]) {
        if (u == prev) continue;
        if (visited[u]) {
            cycle_end = curr;
            cycle_start = u;
            return true;
        }
        parent[u] = curr;
        if (dfs(u, parent[u])) return true;
    }
    return false;
}

void find_cycle() {
    ll n = graph.size();
    visited.assign(n, false);
    parent.assign(n, -1);
    cycle_start = -1;
    for (ll v = 0; v < n; v++) {
        if (!visited[v] && dfs(v, parent[v])) break;
    }
    if (cycle_start != -1) {
        cycle.push_back(cycle_start);
        for (ll v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
    }
}
