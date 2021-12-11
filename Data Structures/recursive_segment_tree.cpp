#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Recursive Segment Tree class
 *
 * @tparam T class for the Segment Tree to contain.
 */
template <class T>
struct segment_tree {
    ll n;
    vector<T> t;

    /**
     * Class Constructor
     *
     * @param a array to build the Segment Tree from.
     */
    segment_tree(vector<T> &a) {
        n = a.size();
        t.resize(4 * n + 5);
        build(a, 1, 0, n - 1);
    }

    /**
     * Utility function for the constructor
     */
    void build(vector<T> &a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

    /**
     * Query array in range
     *
     * @param v set to 1
     * @param tl set to 0
     * @param tr set to n - 1
     * @param l, r returns query in range [l, r].
     * @returns answer to the query.
     */
    T query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > r) return T();
        if (l == tl && r == tr) {
            return t[v];
        }
        ll tm = (tl + tr) / 2;
        return combine(query(v * 2, tl, tm, l, min(r, tm)),
                       query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    /**
     * Update value in array
     *
     * @param v set to 1
     * @param tl set to 0
     * @param tr set to n - 1
     * @param pos index of array to change.
     * @param new_val new value for index.
     */
    void update(ll v, ll tl, ll tr, ll pos, T new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

    /**
     * Combines two values
     *
     * @param t1, t2 two values to combine.
     */
    T combine(T t1, T t2) { return t1 + t2; }
};