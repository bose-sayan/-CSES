//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>

using namespace std;

typedef long long ll;

const int mod = (int) 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int zero_count = 0;
    for (int factor = 5; factor <= n; factor *= 5) {
        zero_count += n / factor;
    }
    cout << zero_count << '\n';
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