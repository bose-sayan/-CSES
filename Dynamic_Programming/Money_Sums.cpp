//
// Created by Sayan Bose on 06-09-2022.
//
#include<iostream>

using namespace std;

const int mxn = 1e5 + 10;
/*
 * dp[i] denotes if a combination of coins
 * encountered until now with a sum of i is possible or not
 */
bool odp[mxn] = {}, ndp[mxn] = {};
int x[105];

void solve() {
    int n, mx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i], mx += x[i];
    odp[0] = true; // base
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= mx; j++) {
            ndp[j] = odp[j];
            if (ndp[j])
                continue;
            if (j >= x[i])
                ndp[j] |= odp[j - x[i]];
        }
        swap(ndp, odp);
    }
    string res;
    int sz = 0;
    for (int i = 1; i <= mx; i++) {
        if (odp[i]) {
            sz++;
            res += to_string(i);
            res += " ";
        }
    }
    cout << sz << '\n' << res << '\n';
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