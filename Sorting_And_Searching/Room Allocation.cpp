//
// Created by Sayan Bose on 26-08-2022.
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int mxn = 2e5 + 10;
vector<int> p[mxn];
int res[mxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p[i].resize(3);
        cin >> p[i][0] >> p[i][1];
        p[i][2] = i;
    }
    sort(p, p + n);
    map<int, vector<int>> rooms; // key-> endTime, val -> rooms
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        auto it = rooms.lower_bound(p[i][0]);
        if (it == rooms.begin()) {
            rooms[p[i][1]].emplace_back(++cnt);
            res[p[i][2]] = cnt;
        } else {
            --it;
            res[p[i][2]] = it->second.back();
            rooms[p[i][1]].emplace_back(it->second.back());
            it->second.pop_back();
            if (it->second.empty())
                rooms.erase(it);
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < n; i++)
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