//
// Created by Sayan Bose on 05-09-2022.
//
#include<iostream>

using namespace std;

const int mxn = 1e5 + 10;
int odp[mxn] = {}, ndp[mxn] = {}; // dp[i] denotes the maximum pages we can get by spending i units
int cost[1005], pages[1005];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j >= cost[i])
                ndp[j] = max(ndp[j], odp[j - cost[i]] + pages[i]);
        }
        for (int j = 1; j <= x; j++)
            odp[j] = ndp[j];
    }
    cout << odp[x] << '\n';
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