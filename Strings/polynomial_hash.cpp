#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll compute_hash(string const& s) {
    const ll p = 31;
    const ll m = 1e9 + 7;
    ll hash_value = 0;
    ll p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}