#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pi pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vpi vector<pair<int, int>>
#define vpll vector<pair<long long, long long>>

#define FOR(i, s, e) for (long long int i = s; i < e; i++)
#define CFOR(i, s, e) for (long long int i = s; i <= e; i++)
#define RFOR(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define TRAV(a, c) for (auto a : c)
#define ITER(it, cs, ce) for (auto it = cs; it != ce; it++)
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(var) \
    cerr << "ln" << __LINE__ << ": " << #var << " = " << (var) << endl

template <class T>
string to_string(vector<T> &vec) {
    std::ostringstream vts;
    if (!vec.empty()) {
        std::copy(vec.begin(), vec.end() - 1,
                  std::ostream_iterator<int>(vts, ", "));
        vts << vec.back();
    }
    return "[" + vts.str() + "]";
}

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

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
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
#endif
#ifdef GOOGLE
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
#endif
}
