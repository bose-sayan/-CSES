#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// In order to have a route between any two cities, the graph needs to be
// connected. Finding out the connected components, and building a road between
// them, makes the graph connected.

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

  function<void(int)> dfs = [&](int src) -> void {
    if (vis[src])
      return;
    vis[src] = true;
    for (auto &i : G[src])
      dfs(i);
  };

  vector<int> components;
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    components.emplace_back(i);
    dfs(i);
  }
  cout << int(components.size()) - 1 << '\n';
  for (int i = 1; i < (int)components.size(); i++) {
    cout << components[i - 1] << ' ' << components[i] << '\n';
  }
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