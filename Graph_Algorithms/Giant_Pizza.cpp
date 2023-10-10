#include <bits/stdc++.h>

using namespace std;

// Global Variables
const int MXN = 3e5 + 10;
vector<int> G[MXN], GT[MXN];
int out[MXN] = {}, outComp[MXN] = {}, col[MXN] = {};
int n, m, curTime = 1;

// Kosaraju's Algorithm for finding SCCs
void findOutTimeDfs(int src) {
    if (out[src])
        return;
    out[src] = 1;   // mark visited
    for (auto &i : G[src]) {
        findOutTimeDfs(i);
    }
    out[src] = curTime++;
}

void findSCCDfs(int src, int c) {
    if (col[src])
        return;
    col[src] = c;
    outComp[c] = max(outComp[c], out[src]);
    for (auto &i : GT[src]) {
        findSCCDfs(i, c);
    }
}

void kosaraju() {
    for (int i = 1; i <= 2 * n; i++) {
        if (!out[i])
            findOutTimeDfs(i);
    }
    vector<int> order(2 * n);
    iota(order.begin(), order.end(), 1);
    sort(order.begin(), order.end(),
         [&](int u, int v) -> bool { return out[u] > out[v]; });
    for (int i = 0, c = 1; i < 2 * n; i++) {
        if (!col[order[i]])
            findSCCDfs(order[i], c++);
    }
}

// Builds the implication graph
// Input: vector of clauses
void buildGraph(vector<pair<int, int>> &clauses) {
    for (auto [x, y] : clauses) {
        int negX = (x > n ? x - n : x + n), negY = (y > n ? y - n : y + n);
        G[negX].emplace_back(y);
        G[negY].emplace_back(x);
        GT[y].emplace_back(negX);
        GT[x].emplace_back(negY);
    }
}

void solve() {
    cin >> m >> n;
    vector<pair<int, int>> clauses(m);
    for (int i = 0; i < m; i++) {
        char ch1, ch2;
        int x1, x2;
        cin >> ch1 >> x1 >> ch2 >> x2;
        clauses[i].first = (ch1 == '+' ? x1 : x1 + n);
        clauses[i].second = (ch2 == '+' ? x2 : x2 + n);
    }
    buildGraph(clauses);
    kosaraju();
    string res;
    for (int i = 1; i <= n; i++) {
        if (col[i] == col[i + n]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        if (outComp[col[i]] > outComp[col[i + n]]) {
            res += '-';
        } else {
            res += '+';
        }
    }
    for (char &ch : res) {
        cout << ch << ' ';
    }
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