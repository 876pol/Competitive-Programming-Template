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
        this->parent.resize(size);
        this->rank.resize(size);
        for (ll i = 0; i < size; i++) this->parent[i] = i;
        this->size = size;
    }

    /**
     * Finds the root of an element
     *
     * @param node element to find root of.
     * @returns root of element.
     */
    ll find(ll node) {
        if (this->parent[node] != node)
            this->parent[node] = find(this->parent[node]);
        return this->parent[node];
    }

    /**
     * Creates union between two elements
     *
     * @param node1, node2 elements to unite.
     */
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