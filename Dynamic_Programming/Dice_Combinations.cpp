//
// Created by Sayan Bose on 02-09-2022.
//
#include<iostream>

using namespace std;


const int mxn = 1e6 + 10, mod = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int dp[mxn]; // dp[i] denotes the number of ways we can get sum i

void solve() {
    int n;
    cin >> n;
    dp[0] = 1; // base
    for (int i = 1; i <= n; i++) {
        dp[i] = 0;
        for (int val = 1; val <= 6; val++) {
            if (i < val)
                break;
            add(dp[i], dp[i - val]);
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