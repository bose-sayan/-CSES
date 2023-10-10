//
// Created by Sayan Bose on 15-09-2022.
//
#include<iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int mxn = (1 << 10);

// Global
ll dp[20][mxn][2];
// dp[i][j][0] denotes how many i digit numbers are possible under the given constraint
// dp[i][j][1] denotes how many i digit numbers less than a fixed value are possible under the same constraints
string N;
int sz;

int toInt(char ch) {
    return ch - '0';
}

ll f(int len, int mask = mxn - 1, bool tight = false, bool zero = true) {
    // base
    if (!len)
        return 1;
    if (!mask)
        return 0;
    if (dp[len][mask][tight] != -1)
        return dp[len][mask][tight];

    // recurse
    int bound = 9;
    if (len == sz || tight) {
        bound = toInt(N[sz - len]);
    }
    ll cnt = 0;
    for (int val = 0; val <= bound; val++) {
        if (!(mask & (1 << val)))
            continue;
        int newMask = mxn - 1;
        if (val || !zero) {
            newMask ^= (1 << val);
        }
        bool newTight = false;
        if ((len == sz || tight) and val == bound) {
            newTight = true;
        }
        bool newZero = (zero && (val == 0));
        cnt += f(len - 1, newMask, newTight, newZero);
    }
    return dp[len][mask][tight] = cnt;
}

ll solve(ll x) {
    memset(dp, -1, sizeof dp);
    N = to_string(x);
    sz = (int) N.length();
    return f(sz);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll L, R;
    cin >> L >> R;
    cout << solve(R) - (L - 1 < 0 ? 0 : solve(L - 1)) << '\n';

    return 0;
}