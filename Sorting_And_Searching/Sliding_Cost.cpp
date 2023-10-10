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
typedef long long ll;

/*
 *
 *  Transitions
 *  if newMedian == oldMedian:
 *      newCost = oldCost - |removedElement - oldMedian| + |addedElement - newMedian|
 *  else:
 *      newCost = oldCost - |removedElement - oldMedian| + |addedElement - newMedian|
 *      _ _ newMedian _ _ _
 *      if newMedian > oldMedian:
 *          cost(leftIndexes) will increase
 *          cost(rightIndexes) will decrease
 *      else:
 *          cost(leftIndexes) will decrease
 *          cost(rightIndexes) will increase
 *          Cases:
 *              newElement < newMedian:
 *                  leftIndexes--;
 *              else
 *                  rightIndexes--;
 */

// Global
const int mxn = 2e5 + 10;
int x[mxn];
ll res[mxn];

void solve() {

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    auto tr = new pb_ds();
    for (int i = 0; i < k; i++)
        tr->insert({x[i], i});

    int order = k / 2 - (k % 2 == 0);

    ll prevMedian, currentMedian = tr->find_by_order(order)->first;
    ll prevCost, currentCost = 0;
    for (int i = 0; i < k; i++)
        currentCost += abs(currentMedian - x[i]);
    res[0] = currentCost;
    prevCost = currentCost, prevMedian = currentMedian;
    for (int i = 0, j = k; j < n; j++) {
        tr->erase({x[i], i});
        tr->insert({x[j], j});
        currentMedian = tr->find_by_order(order)->first;
        currentCost = prevCost - abs(x[i] - prevMedian) + abs(x[j] - currentMedian);
        if (currentMedian != prevMedian) {
            ll diff = abs(currentMedian - prevMedian);
            int leftIndexes = (k / 2) - !(k & 1),
                    rightIndexes = (k / 2);

            /*
             * 1 2 3 4  cost = 4
             * 1 3 4 10 cost = 4 - (2 - 2) - (3 - 2) + left * diff - right * diff + (10 - 3)
             */
            if (x[j] != currentMedian)
                currentCost -= diff;

            if (x[j] > currentMedian)
                rightIndexes--;
            else if (x[j] < currentMedian)
                leftIndexes--;

            currentCost += (currentMedian > prevMedian ? leftIndexes * diff : -leftIndexes * diff);
            currentCost += (currentMedian > prevMedian ? -rightIndexes * diff : rightIndexes * diff);
        }
        res[++i] = currentCost;
        prevMedian = currentMedian;
        prevCost = currentCost;
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