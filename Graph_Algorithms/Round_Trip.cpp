#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Check if there exists a cycle of size >= 3.

const int MXN = 1e5 + 5, INF = 1e9 + 10;

vector<int> G[MXN];
bool vis[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  vector<int> cycle, path;
  function<bool(int, int)> dfs = [&](int src, int par) -> bool {
    if (vis[src]) {
      // found cycle
      cycle.emplace_back(src);
      while (path.back() != src) {
        cycle.emplace_back(path.back());
        path.pop_back();
      }
      cycle.emplace_back(src);
      return true;
    }
    vis[src] = true;
    path.emplace_back(src);
    bool can = false;
    for (auto &des : G[src]) {
      if (des == par)
        continue;
      can |= dfs(des, src);
      if (can)
        break;
    }
    if (!can)
      path.pop_back();
    return can;
  };
  bool can = false;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      can |= dfs(i, -1);
      if (can)
        break;
    }
  }
  if (!can) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << int(cycle.size()) << '\n';
  for (auto &u : cycle) {
    cout << u << ' ';
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