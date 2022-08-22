//
// Created by Sayan Bose on 22-08-2022.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int mxn = 2e5 + 10;
int p[mxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p, p + n);
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(p[i] - p[n / 2]);
    }
    cout << cost << '\n';
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