//
// Created by Sayan Bose on 22-08-2022.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int mxn = 2e5 + 10, inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    long long curSum = -inf, maxSum = -inf;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        curSum = (curSum + x <= x ? x : curSum + x);
        maxSum = max(maxSum, curSum);
    }
    cout << maxSum << '\n';
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