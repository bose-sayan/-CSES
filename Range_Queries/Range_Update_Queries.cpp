#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Iterative Segment Tree
/*
    Credits:
    https://codeforces.com/blog/entry/18051
    https://codeforces.com/blog/entry/1256
*/

const int MXN = 2e5 + 10;
int N; // arr size
ll tr[2 * MXN];

void update(int l, int r, int val) {
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    if (l & 1)
      tr[l++] += val;
    if (r & 1)
      tr[--r] += val;
  }
}

ll query(int idx) {
  ll res = 0;
  for (idx += N; idx; idx >>= 1) {
    res += tr[idx];
  }
  return res;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int Q;
  cin >> N >> Q;
  for (int i = N; i < 2 * N; i++) {
    cin >> tr[i];
  }
  for (int i = 0, T, A, B, V; i < Q; i++) {
    cin >> T;
    if (T == 1) {
      cin >> A >> B >> V;
      update(--A, B, V);
    } else {
      cin >> A;
      cout << query(--A) << '\n';
    }
  }

  return 0;
}