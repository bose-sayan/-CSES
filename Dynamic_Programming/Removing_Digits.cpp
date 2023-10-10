//
// Created by Sayan Bose on 02-09-2022.
//

#include<iostream>

using namespace std;

const int mxn = 1e6 + 10, inf = 1e9;


int dp[mxn]; // dp[i] denotes the minimum number of steps req to convert i -> 0

void solve() {
    int n;
    cin >> n;
    dp[0] = 0; // base
    for (int i = 1, num; i <= n; i++) {
        dp[i] = inf;
        num = i;
        while (num) {
            dp[i] = min(dp[i], dp[i - num % 10] + 1);
            num /= 10;
        }
    }
    cout << dp[n] << '\n';
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