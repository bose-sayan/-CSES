#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/*
  Some observations:
  For any node x there will be nodes:
  -> In the subtree rooted at x
  -> Outside the subtree rooted at x

  For both the cases, we can use DP to get the required sum in linear time

  Let f1(x) denote the sum of distance to nodes inside the subtree rooted at x
  Let f2(x) denote the sum of distance to nodes outside the subtree rooted at x
  Let cnt(x) denote the number of nodes in the subtree rooted at x

  * f1(x) = sum(f1(y) + cnt(y)) for all y, such that y is a child of x

  f2(x) can be broken down into two parts


  Let f2_1 denote ans to part 1 of the solution
  Let f2_2 denote ans to part 2 of the solution

  f2_1(x) denotes the required sum when the subtree rooted at parent of x
  is ignored.
  f2_2(x) denotes the required sum when only the sibling subtrees of x are
  considered.

  * f2_1(x) = f2(par[x]) + (n - cnt(par[x]))
  * f2_2(x) = (f1(p) - (f1(x) + cnt(x))) + (cnt(par[x]) - cnt(x))

  * f2(x) = f2_1(x) + f2_2(x)

  The required ans will be f1(x) + f2(x)

*/

const int MXN = 2e5 + 10;
vector<int> G[MXN];

ll sumInside[MXN],   // The sum of distance to nodes in the subtree
    sumOutside[MXN], // The sum of distance to nodes outside the subtree
    cntDesc[MXN];    // Count of number of descendants

void solve() {
  int n;
  cin >> n;
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  function<void(int, int)> calcIn = [&](int src, int par) {
    cntDesc[src]++;
    for (int &des : G[src]) {
      if (des == par)
        continue;
      calcIn(des, src);
      sumInside[src] += sumInside[des] + cntDesc[des];
      cntDesc[src] += cntDesc[des];
    }
  };

  calcIn(1, -1);

  function<void(int, int)> calcOut = [&](int src, int par) {
    if (par != -1) {
      sumOutside[src] = sumOutside[par] + (n - cntDesc[par]);
      sumOutside[src] += sumInside[par] - (sumInside[src] + cntDesc[src]);
      sumOutside[src] += cntDesc[par] - cntDesc[src];
    }
    for (int &des : G[src]) {
      if (des == par)
        continue;
      calcOut(des, src);
    }
  };

  calcOut(1, -1);

  for (int i = 1; i <= n; i++) {
    cout << sumInside[i] + sumOutside[i] << ' ';
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