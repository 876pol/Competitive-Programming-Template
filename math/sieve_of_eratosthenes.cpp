#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<bool> prime;

void sieve_of_eratosthenes(ll n) {
    prime = vector<bool>(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (ll i = 4; i <= n; i += 2) prime[i] = false;
    for (ll p = 3; p * p <= n; p += 2) {
        if (prime[p]) {
            for (ll i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
}