//
// Created by Sayan Bose on 24-08-2022.
//
#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n, longestSeq = 0;
    cin >> n;
    unordered_map<int, int, custom_hash> mp;
    for (int i = 0, j = 0, x; j < n; j++) {
        cin >> x;
        auto it = mp.find(x);
        if (it != mp.end() and it->second >= i) {
            i = it->second + 1;
        }
        longestSeq = max(longestSeq, j - i + 1);
        mp[x] = j;
    }
    cout << longestSeq << '\n';
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