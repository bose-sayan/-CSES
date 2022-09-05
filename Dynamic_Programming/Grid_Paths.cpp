//
// Created by Sayan Bose on 02-09-2022.
//

#include<iostream>

using namespace std;

const int mxn = 1005, mod = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

char mz[mxn][mxn] = {};
int dp[mxn][mxn]; // dp[i][j] -> number of ways to reach (i, j) from (0, 0)

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mz[i][j];
        }
    }
    if (mz[0][0] == '*') {
        cout << 0 << '\n';
        return;
    }
    dp[0][0] = 1; // base
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mz[i][j] == '*')
                continue;
            if (i - 1 >= 0)
                add(dp[i][j], dp[i - 1][j]);
            if (j - 1 >= 0)
                add(dp[i][j], dp[i][j - 1]);
        }
    }
    cout << dp[n - 1][n - 1] << '\n';
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