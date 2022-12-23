#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct KMP {
    string hs, nd;
    vector<ll> lps, indicies;

    KMP(const string &s, const string &t) {
        hs = s;
        nd = t;
        build_lps();
        kmp();
    }

    void build_lps() {
        lps.assign(nd.size() + 1, 0);
        ll j = 0;
        for (ll i = 1; i < nd.size(); i++) {
            while (j >= 0 && nd[i] != nd[j]) {
                if (j >= 1) {
                    j = lps[j - 1];
                } else {
                    j = -1;
                }
            }
            j++;
            lps[i] = j;
        }
    }

    void kmp() {
        ll j = 0;
        for (ll i = 0; i < hs.size(); i++) {
            while (j >= 0 && nd[j] != hs[i]) {
                if (j >= 1) {
                    j = lps[j - 1];
                } else {
                    j = -1;
                }
            }
            j++;
            if (j == nd.size()) {
                j = lps[j - 1];
                indicies.push_back(i - nd.size() + 1);
            }
        }
    }
};
