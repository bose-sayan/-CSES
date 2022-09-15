//
// Created by Sayan Bose on 15-09-2022.
//
#include<iostream>
#include <cstring>

using namespace std;

const int mxn = 1e6 + 1, mod = 1e9 + 7;

int add(int a, int b) {
    a += b;
    a -= (a >= mod ? mod : 0);
    return a;
}

int mul(long long a, long long b) {
    long long p = a * b;
    p %= mod;
    return int(p);
}

int dp[mxn][2];

// dp[i][0] denotes last row cells are joined
// dp[i][1] denotes last row cells are separate

void preProcess() {
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < mxn; i++) {
        dp[i][0] = add(mul(dp[i - 1][0], 2), dp[i - 1][1]);
        dp[i][1] = add(dp[i - 1][0], mul(dp[i - 1][1], 4));
    }
}

int solve(int n) {
    return add(dp[n][0], dp[n][1]);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    preProcess();
    int T;
    cin >> T;
    for (int i = 0, x; i < T; i++) {
        cin >> x;
        cout << solve(x) << '\n';
    }

    return 0;
}