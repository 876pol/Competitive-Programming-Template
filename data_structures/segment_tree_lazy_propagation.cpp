#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct node {
    ll ans = 0, lazy_add = 0, lazy_set = 0;

    void pull(const node &c1, const node &c2) {
        ans = c1.ans + c2.ans;
    }

    void push(const node &par) {
        if (par.lazy_set != 0) {
            lazy_set = par.lazy_set;
        } else if (par.lazy_add != 0) {
            if (lazy_set != 0) {
                lazy_set += par.lazy_add;
            } else {
                lazy_add += par.lazy_add;
            }
        }
    }

    void apply(ll sz) {
        if (lazy_set != 0) {
            ans = lazy_set * sz;
        } else {
            ans += lazy_add * sz;
        }
        lazy_add = lazy_set = 0;
    }
};

template <class T>
struct segment_tree {
#define lc(x) (x) + 1
#define rc(x) (x) + 2 * (tm - tl + 1)
    ll size;
    vector<T> tree;

    segment_tree() {
        size = 0;
    }

    segment_tree(ll size) {
        this->size = size;
        tree.assign(2 * size, T());
    }

    segment_tree(const vector<T> &a) {
        this->size = a.size();
        tree.assign(2 * size, T());
        build(a, 1, 0, size - 1);
    }

    void build(const vector<T> &a, ll v, ll tl, ll tr) {
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        if (tl == tr) {
            tree[v].push(a[tl]);
            push(v, tl, tm, tr);
        } else {
            build(a, lc(v), tl, tm);
            build(a, rc(v), tm + 1, tr);
            tree[v].pull(tree[lc(v)], tree[rc(v)]);
        }
    }

    void push(ll v, ll tl, ll tm, ll tr) {
        if (tl != tr) {
            tree[lc(v)].push(tree[v]);
            tree[rc(v)].push(tree[v]);
        }
        tree[v].apply(tr - tl + 1);
    }

    T query(ll v, ll tl, ll tr, ll l, ll r) {
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        if (l > tr || r < tl) return T();
        if (l <= tl && tr <= r) {
            return tree[v];
        } else {
            T ret;
            ret.pull(query(lc(v), tl, tm, l, r),
                     query(rc(v), tm + 1, tr, l, r));
            return ret;
        }
    }

    void update(ll v, ll tl, ll tr, ll l, ll r, T val) {
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            tree[v].push(val);
            push(v, tl, tm, tr);
        } else {
            update(lc(v), tl, tm, l, r, val);
            update(rc(v), tm + 1, tr, l, r, val);
            tree[v].pull(tree[lc(v)], tree[rc(v)]);
        }
    }
#undef lc
#undef rc
};
