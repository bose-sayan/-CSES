//
// Created by Sayan Bose on 01-09-2022.
//
#include<iostream>
#include <set>

using namespace std;

typedef long long ll;

const int mxn = 2e5 + 10;
int x[mxn];


void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    ll maxSum = INT64_MIN, curSum = 0, outerSum = 0, left = 0;

    multiset<ll, greater<>> extra;

    for (int i = 0; i < a; i++) {
        curSum += x[i];
    }

    for (int i = a; i < b; i++) {
        outerSum += x[i];
        extra.insert(outerSum);
    }

    maxSum = max(maxSum, curSum + (*extra.begin() > 0 ? *extra.begin() : 0));

    if (a == b) {
        for (int i = 0, j = a; j < n; j++) {
            curSum -= x[i++];
            curSum += x[j];
            maxSum = max(maxSum, curSum);
        }
        cout << maxSum << '\n';
        return;
    }

    for (int i = 0, j = a; j < n; j++) {
        if (i + b < n) {
            outerSum += x[i + b];
            extra.insert(outerSum);
        }
        curSum -= x[i++];
        curSum += x[j];
        left += x[j];
        auto it = extra.find(left);
        if (it != extra.end())
            extra.erase(it);
        maxSum = max(maxSum, curSum + (*extra.begin() - left > 0 ? *extra.begin() - left : 0));
    }
    cout << maxSum << '\n';
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