#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct point {
    ll x, y;

    point(ll x, ll y) {
        this->x = x;
        this->y = y;
    }
};

ll dot_product(point p1, point p2) { 
    return p1.x * p2.x + p1.y * p2.y; 
}

ll cross_product(point p1, point p2) { 
    return p1.x * p2.y - p2.x * p1.y; 
}