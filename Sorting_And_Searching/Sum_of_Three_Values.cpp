//
// Created by Sayan Bose on 31-08-2022.
//
#include<iostream>
#include <algorithm>

using namespace std;

const int mxn = 2e5 + 10;
pair<int, int> a[mxn];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++) {
        int left = x - a[i].first;
        for (int l = i + 1, r = n - 1; l < r;) {
            int curSum = a[l].first + a[r].first;
            if (curSum == left) {
                cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second << '\n';
                return;
            } else if (curSum < left)
                l++;
            else
                r--;
        }
    }
    cout << "IMPOSSIBLE\n";
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