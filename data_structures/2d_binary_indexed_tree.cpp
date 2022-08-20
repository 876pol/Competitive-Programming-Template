#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <class T>
struct binary_indexed_tree_2d {
    ll rows, columns;
    vector<vector<T>> bit;

    binary_indexed_tree_2d() {
        rows = columns = 0; 
    }

    binary_indexed_tree_2d(ll rows, ll columns) {
        this->rows = rows;
        this->columns = columns;
        bit.assign(rows + 1, vector<T>(columns + 1));
    }

    binary_indexed_tree_2d(const vector<vector<T>> &a) {
        rows = a.size();
        columns = a[0].size();
        bit.assign(rows + 1, vector<T>(columns + 1));
        for (ll i = 0; i < rows; i++) {
            for (ll j = 0; j < columns; j++) {
                update(i, j, a[i][j]);
            }
        }
    }

    T query(ll x, ll y) {
        T ret = 0;
        for (ll i = x + 1; i > 0; i -= i & -i) {
            for (ll j = y + 1; j > 0; j -= j & -j) {
                ret = ret + bit[i][j];
            }
        }
        return ret;
    }

    T query(ll x1, ll y1, ll x2, ll y2) {
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) +
               query(x1 - 1, y1 - 1);
    }

    void update(ll x, ll y, T delta) {
        for (ll i = x + 1; i <= rows; i += i & -i) {
            for (ll j = y + 1; j <= columns; j += j & -j) {
                bit[i][j] = bit[i][j] + delta;
            }
        }
    }
};