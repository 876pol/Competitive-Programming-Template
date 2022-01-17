#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Iterative Segment Tree class
 */
struct segment_tree {
    ll n;
    vector<ll> tree;

    /**
     * Class Constructor
     *
     * @param arr array to build the Segment Tree from.
     */
    segment_tree(vector<ll> &arr) {
        n = arr.size();
        tree.resize(2 * n);
        if (!n) return;
        copy(arr.begin(), arr.end(), tree.begin() + n);
        for (ll i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    /**
     * Update value in array
     *
     * @param index index of array to change.
     * @param value new value for index.
     */
    void update(ll index, ll value) {
        tree[index += n] = value;
        for (; index > 1; index >>= 1)
            tree[index >> 1] = tree[index] + tree[index ^ 1];
    }

    /**
     * Query array in range
     *
     * @param l, r returns query in range [l, r).
     * @returns answer to the query.
     */
    ll query(ll l, ll r) {
        ll ans = tree[l + n];
        l++;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) != 0) ans += tree[l++];
            if ((r & 1) != 0) ans += tree[--r];
        }
        return ans;
    }
};