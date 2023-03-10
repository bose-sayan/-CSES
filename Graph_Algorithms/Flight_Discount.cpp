#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pli = pair<ll, int>;

// Imagine there are two copies of the graph
// Let us consider some edge E in the original graph which connects
// two random nodes A and B.
// If we create an edge from node A of the original graph to the
// node B of the copy with edge weight as half of that of E, we can simulate
// the coupon behaviour.
// These edges will be one way (original -> copied),
// since we can use the coupon only once,
// and so we shouldn't be able to return to the original graph once
// we have entered the copied one.
// Once the graph is constructed, any shortest path algo will work.

// Instead of creating a separate copy of the graph, we can modify
// the same graph by maybe adding a huge number to map the nodes.

const int MXN = 2e6 + 10;
const ll INF = 1e18;

vector<pair<int, int>> G[MXN];
ll dis[MXN];

inline int encode(int x) { return x + int(1e6); }

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= encode(n); i++) {
    dis[i] = INF;
  }
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
    G[encode(u)].emplace_back(encode(v), w);
    G[u].emplace_back(encode(v), w / 2);
  }

  // Dijkstra
  priority_queue<pli, vector<pli>, greater<>> pq;
  dis[1] = 0;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [d, src] = pq.top();
    pq.pop();
    if (dis[src] < d)
      continue;
    for (auto &p : G[src]) {
      auto [des, w] = p;
      if (dis[des] <= d + w)
        continue;
      dis[des] = d + w;
      pq.push({d + w, des});
    }
  }
  cout << dis[encode(n)] << '\n';
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