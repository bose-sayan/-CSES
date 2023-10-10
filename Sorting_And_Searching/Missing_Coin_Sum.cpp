//
// Created by Sayan Bose on 22-08-2022.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int mxn = 2e5 + 10;
int x[mxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x, x + n);
    if (x[0] != 1) {
        cout << 1 << '\n';
        return;
    }
    long long cs = 1;
    for (int i = 1; i < n; i++) {
        if (x[i] > cs + 1) {
            cout << cs + 1 << '\n';
            return;
        }
        cs += x[i];
    }
    cout << cs + 1 << '\n';
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