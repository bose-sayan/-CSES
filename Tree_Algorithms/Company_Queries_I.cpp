#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/*
  Binary Lifting does the job for us
*/

const int MXN = 2e5 + 10, H = 22;

int par[MXN][H];

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    cin >> par[i][0];
  }

  // initialize
  for (int h = 0; h < H; h++) {
    par[1][h] = -1;
  }
  for (int i = 2; i <= n; i++) {
    for (int h = 1; h < H; h++) {
      if (par[i][h - 1] == -1) {
        par[i][h] = -1;
        continue;
      }
      par[i][h] = par[par[i][h - 1]][h - 1];
    }
  }

  // Resolve queries
  for (int i = 1, x, k; i <= q; i++) {
    cin >> x >> k;
    int idx = 0;
    while (k) {
      if (k & 1) {
        x = par[x][idx];
        if (x == -1)
          break;
      }
      k >>= 1;
      idx++;
    }
    cout << x << '\n';
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