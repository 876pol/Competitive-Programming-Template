#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define dbg(...)
#define STRUCT_DBG1(...)
#define STRUCT_DBG2(...)
#define STRUCT_DBG3(...)
#define STRUCT_DBG4(...)
#define STRUCT_DBG5(...)
#define STRUCT_DBG6(...)
#define STRUCT_DBG7(...)
#define STRUCT_DBG8(...)
#else
#include "lib/debug.h"
#endif

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
template <class T>
using vec = vector<T>;
using vll = vector<ll>;
using vpll = vector<pair<ll, ll>>;
using vvll = vector<vector<ll>>;
using vvpll = vector<vector<pair<ll, ll>>>;
template <class T>
using indexed_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e - 1; i >= (ll)s; i--)
#define TRAV(a, c) for (const auto &a : c)
#define all(x) x.begin(), x.end()

#define MOD 1000000007
//#define MOD 998244353

#define FASTIO
#define PRECISION
//#define FILE "file"

#define SINGLE
//#define MULTIPLE
//#define GOOGLE

void solve() {
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
#ifdef PRECISION
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
#endif
#ifdef FILE
    freopen((FILE + string(".in")).c_str(), "r", stdin);
    freopen((FILE + string(".out")).c_str(), "w", stdout);
#endif
#ifdef SINGLE
    solve();
#endif
#ifdef MULTIPLE
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
#endif
#ifdef GOOGLE
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
#endif
}
