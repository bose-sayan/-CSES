//
// Created by Sayan Bose on 10-09-2022.
//

#include<iostream>
#include <vector>

using namespace std;

const int mxn = 2e5 + 10;
int dp[mxn];
// dp[i] contains the minimum last element for a subsequence of length i

void solve() {
    int n, res = 0;
    cin >> n;
    for (int i = 0, id = 0, x; i < n; ++i) {
        cin >> x;
        if (!id) {
            res++;
            dp[id++] = x;
            continue;
        }
        auto it = lower_bound(dp, dp + id, x) - dp;
        if (it == id) {
            res++;
            dp[id++] = x;
        } else {
            dp[it] = min(dp[it], x);
        }
    }
    cout << res << '\n';
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