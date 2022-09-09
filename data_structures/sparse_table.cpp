#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    ll value = 0;

    node operator+(const node &n1) {
        return {max(this->value, n1.value)};
    }
};

template <class T>
struct sparse_table {
    vector<vector<T>> table;

    sparse_table(const vector<T> &a) {
        ll n = a.size() + 1;
        ll h = ceil(log2(n));
        table = vector<vector<T>>(h, vector<T>(n));
        for (ll i = 0; i < n; i++) table[0][i] = a[i];
        for (ll i = 1; i < h; i++) {
            for (ll j = 0; j + (1ll << i) <= n; j++) {
                table[i][j] =
                    table[i - 1][j] + table[i - 1][j + (1ll << (i - 1))];
            }
        }
    }

    T query(ll l, ll r) {
        if (r - l < 0) return T();
        ll p = 63 - __builtin_clzll(r - l + 1);
        return table[p][l] + table[p][r - (1ll << p) + 1];
    }
};