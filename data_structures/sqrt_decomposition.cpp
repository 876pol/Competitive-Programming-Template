#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct sqrt_decomposition {
    ll n, s;
    vector<ll> a, b;

    sqrt_decomposition(vector<ll> &arr) {
        n = arr.size();
        s = sqrt(n) + 1;
        a.resize(n);
        b.resize(s);
        for (ll i = 0; i < n; i++) {
            a[i] = arr[i];
            b[i / s] += arr[i];
        }
    }

    ll query(ll l, ll r) {
        ll ans = 0;
        ll cl = l / s, cr = r / s;
        if (cl == cr) {
            for (ll i = l; i <= r; i++) ans += a[i];
        } else {
            for (ll i = l, end = (cl + 1) * s - 1; i <= end; i++) ans += a[i];
            for (ll i = cl + 1; i <= cr - 1; i++) ans += b[i];
            for (ll i = cr * s; i <= r; i++) ans += a[i];
        }
        return ans;
    }

    void update(ll idx, ll val) {
        a[idx] = val;
        ll bi = idx / s;
        b[bi] = 0;
        for (ll i = idx / s * s; i < (idx / s + 1) * s; i++) {
            b[bi] += a[i];
        }
    }
};