//
// Created by Sayan Bose on 31-08-2022.
//
#include<iostream>
#include <algorithm>

using namespace std;

const int mxn = 2e5 + 10;
pair<int, int> p[mxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n);
    long reward = p[0].second - p[0].first, cur = p[0].first;
    for (int i = 1; i < n; i++) {
        cur += p[i].first;
        reward += p[i].second - cur;
    }
    cout << reward << '\n';
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