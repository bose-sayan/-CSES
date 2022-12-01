#include<bits/stdc++.h>
using namespace std;

// Sparse Matrix
const int MXN = 2e5 + 10;
const int MXL = 25; // max number of summands (13 -> 8 + 4 + 1, no. of summands = 3)

int log2_floor(int i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

int dp[MXN][MXL];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> dp[i][0];
    }

    for (int lvl = 1; lvl < MXL; lvl++) {
        for (int i = 0; i + (1 << lvl) - 1 < n; i++) {
            dp[i][lvl] = min(dp[i][lvl - 1], dp[i + (1 << (lvl - 1))][lvl - 1]);
        }
    }

    for (int i = 0, l, r, width; i < q; i++) {
        cin >> l >> r;
        --l, --r;
        width = log2_floor(r - l + 1);
        cout << min(dp[l][width], dp[r - (1 << width) + 1][width]) << '\n';
    }

    return 0;
}