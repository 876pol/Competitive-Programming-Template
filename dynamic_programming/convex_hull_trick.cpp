#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct CHT {
    vector<ll> m, b;

    bool bad(ll l1, ll l2, ll l3) {
        return (ld)(b[l3] - b[l1]) * (ld)(m[l1] - m[l2]) >
               (ld)(b[l2] - b[l1]) * (ld)(m[l1] - m[l3]);
    }

    void add(ll slope, ll yint) {
        m.push_back(slope);
        b.push_back(yint);
        ll s = m.size();
        while (s >= 3 && bad(s - 3, s - 2, s - 1)) {
            s--;
            m.erase(m.end() - 2);
            b.erase(b.end() - 2);
        }
    }

    ll f(ll i, ll x) {
        return m[i] * x + b[i];
    }

    ll cost(ll x) {
        ll l = 0, r = m.size() - 2, ans = LLONG_MIN;
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (f(mid, x) > f(mid + 1, x)) {
                r = mid - 1;
                ans = f(mid, x);
            } else {
                l = mid + 1;
            }
        }
        return max(ans, f(m.size() - 1, x));
    }
};