//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>
#include <algorithm>

using namespace std;

void solveTOH(int disksLeft, int source = 1, int helper = 2, int destination = 3) {
    if (disksLeft == 1) {
        // base
        cout << source << ' ' << destination << '\n';
        return;
    }
    solveTOH(disksLeft - 1, source, destination, helper);
    cout << source << ' ' << destination << '\n';
    solveTOH(disksLeft - 1, helper, source, destination);
}

void solve() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    solveTOH(n);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    int tests;
//    cin >> tests;
//    while (tests--)
    solve();
    return 0;
}