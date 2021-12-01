#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Performs DFS (depth-first search)
 *
 * @param graph adjacency list representation of a graph.
 * @param curr start node of search.
 * @param visited an empty array of booleans that gets filled with value
 * `true` if it's possible to reach a node from `start`.
 */
void dfs(vector<vector<ll>> &graph, ll curr, vector<bool> &visited) {
    visited[curr] = true;
    for (ll sub : graph[curr]) {
        if (!visited[sub]) dfs(graph, sub, visited);
    }
}