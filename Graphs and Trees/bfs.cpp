#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Performs BFS (breadth-first search)
 *
 * @param graph adjacency list representation of a graph.
 * @param start start node of search.
 * @returns the distance between `start` and `end` else `-1` if there is no
 * path.
 */
vector<ll> bfs(vector<vector<ll>> &graph, ll start) {
    queue<ll> queue;
    queue.push(start);
    vector<ll> distance(graph.size(), -1);
    ll dist = 0;
    while (!queue.empty()) {
        for (ll i = 0, t = queue.size(); i < t; i++) {
            ll node = queue.front();
            queue.pop();
            if (distance[node] != -1) continue;
            distance[node] = dist;
            for (ll sub : graph[node]) queue.push(sub);
        }
        dist++;
    }
    return distance;
}