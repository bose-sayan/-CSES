#include<iostream>
#include <algorithm>

using namespace std;

void printInBinary(int num, int length) {
    string binForm;
    while (num) {
        binForm += ((num & 1) ? '1' : '0');
        num >>= 1;
    }
    while ((int) binForm.length() != length) {
        binForm += '0';
    }
    reverse(binForm.begin(), binForm.end());
    cout << binForm << '\n';
}

bool vis[66000] = {};

void generate(int length, int curCode = 0) {
    printInBinary(curCode, length);
    vis[curCode] = true;
    for (int i = 0; i < length; i++) {
        int nextCode = curCode ^ (1 << i);
        if (!vis[nextCode])
            generate(length, nextCode);
    }
}

void solve() {
    int n;
    cin >> n;
    generate(n);
}

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    int tests;
//    cin >> tests;
//    while (tests--)
    solve();
    return 0;
}