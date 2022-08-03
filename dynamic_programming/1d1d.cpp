#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n;
vector<ll> dp;

ll cost(ll i, ll j) {
    // Cost function fulfilling the quadrangle inequality: for all i <= j,
    // cost(i,j) + cost(i + 1, j + 1) <= cost(i + 1, j) + cost(i, j + 1).
    return 0;
}

void _1d1d() {
    dp.assign(n + 1, 0);
    deque<pair<ll, pair<ll, ll>>> dq;
    dq.push_back({1, {1, n}}); // decision point, lower bound, upper bound.
    for (ll i = 1; i <= n; i++) {
        while (dq.front().second.second < i) {
            dq.pop_front();
        }
        dp[i] = cost(dq.front().first, i);
        while (dq.size() && cost(i, dq.back().second.first) <=
                                cost(dq.back().first, dq.back().second.first)) {
            dq.pop_back();
        }
        if (dq.empty()) {
            dq.push_back({i, {i + 1, n}});
        } else {
            ll l = i + 1, r = n, ans = -1;
            while (l <= r) {
                ll m = (l + r) / 2;
                if (cost(i, m) <= cost(dq.back().first, m)) {
                    r = m - 1;
                    ans = m;
                } else {
                    l = m + 1;
                }
            }
            if (ans != -1) {
                dq.back().second.second = ans - 1;
                dq.push_back({i, {ans, n}});
            }
        }
    }
    cout << dp[n] << "\n";
}