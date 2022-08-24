//
// Created by Sayan Bose on 22-08-2022.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int mxn = 2e5 + 10;
int a[mxn], idx[mxn];

void solve() {
    int n, q;
    cin >> n >> q;
    int moves = 0;
    memset(idx, -1, sizeof idx);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        moves += (idx[a[i] - 1] == -1 || idx[a[i] - 1] > i);
        idx[a[i]] = i;
    }
    for (int i = 0, x, y; i < q; i++) {
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        if (a[y] - 1 >= 1)
            moves += (idx[a[y]] > idx[a[y] - 1]) and (idx[a[y] - 1] >= x);
        if (a[y] + 1 <= n)
            moves -= (idx[a[y]] > idx[a[y] + 1]) and (x <= idx[a[y] + 1]);
        if (a[x] + 1 <= n and a[x] + 1 != a[y])
            moves += (idx[a[x]] < idx[a[x] + 1]) and (idx[a[x] + 1] <= y);
        if (a[x] - 1 >= 1 and a[x] - 1 != a[y])
            moves -= (idx[a[x]] < idx[a[x] - 1]) and (idx[a[x] - 1] <= y);
        swap(idx[a[x]], idx[a[y]]);
        swap(a[x], a[y]);
        cout << moves << '\n';
    }
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