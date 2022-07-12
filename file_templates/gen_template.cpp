#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
template <class T>
using vec = vector<T>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vpll = vector<pair<ll, ll>>;

#define FOR(i, s, e) for (ll i = (ll)s; i < (ll)e; i++)
#define CFOR(i, s, e) for (ll i = (ll)s; i <= (ll)e; i++)
#define RFOR(i, e, s) for (ll i = (ll)e - 1; i >= (ll)s; i--)
#define TRAV(a, c) for (auto a : c)
#define PB push_back
#define all(x) x.begin(), x.end()

ll rnd(ll a, ll b) { return a + rand() % (b - a + 1); }

void generate() {

}

int main() {
    srand(chrono::duration_cast<chrono::milliseconds>(
                             chrono::system_clock::now().time_since_epoch())
                             .count());
    cout << fixed << setprecision(10);
    generate();
}
