//
// Created by Sayan Bose on 01-09-2022.
//
#include<iostream>
#include <vector>

using namespace std;

const int mxn = 2e5 + 10;
int res[mxn] = {};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> stk;
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        while (!stk.empty() && stk.back().first >= x)
            stk.pop_back();
        if (stk.empty())
            res[i] = 0;
        else
            res[i] = stk.back().second;
        stk.emplace_back(x, i);
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
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