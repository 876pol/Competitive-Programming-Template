#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct centroid_decomposition {
    ll size;
    vector<set<ll>> graph;
    vector<ll> parent, sub_size;

    centroid_decomposition(vector<vector<ll>> &graph) {
        size = graph.size();
        this->graph.assign(size, set<ll>());
        parent.resize(size, 0);
        sub_size.resize(size, 0);
        for (ll i = 0; i < size; i++) {
            for (auto to : graph[i]) {
                this->graph[i].insert(to);
                this->graph[to].insert(i);
            }
        }
        build(1, -1);
    }

    void build(ll curr, ll prev) {
        get_sub_size(curr, prev);
        ll centroid = get_centroid(curr, prev, sub_size[curr]);
        parent[centroid] = prev;
        auto it = graph[centroid].begin();
        while (it != graph[centroid].end()) {
            ll sub = *it;
            graph[sub].erase(centroid);
            it = graph[centroid].erase(it);
            build(sub, centroid);
        }
    }

    void get_sub_size(ll curr, ll prev) {
        sub_size[curr] = 1;
        for (auto sub : graph[curr]) {
            if (prev == sub) continue;
            get_sub_size(sub, curr);
            sub_size[curr] += sub_size[sub];
        }
    }

    ll get_centroid(ll curr, ll prev, ll tree_size) {
        for (auto sub : graph[curr]) {
            if (sub == prev || sub_size[sub] <= tree_size / 2) continue;
            return get_centroid(sub, curr, tree_size);
        }
        return curr;
    }
};
