#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct binary_indexed_tree_2d {
    vector<vector<ll>> bit;
    ll n, m;

    binary_indexed_tree_2d(ll r, ll c) {
        n = r;
        m = c;
        bit.assign(n + 1, vector<ll>(m + 1));
    }

    binary_indexed_tree_2d(vector<vector<ll>> a) {
        n = a.size();
        m = a[0].size();
        bit.assign(n + 1, vector<ll>(m + 1));
        for (ll i = 0; i < a.size(); i++)
            for (ll j = 0; j < a[0].size(); j++) update(i, j, a[i][j]);
    }

    ll query(ll x, ll y) {
        ll ret = 0;
        for (ll i = x + 1; i > 0; i -= i & -i)
            for (ll j = y + 1; j > 0; j -= j & -j) ret += bit[i][j];
        return ret;
    }

    ll query(ll x1, ll y1, ll x2, ll y2) {
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) +
               query(x1 - 1, y1 - 1);
    }

    void update(ll x, ll y, ll delta) {
        for (ll i = x + 1; i <= n; i += i & -i)
            for (ll j = y + 1; j <= m; j += j & -j) bit[i][j] += delta;
    }
};