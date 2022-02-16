#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, x;
vector<ll> a, dp;

void coin() {
    dp.resize(x + 1);
    dp[0] = 1;
    for (ll i = 0; i < x; i++) {
        for (ll j = 0; j < n; j++) {
            if (a[j] + i <= x) {
                dp[a[j] + i] += dp[i];
            }
        }
    }
}