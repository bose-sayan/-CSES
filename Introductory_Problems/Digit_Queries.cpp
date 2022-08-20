//
// Created by Sayan Bose on 19-08-2022.
//
#include<iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll numCount[20]; // Count of numbers with digit length = index

ll ceilDiv(ll a, ll b) {
    return 1 + ((a - 1) / b); // avoid overflow
}

void solve() {
    ll k;
    cin >> k;

    for (ll i = 0, c = 1;; i = i * 10 + 9, c++) {
        if (numCount[c] >= k) {
            ll offset = k - (c - 1 ? numCount[c - 1] : 0);
            i += ceilDiv(offset, c);
            offset -= ((offset - 1) / c) * c;
            string res = to_string(i);
            cout << res[offset - 1] << '\n';
            return;
        }
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

    for (ll i = 9, c = 1; c <= 17; i *= 10, c++) {
        numCount[c] = (i * c) + (c ? numCount[c - 1] : 0);
    }

    int tests;
    cin >> tests;
    while (tests--)
        solve();
    return 0;
}