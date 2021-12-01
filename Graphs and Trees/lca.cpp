#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * LCA (lowest common ancestor) class with binary lifting
 */
struct LCA {
    ll n, l, root;
    vector<ll> level;
    vector<vector<ll>> adj, up;

    /**
     * Class Constructor
     *
     * @param adj adjacency list representation of a graph.
     * @param root root node of graph.
     */
    LCA(vector<vector<ll>> &adj, ll root) {
        this->adj = vector<vector<ll>>(adj);
        n = adj.size();
        this->root = root;
        l = ceil(log2(n));
        up.assign(n, vector<ll>(l + 1));
        level.assign(n, 0);
        dfs(root, -1, 0);
    }

    /**
     * Utility function to preprocess
     */
    void dfs(ll curr, ll prev, ll lvl) {
        up[curr][0] = prev;
        level[curr] = lvl;
        for (ll i = 1; i <= l; ++i) {
            if (up[curr][i - 1] != -1)
                up[curr][i] = up[up[curr][i - 1]][i - 1];
            else
                up[curr][i] = -1;
        }
        for (ll u : adj[curr]) {
            if (u != prev) dfs(u, curr, lvl + 1);
        }
    }

    /**
     * Calculates LCA of two nodes
     * @param u, v two nodes to find LCA of.
     */
    ll lca(ll u, ll v) {
        if (level[u] < level[v]) swap(u, v);
        for (ll i = l; i >= 0; i--)
            if ((level[u] - pow(2, i)) >= level[v]) u = up[u][i];
        if (u == v) return u;
        for (ll i = l; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    /**
     * Calculates the kth ancestor of a node
     * @param n node to find ancestor of.
     * @param k the kth ancestor of node.
     */
    ll kth_ancestor(ll n, ll k) {
        ll ans = n;
        for (ll i = 0; i <= 63; i++)
            if (k & (1ll << i)) {
                if (ans == -1) return -1;
                ans = up[ans][i];
            }
        return ans;
    }
};