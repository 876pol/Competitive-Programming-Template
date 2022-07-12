#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// cannot set to 0
struct segment_tree {
    ll size;
    vector<ll> tree, lazy_add, lazy_set;

    segment_tree(vector<ll> &a) {
        size = a.size();
        tree.assign(size * 4, 0);
        lazy_add.assign(size * 4, 0);
        lazy_set.assign(size * 4, 0);
        build(a, 1, 0, size - 1);
    }

    void build(vector<ll> &a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && tr <= r) {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        push_down(v, tl, tm, tr);
        return query(v * 2, tl, tm, l, r) + query(v * 2 + 1, tm + 1, tr, l, r);
    }

    void add(ll v, ll tl, ll tr, ll l, ll r, ll val) {
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            tree[v] += val * (tr - tl + 1);
            if (lazy_set[v] == 0) {
                lazy_add[v] += val;
            } else {
                lazy_set[v] += val;
            }
        } else {
            ll tm = (tl + tr) / 2;
            push_down(v, tl, tm, tr);
            add(v * 2, tl, tm, l, r, val);
            add(v * 2 + 1, tm + 1, tr, l, r, val);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    void set(ll v, ll tl, ll tr, ll l, ll r, ll val) {
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            tree[v] = val * (tr - tl + 1);
            lazy_add[v] = 0;
            lazy_set[v] = val;
        } else {
            ll tm = (tl + tr) / 2;
            push_down(v, tl, tm, tr);
            set(v * 2, tl, tm, l, r, val);
            set(v * 2 + 1, tm + 1, tr, l, r, val);
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }

    void push_down(ll v, ll l, ll tm, ll r) {
        if (lazy_set[v] != 0) {
            lazy_set[v * 2] = lazy_set[v * 2 + 1] = lazy_set[v];
            tree[v * 2] = lazy_set[v] * (tm - l + 1);
            tree[v * 2 + 1] = lazy_set[v] * (r - tm);
            lazy_add[v * 2] = lazy_add[v * 2 + 1] = 0;
            lazy_set[v] = 0;
        } else if (lazy_add[v] != 0) {
            if (lazy_set[v * 2] == 0) {
                lazy_add[v * 2] += lazy_add[v];
            } else {
                lazy_set[v * 2] += lazy_add[v];
                lazy_add[v * 2] = 0;
            }
            if (lazy_set[v * 2 + 1] == 0) {
                lazy_add[v * 2 + 1] += lazy_add[v];
            } else {
                lazy_set[v * 2 + 1] += lazy_add[v];
                lazy_add[v * 2 + 1] = 0;
            }
            tree[v * 2] += lazy_add[v] * (tm - l + 1);
            tree[v * 2 + 1] += lazy_add[v] * (r - tm);
            lazy_add[v] = 0;
        }
    }
};