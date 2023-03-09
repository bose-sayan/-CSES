#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// By inverting the scores one gains by going through the tunnels,
// the problem can be reframed as finding the shortest path

// Howeever, if there exists a negative cycle
// and the destination is reachable from any vertex of the cycle,
// we encounter the arbitarily large score problem.

// We can use Bellman Ford for this problem.

const int MXN = 2550;
const ll INF = 1e18;

ll dis[MXN];
vector<tuple<int, int, int>> edges;
vector<int> G[MXN];
bool inCycle[MXN], vis[MXN];

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 2; i <= n; i++) {
    dis[i] = INF;
  }

  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    edges.emplace_back(u, v, -w);
    G[v].emplace_back(u);
  }

  bool any;
  for (int i = 0; i < n; i++) {
    any = false;
    for (auto &e : edges) {
      auto [u, v, w] = e;
      if (dis[u] != INF && dis[v] > max(-INF, dis[u] + w)) {
        dis[v] = max(-INF, dis[u] + w);
        any = true;
        if (i == n - 1) {
          inCycle[u] = inCycle[v] = true;
        }
      }
    }
    if (!any)
      break;
  }

  if (!any) {
    // no negative cycle
    cout << -dis[n] << '\n';
    return;
  }

  function<bool(int)> dfs = [&](int src) -> bool {
    if (vis[src])
      return false;
    if (inCycle[src])
      return true;
    vis[src] = true;
    for (auto &des : G[src]) {
      if (dfs(des))
        return true;
    }
    return false;
  };

  if (dfs(n)) {
    cout << -1 << '\n';
    return;
  }
  cout << -dis[n] << '\n';
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