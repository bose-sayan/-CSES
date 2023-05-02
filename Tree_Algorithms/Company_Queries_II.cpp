#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/*
  Again we can use Binary Lifting for finding out the LCA
*/

const int MXN = 2e5 + 10, H = 25;

int par[MXN][H], depth[MXN];
vector<int> G[MXN];

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    cin >> par[i][0];
    G[par[i][0]].emplace_back(i);
    G[i].emplace_back(par[i][0]);
  }

  // initialize
  for (int h = 0; h < H; h++) {
    par[1][h] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int h = 1; h < H; h++) {
      par[i][h] = par[par[i][h - 1]][h - 1];
    }
  }

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

  function<void(int, int)> calcDepth = [&](int src, int p) {
    if (p != -1)
      depth[src] = depth[p] + 1;
    for (int &des : G[src]) {
      if (des != p)
        calcDepth(des, src);
    }
  };

  calcDepth(1, -1);

  function<int(int, int)> findLCA = [&](int x, int y) -> int {
    // For dealing with the case when one is a descendant of the other
    if (depth[x] > depth[y])
      swap(x, y);
    if (depth[x] != depth[y]) {
      int diff = depth[y] - depth[x];
      y = getAncestor(y, diff);
    }

    int low = 0, hi = MXN;
    int lca = 1;
    while (low <= hi) {
      int mid = (low + hi) / 2;
      int ax = getAncestor(x, mid), ay = getAncestor(y, mid);
      if (ax == ay) {
        lca = ax;
        hi = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return lca;
  };

  // Resolve Queries
  for (int i = 0, x, y; i < q; i++) {
    cin >> x >> y;
    cout << findLCA(x, y) << '\n';
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