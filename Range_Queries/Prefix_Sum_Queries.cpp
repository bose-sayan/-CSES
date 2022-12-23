#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;

struct Info {
  ll totalSum, mxSum;
  ll mxLeftSum;
  Info() { mxSum = totalSum = mxLeftSum = 0; }
  Info(ll val) { mxSum = totalSum = mxLeftSum = val; }
};

// Top Down Segment Tree (more intuitive)

struct SegTree {
  int lb, rb;
  Info *data;
  SegTree *left, *right;
  SegTree(int l, int r, const vector<int> &A) {
    lb = l, rb = r;
    if (l == r) {
      data = new Info(A[l]);
      return;
    }
    int mid = (l + r) / 2;
    left = new SegTree(l, mid, A);
    right = new SegTree(mid + 1, r, A);
    data = combine(left->data, right->data);
  }

  Info *combine(Info *leftData, Info *rightData) {
    auto newData = new Info();
    newData->totalSum = leftData->totalSum + rightData->totalSum;
    newData->mxLeftSum = max(
        {leftData->mxLeftSum,
         leftData->totalSum + max(rightData->mxLeftSum, rightData->totalSum)});
    newData->mxSum =
        max({newData->totalSum, leftData->mxSum, newData->mxLeftSum});
    return newData;
  }

  void update(int idx, int val) {
    if (lb == rb) {
      delete data;
      data = new Info(val);
      return;
    }
    if (left->rb >= idx) {
      left->update(idx, val);
    } else {
      right->update(idx, val);
    }
    data = combine(left->data, right->data);
  }

  Info *query(int l, int r) {
    if (lb >= l && rb <= r) {
      return data;
    }
    if (lb > r || rb < l) {
      return new Info(-INF);
    }
    auto leftData = left->query(l, r), rightData = right->query(l, r);
    if (leftData->totalSum == -INF)
      return rightData;
    else if (rightData->totalSum == -INF)
      return leftData;
    return combine(leftData, rightData);
  }
};

int main() {

#ifdef LOCAL
  (void)!freopen("in.txt", "r", stdin);
  (void)!freopen("out.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  auto tr = new SegTree(0, N - 1, A);

  for (int i = 0, t; i < Q; i++) {
    cin >> t;
    if (t == 1) {
      int k, u;
      cin >> k >> u;
      tr->update(k - 1, u);
    } else {
      int a, b;
      cin >> a >> b;
      cout << max(0ll, tr->query(a - 1, b - 1)->mxSum) << '\n';
    }
  }

  return 0;
}