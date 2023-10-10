#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// This problem is basically checking if the graph is bipartite

const int MXN = 1e5 + 5, INF = 1e9 + 10;

vector<int> G[MXN];
int col[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    col[i] = -1;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  function<bool(int, int)> dfs = [&](int src, int c) -> bool {
    if (col[src] != -1) {
      if (col[src] != c)
        return false;
      return true;
    }
    col[src] = c;
    bool ok = true;
    for (auto &des : G[src]) {
      ok &= dfs(des, !c);
      if (!ok)
        break;
    }
    return ok;
  };
  bool can = true;
  for (int i = 1; i <= n; i++) {
    if (col[i] == -1) {
      can &= dfs(i, 0);
      if (!can)
        break;
    }
  }
  if (!can) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for (int i = 1; i <= n; i++) {
    cout << col[i] + 1 << ' ';
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