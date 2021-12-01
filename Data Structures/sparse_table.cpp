#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Sparse Table class for static RMQ (range minimum query)
 *
 * @tparam T class for Sparse Table to contain.
 */
template <class T>
struct sparse_table {
    vector<vector<T>> table;

    /**
     * Class Constructor
     *
     * @param a array to build the Sparse Table from.
     */
    sparse_table(vector<T> a) {
        ll n = a.size() + 1;
        ll h = ceil(log2(n));
        table = vector<vector<T>>(h, vector<T>(n));
        for (ll i = 0; i < n; i++) table[0][i] = a[i];
        for (ll i = 1; i < h; i++) {
            for (ll j = 0; j + (1 << i) <= n; j++) {
                table[i][j] =
                    combine(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    /**
     * Query array in range
     *
     * @param l, r range [l, r) to query.
     * @returns answer to the query.
     */
    T query(ll l, ll r) {
        if (r - l == 0) return T();
        ll p = 31 - __builtin_clz(r - l);
        return combine(table[p][l], table[p][r - (1 << p)]);
    }

    /**
     * Combines two values
     *
     * @param t1, t2 two values to combine.
     */
    T combine(T &t1, T &t2) { return min(t1, t2); }
};