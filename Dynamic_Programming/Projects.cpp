//
// Created by Sayan Bose on 13-09-2022.
//

#include<iostream>
#include <algorithm>
#include <vector>

#define len(x) (int) (x).size()

using namespace std;

typedef long long ll;

struct project {
    int start, end, profit;

    bool operator<(const project p) const {
        if (end == p.end)
            return start < p.start;
        return end < p.end;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<project> projects(n);
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].profit;
    }
    sort(projects.begin(), projects.end());
    vector<int> endTime;
    vector<ll> dp; // dp[i] denotes the maximum profit we can get in i days

    for (auto &p: projects) {
        auto idx = lower_bound(endTime.begin(), endTime.end(), p.start) - endTime.begin();
        if (idx == len(endTime) || endTime[idx] >= p.start) {
            if (idx == 0) {
                if (!endTime.empty() and endTime.back() == p.end)
                    dp.back() = max(dp.back(), (ll) p.profit);
                else {
                    endTime.emplace_back(p.end);
                    dp.emplace_back(max(!dp.empty() ? dp.back() : 0, (ll) p.profit));
                }
                continue;
            }
            --idx;
        }
        if (p.end == endTime.back())
            dp.back() = max(dp.back(), dp[idx] + p.profit);
        else {
            endTime.emplace_back(p.end);
            dp.emplace_back(max(dp.back(), dp[idx] + p.profit));
        }
    }
    ll res = 0;
    for (auto &i: dp)
        res = max(res, i);
    cout << res << '\n';
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