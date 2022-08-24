//
// Created by Sayan Bose on 24-08-2022.
//
#include <iostream>
#include <set>

using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;
    set<int> positions;
    multiset<int, greater<>> passageLengths; // no light passages
    positions.insert(0);
    positions.insert(x);
    passageLengths.insert(x);
    for (int i = 0, p, l, r; i < n; i++) {
        cin >> p;
        auto it = positions.lower_bound(p);
        if (*it > p)
            it--;
        l = *it, r = *(++it);
        passageLengths.erase(passageLengths.find(r - l));
        passageLengths.insert(r - p);
        passageLengths.insert(p - l);
        positions.insert(p);
        cout << *passageLengths.begin() << ' ';
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