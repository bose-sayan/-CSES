//
// Created by Sayan Bose on 13-09-2022.
//

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mul(int a, int b) {
    long long p = a;
    p *= b;
    p %= mod;
    return (int) p;
}

const int mxn = (1 << 10);
int dp[1005][mxn];
int n, m;

void toBinary(string &res, int num, int digits) {
    while (num) {
        res += ((num & 1) ? '1' : '0');
        num >>= 1;
    }
    while (res.length() != digits)
        res += '0';
    reverse(res.begin(), res.end());
}

bool canTransition(int from, int to) {
    // check if it is possible to reach state "to" from state "from"
    string binFrom, binTo;
    toBinary(binFrom, from, n);
    toBinary(binTo, to, n);
    for (int i = 0; i < n; i++) {
        if (binTo[i] == '1' and binFrom[i] == '1') {
            if (i + 1 < n and (binFrom[i + 1] == '1' and binTo[i + 1] == '1')) {
                ++i;
            } else
                return false;
        } else if (binTo[i] == '0' and binFrom[i] == '0')
            return false;
    }
    return true;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> transitions(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            if (canTransition(j, i))
                transitions[i].emplace_back(j);
        }
    }
    /*
     * Print transitions:
        for (int i = 0; i < (1 << n); i++) {
            cout << i << "-> ";
            for (auto &j: transitions[i])
                cout << j << ' ';
            cout << '\n';
        }
     */
    dp[0][(1 << n) - 1] = 1; // base
    for (int c = 1; c <= m; c++) {
        for (int s = 0; s < (1 << n); s++) {
            dp[c][s] = 0;
            for (auto &t: transitions[s]) {
                dp[c][s] = add(dp[c][s], dp[c - 1][t]);
            }
        }
    }
    cout << dp[m][(1 << n) - 1] << '\n';
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