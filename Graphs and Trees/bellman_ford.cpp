#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Performs Bellman-Ford's algorithm for shortest path
 *
 * @param edges edge list representation of a graph, where each edge is
 * represented by a `pair<pair<ll, ll>, ll>`, where the
 * first pair represents the start and end of an edge, and the second integer
 * represents the weight.
 * @param start start node of algorithm.
 * @param size number of nodes in the graph.
 * @returns an array of distances between `start` and every other node, else an
 * empty array if the graph contains a negative cycle.
 */
vector<ll> bellman_ford(vector<pair<pair<ll, ll>, ll>> &edges, ll start,
                        ll size) {
    vector<ll> distance(size, LLONG_MAX);
    distance[start] = 0;
    for (ll i = 0; i < size - 1; i++) {
        bool not_changed = true;
        for (auto edge : edges) {
            if (distance[edge.first.first] == LLONG_MAX) continue;
            if (distance[edge.first.first] + edge.second <
                distance[edge.first.second]) {
                distance[edge.first.second] =
                    distance[edge.first.first] + edge.second;
                not_changed = false;
            }
        }
        if (not_changed) return distance;
    }
    for (auto edge : edges) {
        if (distance[edge.first.first] == LLONG_MAX) continue;
        if (distance[edge.first.first] + edge.second <
            distance[edge.first.second]) {
            return vector<ll>();
        }
    }
    return distance;
}