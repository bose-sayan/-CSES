#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Single source shortest path algos like Dijkstras can solve this problem

const int MXN = 1e5 + 5;
const long long INF = 1e18;

vector<pair<int, int>> G[MXN];
long long dis[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    dis[i] = INF;
  }
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
  }

  // Dijkstra
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>
      pq;
  pq.push({0, 1});
  while (!pq.empty()) {
    auto [d, src] = pq.top();
    pq.pop();
    if (d > dis[src])
      continue;
    for (auto &des : G[src]) {
      if (dis[des.first] > d + des.second) {
        dis[des.first] = d + des.second;
        pq.push({dis[des.first], des.first});
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dis[i] << ' ';
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