//
// Created by Sayan Bose on 25-08-2022.
//
#include<iostream>

using namespace std;

struct LinkedList {
    int val;
    LinkedList *next;
};

void solve() {
    int n;
    cin >> n;
    LinkedList *head = new LinkedList(), *cur = head;
    for (int i = 1; i <= n; i++) {
        cur->val = i;
        if (i == n) {
            cur->next = head;
            break;
        }
        cur->next = new LinkedList();
        cur = cur->next;
    }
    int c = 1;
    LinkedList *prev = head;
    cur = head;
    while (n) {
        if (c == 2) {
            cout << cur->val << ' ';
            prev->next = cur->next;
            n--;
            c = 0;
        }
        c++;
        prev = cur;
        cur = cur->next;
    }
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