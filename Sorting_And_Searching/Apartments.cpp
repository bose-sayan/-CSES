//
// Created by Sayan Bose on 20-08-2022.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int mxn = 200005;
int a[mxn], b[mxn];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

    int cnt = 0;
    for (int ai = 0, bi = 0; ai < n && bi < m;) {
        if (abs(a[ai] - b[bi]) <= k) {
            cnt++;
            ai++;
            bi++;
        } else if (a[ai] < b[bi])
            ai++;
        else
            bi++;
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