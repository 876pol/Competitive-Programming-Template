#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Returns x ^ y (x to the power of y)
 *
 * @param x the base.
 * @param y the exponent.
 * @returns x ^ y of `x` and `y`.
 */
ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = res * x;
        y = y >> 1;
        x = x * x;
    }
}

/**
 * Returns x ^ y % p (x to the power of y mod p)
 *
 * @param x the base.
 * @param y the exponent.
 * @param p modulus value.
 * @returns x ^ y % p of `x`, `y`, and `p`.
 */
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