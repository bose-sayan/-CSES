#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Modification of dijkstra to keep a track of all the info required solves the
// problem

const int MXN = 1e5 + 10, MOD = 1e9 + 7;
const ll INF = 1e18;
vector<pair<int, int>> G[MXN];
ll dis[MXN];
int mnFlightCnt[MXN], mxFlightCnt[MXN], cntMnRoutes[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
  }
  for (int i = 1; i <= n; i++) {
    dis[i] = INF;
    cntMnRoutes[i] = 0;
    mnFlightCnt[i] = 1e9;
    mxFlightCnt[i] = 0;
  }

  // Dijkstra
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
  pq.push({0, 1});
  dis[1] = 0;
  mnFlightCnt[1] = 0;
  cntMnRoutes[1] = 1;
  while (!pq.empty()) {
    auto [d, src] = pq.top();
    pq.pop();
    if (d > dis[src])
      continue;
    for (auto &p : G[src]) {
      auto [des, w] = p;
      if (dis[des] < d + w)
        continue;
      else if (dis[des] == d + w) {
        cntMnRoutes[des] += cntMnRoutes[src];
        cntMnRoutes[des] %= MOD;
        mnFlightCnt[des] = min(mnFlightCnt[des], mnFlightCnt[src] + 1);
        mxFlightCnt[des] = max(mxFlightCnt[des], mxFlightCnt[src] + 1);
      } else {
        dis[des] = d + w;
        cntMnRoutes[des] = cntMnRoutes[src];
        mnFlightCnt[des] = mnFlightCnt[src] + 1;
        mxFlightCnt[des] = mxFlightCnt[src] + 1;
        pq.push({d + w, des});
      }
    }
  }
  cout << dis[n] << ' ' << cntMnRoutes[n] << ' ' << mnFlightCnt[n] << ' '
       << mxFlightCnt[n] << '\n';
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