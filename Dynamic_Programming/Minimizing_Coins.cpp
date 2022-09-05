//
// Created by Sayan Bose on 02-09-2022.
//
#include<iostream>
#include <algorithm>

using namespace std;


const int mxn = 1e6 + 10, inf = 1e9;

int dp[mxn]; // dp[i] denotes the minimum coins required to get value i
int coins[105];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i)
        cin >> coins[i];
    sort(coins, coins + n);
    dp[0] = 0; // base
    for (int i = 1; i <= x; i++) {
        dp[i] = inf;
        for (int j = 0; j < n; j++) {
            if (i < coins[j])
                break;
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    cout << (dp[x] == inf ? -1 : dp[x]) << '\n';
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