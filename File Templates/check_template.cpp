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

#define PI 3.1415926535897932384626433832795

ifstream answer("out/answer", ifstream::in);
ifstream correct_answer("out/correct_answer", ifstream::in);

int main() {
    while (answer && correct_answer) {
        string a, b;
        answer >> a;
        correct_answer >> b;
        if (a != b) {
            cout << "WA\n";
            return -1;
        }
    }
    if (answer || correct_answer) {
        cout << "WA\n";
        return -1;
    }
    return 0;
}
