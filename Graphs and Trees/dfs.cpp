#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<ll>> graph;
vector<bool> visited;

void dfs(ll curr) {
    visited[curr] = true;
    for (ll sub : graph[curr]) {
        if (!visited[sub]) dfs(sub);
    }
}