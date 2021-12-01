#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Performs Floyd-Warshall's algorithm
 *
 * @param matrix adjacency matrix representation of a graph.
 * @returns a distance matrix.
 */
vector<vector<ll>> floyd_warshall(vector<vector<ll>> &matrix) {
    ll n = matrix.size();
    vector<vector<ll>> distance(matrix);
    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                if (distance[i][k] != LLONG_MAX &&
                    distance[k][j] != LLONG_MAX) {
                    distance[i][j] =
                        min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }
    return distance;
}