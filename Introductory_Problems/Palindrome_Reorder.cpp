//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>
#include <algorithm>

using namespace std;


int charFrequency[26] = {};

void solve() {
    string s;
    cin >> s;
    for (char &c: s)
        charFrequency[c - 'A']++;
    string res;
    char cur = 'A', oddFreqChar = '-';
    for (int &i: charFrequency) {
        if (i & 1) {
            if (oddFreqChar != '-') {
                cout << "NO SOLUTION\n";
                return;
            }
            oddFreqChar = cur++;
            continue;
        }
        i /= 2;
        while (i--)
            res += cur;
        cur++;
    }
    cout << res;
    while (oddFreqChar != '-' and charFrequency[oddFreqChar - 'A']--)
        cout << oddFreqChar;
    reverse(res.begin(), res.end());
    cout << res << '\n';
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