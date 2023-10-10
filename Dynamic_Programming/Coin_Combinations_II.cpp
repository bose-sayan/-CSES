//
// Created by Sayan Bose on 02-09-2022.
//
#include<iostream>
#include <algorithm>

using namespace std;

const int mxn = 1e6 + 10, mod = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int dp[mxn] = {}; // dp[i] denotes the number of ways to get value i
int coins[105];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> coins[i];
    dp[0] = 1; // base
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= x; i++)
            if (i >= coins[j])
                add(dp[i], dp[i - coins[j]]);
    }
    cout << dp[x] << '\n';
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