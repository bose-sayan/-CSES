#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// find shortest path of unweighted graph -> bfs

const int MXN = 1005, INF = 1e9 + 10;
char mz[MXN][MXN];
int dis[MXN][MXN];
pair<pair<int, int>, char> par[MXN][MXN];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};

void solve() {
  int n, m;
  cin >> n >> m;
  string path;
  queue<int> qx, qy, qd;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mz[i][j];
      dis[i][j] = INF;
      if (mz[i][j] == 'A') {
        qx.push(i);
        qy.push(j);
        qd.push(0);
        par[i][j] = {{i, j}, '-'};
        dis[i][j] = 0;
      }
    }
  }
  while (!qx.empty()) {
    int si = qx.front(), sj = qy.front(), d = qd.front();
    qx.pop(), qy.pop(), qd.pop();
    if (mz[si][sj] == 'B') {
      // extract path
      while (mz[si][sj] != 'A') {
        path += par[si][sj].second;
        auto [i, j] = par[si][sj].first;
        si = i, sj = j;
      }
      break;
    }
    if (d > dis[si][sj])
      continue;
    for (int i = 0; i < 4; i++) {
      int ni = si + dx[i], nj = sj + dy[i];
      if ((ni < 0 || nj < 0) || (ni >= n || nj >= m))
        continue;
      if (mz[ni][nj] == '#' || dis[ni][nj] <= d + 1)
        continue;
      par[ni][nj] = {{si, sj}, dir[i]};
      dis[ni][nj] = d + 1;
      qx.push(ni);
      qy.push(nj);
      qd.push(dis[ni][nj]);
    }
  }
  if (path.empty()) {
    cout << "NO\n";
    return;
  }
  reverse(path.begin(), path.end());
  cout << "YES \n" << path.size() << '\n' << path << '\n';
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