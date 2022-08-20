//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>

using namespace std;

typedef long long ll;

void solve() {
    int row, col;
    cin >> row >> col;
    int diagonal = max(row, col);
    ll diagonal_val = ll(diagonal) * ll(diagonal) - (diagonal - 1);
    ll res = diagonal_val;
    if (row > col) {
        res += ll((row & 1) ? col - row : row - col);
    } else {
        res += ll((col & 1) ? col - row : row - col);
    }
    cout << res << '\n';
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--)
        solve();
    return 0;
}