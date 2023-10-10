#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// The diameter is the longest path between nodes, so the nodes are leaves
// Running DFS once finds one of the leaf node
// Running it again with the leaf node as root, gives us the max path length

const int MXN = 2e5 + 10;
vector<int> G[MXN];

void solve() {
  int n;
  cin >> n;
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  int mxDis = 0, mxDisNode = -1, curDis = 0;
  function<void(int, int)> dfs = [&](int src, int par) {
    if (curDis > mxDis) {
      mxDis = curDis;
      mxDisNode = src;
    }
    for (int &des : G[src]) {
      if (des == par)
        continue;
      curDis++;
      dfs(des, src);
      curDis--;
    }
  };
  dfs(1, -1);
  if (mxDisNode != -1)
    dfs(mxDisNode, -1);
  cout << mxDis << '\n';
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