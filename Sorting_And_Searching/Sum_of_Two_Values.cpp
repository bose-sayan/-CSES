//
// Created by Sayan Bose on 22-08-2022.
//
#include <iostream>
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
    for (int i = 0, j = n - 1, sum; i < j;) {
        sum = a[i].first + a[j].first;
        if (sum == x) {
            cout << a[i].second << ' ' << a[j].second << '\n';
            return;
        } else if (sum < x)
            i++;
        else
            j--;
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