#include <bits/stdc++.h>

using namespace std;

const int MXN = 1003;
int dp[MXN][MXN];

int cnt(int x1, int y1, int x2, int y2) {
  --x1, --y1, --x2, --y2;
  int res = dp[x2][y2];
  if (y1 - 1 >= 0)
    res -= dp[x2][y1 - 1];
  if (x1 - 1 >= 0)
    res -= dp[x1 - 1][y2];
  if (y1 - 1 >= 0 && x1 - 1 >= 0)
    res += dp[x1 - 1][y1 - 1];
  return res;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;

  char ch;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ch;
      dp[i][j] = (ch == '*');
      if (i - 1 >= 0)
        dp[i][j] += dp[i - 1][j];
      if (j - 1 >= 0)
        dp[i][j] += dp[i][j - 1];
      if (i - 1 >= 0 && j - 1 >= 0)
        dp[i][j] -= dp[i - 1][j - 1];
    }
  }

  for (int i = 0, x1, y1, x2, y2; i < q; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << cnt(x1, y1, x2, y2) << '\n';
  }

  return 0;
}