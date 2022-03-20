#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct segment_tree {
    struct node {
        ll val = 0;
        ll la = 0;
        ll ls = 0;
    };

    ll n;
    vector<node> tree;

    segment_tree(vector<ll> &a) {
        this->n = a.size();
        tree.resize(n * 4);
        build(a, 1, 0, n - 1);
    }

    void build(vector<ll> &a, ll v, ll tl, ll tr) {
        tree[v].la = tree[v].ls = 0;
        if (tl == tr) {
            tree[v].val = a[tl];
            return;
        }
        ll mid = (tl + tr) / 2;
        build(a, v * 2, tl, mid);
        build(a, v * 2 + 1, mid + 1, tr);
        tree[v].val = tree[v * 2].val + tree[v * 2 + 1].val;
        return;
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && tr <= r) return tree[v].val;
        ll mid = (tl + tr) / 2;
        pushdown(v, tl, mid, tr);
        return query(v * 2, tl, mid, l, r) +
               query(v * 2 + 1, mid + 1, tr, l, r);
    }

    void add(ll v, ll tl, ll tr, ll l, ll r, ll val) {
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            tree[v].val += val * (tr - tl + 1);
            if (tree[v].ls == 0)
                tree[v].la += val;
            else
                tree[v].ls += val;
            return;
        }
        ll mid = (tl + tr) / 2;
        pushdown(v, tl, mid, tr);
        add(v * 2, tl, mid, l, r, val);
        add(v * 2 + 1, mid + 1, tr, l, r, val);
        tree[v].val = tree[v * 2].val + tree[v * 2 + 1].val;
        return;
    }

    void set(ll v, ll tl, ll tr, ll l, ll r, ll val) {
        if (l > tr || r < tl) return;
        if (l <= tl && tr <= r) {
            tree[v].val = val * (tr - tl + 1);
            tree[v].la = 0;
            tree[v].ls = val;
            return;
        }
        ll mid = (tl + tr) / 2;
        pushdown(v, tl, mid, tr);
        set(v * 2, tl, mid, l, r, val);
        set(v * 2 + 1, mid + 1, tr, l, r, val);
        tree[v].val = tree[v * 2].val + tree[v * 2 + 1].val;
        return;
    }

    void pushdown(ll v, ll l, ll mid, ll r) {
        if (tree[v].ls != 0) {  // lazy: range set
            tree[v * 2].ls = tree[v * 2 + 1].ls = tree[v].ls;
            tree[v * 2].val = tree[v].ls * (mid - l + 1);
            tree[v * 2 + 1].val = tree[v].ls * (r - mid);
            tree[v * 2].la = tree[v * 2 + 1].la = 0;
            tree[v].ls = 0;
        } else if (tree[v].la != 0) {  // lazy: range add
            if (tree[v * 2].ls == 0)
                tree[v * 2].la += tree[v].la;
            else {
                tree[v * 2].ls += tree[v].la;
                tree[v * 2].la = 0;
            }
            if (tree[v * 2 + 1].ls == 0)
                tree[v * 2 + 1].la += tree[v].la;
            else {
                tree[v * 2 + 1].ls += tree[v].la;
                tree[v * 2 + 1].la = 0;
            }
            tree[v * 2].val += tree[v].la * (mid - l + 1);
            tree[v * 2 + 1].val += tree[v].la * (r - mid);
            tree[v].la = 0;
        }
        return;
    }
};