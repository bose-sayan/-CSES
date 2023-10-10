#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Let f(x, 0) be the max matching when x is not an endpoint to any of the edges
// selected. Let f(x, 1) be the max matching when x is an endpoint to some edge
// which is selected. A simple recurring relation for the problem will be:
// f(x, 0) = sum(max(f(y, 0), f(y, 1))) for all y which is a child of x
// f(x, 1) = max(1 + f(y, 0) + sum (max(f(z, 0), f(z, 1))) for all z which is a
// child of x and != y ) for all y which is a child of x

const int MXN = 2e5 + 10;
vector<int> G[MXN];
bool vis[MXN] = {};
int dp[MXN][2];

void solve() {
  int n;
  cin >> n;
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  int mxMatch = 0;
  function<void(int, int)> dfs = [&](int src, int par) {
    for (auto &des : G[src]) {
      if (des == par)
        continue;
      dfs(des, src);
      dp[src][0] += max(dp[des][0], dp[des][1]);
    }

    for (auto &des : G[src]) {
      if (des == par)
        continue;
      dp[src][1] = max(dp[src][1], 1 + dp[des][0] + dp[src][0] -
                                       max(dp[des][0], dp[des][1]));
    }

    mxMatch = max({mxMatch, dp[src][0], dp[src][1]});
  };

  dfs(1, -1);

  cout << mxMatch << '\n';
}

int main() {

#ifdef LOCAL
  (void)!freopen("in.txt", "r", stdin);
  (void)!freopen("out.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();

  return 0;
}