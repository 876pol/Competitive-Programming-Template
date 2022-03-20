#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct sparse_table {
    vector<vector<pair<ll, ll>>> table;

    sparse_table() {}

    sparse_table(vector<pair<ll, ll>> a) {
        ll n = a.size() + 1;
        ll h = ceil(log2(n));
        table = vector<vector<pair<ll, ll>>>(h, vector<pair<ll, ll>>(n));
        for (ll i = 0; i < n; i++) table[0][i] = a[i];
        for (ll i = 1; i < h; i++) {
            for (ll j = 0; j + (1 << i) <= n; j++) {
                table[i][j] =
                    min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    pair<ll, ll> query(ll l, ll r) {
        if (r - l == 0) return {-1, -1};
        ll p = 31 - __builtin_clz(r - l);
        return min(table[p][l], table[p][r - (1 << p)]);
    }
};

ll n, root, q;
vector<ll> loc;
vector<pair<ll, ll>> euler;  // height, id of node
vector<vector<ll>> graph;
sparse_table st;

void dfs(ll curr, ll prev, ll lvl) {
    euler.push_back({lvl, curr});
    for (ll e : graph[curr]) {
        if (e == prev) continue;
        dfs(e, curr, lvl + 1);
        euler.push_back({lvl, curr});
    }
    loc[curr] = euler.size() - 1;
}

void preprocess(ll r) {
    root = r;
    loc.resize(n + 1);
    dfs(r, -1, 0);
    st = sparse_table(euler);
}

ll lca(ll u, ll v) {
    if (loc[u] > loc[v]) swap(u, v);
    return st.query(loc[u], loc[v] + 1).second;
}
