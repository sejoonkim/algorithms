#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용한다.

int board[502][502] = {
    {1,1,1,0,1,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
}; // 1 is Blue, 0 is Red

bool visited[502][502]; // save visited
int n = 7, m = 10; // n = number of rows, m = number of columns
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // the four directions

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    visited[0][0] = 1; // check already visited (0, 0)
    Q.push({0, 0}); // push to Q the starting point
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++) { // will check for all 4-directions
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어간다.
            if (nx < 0 or nx >= m or ny < 0 or ny >= n) continue; // 범위 밖일 경우 넘어간다.
            if (visited[nx][ny] or board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우 넘어간다.
            visited[nx][ny] = 1; // (nx, ny)를 방문했다고 명시한다.
            Q.push({nx, ny});
        }
    }
}