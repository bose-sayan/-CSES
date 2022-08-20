//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>

using namespace std;

// Sol 1 -> Sum of n numbers - Sum of given numbers
// Sol 2 -> XOR of n numbers ^ XOR of given numbers


void solve() {
    int n;
    cin >> n;
    int x1 = 1, x2 = 0;
    for (int i = 2, num; i <= n; i++) {
        x1 ^= i;
        cin >> num;
        x2 ^= num;
    }
    cout << (x1 ^ x2) << '\n';
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