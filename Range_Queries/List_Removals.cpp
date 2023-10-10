#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 10;
int N; // arr size
int tr[2 * MXN], val[2 * MXN], a[MXN];

// build the tree
void initialize() {
  // ! Put all elements in the leaf nodes: a[i] -> tr[i + n] before building
  for (int i = N - 1; i; i--) {
    tr[i] = (tr[i << 1] + tr[(i << 1) | 1]); // tr[i] = f(tr[2i], tr[2i + 1])
  }
}

void fillVal(int src = 1) {
  static int idx = 0;
  if (src >= N) {
    val[src] = a[idx++];
    return;
  }
  fillVal(2 * src);
  fillVal(2 * src + 1);
}

void update(int idx, int v) {
  tr[idx] = v;
  // update parent segments
  for (; idx; idx >>= 1) {
    tr[idx >> 1] = (tr[idx] + tr[idx ^ 1]); // tr[x / 2] = f(tr[x], tr[x +/- 1])
  }
}

int findVal(int idx) {
  int curNode = 1;
  while (curNode < N) {
    int lChild = curNode * 2, rChild = curNode * 2 + 1;
    if (tr[lChild] >= idx) {
      curNode = lChild;
    } else {
      idx -= tr[lChild];
      curNode = rChild;
    }
  }
  update(curNode, 0);
  return val[curNode];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N;

  for (int i = N; i < 2 * N; i++) {
    cin >> a[i - N];
    tr[i] = 1;
  }

  initialize();
  fillVal();

  for (int i = 0, id; i < N; i++) {
    cin >> id;
    cout << findVal(id) << ' ';
  }

  cout << '\n';

  return 0;
}