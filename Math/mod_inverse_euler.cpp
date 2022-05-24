#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1ll;
        x = (x * x) % p;
    }
    return res;
}

ll mod_inverse(ll a, ll m) {
    return powermod(a, m - 2, m);
}