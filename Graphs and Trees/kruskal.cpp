#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
    vector<ll> parent;
    vector<ll> rank;
    ll size;

    DSU(ll size) {
        this->parent.resize(size);
        this->rank.resize(size);
        for (ll i = 0; i < size; i++) this->parent[i] = i;
        this->size = size;
    }

    ll find(ll node) {
        if (this->parent[node] != node)
            this->parent[node] = find(this->parent[node]);
        return this->parent[node];
    }

    void unify(ll node1, ll node2) {
        ll root1 = find(node1);
        ll root2 = find(node2);
        if (this->rank[root1] < this->rank[root2]) {
            this->parent[root1] = root2;
        } else if (this->rank[root1] > this->rank[root2]) {
            this->parent[root2] = root1;
        } else {
            this->parent[root2] = root1;
            this->rank[root1]++;
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