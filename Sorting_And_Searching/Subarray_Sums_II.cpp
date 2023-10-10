//
// Created by Sayan Bose on 01-09-2022.
//
#include<iostream>
#include <map>

using namespace std;

typedef long long ll;

const int mxn = 2e5 + 10;

void solve() {
    int n, x;
    cin >> n >> x;
    ll cSum = 0, cnt = 0;
    map<ll, int> pref;
    pref[0] = 1;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        cSum += a;
        cnt += pref[cSum - x];
        pref[cSum]++;
    }
    cout << cnt << '\n';
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