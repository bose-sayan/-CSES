#include<bits/stdc++.h>

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

// build the tree
void initialize() {
    // ! Put all elements in the leaf nodes: a[i] -> tr[i + n] before building
    for (int i = N - 1; i; i--) {
        tr[i] = tr[i << 1] + tr[(i << 1) | 1]; // tr[i] = tr[2i] + tr[2i + 1]
    }
}

void update(int idx, int val) {
    idx += N;
    tr[idx] = val;
    // update parent segments
    for (; idx; idx >>= 1) {
        tr[idx >> 1] = tr[idx] + tr[idx ^ 1]; // tr[x / 2] = tr[x] + tr[x +/- 1] 
    }
}

ll query(int l, int r) {
    ll res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        // if (l & 1) => right child is present, not left.
        // Thus take right child, and move to the right adjacent node.
        // Similar for r
        if (l & 1) res += tr[l++]; 
        if (r & 1) res += tr[--r];
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
    initialize();
    for (int i = 0, T, A, B; i < Q; i++) {
        cin >> T >> A >> B;
        --A;
        if (T == 1) {
            update(A, B);
        } else {
            cout << query(A, B) << '\n';
        }
    }

    return 0;
}