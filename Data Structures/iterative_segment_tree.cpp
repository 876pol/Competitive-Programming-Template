#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct segment_tree {
    ll n;
    vector<ll> tree;

    segment_tree(vector<ll> &arr) {
        n = arr.size();
        tree.resize(2 * n);
        if (!n) return;
        copy(arr.begin(), arr.end(), tree.begin() + n);
        for (ll i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(ll index, ll value) {
        tree[index += n] = value;
        for (; index > 1; index >>= 1)
            tree[index >> 1] = tree[index] + tree[index ^ 1];
    }

    ll query(ll l, ll r) {
        ll ans = tree[l + n];
        l++;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if ((l & 1) != 0) ans += tree[l++];
            if ((r & 1) != 0) ans += tree[--r];
        }
        return ans;
    }
};