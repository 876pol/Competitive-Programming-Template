#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <class T>
struct binary_indexed_tree {
    vector<T> bit;
    ll size;

    binary_indexed_tree() {
        size = 0;
    }

    binary_indexed_tree(ll sz) {
        size = sz;
        bit.assign(size + 1, T());
    }

    binary_indexed_tree(const vector<T> &a) {
        size = a.size();
        bit.assign(size + 1, T());
        for (ll i = 0; i < size; i++) {
            update(i, a[i]);
        }
    }

    T query(ll r) {
        T ret = 0;
        for (ll i = r + 1; i > 0; i -= i & -i) {
            ret = ret + bit[i];
        }
        return ret;
    }

    T query(ll l, ll r) { 
        return query(r) - query(l - 1);
    }

    void update(ll index, T delta) {
        for (ll i = index + 1; i <= size; i += i & -i) {
            bit[i] = bit[i] + delta;
        }
    }
};