//
// Created by Sayan Bose on 22-08-2022.
//
#include <iostream>
#include <set>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> mp;
    for (int i = 0, h; i < n; ++i) {
        cin >> h;
        mp.insert(h);
    }
    for (int i = 0, t; i < m; ++i) {
        cin >> t;
        auto it = mp.lower_bound(t);
        if (it == mp.end() || *it > t) {
            if (it == mp.begin()) {
                cout << -1 << '\n';
                continue;
            }
            else
                --it;
        }
        cout << *it << '\n';
        mp.erase(it);
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