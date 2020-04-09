/*
start - 13 : 53
end - 14 : 28

- visited array = the for loop goes through each elements is the visited array and then does BFS on them
- make a pair in the queue, pair<int, int> pair->first is the x, and pair->second is the y
- make a vector to save the counts of area

1. get the inputs
    - do double for loop to get the graph
2. set the combinations of movement
    - up, down, left, right
3. start the for loop, do BFS if the root node is not visited, push to Q the starting point
4. get Q.front() and pop
5. explore for all four directions
6. push the elements to Q
*/

#include <bits/stdc++.h>
using namespace std;

int board[501][501];
int visited[501][501];


// the four directions
int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
   
    vector<int> numbers;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            if (board[i][j] == 1 && !visited[i][j]) {
                int count = 0;
                queue< pair<int,int> > Q; // initialize the queue.
                visited[i][j] = 1;
                Q.push({i, j});
                count++;

                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (visited[nx][ny] || board[nx][ny] != 1) continue;
                        visited[nx][ny] = 1;
                        Q.push({nx, ny});
                        count++;
                    }
                }
                numbers.push_back(count);
            }
        }
    }
    if (!numbers.empty()){
        cout << numbers.size() << '\n' << *max_element(numbers.begin(), numbers.end()) << '\n';
    }
    else cout << 0 << '\n' << 0;
    return 0;
}
