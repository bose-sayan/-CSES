//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>

using namespace std;

typedef long long ll;

void solve() {
    int a, b;
    cin >> a >> b;
    if ((2 * b - a) % 3 != 0) {
        cout << "NO\n";
        return;
    }
    int y = (2 * b - a) / 3;
    int x = b - 2 * y;
    cout << (x >= 0 and y >= 0 ? "YES" : "NO") << '\n';
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    while (tests--)
        solve();
    return 0;
}