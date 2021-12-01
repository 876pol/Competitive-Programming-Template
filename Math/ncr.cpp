#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Returns nCr (n choose r)
 *
 * @param n first number of nCr.
 * @param r second number of nCr.
 * @returns nCr of `n` and `r`.
 */
ll ncr(ll n, ll r) {
    if (r > n - r) r = n - r;
    ll C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]);
    return C[r];
}

/**
 * Returns nCr % p (n choose r mod p)
 *
 * @param n first number of nCr.
 * @param r second number of nCr.
 * @param p modulus value.
 * @returns nCr mod p of `n`, `r`, and `p`.
 */
ll ncrmodp(ll n, ll r, ll p) {
    if (r > n - r) r = n - r;
    ll C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
    return C[r];
}