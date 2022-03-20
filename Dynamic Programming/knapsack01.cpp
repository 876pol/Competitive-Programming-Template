#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, w;
vector<ll> dp;
vector<pair<ll, ll>> a;  // weight, value

void knapsack() {
    dp.resize(w + 1);
    for (ll i = 1; i <= n; i++) {
        for (ll j = w; j >= 0; j--) {
            if (j - a[i - 1].first >= 0) {
                dp[j] = max(dp[j], dp[j - a[i - 1].first] + a[i - 1].second);
            }
        }
    }
}