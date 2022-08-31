//
// Created by Sayan Bose on 26-08-2022.
//
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef vector<int> vi;

const int mxn = 2e5 + 10;
vi x[mxn];
bool contains[mxn] = {}, contained[mxn] = {};

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        x[i].resize(3);
        cin >> x[i][0] >> x[i][1];
        x[i][2] = i;
    }
    sort(x, x + n, [](const vi &v1, const vi &v2) -> bool {
        if (v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    });
    // contains
    int mnEndSoFar = 1e9 + 10;
    for (int i = n - 1; i >= 0; i--) {
        if (mnEndSoFar <= x[i][1])
            contains[x[i][2]] = true;
        mnEndSoFar = min(mnEndSoFar, x[i][1]);
    }
    // contained
    int mxEndSoFar = 0;
    for (int i = 0; i < n; i++) {
        if (mxEndSoFar >= x[i][1])
            contained[x[i][2]] = true;
        mxEndSoFar = max(mxEndSoFar, x[i][1]);
    }
    for (int i = 0; i < n; i++)
        cout << contains[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << contained[i] << ' ';
    cout << '\n';
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