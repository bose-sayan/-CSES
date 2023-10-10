//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    for (; n != 1;) {
        cout << n << ' ';
        if (n & 1)
            (n *= 3)++;
        else
            n >>= 1;
    }
    cout << 1 << '\n';
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