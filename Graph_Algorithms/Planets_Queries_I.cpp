#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// We can use binary lifting to optimize the query processing

const int MXN = 2e5 + 10;

int desc[MXN][35];

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> desc[i][1];
    desc[i][0] = i;
  }
  for (int j = 2; j <= 34; j++) {
    for (int i = 1; i <= n; i++) {
      desc[i][j] = desc[desc[i][j - 1]][j - 1];
    }
  }

  for (int i = 1, src, moves, ans; i <= q; i++) {
    cin >> src >> moves;
    ans = src;
    int id = 1;
    while (moves) {
      if (moves & 1) {
        ans = desc[ans][id];
      }
      id++;
      moves >>= 1;
    }
    cout << ans << '\n';
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