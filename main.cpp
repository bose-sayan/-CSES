#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/*
  We can use the concept of LCA for solving this
  Let lca = LCA of x and y
  dis(x, y) = dis(x, lca) + dis(y, lca)
  dis(lca, x) = depth(x) - depth(lca)
*/

const int MXN = 2e5 + 10, H = 25;

int par[MXN][H], depth[MXN], tin[MXN], tout[MXN], timer = 0;
vector<int> G[MXN];

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  // initialize

  function<void(int, int)> calcDepth = [&](int src, int p) {
    tin[src] = ++timer;
    if (src != p)
      depth[src] = depth[p] + 1;
    par[src][0] = p;
    for (int h = 1; h < H; h++) {
      par[src][h] = par[par[src][h - 1]][h - 1];
    }
    for (int &des : G[src]) {
      if (des == p)
        continue;
      calcDepth(des, src);
    }
    tout[src] = ++timer;
  };

  calcDepth(1, 1);

  function<bool(int, int)> isAncestor = [&](int x, int y) -> bool {
    return (tin[x] <= tin[y]) && (tout[y] <= tout[x]);
  };

  function<int(int, int)> getAncestor = [&](int x, int jumps) -> int {
    int idx = 0;
    while (jumps) {
      if (jumps & 1) {
        x = par[x][idx];
      }
      jumps >>= 1;
      idx++;
    }
    return x;
  };

  function<int(int, int)> findLCA = [&](int x, int y) -> int {
    // For dealing with the case when one is a descendant of the other
    if (isAncestor(x, y))
      return x;
    if (isAncestor(y, x))
      return y;
    for (int i = H - 1; i >= 0; i--) {
      if (!isAncestor(par[x][i], y))
        x = par[x][i];
    }
    return par[x][0];
  };

  // Resolve Queries
  for (int i = 0, x, y; i < q; i++) {
    cin >> x >> y;
    int lca = findLCA(x, y);
    cout << (depth[x] - depth[lca]) + (depth[y] - depth[lca]) << '\n';
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