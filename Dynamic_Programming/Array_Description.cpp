//
// Created by Sayan Bose on 05-09-2022.
//
#include<iostream>

using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int odp[105] = {}, ndp[105] = {}; // dp[i] denotes number of possible sequences ending with i

void solve() {
    int n, m, x, res = 0;
    cin >> n >> m >> x;
    for (int i = (x ? x : 1); i <= (x ? x : m); i++) {  // base
        odp[i]++;
        if (n == 1)
            res = add(res, odp[i]);
    }
    for (int i = 1; i < n; i++) {
        cin >> x;
        fill(ndp, ndp + (m + 1), 0);
        for (int j = (x ? x : 1); j <= (x ? x : m); j++) {
            ndp[j] = add(add(odp[j - 1], odp[j]), odp[j + 1]);
            if (i == n - 1)
                res = add(res, ndp[j]);
        }
        swap(odp, ndp);
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