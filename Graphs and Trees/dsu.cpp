#include <bits/stdc++.h>
using namespace std;

#define ll long long


/**
 * DSU (disjointed set union) class
 */
struct DSU {
    vector<ll> parent;
    vector<ll> rank;
    ll size;

    /**
     * Class Constructor
     *
     * @param size size of DSU.
     */
    DSU(ll size) {
        parent.resize(size);
        rank.resize(size);
        for (ll i = 0; i < size; i++) parent[i] = i;
        this->size = size;
    }

    /**
     * Finds the root of an element
     *
     * @param node element to find root of.
     * @returns root of element.
     */
    ll find(ll node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    /**
     * Creates union between two elements
     *
     * @param node1, node2 elements to unite.
     */
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