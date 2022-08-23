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

struct ncr {
    vector<ll> fact;

    ncr() {
    }

    ncr(ll n) {
        fact.assign(n + 1, 1);
        for (ll i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= MOD;
        }
    }

    ll _ncr(ll n, ll r) {
        return fact[n] * mod_inverse(fact[n - r] * fact[r] % MOD, MOD) % MOD;
    }
};

struct polynomial_hash {
    ll size, P = 31;
    vector<ll> p_pow, hash_value;
    ncr _ncr;

    polynomial_hash(const string& s) {
        size = s.size();
        p_pow.assign(size + 1, 0);
        p_pow[0] = 1;
        hash_value.assign(size + 1, 0);
        _ncr = ncr(size + 1);
        for (ll i = 0; i < size; i++) {
            hash_value[i + 1] =
                (hash_value[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
            p_pow[i + 1] = (p_pow[i] * P) % MOD;
        }
    }

    ll get_hash(ll l, ll r) {
        return (hash_value[r] - hash_value[l] + MOD) * mod_inverse(p_pow[l + 1], MOD) % MOD;
    }
};