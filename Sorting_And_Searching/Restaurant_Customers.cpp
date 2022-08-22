//
// Created by Sayan Bose on 22-08-2022.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int mxn = 4e5 + 10;
pair<int, int> t[mxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0, j = 0, entry, exit; i < n; i++) {
        cin >> entry >> exit;
        t[j++] = {entry, 1};
        t[j++] = {exit, -1};
    }
    sort(t, t + 2 * n);
    int maxPeople = 0, curPeople = 0;
    for (int i = 0; i < 2 * n; i++) {
        curPeople += t[i].second;
        maxPeople = max(maxPeople, curPeople);
    }
    cout << maxPeople << '\n';
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