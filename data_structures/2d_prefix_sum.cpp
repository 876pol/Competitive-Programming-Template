#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct prefix_sum_2d {
    ll n, m;
    vector<vector<ll>> ps;

    prefix_sum_2d(vector<vector<ll>> &a) {
        n = a.size();
        m = a[0].size();
        ps.resize(n + 1, vector<ll>(m + 1));
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                ps[i][j] = ps[i - 1][j] + ps[i][j - 1] + a[i - 1][j - 1] -
                           ps[i - 1][j - 1];
            }
        }
    }

    ll query(ll y1, ll x1, ll y2, ll x2) {
        return ps[y2 + 1][x2 + 1] - ps[y1][x2 + 1] - ps[y2 + 1][x1] +
               ps[y1][x1];
    }
};