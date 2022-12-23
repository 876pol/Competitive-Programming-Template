#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct binary_lifting {
    ll size, log_size;
    vector<ll> level;
    vector<vector<ll>> up;

    binary_lifting(vector<vector<ll>> &graph) {
        size = graph.size();
        log_size = ceil(log2(size));
        up.assign(size, vector<ll>(log_size + 1));
        level.assign(size, 0);
        dfs(1, -1, 0, graph);
        for (ll i = 1; i < log_size; i++) {
            for (ll j = 0; j < size; j++) {
                if (up[j][i - 1] != -1) {
                    up[j][i] = up[up[j][i - 1]][i - 1];
                } else {
                    up[j][i] = -1;
                }
            }
        }
    }

    void dfs(ll curr, ll prev, ll depth, vector<vector<ll>> &graph) {
        up[curr][0] = prev;
        level[curr] = depth;
        for (auto child : graph[curr]) {
            if (child == prev) continue;
            dfs(child, curr, depth + 1, graph);
        }
    }

    ll lca(ll u, ll v) {
        if (level[u] < level[v]) swap(u, v);
        for (ll i = log_size; i >= 0; i--) {
            if ((level[u] - (1ll << i)) >= level[v]) {
                u = up[u][i];
            }
        }
        if (u == v) return u;
        for (ll i = log_size; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};
