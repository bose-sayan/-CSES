#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MXN = 2e5 + 10;
vector<int> G[MXN];
int subordinateCount[MXN];

void solve() {
  int n;
  cin >> n;
  for (int i = 2, x; i <= n; i++) {
    cin >> x;
    G[x].emplace_back(i);
  }
  function<void(int)> dfs = [&](int src) {
    for (auto &sub : G[src]) {
      dfs(sub);
      subordinateCount[src] += subordinateCount[sub] + 1;
    }
  };
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << subordinateCount[i] << ' ';
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