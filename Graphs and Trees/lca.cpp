#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, l;
vector<ll> level;
vector<vector<ll>> graph, up;

void dfs(ll curr, ll prev, ll lvl) {
    up[curr][0] = prev;
    level[curr] = lvl;
    for (ll i = 1; i <= l; ++i) {
        if (up[curr][i - 1] != -1)
            up[curr][i] = up[up[curr][i - 1]][i - 1];
        else
            up[curr][i] = -1;
    }
    for (ll u : graph[curr]) {
        if (u != prev) dfs(u, curr, lvl + 1);
    }
}

void preprocess(ll root) {
    l = ceil(log2(n + 1));
    up.assign(n + 1, vector<ll>(l + 1));
    level.assign(n + 1, 0);
    dfs(root, -1, 0);
}

ll lca(ll u, ll v) {
    if (level[u] < level[v]) swap(u, v);
    for (ll i = l; i >= 0; i--)
        if ((level[u] - pow(2, i)) >= level[v]) u = up[u][i];
    if (u == v) return u;
    for (ll i = l; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

ll kth_ancestor(ll n, ll k) {
    ll ans = n;
    for (ll i = 0; i <= 63; i++)
        if (k & (1ll << i)) {
            if (ans == -1) return -1;
            ans = up[ans][i];
        }
    return ans;
}
