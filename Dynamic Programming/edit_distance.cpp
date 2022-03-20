#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string a, b;
vector<vector<ll>> dp;

void edit_distance() {
    dp.resize(a.size() + 1, vector<ll>(b.size() + 1));
    for (ll i = 0; i <= a.size(); i++) dp[i][0] = i;
    for (ll i = 0; i <= b.size(); i++) dp[0][i] = i;
    for (ll i = 1; i <= a.size(); i++) {
        for (ll j = 1; j <= b.size(); j++) {
            dp[i][j] = min(dp[i - 1][j] + 1,
                           min(dp[i][j - 1] + 1,
                               dp[i - 1][j - 1] + (a[i - 1] != b[j - 1])));
        }
    }
}