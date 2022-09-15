//
// Created by Sayan Bose on 10-09-2022.
//

#include<iostream>

using namespace std;

const int mxn = 1e5 + 10, mod = 1e9 + 7;
int odp[mxn] = {}, ndp[mxn] = {}; // dp[i] denotes the number of ways we can obtain subsets with sum i

void add(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

void solve() {
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum & 1) {
        cout << 0 << '\n';
        return;
    }
    sum /= 2;
    odp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            ndp[j] = odp[j];
            if (j >= i)
                add(ndp[j], odp[j - i]);
        }
        swap(ndp, odp);
    }
    cout << ndp[sum] << '\n';
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