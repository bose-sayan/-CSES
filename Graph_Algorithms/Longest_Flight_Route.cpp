#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Since the graph is a DAG
// we can try to process the nodes one by one from the start
// For each node, find which nodes we can visit form there.
// Imagine from node A, we can go to node B
// If the number of nodes visited uptil now, is more than the nodes visited by
// some other path which ends at B, then update the best path from source to B
// to be the one passing through A.

// The order in which the nodes are processed is important
// Topological Sorting gives us the optimal order for processing

const int MXN = 1e5 + 10;
vector<int> G[MXN];
bool vis[MXN], inStack[MXN];
int bestPathCount[MXN], par[MXN];

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
    cout << "IMPOSSIBLE\n";
    return;
  }

  // Process the nodes
  bestPathCount[1] = 1;
  par[1] = -1;
  for (int &node : order) {
    for (auto &neighbour : G[node]) {
      if (bestPathCount[neighbour] < bestPathCount[node] + 1) {
        bestPathCount[neighbour] = bestPathCount[node] + 1;
        par[neighbour] = node;
      }
    }
  }

  vector<int> path;

  for (int cur = n; cur != -1; cur = par[cur])
    path.emplace_back(cur);

  reverse(path.begin(), path.end());

  cout << bestPathCount[n] << '\n';

  for (int &node : path) {
    cout << node << ' ';
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