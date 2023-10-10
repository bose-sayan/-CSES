//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>

using namespace std;


void solve() {
    string s;
    cin >> s;
    int n = (int) s.length();
    int maxLen = 0, curLen = 0;
    char lastChar = '.';
    for (int i = 0; i < n; i++) {
        if (s[i] == lastChar) {
            curLen++;
        } else {
            maxLen = max(maxLen, curLen);
            lastChar = s[i];
            curLen = 1;
        }
    }
    maxLen = max(maxLen, curLen);
    cout << maxLen << '\n';
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