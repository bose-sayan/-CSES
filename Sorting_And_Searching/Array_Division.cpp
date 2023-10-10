//
// Created by Sayan Bose on 01-09-2022.
//
#include<iostream>

using namespace std;

typedef long long ll;

const int mxn = 2e5 + 10;
int x[mxn];

void solve() {
    int n, k;
    cin >> n >> k;
    ll low = 0, hi = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        low = max(low, (ll) x[i]);
        hi += x[i];
    }
    auto check = [&](int n, int k, const int x[], ll maxSum) -> bool {
        ll curSum = 0;
        int partitions = 1;
        for (int i = 0; i < n && partitions <= k; i++) {
            if (curSum + x[i] > maxSum) {
                curSum = x[i];
                partitions++;
            } else {
                curSum += x[i];
            }
        }
        return partitions <= k;
    };
    ll ans = -1;
    while (low <= hi) {
        ll mid = low + (hi - low) / 2;
        if (check(n, k, x, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            low = mid + 1;
        }
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