//
// Created by Sayan Bose on 22-08-2022.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int mxn = 2e5 + 10;
pair<int, int> t[mxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t[i].second >> t[i].first;
    }
    sort(t, t + n);
    int watchCount = 0;
    for (int i = 0, lastWatched = -1; i < n; i++) {
        if (t[i].second >= lastWatched) {
            watchCount++;
            lastWatched = t[i].first;
        }
    }
    cout << watchCount << '\n';
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