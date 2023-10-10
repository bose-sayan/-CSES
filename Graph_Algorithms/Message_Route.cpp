#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// BFS can be used to find the shortest path b/w two nodes when the graph is
// unweighted
const int MXN = 1e5 + 5, INF = 1e9 + 10;

vector<int> G[MXN];
int dis[MXN], par[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  for (int i = 1; i <= n; i++) {
    dis[i] = INF;
  }
  dis[1] = 0, par[1] = -1;
  queue<pair<int, int>> q;
  q.push({1, 0});

  while (!q.empty()) {
    auto [src, d] = q.front();
    q.pop();
    if (d > dis[src])
      continue;
    for (auto &des : G[src]) {
      if (dis[des] > d + 1) {
        dis[des] = d + 1;
        par[des] = src;
        q.push({des, d + 1});
      }
    }
  }
  if (dis[n] == INF) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << dis[n] + 1 << '\n';
  vector<int> path;
  while (n != -1) {
    path.emplace_back(n);
    n = par[n];
  }
  reverse(path.begin(), path.end());
  for (auto &city : path) {
    cout << city << ' ';
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