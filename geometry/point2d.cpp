#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

template <class F>
struct point {
    F x, y;

    point() : x(0), y(0) {
    }

    point(const F& x, const F& y) : x(x), y(y) {
    }

    point& operator-() {
        return {-x, -y};
    }

    point& operator+(const point<F>& other) {
        return {x + other.x, y + other.y};
    }

    point& operator-(const point<F>& other) {
        return {x - other.x, y - other.y};
    }

    point& operator*(const F other) {
        return {x * other, y * other};
    }

    point& operator/(const F other) {
        return {x / other.x, y / other.x};
    }

    F operator*(const point<F>& other) {
        return x * other.x + y * other.y;
    }

    F operator^(const point<F>& other) {
        return x * other.y - y * other.x;
    }

    point& operator+=(const point<F>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    point& operator-=(const point<F>& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    point& operator*=(const F& factor) {
        x *= factor;
        y *= factor;
        return *this;
    }

    point& operator/=(const F& factor) {
        x /= factor;
        y /= factor;
        return *this;
    }

    bool operator==(const point<F>& other) {
        return x == other.x && y == other.y;
    }

    bool operator!=(const point<F>& other) {
        return x != other.x || y != other.y;
    }
};

template <class F>
ld angle(const point<F> &p) {
    return atan2(p.y, p.x);
}

template <class F>
ld angle(const point<F> &lhs, const point<F> &rhs) {
    return atan2(lhs ^ rhs, lhs * rhs);
}

template <class F>
ld angle(const point<F>& lhs, const point<F>& rhs, const point<F>& origin) {
    return angle(lhs - origin, rhs - origin);
}

template <class F1, class F2>
point<ld> rotate(const point<F1>& p, const F2& angle) {
    ld angleSin = sin(angle);
    ld angleCos = cos(angle);
    return point<ld>(angleCos * p.x - angleSin * p.y,
                     angleSin * p.x + angleCos * p.y);
}

template <class F1, class F2>
point<F1> rotate(const point<F1>& p, const F2& angle, const point<F1>& origin) {
    return origin + rotate(p - origin, p);
}

template <class F>
point<F> perp(const point<F> &p) {
    return point<F>(-p.y, p.x);
}

template <class F>
F abs(const point<F> &p) {
    return p * p;
}

template <class F>
ld norm(const point<F> &p) {
    return sqrt(abs(p));
}

template <class F>
ld dist(const point<F> &lhs, const point<F> &rhs) {
    return norm(lhs - rhs);
}

template <class F>
F dist2(const point<F>& lhs, const point<F>& rhs) {
    return abs(lhs - rhs);
}
