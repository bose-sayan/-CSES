//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>

using namespace std;


void solve() {
    int n;
    cin >> n;
    long long movesRequired = 0;
    for (int i = 0, last = -1, cur; i < n; i++) {
        cin >> cur;
        movesRequired += (last == -1 ? 0 : max(0, last - cur));
        last = max(last, cur);
    }
    cout << movesRequired << '\n';
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