#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = res * x;
        y = y >> 1;
        x = x * x;
    }
}

ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}