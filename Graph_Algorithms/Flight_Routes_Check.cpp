#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// In a strongly connected component,
// all nodes are reachable from each other
// We can use well known algos such as Kosaraju to
// find all the strongly connected components

const int MXN = 2e5 + 10;
vector<int> G[MXN], GT[MXN];
bool vis[MXN];
int component[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    GT[v].emplace_back(u);
  }
  vector<int> stk;
  function<void(int)> dfs1 = [&](int src) {
    vis[src] = true;
    for (auto &des : G[src]) {
      if (vis[des])
        continue;
      dfs1(des);
    }
    stk.emplace_back(src);
  };
  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    dfs1(i);
  }

  for (int i = 1; i <= n; i++) {
    vis[i] = false;
  }

  int componentId = 0;
  function<void(int)> dfs2 = [&](int src) {
    component[src] = componentId;
    vis[src] = true;
    for (auto &des : GT[src]) {
      if (vis[des])
        continue;
      dfs2(des);
    }
  };

  for (int i = n - 1; i >= 0; i--) {
    if (vis[stk[i]])
      continue;
    componentId++;
    dfs2(stk[i]);
  }

  if (componentId == 1) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";

  for (int i = n - 2; i >= 0; i--) {
    if (component[stk[i]] != component[stk.back()]) {
      cout << stk[i] << ' ' << stk.back() << '\n';
      return;
    }
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