#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Performs DFS (depth-first search)
 *
 * @param graph adjacency list representation of a graph.
 * @param start start node of search.
 * @returns an array of booleans with value `true` if it's possible to reach a
 * node from `start`.
 */
vector<bool> dfs(vector<vector<ll>> &graph, ll start) {
    stack<ll> stack;
    stack.push(start);
    vector<bool> visited(graph.size());
    while (!stack.empty()) {
        ll node = stack.top();
        stack.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (ll sub : graph[node]) stack.push(sub);
    }
    return visited;
}