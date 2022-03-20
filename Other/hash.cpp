#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

struct chash {
    const uint64_t c = 6283185307179586631ll;
    const int r = 42069;
    ll operator()(ll x)
        const {
        return __builtin_bswap64((x ^ r) * c);
    }
};