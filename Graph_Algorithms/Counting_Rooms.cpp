#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Count number of connected components
// room (component) -> '.' cells which are connected

const int MXN = 1005;
char mz[MXN][MXN];
bool vis[MXN][MXN];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

void solve() {
  int n, m;
  cin >> n >> m;

  function<void(int, int)> dfs = [&](int i, int j) -> void {
    if (vis[i][j])
      return;
    vis[i][j] = true;
    for (int id = 0; id < 4; id++) {
      int ni = i + dx[id], nj = j + dy[id];
      if ((ni < 0 || nj < 0) || (ni >= n || nj >= m))
        continue;
      if (mz[ni][nj] == '#')
        continue;
      dfs(ni, nj);
    }
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mz[i][j];
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mz[i][j] == '.' && !vis[i][j]) {
        dfs(i, j);
        count++;
      }
    }
  }
  cout << count << '\n';
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