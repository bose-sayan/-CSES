#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MXN = 2e5 + 10;

// We can use the disjoint set DS to keep track of the info efficiently

struct DSU {
  int components, mxSz;
  vector<int> par, sz;
  DSU(int n) {
    components = n;
    mxSz = 1;
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
    mxSz = max(mxSz, sz[x]);
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  auto dsu = DSU(n);
  for (int i = 0, u, v; i < m; i++) {
    cin >> u >> v;
    dsu.join(u, v);
    cout << dsu.components << ' ' << dsu.mxSz << '\n';
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