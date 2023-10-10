//
// Created by Sayan Bose on 05-09-2022.
//

#include<iostream>

using namespace std;

const int inf = 1e9;
int dp[505][505]; // dp[i][j] denotes the minimum number of moves to break rect(i, j) into squares

void solve() {
    int n, m;
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    for (int i = 1; i <= m; i++)
        dp[i][i] = 0; // base
    for (int i = 1, r1, c1, r2, c2; i <= n; i++) {
        for (int j = i + 1; j <= m; j++) {
            dp[i][j] = inf;
            // row divide
            for (int k = 1; k <= i / 2; k++) {
                r1 = min(k, j), r2 = min(i - k, j), c1 = max(k, j), c2 = max(i - k, j);
                dp[i][j] = min(dp[i][j], dp[r1][c1] + dp[r2][c2] + 1);
            }
            // col divide
            for (int k = 1; k <= j / 2; k++) {
                r1 = min(i, k), r2 = min(i, j - k), c1 = max(i, k), c2 = max(i, j - k);
                dp[i][j] = min(dp[i][j], dp[r1][c1] + dp[r2][c2] + 1);
            }
        }
    }
    cout << dp[n][m] << '\n';
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