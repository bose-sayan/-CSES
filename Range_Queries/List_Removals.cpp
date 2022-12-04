#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5 + 10;
int N; // arr size
int tr[2 * MXN];

// build the tree
void initialize()
{
    // ! Put all elements in the leaf nodes: a[i] -> tr[i + n] before building
    for (int i = N - 1; i; i--)
    {
        tr[i] = (tr[i << 1] + tr[(i << 1) | 1]); // tr[i] = f(tr[2i], tr[2i + 1])
    }
}

void update(int idx, int val)
{
    idx += N;
    tr[idx] = val;
    // update parent segments
    for (; idx; idx >>= 1)
    {
        tr[idx >> 1] = (tr[idx] + tr[idx ^ 1]); // tr[x / 2] = f(tr[x], tr[x +/- 1])
    }
}

int query(int l, int r)
{
    int res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1)
    {
        // if (l & 1) => right child is present, not left.
        // Thus take right child, and move to the right adjacent node.
        // Similar for r
        if (l & 1)
            res = (res + tr[l++]);
        if (r & 1)
            res = (res + tr[--r]);
    }
    return res;
}

int findVal(int idx)
{
    int lowIdx = idx, hiIdx = N - 1, val = -1;
    while (lowIdx <= hiIdx)
    {
        int mid = (lowIdx + hiIdx) / 2;
        if (query(lowIdx, mid + 1))
        {
            idx = mid;
            val = tr[mid + N];
            hiIdx = mid - 1;
        }
        else
        {
            lowIdx = mid + 1;
        }
    }
    update(idx, 0);
    return val;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = N; i < 2 * N; i++)
    {
        cin >> tr[i];
    }

    initialize();

    for (int i = 0, id; i < N; i++)
    {
        cin >> id;
        cout << findVal(id - 1) << ' ';
    }

    cout << '\n';

    return 0;
}