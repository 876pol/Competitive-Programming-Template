#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Binary Indexed Tree / Fenwick Tree class
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
        for (size_t i = 0; i < a.size(); i++) update(i, a[i]);
    }

    /**
     * Query array in range starting from 0
     *
     * @param r returns query in range [0, r].
     * @returns answer to the query.
     */
    T query(ll r) {
        T ret = 0;
        for (++r; r > 0; r -= r & -r) ret = combine(ret, bit[r]);
        return ret;
    }

    /**
     * Query array in range
     *
     * @param l, r returns query in range [l, r].
     * @returns answer to the query.
     */
    T query(ll l, ll r) { return query(r) - query(l - 1); }

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
     * Combines two values
     *
     * @param t1, t2 two values to combine.
     */
    T combine(T &t1, T &t2) { return t1 + t2; }
};