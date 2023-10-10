//
// Created by Sayan Bose on 26-08-2022.
//
#include<iostream>

using namespace std;

typedef long long ll;

const int mxn = 2e5 + 10;
int k[mxn];

void solve() {
    int n, t;
    cin >> n >> t;
    ll l = 1e9 + 10, h = 0, ans;
    for (int i = 0; i < n; ++i) {
        cin >> k[i];
        l = min(l, (ll) k[i]);
        h = max(h, (ll) k[i]);
    }
    h *= ll(t);
    auto check = [](ll mid, const int k[], int n, ll t) -> bool {
        for (int i = 0; i < n; i++) {
            t = max(0ll, t - mid / k[i]);
            if (!t)
                return true;
        }
        return false;
    };
    while (l <= h) {
        ll mid = l + (h - l) / 2ll;
        if (check(mid, k, n, t))
            ans = mid, h = mid - 1;
        else
            l = mid + 1;
    }
    cout << ans << '\n';
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