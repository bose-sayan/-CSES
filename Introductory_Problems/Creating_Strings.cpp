//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(string &in, int partition = 0) {
    if (partition == (int) in.length() - 1) {
        cout << in << '\n';
        return;
    }
    permute(in, partition + 1);
    for (int i = partition + 1; i < (int) in.length(); i++) {
        if (in[i] == in[i - 1])
            continue;
        for (int j = i; j > partition; j--)
            swap(in[j], in[j - 1]);
        permute(in, partition + 1);
        for (int j = partition; j < i; j++)
            swap(in[j], in[j + 1]);
    }
}

int factorial(int n) {
    return (!n ? 1 : n * factorial(n - 1));
}

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<int> cnt(26);
    for (char &c: s)
        cnt[c - 'a']++;
    int permutationCount = factorial((int) s.length());
    for (int &i: cnt)
        permutationCount /= factorial(i);
    cout << permutationCount << '\n';
    permute(s);
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