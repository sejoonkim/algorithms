#include <iostream>
using namespace std;

int maze[8][8], ch[8][8], cnt = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y) {
    cout << x << ' ' << y << '\n';
    int i;
    if (x == 7 && y == 7) {
        cnt++;
    }
    else {
        for (i = 0; i < 4; i++) {
            if (x + dx[i] < 1 || x + dx[i] > 7) continue;
            if (y + dy[i] < 1 || y + dy[i] > 7) continue;
            if (maze[x + dx[i]][y + dy[i]] == 0 && ch[x + dx[i]][y + dy[i]] == 0) {
                ch[x + dx[i]][y + dy[i]] = 1;
                DFS(x + dx[i], y + dy[i]);
                ch[x + dx[i]][y + dy[i]] = 0;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int i, j;
    for (i = 1; i <= 7; i++) {
        for (j = 1; j <= 7; j++) {
            cin >> maze[i][j];
        }
    }

    ch[1][1] = 1;
    DFS(1, 1);
    cout << cnt;

    return 0;
}

// sensei
