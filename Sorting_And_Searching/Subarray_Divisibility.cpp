//
// Created by Sayan Bose on 01-09-2022.
//
#include<iostream>
#include <map>

using namespace std;

typedef long long ll;

ll add(ll a, ll b, ll mod) {
    return ((a % mod) + (b % mod)) % mod;
}


/*
 * (prefixSum[r] - prefixSum[l]) % n == 0
 * ((p[r] % n) - (p[l] % n)) % n == 0, this implies =>
 * (p[r] % n) - (p[l] % n) == 0 or
 * (p[r] % n) - (p[l] % n) == n or
 * (p[r] % n) - (p[l] % n) == -n
 * This is because, upperBound(exp) = (n - 1) - (-(n - 1)) = 2n - 2
 * 2n - 2 is the max value, any other difference we will get will be less than it
 * Thus next lower number divisible by n is n itself
 * Thus n can be considered as the maximum value one can get
 * ||ly for the minimum bound.
 */

void solve() {
    int n;
    cin >> n;
    ll cnt = 0, cSum = 0;
    map<ll, ll> pref;
    pref[0]++;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        cSum = add(cSum, x, n);
        cnt += pref[cSum];
        cnt += pref[cSum - n];
        cnt += pref[cSum + n];
        pref[cSum]++;
    }
    cout << cnt << '\n';
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