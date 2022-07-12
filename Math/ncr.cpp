#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ncr(ll n, ll r) {
    if (r > n - r) r = n - r;
    ll C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]);
    return C[r];
}

ll ncrmodp(ll n, ll r, ll p) {
    if (r > n - r) r = n - r;
    ll C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
    return C[r];
}