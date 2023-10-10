#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

int a[MXN];

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i)
      a[i] ^= a[i - 1];
  }

  for (int i = 0, l, r; i < q; i++) {
    cin >> l >> r;
    --l, --r;
    cout << (a[r] ^ (l - 1 >= 0 ? a[l - 1] : 0)) << '\n';
  }

  return 0;
}