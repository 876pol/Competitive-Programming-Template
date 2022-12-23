#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr pair<ll, ll> inv_gcd(ll a, ll b) {
    a %= b;
    if (a < b) a += b;
    if (a == 0) return {b, 0};
    ll s = b, t = a;
    ll m0 = 0, m1 = 1;
    while (t) {
        ll u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {s, m0};
}

template <int m>
struct static_modint {
    using mint = static_modint;

   public:
    static constexpr int mod() {
        return m;
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {
    }

    template <class T>
    static_modint(T v) {
        ll x = (ll)(v % (ll)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }

    unsigned int val() const {
        return _v;
    }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        ll z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) {
        return *this = *this * rhs.inv();
    }

    mint operator+() const {
        return *this;
    }
    mint operator-() const {
        return mint() - *this;
    }

    mint pow(ll n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = inv_gcd(_v, m);
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }
    friend istream &operator>>(istream& lhs, mint& rhs) {
        ll value;
        lhs >> value;
        rhs = mint(value);
        return lhs;
    }
    friend ostream &operator<<(ostream& lhs, mint& rhs) {
        return cout << rhs.val();
    }

   private:
    unsigned int _v;
    static constexpr unsigned int umod() {
        return m;
    }
};