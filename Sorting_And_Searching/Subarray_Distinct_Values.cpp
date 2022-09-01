//
// Created by Sayan Bose on 01-09-2022.
//
#include<iostream>
#include <map>

#define len(x) (int) (x).size()

using namespace std;

typedef long long ll;

const int mxn = 2e5 + 10;
int x[mxn];

ll countSubarray(int left, int right) {
    // sub-arrays containing index left
    return right - left + 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    map<int, int> distinct;
    ll count = 0;
    for (int i = 0, j = 0; j < n; j++) {
        distinct[x[j]]++;
        while (len(distinct) > k) {
            count += countSubarray(i, j - 1);
            distinct[x[i]]--;
            if (!distinct[x[i]])
                distinct.erase(x[i]);
            i++;
        }
        if (j == n - 1) {
            while (!distinct.empty()) {
                count += countSubarray(i, j);
                distinct[x[i]]--;
                if (!distinct[x[i]])
                    distinct.erase(x[i]);
                i++;
            }
        }
    }
    cout << count << '\n';
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