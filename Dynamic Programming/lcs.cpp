#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m;
vector<ll> a, b;
vector<vector<ll>> dp;

void lcs() {
    dp.assign(n + 1, vector<ll>(m + 1));
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}
