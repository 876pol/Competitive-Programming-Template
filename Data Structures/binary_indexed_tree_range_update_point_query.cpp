#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Binary Indexed Tree / Fenwick Tree class for Range Update and Point Query
 *
 * @tparam T class for the Binary Indexed Tree to contain.
 */
template <class T>
struct binary_indexed_tree {
    vector<T> bit;
    vector<T> array;
    ll size;

    /**
     * Class Constructor
     *
     * @param a array to build the Binary Indexed Tree from.
     */
    binary_indexed_tree(vector<T> a) {
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
    T query(ll r) {
        T ret = 0;
        for (++r; r > 0; r -= r & -r) ret += bit[r];
        return ret;
    }

    /**
     * Update value in array
     *
     * @param idx index of array to change.
     * @param delta amount to change.
     */
    void update(ll idx, T delta) {
        array[idx] = combine(array[idx], delta);
        for (++idx; idx < size; idx += idx & -idx)
            bit[idx] = combine(bit[idx], delta);
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

    /**
     * Combines two values
     *
     * @param t1, t2 two values to combine.
     */
    T combine(T &t1, T &t2) { return t1 + t2; }
};