#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void fastscan(ll &number) {
    bool negative = false;
    ll c;
    number = 0;
    c = getchar();
    if (c == '-') {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
    if (negative) number *= -1;
}