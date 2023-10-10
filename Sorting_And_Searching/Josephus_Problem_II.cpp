//
// Created by Sayan Bose on 31-08-2022.
//
#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define len(x) (int) (x)->size()

using namespace __gnu_pbds;
using namespace std;

// set operations + ( orderOfKey, findKeyByOrder )
typedef tree<int, null_type, less<>, rb_tree_tag,
        tree_order_statistics_node_update>
        pb_ds;

void solve() {
    int n, k;
    cin >> n >> k;
    auto tr = new pb_ds();
    for (int i = 1; i <= n; i++) {
        tr->insert(i);
    }
    for (int start = 0; !tr->empty();) {
        int kill = (start + k) % len(tr);
        auto it = tr->find_by_order(kill);
        cout << *it << ' ';
        tr->erase(it);
        start = kill;
    }
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}