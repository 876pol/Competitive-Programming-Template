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
        for (ll i = 0; i < size; i++) parent[i] = i;
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

ll n, m;
vector<pair<ll, pair<ll, ll>>> edges, mst;  // weight, src, dest

void kruskal() {
    DSU dsu(n + 1);
    sort(edges.begin(), edges.end());
    for (ll i = 0; i < edges.size(); i++) {
        if (dsu.find(edges[i].second.first) !=
            dsu.find(edges[i].second.second)) {
            dsu.unify(edges[i].second.first, edges[i].second.second);
            mst.push_back(edges[i]);
        }
    }
}