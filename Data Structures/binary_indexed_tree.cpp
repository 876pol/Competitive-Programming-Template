#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct binary_indexed_tree {
    vector<ll> bit;
    ll size;

    binary_indexed_tree(ll sz) {
        size = sz + 1;
        bit.assign(size, 0);
    }

    binary_indexed_tree(vector<ll> a) {
        size = a.size() + 1;
        bit.assign(size, 0);
        for (ll i = 0; i < a.size(); i++) update(i, a[i]);
    }

    ll query(ll r) {
        ll ret = 0;
        for (++r; r > 0; r -= r & -r) ret += bit[r];
        return ret;
    }

    ll query(ll l, ll r) { return query(r) - query(l - 1); }

    void update(ll idx, ll delta) {
        for (++idx; idx < size; idx += idx & -idx)
            bit[idx] += delta;
    }
};