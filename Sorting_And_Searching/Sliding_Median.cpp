//
// Created by Sayan Bose on 01-09-2022.
//

#include<iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag,
        tree_order_statistics_node_update>
        pb_ds;

// Global
const int mxn = 2e5 + 10;
int x[mxn], res[mxn];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    auto tr = new pb_ds();
    for (int i = 0; i < k; i++)
        tr->insert({x[i], i});
    int order = k / 2 - (k % 2 == 0);
    res[0] = tr->find_by_order(order)->first;
    for (int i = 0, j = k; j < n; j++) {
        tr->erase({x[i], i++});
        tr->insert({x[j], j});
        res[i] = tr->find_by_order(order)->first;
    }
    for (int i = 0; i <= n - k; i++)
        cout << res[i] << ' ';
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