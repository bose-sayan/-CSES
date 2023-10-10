// DP on SCC
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Global Variables
const int MXN = 1e5 + 10;
vector<int> G[MXN], GT[MXN];
int out[MXN] = {}, outComp[MXN] = {}, col[MXN] = {}, val[MXN];
int n, m, curTime = 1;

// Kosaraju's Algorithm for finding SCCs
void findOutTimeDfs(int src) {
    if (out[src])
        return;
    out[src] = 1;   // mark visited
    for (auto &i : G[src]) {
        findOutTimeDfs(i);
    }
    out[src] = curTime++;
}

void findSCCDfs(int src, int c) {
    if (col[src])
        return;
    col[src] = c;
    outComp[c] = max(outComp[c], out[src]);
    for (auto &i : GT[src]) {
        findSCCDfs(i, c);
    }
}

void kosaraju() {
    for (int i = 0; i < n; i++) {
        if (!out[i])
            findOutTimeDfs(i);
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int u, int v) -> bool { return out[u] > out[v]; });
    for (int i = 0, c = 1; i < n; i++) {
        if (!col[order[i]])
            findSCCDfs(order[i], c++);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v);
        GT[v].emplace_back(u);
    }
    kosaraju();
    int nComp = *max_element(col, col + n);
    vector<ll> dp(nComp + 1);
    vector<vector<int>> comp(nComp + 1);
    for (int i = 0; i < n; i++) {
        dp[col[i]] += val[i];
        comp[col[i]].emplace_back(i);
    }
    vector<int> comps(nComp);
    iota(comps.begin(), comps.end(), 1);
    sort(comps.begin(), comps.end(),
         [&](int c1, int c2) -> bool { return outComp[c1] < outComp[c2]; });
    ll res = dp[comps[0]];
    for (int i = 1; i < nComp; i++) {
        int c = comps[i];
        ll mx = dp[c];
        for (int &u : comp[c]) {
            for (int &v : G[u]) {
                if (col[v] != c) {
                    mx = max(mx, dp[c] + dp[col[v]]);
                }
            }
        }
        dp[c] = max(dp[c], mx);
        res = max(res, dp[c]);
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}