//
// Created by Sayan Bose on 01-09-2022.
//
#include<iostream>

using namespace std;

const int mxn = 2e5 + 10;
int a[mxn];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0, j = 0, cs = 0; j < n; j++) {
        cs += a[j];
        while (cs > x) {
            cs -= a[i++];
        }
        cnt += (cs == x);
    }
    cout << cnt << '\n';
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