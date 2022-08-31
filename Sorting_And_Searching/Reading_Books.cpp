//
// Created by Sayan Bose on 31-08-2022.
//
#include<iostream>
#include <algorithm>

using namespace std;

const int mxn = 2e5 + 10;
int t[mxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t, t + n);
    long long curTime = 0;
    for (int i = 0; i < n - 1; i++) {
        curTime += t[i];
    }
    curTime += (curTime < t[n - 1] ? t[n - 1] - curTime : 0);
    curTime += t[n - 1];
    cout << curTime << '\n';
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