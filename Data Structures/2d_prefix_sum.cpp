#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * 2D Prefix Sum Array class for 2D sum queries
 * 
 * @tparam T class for the Binary Indexed Tree to contain.
 */
template <class T>
struct prefix_sum_2d {
    ll n, m;
    vector<vector<T>> ps;

    /**
     * Class Constructor
     *
     * @param a 2D array to build the Prefix Sum Array from.
     */
    prefix_sum_2d(vector<vector<T>> &a) {
        n = a.size();
        m = a[0].size();
        ps.resize(n + 1, vector<ll>(m + 1));
        ps[1][1] = a[0][0];
        for (ll i = 2; i <= n; i++) ps[i][1] = combine(ps[i - 1][1], a[i - 1][0]);
        for (ll i = 2; i <= m; i++) ps[1][i] = combine(ps[1][i - 1], a[0][i - 1]);
        for (ll i = 2; i <= n; i++) {
            for (ll j = 2; j <= m; j++) {
                ps[i][j] =
                    decombine(combine(combine(ps[i - 1][j], ps[i][j - 1]), a[i - 1][j - 1]),
                                      ps[i - 1][j - 1]);
            }
        }
    }

    /**
     * Query 2D Prefix Sum Array
     *
     * @param y1, x1, y2, x2 returns query to [(y1, x1), (y2, x2)].
     * @returns answer to the query.
     */
    T query(ll y1, ll x1, ll y2, ll x2) {
        return decombine(combine(ps[y2 + 1][x2 + 1], ps[y1][x1]),
                         combine(ps[y1][x2 + 1], ps[y2 + 1][x1]));
    }

    /**
     * Combines two values
     *
     * @param t1, t2 two values to combine.
     */
    T combine(T t1, T t2) { return t1 + t2; }

    /**
     * Decombines two values
     *
     * @param t1, t2 two values to decombine.
     */
    T decombine(T t1, T t2) { return t1 - t2; }
};