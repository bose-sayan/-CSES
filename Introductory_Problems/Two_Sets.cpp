//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    ll sum = (ll(n) * ll(n + 1)) / 2ll;
    if (sum & 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    sum /= 2;
    vector<int> set_1, set_2;
    for (int i = n; i >= 1; i--) {
        if (sum < i) {
            if (sum)
                set_1.emplace_back(sum);
            while (i) {
                if (i != sum)
                    set_2.emplace_back(i);
                i--;
            }
            break;
        } else {
            set_1.emplace_back(i);
            sum -= i;
        }
    }
    cout << (int) set_1.size() << '\n';
    for (int &i: set_1)
        cout << i << ' ';
    cout << '\n' << (int) set_2.size() << '\n';
    for (int &i: set_2)
        cout << i << ' ';
    cout << '\n';
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