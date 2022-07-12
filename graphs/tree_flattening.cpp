#include <bits/stdc++.h>

using namespace std;

using ll = long long;


// data structure for query + update, can be swapped depending on need
struct binary_indexed_tree {
    vector<ll> bit;
    vector<ll> array;
    ll size;

    binary_indexed_tree(ll sz) {
        size = sz + 1;
        bit.assign(size, 0);
        array.assign(size, 0);
    }

    binary_indexed_tree(vector<ll> a) {
        size = a.size() + 1;
        bit.assign(size, 0);
        array.assign(size, 0);
        for (size_t i = 0; i < a.size(); i++) update(i, a[i]);
    }

    ll query(ll r) {
        ll ret = 0;
        for (++r; r > 0; r -= r & -r) ret += bit[r];
        return ret;
    }

    ll query(ll l, ll r) { return query(r) - query(l - 1); }

    void update(ll idx, ll delta) {
        array[idx] += delta;
        for (++idx; idx < size; idx += idx & -idx)
            bit[idx] += delta;
    }
};

vector<vector<ll>> graph;
vector<ll> id, c, sz, val, arr;  // id of node, id to index, size of subtree,
                                 // values in euler tour, values in each node
ll ind;
binary_indexed_tree bit;

ll dfs(ll curr, ll prev) {
    ll size = 1;
    id[ind] = curr;
    c[curr] = ind;
    val[c[curr]] = arr[curr];
    ind++;
    for (auto sub : graph[curr]) {
        if (sub != prev) {
            size += dfs(sub, curr);
        }
    }
    return sz[c[curr]] = size;
}

void tree_flattening(ll root) {
    ll n = graph.size();
    ind = 0;
    id.assign(n, 0);
    c.assign(n, 0);
    sz.assign(n, 0);
    val.assign(n, 0);
    dfs(root, -1);
    bit = binary_indexed_tree(val);
}
