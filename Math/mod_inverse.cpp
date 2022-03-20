#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b) { 
    return ((b == 0) ? a : gcd(b, a % b)); 
}

ll mod_inverse(ll a, ll m) {
    if (gcd(a, m) != 1) return -1;
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}