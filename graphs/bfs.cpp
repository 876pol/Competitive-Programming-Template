#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
vector<vector<ll>> graph;
vector<ll> dist;

void bfs() {
    dist.assign(n + 1, -1);
    queue<ll> queue;
    queue.push(1);
    ll curr = 0;
    while (!queue.empty()) {
        for (ll i = 0, t = queue.size(); i < t; i++) {
            ll node = queue.front();
            queue.pop();
            if (dist[node] != -1) continue;
            dist[node] = curr;
            for (ll sub : graph[node]) queue.push(sub);
        }
        curr++;
    }
}