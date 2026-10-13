/**
 * Problem: 4A - Watermelon
 * Contest: Codeforces Beta Round 4 (Div. 2 Only)
 * Problem Link: https://codeforces.com/problemset/problem/4/A
 * Rating: 800
 * Tags: Math, Brute Force
 *
 * Solution by: Alok Kumar (https://github.com/alok-devforge)
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Fast I/O for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w;
    if (!(cin >> w)) return 0;

    // A valid partition requires two positive even integers (minimum 2 + 2 = 4).
    // Any even integer w >= 4 can always be split into 2 and (w - 2), both of which are even.
    // For w = 2, the only positive split is 1 + 1 (both odd), which is invalid.
    if (w >= 4 && w % 2 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}
