#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Detecting cycles in a directed graph can be done using simple DFS
// with some data structure to identify which node is an ancestor.

const int MXN = 1e5 + 10;
const ll INF = 1e18;
vector<int> G[MXN];
bool vis[MXN], inStack[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
  }
  vector<int> path, cycle;
  function<bool(int)> dfs = [&](int src) -> bool {
    if (vis[src]) {
      if (!inStack[src]) {
        return false;
      }
      // found cycle
      cycle.emplace_back(src);
      for (int i = int(path.size()) - 1; path[i] != src; i--) {
        cycle.emplace_back(path[i]);
      }
      cycle.emplace_back(src);
      reverse(cycle.begin(), cycle.end());
      return true;
    }
    vis[src] = inStack[src] = true;
    path.emplace_back(src);
    for (auto &des : G[src]) {
      if (dfs(des))
        return true;
    }
    inStack[src] = false;
    path.pop_back();
    return false;
  };
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    if (dfs(i)) {
      cout << int(cycle.size()) << '\n';
      for (auto &v : cycle) {
        cout << v << ' ';
      }
      return;
    }
  }
  cout << "IMPOSSIBLE\n";
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