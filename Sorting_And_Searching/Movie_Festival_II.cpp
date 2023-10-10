//
// Created by Sayan Bose on 01-09-2022.
//
#include<iostream>
#include <algorithm>
#include <set>

using namespace std;

const int mxn = 2e5 + 10;
pair<int, int> t[mxn];


void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> t[i].second >> t[i].first;
    }
    sort(t, t + n);

    int count = 0;
    multiset<int> endTimes;

    for (int i = 0; i < k; i++)
        endTimes.insert(0);

    for (int i = 0, startTime; i < n; ++i) {
        startTime = t[i].second;
        auto it = endTimes.lower_bound(startTime);
        if (it == endTimes.end() || *it > startTime) {
            if (it == endTimes.begin())
                continue;
            --it;
        }
        endTimes.erase(it);
        endTimes.insert(t[i].first);
        count++;
    }
    cout << count << '\n';

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