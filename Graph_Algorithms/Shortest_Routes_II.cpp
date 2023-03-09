#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// All pairs shortest path algos like Floyd Warshall can solve this problem

const int MXN = 5e2 + 5;
const long long INF = 1e18;

ll dis[MXN][MXN];

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (i == j) {
        dis[i][j] = 0;
        continue;
      }
      dis[i][j] = dis[j][i] = INF;
    }
  }
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    dis[u][v] = dis[v][u] = min(dis[u][v], ll(w));
  }
  for (int intermediate = 1; intermediate <= n; intermediate++) {
    for (int u = 1; u <= n; u++) {
      for (int v = 1; v <= n; v++) {
        dis[u][v] = min(dis[u][v], dis[u][intermediate] + dis[intermediate][v]);
      }
    }
  }

  for (int i = 0, u, v; i < q; i++) {
    cin >> u >> v;
    cout << (dis[u][v] == INF ? -1 : dis[u][v]) << '\n';
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