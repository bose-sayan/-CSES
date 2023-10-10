#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// This is similar to the Longest Flight Route problem
// Only difference is that we need to count the no of paths possible

const int MXN = 1e5 + 10, MOD = 1e9 + 7;
vector<int> G[MXN];
bool vis[MXN], inStack[MXN];
int pathCnt[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
  }
  vector<int> order;
  function<void(int)> dfs = [&](int src) -> void {
    if (vis[src])
      return;
    vis[src] = true;
    inStack[src] = true;
    for (auto &des : G[src]) {
      dfs(des);
    }
    order.emplace_back(src);
    inStack[src] = false;
  };
  dfs(1);
  reverse(order.begin(), order.end());

  if (!vis[n]) {
    cout << 0 << '\n';
    return;
  }

  // Process the nodes
  pathCnt[1] = 1;
  for (int &node : order) {
    for (auto &neighbour : G[node]) {
      pathCnt[neighbour] += pathCnt[node];
      pathCnt[neighbour] %= MOD;
    }
  }
  cout << pathCnt[n] << '\n';
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