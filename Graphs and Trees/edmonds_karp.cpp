#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
vector<vector<ll>> capacity;
vector<vector<ll>> graph;

ll bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, LLONG_MAX});
    while (!q.empty()) {
        ll curr = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (ll next : graph[curr]) {
            if (parent[next] == -1 && capacity[curr][next]) {
                parent[next] = curr;
                ll new_flow = min(flow, capacity[curr][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

ll edmonds_karp(ll s, ll t) {
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;
    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        ll curr = t;
        while (curr != s) {
            ll prev = parent[curr];
            capacity[prev][curr] -= new_flow;
            capacity[curr][prev] += new_flow;
            curr = prev;
        }
    }
    return flow;
}