#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Returns GCD (greatest common divisor)
 *
 * @param a, b one number to find GCD of.
 * @returns GCD of `a` and `b`.
 */
ll gcd(ll a, ll b) { 
    return ((b == 0) ? a : gcd(b, a % b)); 
}

/**
 * Returns LCM (least common multiple)
 *
 * @param a, b one number to find LCM of.
 * @returns LCM of `a` and `b`.
 */
ll lcm(ll a, ll b) { 
    return a / gcd(a, b) * b; 
}