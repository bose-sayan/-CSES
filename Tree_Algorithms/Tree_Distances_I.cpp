#include <bits/stdc++.h>

using namespace std;

using ll = long long;

/*
  Some observations:
  For any node n1 and node n2 for which dis(n1, n2) is max, the possibilities
  are:
  -> n2 is a descendant of n1
    In this case, we can simply use DFS and DP to find the max depth of the
    subtree rooted at n1
  -> n2 is not a descendant of n1
    In this case, we need to find the longest path from parent of n1 to n2
    Here again we have two possibilities:
      :- n2 is a descendant of par[n1]
        In this case, we basically need to find the longest path from par[n1]
        to any of its descendants. We do need to check that n1 isn't a part of
        this path.
      :- n2 is not a descendant of par[n1]
        This can be thought of as a recurring subtask.
*/

const int MXN = 2e5 + 10;
vector<int> G[MXN];

int mxPathIn[MXN]; // distance of longest path from cur node to another node in
                   // its subtree
int secondMxPathIn[MXN]; // distance of second longest path from cur node to
                         // another node in its subtree
int mxPathOut[MXN]; // distance of longest path from cur node to another node
                    // not in its subtree
int mxPath[MXN];    // distance of longest path from cur node to another node
int mxPathInChild[MXN]; // node which contributes to mxPathIn[]

void solve() {
  int n;
  cin >> n;
  for (int i = 0, u, v; i < n - 1; i++) {
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  function<void(int, int)> calcMxPathIn = [&](int src, int par) {
    for (auto &des : G[src]) {
      if (des == par)
        continue;
      calcMxPathIn(des, src);
      if (mxPathIn[des] + 1 >= mxPathIn[src]) {
        secondMxPathIn[src] = mxPathIn[src];
        mxPathIn[src] = mxPathIn[des] + 1;
        mxPathInChild[src] = des;
        mxPath[src] = mxPathIn[src];
      } else if (mxPathIn[des] + 1 >= secondMxPathIn[src]) {
        secondMxPathIn[src] = mxPathIn[des] + 1;
      }
    }
  };
  calcMxPathIn(1, -1);
  function<void(int, int)> calcMxPathOut = [&](int src, int par) {
    if (par != -1)
      mxPathOut[src] = max(mxPathOut[par] + 1,
                           (mxPathInChild[par] == src ? secondMxPathIn[par] + 1
                                                      : mxPathIn[par] + 1));
    mxPath[src] = max(mxPath[src], mxPathOut[src]);
    for (auto &des : G[src]) {
      if (des == par)
        continue;
      calcMxPathOut(des, src);
    }
  };
  calcMxPathOut(1, -1);
  for (int i = 1; i <= n; i++) {
    cout << mxPath[i] << ' ';
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