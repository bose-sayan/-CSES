//
// Created by Sayan Bose on 24-08-2022.
//
#include <iostream>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    multiset<int> ms;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        auto it = ms.upper_bound(x);
        if (it != ms.end())
            ms.erase(it);
        ms.insert(x);
    }
    cout << (int) ms.size() << '\n';
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