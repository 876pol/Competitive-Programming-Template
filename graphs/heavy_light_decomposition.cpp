#include <bits/stdc++.h>
using namespace std;

#define PROBLEM "https://cses.fi/problemset/task/2134/"

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

// parent of node, depth of node, heavy child, start of heavy
// segment, corresponding position of seg_arr, values on each
// node, values in segment tree.
ll n, q;
vector<ll> parent, depth, heavy, head, a, seg_arr, pos;
vector<vector<ll>> graph;
ll curr_pos;
segment_tree st;

ll dfs(ll curr) {
    ll size = 1;
    ll max_size = 0;
    for (auto sub : graph[curr]) {
        if (sub == parent[curr]) continue;
        parent[sub] = curr;
        depth[sub] = depth[curr] + 1;
        ll sub_size = dfs(sub);
        size += sub_size;
        if (sub_size > max_size) {
            max_size = sub_size;
            heavy[curr] = sub;
        }
    }
    return size;
}

void decompose(ll curr, ll head_node) {
    head[curr] = head_node;
    pos[curr] = curr_pos++;
    if (heavy[curr] != -1) {
        decompose(heavy[curr], head_node);
    }
    for (ll sub : graph[curr]) {
        if (sub != parent[curr] && sub != heavy[curr]) {
            decompose(sub, sub);
        }
    }
}

ll query(ll l, ll r) {
    ll res = 0;
    for (; head[l] != head[r]; r = parent[head[r]]) {
        if (depth[head[l]] > depth[head[r]]) {
            swap(l, r);
        }
        ll curr_heavy_path_max = st.query(1, 0, n, pos[head[r]], pos[r]);
        res = max(res, curr_heavy_path_max);
    }
    if (depth[l] > depth[r]) {
        swap(l, r);
    }
    ll last_heavy_path_max = st.query(1, 0, n, pos[l], pos[r]);
    res = max(res, last_heavy_path_max);
    return res;
}

void update(ll index, ll value) {
    st.update(1, 0, n, pos[index], value);
}

void preprocess() {
    parent.assign(n + 1, 0);
    depth.assign(n + 1, 0);
    heavy.assign(n + 1, -1);
    head.assign(n + 1, 0);
    seg_arr.assign(n + 1, 0);
    pos.assign(n + 1, 0);
    curr_pos = 0;

    dfs(1);
    decompose(1, 1);

    for (ll i = 1; i <= n; i++) {
        seg_arr[pos[i]] = a[i];
    }
    st = segment_tree(seg_arr);
}

int main() {
    cin >> n >> q;
    a.assign(n + 1, 0);
    graph.assign(n + 1, vector<ll>());
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    preprocess();
    for (ll i = 0; i < q; i++) {
        ll op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            update(l, r);
        } else {
            cout << query(l, r) << " \n"[i == q - 1];
        }
    }
}