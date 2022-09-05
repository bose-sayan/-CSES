//
// Created by Sayan Bose on 05-09-2022.
//

#include<iostream>

using namespace std;

const int mxn = 5005;
int dp[mxn][mxn];

/* dp[i][j] denotes minimum number of operations required
   to convert s1[0..i - 1] to s2[0...j - 1]
*/

void solve() {
    string s, t;
    cin >> s >> t;
    int n = (int) s.length(), m = (int) t.length();
    // base
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // add / remove
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                // replace
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
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