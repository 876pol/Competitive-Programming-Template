#include <bits/stdc++.h>

using namespace std;

using ll = long long;


struct binary_indexed_tree {
    vector<ll> bit;
    ll size;

    binary_indexed_tree() {
        size = 0;
    }

    binary_indexed_tree(ll sz) {
        size = sz + 1;
        bit.assign(size, 0);
    }

    binary_indexed_tree(vector<ll> a) {
        size = a.size() + 1;
        bit.assign(size, 0);
        for (ll i = 0; i < a.size(); i++) {
            update(i, a[i]);
        }
    }

    ll query(ll r) {
        ll ret = 0;
        for (ll i = r + 1; i > 0; i -= i & -i) {
            ret = ret + bit[i];
        }
        return ret;
    }

    ll query(ll l, ll r) { 
        return query(r) - query(l - 1);
    }

    void update(ll index, ll delta) {
        for (ll i = index + 1; i < size; i += i & -i) {
            bit[i] = bit[i] + delta;
        }
    }
};

struct tree_flattening {
    vector<ll> id, c, sz, val, arr;  // id of node, id to index, size of subtree,
                                 // values in euler tour, values in each node
    ll ind;
    binary_indexed_tree bit;
    
    tree_flattening(vector<vector<ll>> &graph) {
        ll n = graph.size();
        ind = 0;
        id.assign(n, 0);
        c.assign(n, 0);
        sz.assign(n, 0);
        val.assign(n, 0);
        dfs(1, -1, graph);
        bit = binary_indexed_tree(val);
    }

    ll dfs(ll curr, ll prev, vector<vector<ll>> &graph) {
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
};