#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<ll>> matrix, dist;

void floyd_warshall() {
    ll n = matrix.size();
    dist = vector<vector<ll>>(matrix);
    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (dist[i][k] != LLONG_MAX &&
                    dist[k][j] != LLONG_MAX) {
                    dist[i][j] =
                        min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}