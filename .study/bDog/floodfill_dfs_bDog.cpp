#include <iostream>
#include <stack>

using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,1,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

bool visited[502][502];
int n = 7, m = 10;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack< pair<int, int> > s;

    visited[0][0] = 1;
    s.push({0, 0});

    while(!s.empty()) {
        auto cur = s.top(); s.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!board[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            s.push({nx, ny});
        }
        
    }
    return 0;
}