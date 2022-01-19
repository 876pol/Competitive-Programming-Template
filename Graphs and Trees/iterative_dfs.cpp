#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
vector<vector<ll>> graph;
vector<bool> visited;

void dfs(ll start) {
    stack<ll> stack;
    stack.push(start);
    visited.assign(n + 1, false);
    while (!stack.empty()) {
        ll node = stack.top();
        stack.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (ll sub : graph[node]) stack.push(sub);
    }
}