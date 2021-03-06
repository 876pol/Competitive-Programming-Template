#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define MOD 1000000007

vector<ll> fact;

void preprocess(ll n) {
	fact.assign(n + 1, 1);
	for (ll i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
}

ll gcd(ll a, ll b) { 
    return ((b == 0) ? a : gcd(b, a % b)); 
}

ll mod_inverse(ll a) {
    if (gcd(a, MOD) != 1) return -1;
    ll m0 = MOD;
    ll m = MOD;
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

ll ncr(ll n, ll r) {
	return fact[n] * mod_inverse(fact[n - r] * fact[r] % MOD) % MOD;
}