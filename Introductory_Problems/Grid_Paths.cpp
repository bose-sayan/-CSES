//
// Created by Sayan Bose on 19-08-2022.
//
#include<iostream>

using namespace std;


int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
char path[50];
bool vis[8][8] = {};

bool wallSplit(int x, int y) {
    if (x == 1 || x == 7) {
        return (y - 1 >= 1 && !vis[x][y - 1]) && (y + 1 <= 7 && !vis[x][y + 1]);
    }
    if (y == 1 || y == 7) {
        return (x - 1 >= 1 && !vis[x - 1][y]) && (x + 1 <= 7 && !vis[x + 1][y]);
    }
    return false;
}

bool pathSplit(int x, int y) {
    if (x == 1 || x == 7 || y == 1 || y == 7)
        return false;
    if ((!vis[x][y - 1] && !vis[x][y + 1]) && (vis[x + 1][y] && vis[x - 1][y]))
        return true;
    if ((!vis[x - 1][y] && !vis[x + 1][y]) && (vis[x][y + 1] && vis[x - 1][y - 1]))
        return true;
    return false;
}

int ans = 0;

void recurse(int id, int x, int y) {
    if (id == 48) {
        ans += (x == 7 && y == 1);
        return;
    }
    if (x == 7 and y == 1)
        return;
    if (wallSplit(x, y))
        return;
    if (pathSplit(x, y))
        return;
    if (path[id] == '?') {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if ((nx < 1 || nx > 7) || (ny < 1 || ny > 7))
                continue;
            if (vis[nx][ny])
                continue;
            vis[nx][ny] = true;
            recurse(id + 1, nx, ny);
            vis[nx][ny] = false;
        }
    } else {
        if (path[id] == 'U') {
            x--;
        } else if (path[id] == 'D') {
            x++;
        } else if (path[id] == 'L') {
            y--;
        } else {
            y++;
        }
        if ((x < 1 || x > 7) || (y < 1 || y > 7))
            return;
        else if (!vis[x][y]) {
            vis[x][y] = true;
            recurse(id + 1, x, y);
            vis[x][y] = false;
        }
    }
}

void solve() {
    scanf("%s", path);
    vis[1][1] = true;
    recurse(0, 1, 1);
    printf("%d", ans);
}

int main() {
    solve();
}