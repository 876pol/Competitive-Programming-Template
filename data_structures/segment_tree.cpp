#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct segment_tree {
    ll size;
    vector<ll> tree;

    segment_tree() {
        size = 0;
    }

    segment_tree(vector<ll> &a) {
        size = a.size();
        tree.resize(2 * size);
        build(a, 1, 0, size - 1);
    }

    void build(vector<ll> &a, ll v, ll tl, ll tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            build(a, v + 1, tl, tm);
            build(a, v + 2 * (tm - tl + 1), tm + 1, tr);
            tree[v] = tree[v + 1] + tree[v + 2 * (tm - tl + 1)];
        }
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && tr <= r) {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        return query(v + 1, tl, tm, l, r) +
               query(v + 2 * (tm - tl + 1), tm + 1, tr, l, r);
    }

    void update(ll v, ll tl, ll tr, ll index, ll value) {
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

struct tree_flattening {
    ll size, ind;
    vector<ll> node_id, loc, sub_size,
        value;  // id of node, location of node, size of subtree,
                // values in euler tour.
    segment_tree st;

    tree_flattening(vector<vector<ll>> &graph, vector<ll> &arr) {
        size = graph.size();
        ind = 0;
        node_id.assign(size, 0);
        loc.assign(size, 0);
        sub_size.assign(size, 0);
        value.assign(size, 0);
        dfs(1, -1, graph, arr);
        st = segment_tree(value);
    }

    ll dfs(ll curr, ll prev, vector<vector<ll>> &graph, vector<ll> &arr) {
        ll size = 1;
        node_id[ind] = curr;
        loc[curr] = ind;
        value[loc[curr]] = arr[curr];
        ind++;
        for (auto sub : graph[curr]) {
            if (sub != prev) {
                size += dfs(sub, curr, graph, arr);
            }
        }
        return sub_size[loc[curr]] = size;
    }

    ll query(ll sub_tree) {
        return st.query(1, 0, size - 1, loc[sub_tree],
                        loc[sub_tree] + sub_size[loc[sub_tree]] - 1);
    }

    void update(ll node, ll new_value) {
        st.update(1, 0, size - 1, loc[node], new_value);
    }
};
