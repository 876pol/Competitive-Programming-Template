#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
vector<vector<ll>> graph;
vector<ll> subtree_size;

ll get_subtree_size(ll curr, ll prev) {
    subtree_size[curr] = 1;
    for (ll i : graph[curr]) {
        if (i == prev) continue;
        subtree_size[curr] += get_subtree_size(i, curr);
    }
    return subtree_size[curr];
}

ll get_centroid(ll curr, ll prev) {
    for (ll i : graph[curr]) {
        if (i == prev) continue;
        if (subtree_size[i] * 2 > n) {
            return get_centroid(i, curr);
        }
    }
    return curr;
}

ll centroid_decomposition(ll root) {
    subtree_size.resize(graph.size());
    get_subtree_size(root, -1);
    return get_centroid(root, -1);
}