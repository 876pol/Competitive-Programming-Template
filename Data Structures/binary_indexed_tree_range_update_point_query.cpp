#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct binary_indexed_tree {
    vector<ll> bit;
    vector<ll> array;
    ll size;

    binary_indexed_tree(ll sz) {
        size = sz + 1;
        bit.assign(size, 0);
        array.assign(size, 0);
    }

    binary_indexed_tree(vector<ll> a) {
        size = a.size() + 1;
        bit.assign(size, 0);
        array.assign(size, 0);
        for (size_t i = 0; i < a.size(); i++) range_update(i, i, a[i]);
    }

    ll query(ll r) {
        ll ret = 0;
        for (++r; r > 0; r -= r & -r) ret += bit[r];
        return ret;
    }

    void update(ll idx, ll delta) {
        array[idx] += delta;
        for (++idx; idx < size; idx += idx & -idx)
            bit[idx] += delta;
    }

    void range_update(ll l, ll r, ll delta) {
        update(l, delta);
        update(r + 1, -delta);
    }
};