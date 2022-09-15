//
// Created by Sayan Bose on 13-09-2022.
//

#include<iostream>

using namespace std;

const int mxn = (1 << 20);
int rides[mxn], lastWeight[mxn];
/*
 * rides[i] denotes the minimum number of rides for a subset of i peeps
 * lastWeight[i] denotes the total weight of the last ride
 */
int n, x;
int w[25];

void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    rides[0] = 1, lastWeight[0] = 0;
    for (int s = 1; s < (1 << n); s++) {
        rides[s] = n + 1; // worst case
        lastWeight[s] = 0;  // worst case
        for (int p = 0; p < n; p++) {
            if (s & (1 << p)) {
                // p is present in s
                int mask = s ^ (1 << p); // remove p from s
                int r = rides[mask], wgt = lastWeight[mask];
                if (wgt + w[p] <= x) {
                    // can include in the same ride
                    wgt += w[p];
                } else {
                    // new ride for p
                    ++r;
                    wgt = w[p];
                }
                if (r < rides[s] || (r == rides[s] and lastWeight[s] > wgt)) {
                    rides[s] = r, lastWeight[s] = wgt;
                }
            }
        }
    }
    cout << rides[(1 << n) - 1] << '\n';
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