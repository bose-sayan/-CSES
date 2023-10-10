#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MXN = 2e5 + 10;

// For a cycle, the number of moves required for any node in the cycle
// to complete the required objective, will be same, and is equal to the
// length of the cycle.
// For other nodes, the extra moves required will be the number of
// teleportations required to reach any cycle.

int nxt[MXN], dp[MXN];
bool vis[MXN], inStk[MXN];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
    dp[i] = -1;
  }

  // find cycles
  vector<int> path;
  function<void(int)> dfs = [&](int src) {
    if (inStk[src]) {
      vector<int> cycle;
      for (int i = int(path.size()) - 1; path[i] != src; i--) {
        cycle.emplace_back(path[i]);
      }
      cycle.emplace_back(src);
      for (int &i : cycle) {
        dp[i] = int(cycle.size());
      }
      return;
    }
    if (vis[src])
      return;
    vis[src] = inStk[src] = true;
    path.emplace_back(src);
    dfs(nxt[src]);
    inStk[src] = false;
    path.pop_back();
  };
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    dfs(i);
  }
  function<int(int)> dfs2 = [&](int src) {
    if (dp[src] != -1)
      return dp[src];
    return dp[src] = dfs2(nxt[src]) + 1;
  };

  for (int i = 1; i <= n; i++) {
    if (dp[i] != -1)
      continue;
    dfs2(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << ' ';
  }
  cout << '\n';
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