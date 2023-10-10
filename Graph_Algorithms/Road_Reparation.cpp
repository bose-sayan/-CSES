#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MXN = 2e5 + 10;

// Min no. of edges so that the graph is connected
// are found if the graph is a tree

// Since we need to minimize the cost, finding the MST
// of the graph will give us the optimal choice.

// We can use well known algos such as Kruskals to find the MST

struct Edge {
  int src, des, wgt;
  bool operator<(const Edge &e) { return wgt < e.wgt; }
};

struct DSU {
  int components;
  vector<int> par, sz;
  DSU(int n) {
    components = n;
    par.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
      sz[i] = 1;
    }
  }
  int getPar(int x) { return par[x] = (x == par[x] ? x : getPar(par[x])); }
  bool isConnected(int x, int y) { return getPar(x) == getPar(y); }
  void join(int x, int y) {
    x = getPar(x), y = getPar(y);
    if (x == y)
      return;
    components--;
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    par[y] = x;
    sz[x] += sz[y];
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<Edge> edges(m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].src >> edges[i].des >> edges[i].wgt;
  }
  sort(edges.begin(), edges.end());
  auto dsu = DSU(n);
  ll cost = 0;
  for (auto &e : edges) {
    if (dsu.isConnected(e.src, e.des))
      continue;
    dsu.join(e.src, e.des);
    cost += e.wgt;
  }
  if (dsu.components > 1) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  cout << cost << '\n';
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