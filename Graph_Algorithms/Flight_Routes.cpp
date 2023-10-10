#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// k-shortest paths can be found by an extension of the dijkstra's SSSP algo
// More info:
// https://en.wikipedia.org/wiki/K_shortest_path_routing#Loopy_variant

const int MXN = 1e5 + 10;
const ll INF = 1e18;
vector<pair<int, int>> G[MXN];
int cnt[MXN];

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
  }
  // Dijkstra
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
  pq.push({0, 1});
  vector<ll> costs;
  while (!pq.empty() && cnt[n] < k) {
    auto [d, s] = pq.top();
    pq.pop();
    cnt[s]++;
    if (s == n)
      costs.emplace_back(d);
    if (cnt[s] <= k) {
      for (auto &i : G[s]) {
        pq.push({i.second + d, i.first});
      }
    }
  }
  sort(costs.begin(), costs.end());
  for (auto &c : costs) {
    cout << c << ' ';
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