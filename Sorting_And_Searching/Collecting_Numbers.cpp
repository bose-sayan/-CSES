//
// Created by Sayan Bose on 22-08-2022.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int mxn = 2e5 + 10;
bool f[mxn] = {};

void solve() {
    int n;
    cin >> n;
    int moves = 0;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        moves += !(f[x - 1]);
        f[x] = true;
    }
    cout << moves << '\n';
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}