//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>

using namespace std;

typedef long long ll;

int apples[25];
ll totalSum = 0;

ll findMinWeightDiff(int n, ll curIdx = 0, ll curSum = 0) {
    if (curIdx == n) {
        return abs(2 * curSum - totalSum);
    }
    // don't take
    ll minDiff = findMinWeightDiff(n, curIdx + 1, curSum);
    // take
    minDiff = min(minDiff, findMinWeightDiff(n, curIdx + 1, curSum + apples[curIdx]));
    return minDiff;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> apples[i];
        totalSum += (ll) apples[i];
    }
    cout << findMinWeightDiff(n) << '\n';
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    int tests;
//    cin >> tests;
//    while (tests--)
    solve();
    return 0;
}