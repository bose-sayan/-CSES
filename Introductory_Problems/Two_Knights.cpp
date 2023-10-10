//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll total_ways, illegal_ways = 0;
    cout << 0 << '\n';
    for (int i = 2; i <= n; i++) {
        total_ways = ll(i * i) * ll(i * i - 1);
        illegal_ways += ll(16 * (i - 2));
        cout << (total_ways - illegal_ways) / 2ll << '\n';
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