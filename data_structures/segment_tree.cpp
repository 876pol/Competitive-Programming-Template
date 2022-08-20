#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <class T>
struct segment_tree {
    ll size;
    vector<T> tree;

    segment_tree() {
        size = 0;
    }

    segment_tree(ll size) {
        this->size = size;
        tree.assign(2 * size, T());
    }

    segment_tree(vector<T> &a) {
        this->size = a.size();
        tree.assign(2 * size, T());
        build(a, 1, 0, size - 1);
    }

    void build(vector<T> &a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(a, v + 1, tl, tm);
            build(a, v + 2 * (tm - tl + 1), tm + 1, tr);
            tree[v] = tree[v + 1] + tree[v + 2 * (tm - tl + 1)];
        }
    }

    T query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > tr || r < tl) return T();
        if (l <= tl && tr <= r) {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        return query(v + 1, tl, tm, l, r) +
               query(v + 2 * (tm - tl + 1), tm + 1, tr, l, r);
    }

    void update(ll v, ll tl, ll tr, ll index, T value) {
        if (tl == tr) {
            tree[v] = value;
        } else {
            ll tm = (tl + tr) / 2;
            if (index <= tm) {
                update(v + 1, tl, tm, index, value);
            } else {
                update(v + 2 * (tm - tl + 1), tm + 1, tr, index, value);
            }
            tree[v] = tree[v + 1] + tree[v + 2 * (tm - tl + 1)];
        }
    }
};