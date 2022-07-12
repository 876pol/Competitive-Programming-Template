#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll extended_euclidean(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll mod_inverse(ll a, ll m) {
    ll x, y;
    if (extended_euclidean(a, m, x, y) != 1) {
        return -1;
    }
    return (x % m + m) % m;
}