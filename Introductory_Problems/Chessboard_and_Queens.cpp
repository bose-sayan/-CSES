//
// Created by Sayan Bose on 18-08-2022.
//
#include<iostream>

using namespace std;

char board[8][8];

/*
 * Check if queen can be placed in cell (a, b)
 *  -> No other queen in row a
 *  -> No other queen in col b
 *  -> No other queen in upper left diagonal (a - b)
 *  -> No other queen in upper right diagonal (a + b)
 */

bool col[8] = {};
bool rightDiagonal[20] = {};
bool leftDiagonal_P[8] = {}, leftDiagonal_N[8] = {};

bool check(int i, int j) {
    if (board[i][j] == '*')
        return false;
    if (col[j])
        return false;
    if (rightDiagonal[i + j])
        return false;
    if (i - j < 0 ? leftDiagonal_N[abs(i - j)] : leftDiagonal_P[i - j])
        return false;
    return true;
}

void update(int i, int j) {
    col[j] = rightDiagonal[i + j] = true;
    if (i < j) {
        leftDiagonal_N[abs(i - j)] = true;
    } else {
        leftDiagonal_P[i - j] = true;
    }
}

void rollBack(int i, int j) {
    col[j] = rightDiagonal[i + j] = false;
    if (i < j) {
        leftDiagonal_N[abs(i - j)] = false;
    } else {
        leftDiagonal_P[i - j] = false;
    }
}

int recurse(int queenCount, int i = 0, int j = 0) {
    if (!queenCount)
        return 1;
    else if (i > 7 or j > 7)
        return 0;
    if (!check(i, j)) {
        return recurse(queenCount, i + (j == 7), (j == 7 ? 0 : j + 1));
    }
    update(i, j);
    int count = recurse(queenCount - 1, i + 1, 0);
    rollBack(i, j);
    count += recurse(queenCount, i + (j == 7), (j == 7 ? 0 : j + 1));
    return count;
}

void solve() {
    for (auto &i: board) {
        for (char &j: i) {
            cin >> j;
        }
    }
    cout << recurse(8) << '\n';
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