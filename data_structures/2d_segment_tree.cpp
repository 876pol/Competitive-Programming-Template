#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <class T>
struct segment_tree_2d {
    ll rows, columns;
    vector<vector<T>> tree;

    segment_tree_2d() {
        rows = 0;
        columns = 0;
    }

    segment_tree_2d(ll rows, ll columns) {
        this->rows = rows;
        this->columns = columns;
        tree.assign(2 * rows, vector<T>(2 * columns));
    }

    segment_tree_2d(vector<vector<T>> &a) {
        this->rows = a.size();
        this->columns = a[0].size();
        tree.assign(2 * rows, vector<T>(2 * columns));
        build_x(a, 1, 0, rows - 1);
    }

    void build_x(vector<vector<T>> &a, ll vx, ll tlx, ll trx) {
        if (tlx != trx) {
            ll tmx = (tlx + trx) / 2;
            build_x(a, vx + 1, tlx, tmx);
            build_x(a, vx + 2 * (tmx - tlx + 1), tmx + 1, trx);
        }
        build_y(a, vx, tlx, trx, 1, 0, columns - 1);
    }

    void build_y(vector<vector<T>> &a, ll vx, ll tlx, ll trx, ll vy, ll tly,
                 ll try_) {
        if (tly == try_) {
            if (tlx == trx) {
                tree[vx][vy] = a[tlx][tly];
            } else {
                ll tmx = (tlx + trx) / 2;
                tree[vx][vy] =
                    tree[vx + 1][vy] + tree[vx + 2 * (tmx - tlx + 1)][vy];
            }
        } else {
            ll tmy = (tly + try_) / 2;
            build_y(a, vx, tlx, trx, vy + 1, tly, tmy);
            build_y(a, vx, tlx, trx, vy + 2 * (tmy - tly + 1), tmy + 1, try_);
            tree[vx][vy] =
                tree[vx][vy + 1] + tree[vx][vy + 2 * (tmy - tly + 1)];
        }
    }

    T query_x(ll vx, ll tlx, ll trx, ll lx, ll rx, ll ly, ll ry) {
        if (lx > rx) return T();
        if (lx == tlx && trx == rx) {
            return query_y(vx, 1, 0, columns - 1, ly, ry);
        }
        ll tmx = (tlx + trx) / 2;
        return query_x(vx + 1, tlx, tmx, lx, min(rx, tmx), ly, ry) +
               query_x(vx + 2 * (tmx - tlx + 1), tmx + 1, trx, max(lx, tmx + 1),
                       rx, ly, ry);
    }

    T query_y(ll vx, ll vy, ll tly, ll try_, ll ly, ll ry) {
        if (ly > ry) return T();
        if (ly == tly && try_ == ry) {
            return tree[vx][vy];
        }
        ll tmy = (tly + try_) / 2;
        return query_y(vx, vy + 1, tly, tmy, ly, min(ry, tmy)) +
               query_y(vx, vy + 2 * (tmy - tly + 1), tmy + 1, try_,
                       max(ly, tmy + 1), ry);
    }

    void update_x(ll vx, ll tlx, ll trx, ll x, ll y, T new_val) {
        if (tlx != trx) {
            ll mx = (tlx + trx) / 2;
            if (x <= mx) {
                update_x(vx + 1, tlx, mx, x, y, new_val);
            } else {
                ll tmx = (tlx + trx) / 2;
                update_x(vx + 2 * (tmx - tlx + 1), mx + 1, trx, x, y, new_val);
            }
        }
        update_y(vx, tlx, trx, 1, 0, columns - 1, x, y, new_val);
    }

    void update_y(ll vx, ll tlx, ll trx, ll vy, ll tly, ll try_, ll x, ll y,
                  T new_val) {
        if (tly == try_) {
            if (tlx == trx) {
                tree[vx][vy] = new_val;
            } else {
                ll tmx = (tlx + trx) / 2;
                tree[vx][vy] =
                    tree[vx + 1][vy] + tree[vx + 2 * (tmx - tlx + 1)][vy];
            }
        } else {
            ll tmy = (tly + try_) / 2;
            if (y <= tmy) {
                update_y(vx, tlx, trx, vy + 1, tly, tmy, x, y, new_val);
            } else {
                update_y(vx, tlx, trx, vy + 2 * (tmy - tly + 1), tmy + 1, try_,
                         x, y, new_val);
            }
            tree[vx][vy] =
                tree[vx][vy + 1] + tree[vx][vy + 2 * (tmy - tly + 1)];
        }
    }
};