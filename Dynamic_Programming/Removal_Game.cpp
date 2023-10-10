//
// Created by Sayan Bose on 07-09-2022.
//

#include<iostream>

using namespace std;

typedef long long ll;

const int mxn = 5005;
int x[mxn];
ll dp[mxn][mxn];
/*
 * dp[i][j] denotes:
 *       if turn(1) -> maximum value player 1 can get from the subarray [i, j]
 *       else -> minimum value player 1 can get from the subarray left after current move
 */

const ll unknown = INT64_MAX;

ll recurse(int i, int j, int turn) {
    if (dp[i][j] != unknown)
        return dp[i][j];
    if (i == j) {
        return dp[i][j] = (!turn ? x[i] : 0);
    }
    ll op1 = recurse(i + 1, j, !turn), op2 = recurse(i, j - 1, !turn);
    if (turn) {
        if (op1 > op2)
            return dp[i][j] = op2;
        return dp[i][j] = op1;
    }
    return dp[i][j] = max(op1 + x[i], op2 + x[j]);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        for (int j = 0; j < n; j++)
            dp[i][j] = unknown;
    }
    cout << recurse(0, n - 1, 0) << '\n';
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