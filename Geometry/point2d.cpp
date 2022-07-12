#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ld long double

struct point2d {
    ll x, y;

    point2d() {}

    point2d(ll x, ll y) {
        this->x = x;
        this->y = y;
    }

    point2d& operator+=(const point2d &t) {
        x += t.x;
        y += t.y;
        return *this;
    }

    point2d& operator-=(const point2d &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }

    point2d& operator*=(ftype t) {
        x *= t;
        y *= t;
        return *this;
    }

    point2d& operator/=(ftype t) {
        x /= t;
        y /= t;
        return *this;
    }

    point2d operator+(const point2d &t) const {
        return point2d(*this) += t;
    }

    point2d operator-(const point2d &t) const {
        return point2d(*this) -= t;
    }

    point2d operator*(ftype t) const {
        return point2d(*this) *= t;
    }
    
    point2d operator/(ftype t) const {
        return point2d(*this) /= t;
    }
};

ll dot(point2d &p1, point2d &p2) { 
    return p1.x * p2.x + p1.y * p2.y; 
}

ll cross(point2d &p1, point2d &p2) { 
    return p1.x * p2.y - p2.x * p1.y; 
}

ll norm(point2d a) {
    return dot(a, a);
}

ld abs(point2d a) {
    return sqrt(norm(a));
}

ld proj(point2d a, point2d b) {
    return dot(a, b) / abs(b);
}

ld angle(point2d a, point2d b) {
    return acos(dot(a, b) / abs(a) / abs(b));
}

point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}