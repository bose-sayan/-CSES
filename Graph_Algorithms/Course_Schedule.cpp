#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Consider a graph with the courses as vertices and
// the edges as the conditions
// Topological sorting of this graph will give us the required order
// Do check if the graph is a DAG.

const int MXN = 1e5 + 10;
vector<int> G[MXN];
bool vis[MXN], inStack[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
  }
  vector<int> order;
  function<bool(int)> dfs = [&](int src) -> bool {
    if (vis[src])
      return !inStack[src];
    vis[src] = true;
    inStack[src] = true;
    for (auto &des : G[src]) {
      if (!dfs(des))
        return false;
    }
    order.emplace_back(src);
    inStack[src] = false;
    return true;
  };
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    if (!dfs(i)) {
      cout << "IMPOSSIBLE\n";
      return;
    }
  }
  reverse(order.begin(), order.end());
  for (int &v : order) {
    cout << v << ' ';
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