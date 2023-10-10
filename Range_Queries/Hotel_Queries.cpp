#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 10;
int N; // arr size
int tr[2 * MXN];

// build the tree
void initialize() {
  // ! Put all elements in the leaf nodes: a[i] -> tr[i + n] before building
  for (int i = N - 1; i; i--) {
    tr[i] = max(tr[i << 1], tr[(i << 1) | 1]); // tr[i] = f(tr[2i], tr[2i + 1])
  }
}

void update(int idx, int val) {
  idx += N;
  tr[idx] = val;
  // update parent segments
  for (; idx; idx >>= 1) {
    tr[idx >> 1] =
        max(tr[idx], tr[idx ^ 1]); // tr[x / 2] = f(tr[x], tr[x +/- 1])
  }
}

int query(int l, int r) {
  int res = 0;
  for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
    // if (l & 1) => right child is present, not left.
    // Thus take right child, and move to the right adjacent node.
    // Similar for r
    if (l & 1)
      res = max(res, tr[l++]);
    if (r & 1)
      res = max(res, tr[--r]);
  }
  return res;
}

int findRoom(int roomsRequired) {
  int lowIdx = 0, hiIdx = N - 1, idx = -1;
  while (lowIdx <= hiIdx) {
    int mid = (lowIdx + hiIdx) / 2;
    if (query(lowIdx, mid + 1) >= roomsRequired) {
      idx = mid;
      hiIdx = mid - 1;
    } else {
      lowIdx = mid + 1;
    }
  }
  if (idx != -1)
    update(idx, tr[idx + N] - roomsRequired);
  return idx + 1;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int q;
  cin >> N >> q;

  for (int i = N; i < 2 * N; i++) {
    cin >> tr[i];
  }

  initialize();

  for (int i = 0, requiredRooms; i < q; i++) {
    cin >> requiredRooms;
    cout << findRoom(requiredRooms) << ' ';
  }

  cout << '\n';

  return 0;
}