#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
template <class K, class R>
using indexed_map =
    tree<K, R, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e - 1; i >= (ll)s; i--)
#define TRAV(a, c) for (auto a : c)
#define all(x) x.begin(), x.end()

#ifndef ONLINE_JUDGE
vector<string> split_args(const string &s) {
    int f = 0, q = 0;
    vector<string> args = {""};
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == ',' && !q && !f) {
            args.push_back("");
            i++;
            continue;
        }
        args.back().push_back(s[i]);
        if (s[i] == '\\') args.back().push_back(s[++i]);
        if (s[i] == '\"') q = !q;
        if (s[i] == '(' && !q) f++;
        if (s[i] == ')' && !q) f--;
    }
    return args;
}

template <class K, class V>
ostream &operator<<(ostream &out, const pair<K, V> &obj) {
    return out << "(" << obj.first << ", " << obj.second << ")";
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &out, const T &obj) {
    out << '[';
    for (auto it = obj.begin(); it != obj.end(); it++) {
        out << &", "[2 * (it == obj.begin())] << *it;
    }
    return out << ']';
}

#define dbg(...)                                                  \
    [](const auto &...x) {                                        \
        vector<string> vs = split_args(#__VA_ARGS__);             \
        cerr << "LINE " << __LINE__ << ":\n";                     \
        ll ind = 0;                                               \
        ((cerr << "  " << vs[ind++] << " = " << x << endl), ...); \
    }(__VA_ARGS__)

#else
#define dbg(...)
#endif

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
