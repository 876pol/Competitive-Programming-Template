#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Performs binary search
 *
 * @param arr sorted array to search through.
 * @param x element to search for.
 * @returns true if element is in array.
 */
bool binary_search(vector<ll> &arr, ll x) {
    ll a = 0, b = arr.size() - 1;
    while (a <= b) {
        ll k = a + (b - a) / 2;
        if (arr[k] == x) {
            return true;
        }
        if (arr[k] > x)
            b = k - 1;
        else
            a = k + 1;
    }
    return false;
}