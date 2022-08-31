//
// Created by Sayan Bose on 26-08-2022.
//
#include<iostream>
#include<algorithm>
#include<vector>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag,
        tree_order_statistics_node_update>
        pb_ds;
typedef vector<int> vi;

const int mxn = 2e5 + 10;
vi x[mxn];
int contains[mxn] = {}, contained[mxn] = {};

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        x[i].resize(3);
        cin >> x[i][0] >> x[i][1];
        x[i][2] = i;
    }
    sort(x, x + n, [](const vi &v1, const vi &v2) -> bool {
        if (v1[0] == v2[0])
            return v1[1] > v2[1];
        return v1[0] < v2[0];
    });
    // contains
    auto tr = new pb_ds();
    for (int i = n - 1, cnt; i >= 0; i--) {
        cnt = (int) tr->order_of_key({x[i][1], n - i});
        contains[x[i][2]] = cnt;
        tr->insert({x[i][1], n - i});
    }
    // contained
    tr->clear();
    for (int i = 0, cnt; i < n; i++) {
        cnt = (int) tr->size() - (int) tr->order_of_key({x[i][1], n - i});
        contained[x[i][2]] = cnt;
        tr->insert({x[i][1], n - i});
    }
    for (int i = 0; i < n; i++)
        cout << contains[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << contained[i] << ' ';
    cout << '\n';
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