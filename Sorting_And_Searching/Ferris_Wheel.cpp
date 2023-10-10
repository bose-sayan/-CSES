//
// Created by Sayan Bose on 20-08-2022.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int mxn = 200005;
int p[mxn];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p, p + n);
    int l = 0, r = n - 1, cnt = 0;
    while (l <= r) {
        cnt++;
        if (p[r--] + p[l] <= x)
            l++;
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