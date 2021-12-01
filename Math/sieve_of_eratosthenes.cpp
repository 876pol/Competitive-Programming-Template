#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Generates all primes numbers up to integer
 *
 * @param n runs sieve up to integer n.
 * @returns a boolean array where the value at index `i` is `true` if the number
 * is prime.
 */
void sieve_of_eratosthenes(ll n, vector<bool> &prime) {
    prime = vector<bool>(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (ll p = 2; p * p <= n; p++) {
        if (prime[p])
            for (ll i = p * p; i <= n; i += p) prime[i] = false;
    }
}