#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
vector<ll> a, dp;

void lis() {
    for (ll i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end()) {
            dp.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
}