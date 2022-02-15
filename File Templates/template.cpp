#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define vec vector
#define indexed_set                                          \
    tree<ll, null_type, less<ll>, rb_tree_tag, \
         tree_order_statistics_node_update>

#define FOR(i, s, e) for (ll i = s; i < e; i++)
#define CFOR(i, s, e) for (ll i = s; i <= e; i++)
#define RFOR(i, e, s) for (ll i = e - 1; i >= s; i--)
#define TRAV(a, c) for (auto a : c)
#define PB push_back
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << "ln" << __LINE__ << ": " << #x << " = " << x << endl
mt19937_64 rng(100);

template <class T>
string to_string(vector<T> &vec) {
    std::ostringstream vts;
    if (!vec.empty()) {
        std::copy(vec.begin(), vec.end() - 1,
                  std::ostream_iterator<T>(vts, ", "));
        vts << vec.back();
    }
    return "[" + vts.str() + "]";
}

#define MOD 1000000007

#define FASTIO ;
#define PRECISION ;
//#define FILE ;

#define SINGLE ;
//#define MULTIPLE ;
//#define GOOGLE ;

void solve() {}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
#ifdef PRECISION
    cout << fixed << setprecision(10);
#endif
#ifdef FILE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
