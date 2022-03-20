#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<bool> prime;

void sieve_of_eratosthenes(ll n) {
    prime = vector<bool>(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p])
            for (ll i = p * p; i <= n; i += p) prime[i] = false;
    }
}