#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pli = pair<ll, int>;

// Bellman Ford does the job

const int MXN = 2550;
const ll INF = 1e18;

vector<vector<int>> edges;
int par[MXN];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0, u, v, w; i < m; i++) {
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
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