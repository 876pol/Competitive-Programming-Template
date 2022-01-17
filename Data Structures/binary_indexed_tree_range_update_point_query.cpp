#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Binary Indexed Tree / Fenwick Tree class
 *
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
        for (size_t i = 0; i < a.size(); i++) range_update(i, i, a[i]);
    }

    /**
     * Query array at a point
     *
     * @param r returns query at point `r`.
     * @returns answer to the query.
     */
    ll query(ll r) {
        ll ret = 0;
        for (++r; r > 0; r -= r & -r) ret += bit[r];
        return ret;
    }

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

    /**
     * Update value in range
     *
     * @param l, r values are updated in range [l, r]
     * @param delta amount to change.
     */
    void range_update(ll l, ll r, ll delta) {
        update(l, delta);
        update(r + 1, -delta);
    }
};