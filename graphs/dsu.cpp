#include <bits/stdc++.h>
using namespace std;

using ll = long long;


struct DSU {
    vector<ll> parent;
    vector<ll> rank;
    ll size;

    DSU(ll size) {
        parent.resize(size);
        rank.resize(size);
        iota(parent.begin(), parent.end(), 0ll);
        this->size = size;
    }

    ll find(ll node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void unify(ll node1, ll node2) {
        ll root1 = find(node1);
        ll root2 = find(node2);
        if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
};