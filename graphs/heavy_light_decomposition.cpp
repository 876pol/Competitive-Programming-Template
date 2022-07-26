#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct segment_tree {
    ll size;
    vector<ll> tree;

    segment_tree() {
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
            tree[v] = max(tree[v + 1], tree[v + 2 * (tm - tl + 1)]);
        }
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r) {
        if (l > tr || r < tl) return 0;
        if (l <= tl && tr <= r) {
            return tree[v];
        }
        ll tm = (tl + tr) / 2;
        return max(query(v + 1, tl, tm, l, r),
                   query(v + 2 * (tm - tl + 1), tm + 1, tr, l, r));
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
            tree[v] = max(tree[v + 1], tree[v + 2 * (tm - tl + 1)]);
        }
    }
};


struct HLD {
    ll size, curr_pos;
    // parent of node, depth of node, heavy child, start of heavy
    // segment, corresponding position of seg_arr, values on each
    // node, values in segment tree.
    vector<ll> parent, depth, heavy, head, seg_arr, pos;
    segment_tree st;

    HLD(vector<vector<ll>> &graph, vector<ll> &a) {
        size = graph.size();
        parent.assign(size, 0);
        depth.assign(size, 0);
        heavy.assign(size, -1);
        head.assign(size, 0);
        seg_arr.assign(size, 0);
        pos.assign(size, 0);
        curr_pos = 0;

        dfs(1, graph);
        decompose(1, 1, graph);

        for (ll i = 1; i < size; i++) {
            seg_arr[pos[i]] = a[i];
        }
        st = segment_tree(seg_arr);
    }

    ll dfs(ll curr, vector<vector<ll>> &graph) {
        ll size = 1;
        ll max_size = 0;
        for (auto sub : graph[curr]) {
            if (sub == parent[curr]) continue;
            parent[sub] = curr;
            depth[sub] = depth[curr] + 1;
            ll sub_size = dfs(sub, graph);
            size += sub_size;
            if (sub_size > max_size) {
                max_size = sub_size;
                heavy[curr] = sub;
            }
        }
        return size;
    }

    void decompose(ll curr, ll head_node, vector<vector<ll>> &graph) {
        head[curr] = head_node;
        pos[curr] = curr_pos++;
        if (heavy[curr] != -1) {
            decompose(heavy[curr], head_node, graph);
        }
        for (auto sub : graph[curr]) {
            if (sub != parent[curr] && sub != heavy[curr]) {
                decompose(sub, sub, graph);
            }
        }
    }

    ll query(ll l, ll r) {
        ll res = 0;
        for (; head[l] != head[r]; r = parent[head[r]]) {
            if (depth[head[l]] > depth[head[r]]) {
                swap(l, r);
            }
            ll curr_path = st.query(1, 0, size - 1, pos[head[r]], pos[r]);
            res = max(res, curr_path);
        }
        if (depth[l] > depth[r]) {
            swap(l, r);
        }
        ll curr_path = st.query(1, 0, size - 1, pos[l], pos[r]);
        res = max(res, curr_path);
        return res;
    }

    void update(ll index, ll value) {
        st.update(1, 0, size - 1, pos[index], value);
    }
};