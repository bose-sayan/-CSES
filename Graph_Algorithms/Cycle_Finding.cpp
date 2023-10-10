#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Bellman Ford does the job

const int MXN = 2550;
const ll INF = 1e18;

vector<tuple<int, int, int>> edges;
int par[MXN];
ll dis[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    edges.emplace_back(u, v, w);
  }
  int lastRelaxedVertex = -1;
  for (int i = 0; i < n; i++) {
    lastRelaxedVertex = -1;
    for (auto &e : edges) {
      auto [u, v, w] = e;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        par[v] = u;
        lastRelaxedVertex = v;
      }
    }
  }
  if (lastRelaxedVertex == -1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int cycleVertex = lastRelaxedVertex;
  for (int i = 0; i < n; i++) {
    cycleVertex = par[cycleVertex];
  }
  vector<int> cycle;
  for (int cur = cycleVertex;; cur = par[cur]) {
    cycle.emplace_back(cur);
    if (cur == cycleVertex && int(cycle.size()) > 1)
      break;
  }
  reverse(cycle.begin(), cycle.end());
  for (auto &v : cycle) {
    cout << v << ' ';
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