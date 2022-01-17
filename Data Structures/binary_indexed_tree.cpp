#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Binary Indexed Tree / Fenwick Tree class
 */
struct binary_indexed_tree {
    vector<ll> bit;
    vector<ll> array;
    ll size;

    /**
     * Class Constructor
     *
     * @param a array to build the Binary Indexed Tree from.
     */
    binary_indexed_tree(vector<ll> a) {
        size = a.size() + 1;
        bit.assign(size, 0);
        array.assign(size, 0);
        for (size_t i = 0; i < a.size(); i++) update(i, a[i]);
    }

    /**
     * Query array in range starting from 0
     *
     * @param r returns query in range [0, r].
     * @returns answer to the query.
     */
    ll query(ll r) {
        ll ret = 0;
        for (++r; r > 0; r -= r & -r) ret += bit[r];
        return ret;
    }

    /**
     * Query array in range
     *
     * @param l, r returns query in range [l, r].
     * @returns answer to the query.
     */
    ll query(ll l, ll r) { return query(r) - query(l - 1); }

    /**
     * Update value in array
     *
     * @param idx index of array to change.
     * @param delta amount to change.
     */
    void update(ll idx, ll delta) {
        array[idx] += delta;
        for (++idx; idx < size; idx += idx & -idx)
            bit[idx] += delta;
    }
};