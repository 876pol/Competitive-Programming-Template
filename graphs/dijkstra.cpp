#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
vector<vector<pair<ll, ll>>> graph; // weight, dest
vector<ll> dist;
vector<bool> visited;

void dijkstra(ll start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        queue;
    dist.assign(n + 1, LLONG_MAX);
    visited.assign(n + 1, 0);
    dist[start] = 0;
    queue.push({0, start});
    while (!queue.empty()) {
        ll a = queue.top().second;
        queue.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto u : graph[a]) {
            ll w = u.first, b = u.second;
            if (dist[a] != LLONG_MAX && dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                queue.push({dist[b], b});
            }
        }
    }
}