#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MXN = 2e5 + 10;

// The graph is such that there will arise four types of queries

int inCycleId[MXN], incidentOnCycle[MXN], disFromCycle[MXN], orderInCycle[MXN];
int desc[MXN][25];
bool vis[MXN], inStk[MXN];

struct Cycle {
  int id, len;
};

vector<Cycle> cycles;

void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> desc[i][1];
    desc[i][0] = i;
    inCycleId[i] = -1;
  }

  // initialize for binary jumping
  for (int j = 2; j <= 22; j++) {
    for (int i = 1; i <= n; i++) {
      desc[i][j] = desc[desc[i][j - 1]][j - 1];
    }
  }

  // find cycles
  vector<int> path;
  function<void(int)> dfs = [&](int src) {
    if (inStk[src]) {
      // found cycle
      auto cycle = Cycle();
      cycle.id = int(cycles.size());
      vector<int> order;
      for (int i = int(path.size()) - 1; path[i] != src; i--) {
        order.emplace_back(path[i]);
        inCycleId[path[i]] = cycle.id;
        incidentOnCycle[path[i]] = path[i];
        disFromCycle[path[i]] = 0;
      }
      order.emplace_back(src);
      incidentOnCycle[src] = src;
      disFromCycle[src] = 0;
      inCycleId[src] = cycle.id;
      reverse(order.begin(), order.end());
      for (int i = 0; i < int(order.size()); i++)
        orderInCycle[order[i]] = i;
      cycle.len = int(order.size());
      cycles.push_back(cycle);
      return;
    }
    if (vis[src])
      return;
    vis[src] = true;
    inStk[src] = true;
    path.emplace_back(src);
    dfs(desc[src][1]);
    inStk[src] = false;
    path.pop_back();
  };

  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    dfs(i);
  }

  // find cycles on which a node is incident
  for (int i = 1; i <= n; i++)
    vis[i] = (inCycleId[i] != -1);

  function<void(int)> dfs2 = [&](int src) {
    if (vis[src])
      return;
    vis[src] = true;
    dfs2(desc[src][1]);
    incidentOnCycle[src] = incidentOnCycle[desc[src][1]];
    disFromCycle[src] = disFromCycle[desc[src][1]] + 1;
  };

  for (int i = 1; i <= n; i++) {
    if (vis[i])
      continue;
    dfs2(i);
  }

  // process queries

  for (int i = 1, src, des; i <= q; i++) {
    cin >> src >> des;
    // Case 1:
    if (inCycleId[src] == -1 && inCycleId[des] == -1) {
      // src and des both not in cycle
      // Now check if we can reach des from src
      int d = disFromCycle[src] - disFromCycle[des];
      if (d < 0) {
        // not possible
        cout << -1 << '\n';
      } else {
        int id = 1, x = d;
        while (d) {
          if (d & 1) {
            src = desc[src][id];
          }
          d >>= 1;
          id++;
        }
        if (src == des) {
          // we have reached des
          cout << x << '\n';
        } else {
          // not possible
          cout << -1 << '\n';
        }
      }
    }
    // Case 2:
    else if (inCycleId[src] != -1 && inCycleId[des] == -1) {
      // src in cycle, but not des
      // not possible
      cout << -1 << '\n';
    }
    // Case 3:
    else if (inCycleId[src] == -1 && inCycleId[des] != -1) {
      // src not in cycle, but des in cycle
      if (inCycleId[incidentOnCycle[src]] != inCycleId[des]) {
        // both are incident on different cycles
        cout << -1 << '\n';
      } else {
        int res = disFromCycle[src];
        src = incidentOnCycle[src];
        if (orderInCycle[src] <= orderInCycle[des]) {
          res += orderInCycle[des] - orderInCycle[src];
        } else {
          res += cycles[inCycleId[src]].len - orderInCycle[src];
          res += orderInCycle[des];
        }
        cout << res << '\n';
      }
    }
    // Case 4:
    else {
      // both src and des in cycle
      if (inCycleId[src] != inCycleId[des]) {
        // different cycles
        cout << -1 << '\n';
      } else {
        int res = 0;
        if (orderInCycle[src] <= orderInCycle[des]) {
          res += orderInCycle[des] - orderInCycle[src];
        } else {
          res += cycles[inCycleId[src]].len - orderInCycle[src];
          res += orderInCycle[des];
        }
        cout << res << '\n';
      }
    }
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