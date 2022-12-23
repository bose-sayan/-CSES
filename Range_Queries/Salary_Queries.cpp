#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int MXN = 2e5 + 10;
int N, Q, p[MXN];

typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag,
             tree_order_statistics_node_update>
    pb_ds;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> Q;

  auto tr = new pb_ds();

  for (int i = 1; i <= N; i++) {
    cin >> p[i];
    tr->insert({p[i], i});
  }

  for (int i = 1; i <= Q; i++) {
    char type;
    cin >> type;
    if (type == '!') {
      int k, x;
      cin >> k >> x;
      tr->erase({p[k], k});
      tr->insert({x, k});
      p[k] = x;
    } else {
      int a, b;
      cin >> a >> b;
      int r = int(tr->order_of_key({b, INT_MAX}));
      int l = int(tr->order_of_key({a - 1, INT_MAX}));
      cout << r - l << '\n';
    }
  }
  delete (tr);
  return 0;
}