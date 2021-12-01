#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Performs Dijkstra's algorithm
 *
 * @param graph adjacency list representation of a graph where each edge is
 * represented as a `pair<ll, ll>`, where the first pair is the
 * weight and the second pair is the destination.
 * @param start start node of search.
 * @returns an array of distances between `start` and every other node.
 */
vector<ll> dijkstra(vector<vector<pair<ll, ll>>> &graph, ll start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        queue;
    vector<ll> distance(graph.size(), LLONG_MAX);
    vector<bool> visited(graph.size());
    distance[start] = 0;
    queue.push(make_pair(0, start));
    while (!queue.empty()) {
        ll a = queue.top().second;
        queue.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto u : graph[a]) {
            ll w = u.first, b = u.second;
            if (distance[a] != LLONG_MAX && distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                queue.push(make_pair(distance[b], b));
            }
        }
    }
    return distance;
}