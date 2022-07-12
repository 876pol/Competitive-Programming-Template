#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct sparse_table {
    vector<vector<ll>> table;

    sparse_table(vector<ll> a) {
        ll n = a.size() + 1;
        ll h = ceil(log2(n));
        table = vector<vector<ll>>(h, vector<ll>(n));
        for (ll i = 0; i < n; i++) table[0][i] = a[i];
        for (ll i = 1; i < h; i++) {
            for (ll j = 0; j + (1 << i) <= n; j++) {
                table[i][j] =
                    min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    ll query(ll l, ll r) {
        if (r - l == 0) return 0;
        ll p = 63 - __builtin_clzll(r - l);
        return min(table[p][l], table[p][r - (1ll << p)]);
    }
};