#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// We can't go to a cell if a monster can reach that cell in the same number of
// steps as the person does. So those cells can be considered unreachable.

// We can use multisource BFS to find the number of steps
// needed for some monster to reach a particular cell.

const int MXN = 1e3 + 5, INF = 1e9 + 10;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};
char mz[MXN][MXN];
int dis[MXN][MXN];
char parDir[MXN][MXN];

void solve() {
  int n, m;
  cin >> n >> m;

  queue<int> qx, qy, qd;

  int Sx, Sy; // starting cell of the person

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mz[i][j];

      // initialize dis
      dis[i][j] = INF;

      // If monster, add to queue
      if (mz[i][j] == 'M') {
        qx.push(i);
        qy.push(j);
        qd.push(0);
        dis[i][j] = 0;
      } else if (mz[i][j] == 'A') {
        Sx = i, Sy = j;
      }
    }
  }
  while (!qx.empty()) {
    int sx = qx.front(), sy = qy.front(), d = qd.front();
    qx.pop(), qy.pop(), qd.pop();
    if (dis[sx][sy] < d)
      continue;
    for (int i = 0; i < 4; i++) {
      int ex = sx + dx[i], ey = sy + dy[i];
      if ((ex < 0 || ex == n) || (ey < 0 || ey == m))
        continue;
      if (mz[ex][ey] == '#' || dis[ex][ey] <= d + 1)
        continue;
      dis[ex][ey] = d + 1;
      qx.push(ex);
      qy.push(ey);
      qd.push(d + 1);
    }
  }

  // now check if a path exists for the person
  qx.push(Sx);
  qy.push(Sy);
  qd.push(0);
  dis[Sx][Sy] = 0;
  string path;
  bool isPossible = false;
  while (!qx.empty()) {
    int sx = qx.front(), sy = qy.front(), d = qd.front();
    qx.pop(), qy.pop(), qd.pop();
    if ((sx == 0 || sx == n - 1) || (sy == 0 || sy == m - 1)) {
      // Found a path
      isPossible = true;
      while (sx != Sx || sy != Sy) {
        char pDir = parDir[sx][sy];
        path += pDir;
        if (pDir == 'U') {
          sx++;
        } else if (pDir == 'D') {
          sx--;
        } else if (pDir == 'L') {
          sy++;
        } else {
          sy--;
        }
      }
      reverse(path.begin(), path.end());
      break;
    }
    if (dis[sx][sy] < d)
      continue;
    for (int i = 0; i < 4; i++) {
      int ex = sx + dx[i], ey = sy + dy[i];
      if ((ex < 0 || ex == n) || (ey < 0 || ey == m))
        continue;
      if (mz[ex][ey] == '#' || dis[ex][ey] <= d + 1)
        continue;
      dis[ex][ey] = d + 1;
      parDir[ex][ey] = dir[i];
      qx.push(ex);
      qy.push(ey);
      qd.push(d + 1);
    }
  }
  if (!isPossible) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  cout << int(path.length()) << '\n';
  cout << path << '\n';
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