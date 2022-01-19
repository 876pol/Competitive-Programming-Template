#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
vector<pair<pair<ll, ll>, ll>> edges;  // start, end, weight
vector<ll> dist;
bool negative_cycle;

void bellman_ford(ll start) {
    dist.assign(n + 1, LLONG_MAX);
    dist[start] = 0;
    for (ll i = 0; i < n; i++) {
        bool not_changed = true;
        for (auto edge : edges) {
            if (dist[edge.first.first] == LLONG_MAX) continue;
            if (dist[edge.first.first] + edge.second <
                dist[edge.first.second]) {
                dist[edge.first.second] = dist[edge.first.first] + edge.second;
                not_changed = false;
            }
        }
        if (not_changed) return;
    }
    for (auto edge : edges) {
        if (dist[edge.first.first] == LLONG_MAX) continue;
        if (dist[edge.first.first] + edge.second < dist[edge.first.second]) {
            negative_cycle = true;
            return;
        }
    }
}