// /*
// start - 12 : 11
//   end - 

// 1. global variables
//     1. #define for the X and Y to first and second
//     2. n, m, g, r
//     3. board
//     4. dx, dy
//     5. vector for candidates
//     6. candsz
//     7. const int EMPTY, GREEN, RED, FLOWER
//     8. for backtracking = isused[10]
//     9. index for each color = chosen_g[5], chosen_r[5]
//     10. max

// 2. main
//     1. get the inputs nmgr
//     2. initialize the board
//         1. when board is 2, push back to the candidate
//     3. candsz = cand.size()
//     4. select_g(0);

// 3. select_g(0)
//     1. if number of green juice is zero
//         1. select_r(0) 
//         2. return
//     2. initialize current
// */

// #include <iostream>
// #include <queue>
// using namespace std;

// #define X first
// #define Y second

// int n,m,g,r;
// int board[52][52];
// int dx[4] = {1,0,-1,0};
// int dy[4] = {0,1,0,-1};
// vector<pair<int,int> > cand;
// int candsz;
// const int EMPTY = 0;
// const int GREEN = 1;
// const int RED = 2;
// const int FLOWER = 3;
// // backtracking을 위한 변수
// bool isused[10];
// // 초록/빨강 배양액으로 선택한 위치의 index
// int chosen_g[5], chosen_r[5]; 

// int mx;


// int solve(){
//   int cnt = 0;
//   pair<int,int> state[52][52]; // {arrival time, color}

//   queue<pair<int,int>> q;
//   for(int i = 0; i < g; i++){
//     state[cand[chosen_g[i]].X][cand[chosen_g[i]].Y] = {0, GREEN};
//     q.push(cand[chosen_g[i]]);
//   }
//   for(int i = 0; i < r; i++){
//     state[cand[chosen_r[i]].X][cand[chosen_r[i]].Y] = {0, RED};
//     q.push(cand[chosen_r[i]]);
//   }

//   while(!q.empty()){
//     auto cur = q.front(); q.pop();
//     int curtime = state[cur.X][cur.Y].X;
//     int curcolor = state[cur.X][cur.Y].Y;
//     if(state[cur.X][cur.Y].Y == FLOWER) continue;
//     for(int dir = 0; dir < 4; dir++){
//       int nx = cur.X + dx[dir];
//       int ny = cur.Y + dy[dir];
//       if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
//       if(board[nx][ny] == 0) continue;
//       if(state[nx][ny].Y == EMPTY){
//         state[nx][ny] = {curtime+1, curcolor};
//         q.push({nx,ny});
//       }
//       else if(state[nx][ny].Y == RED){
//         if(curcolor == GREEN && state[nx][ny].X == curtime+1){
//           cnt++;
//           state[nx][ny].Y = FLOWER;
//         }
//       }
//       else if(state[nx][ny].Y == GREEN){
//         if(curcolor == RED && state[nx][ny].X == curtime+1){
//           cnt++;
//           state[nx][ny].Y = FLOWER;
//         }        
//       }
//     }
//   }
//   return cnt;
// }

// void select_r(int idx){
//   if(idx == r){
//     mx = max(mx, solve());
//     return;
//   }
//   int cur = 0;
//   if(idx != 0) cur = chosen_r[idx-1]+1;
//   while(cur < candsz){
//     if(isused[cur]){
//       cur++;
//       continue;
//     }
//     isused[cur] = true;
//     chosen_r[idx] = cur;
//     select_r(idx+1);
//     isused[cur] = false;
//     cur++;
//   }
// }
// void select_g(int idx){
//   if(idx == g){
//     select_r(0);
//     return;
//   }
//   int cur = 0;
//   if(idx != 0) cur = chosen_g[idx-1]+1;
//   while(cur < candsz){
//     isused[cur] = true;
//     chosen_g[idx] = cur;
//     select_g(idx+1);
//     isused[cur] = false;
//     cur++;
//   }
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n >> m >> g >> r;  
//   for(int i = 0; i < n; i++){
//     for(int j = 0; j < m; j++){
//       cin >> board[i][j];
//       if(board[i][j] == 2)
//         cand.push_back({i,j});
//     }
//   }
//   candsz = cand.size();
//   select_g(0);
//   cout << mx << '\n';
// }

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m,g,r;
int board[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int> > cand;
int candsz;
const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;
// next_permutaion을 위한 변수, cand가 7이고 g=1,r=4일 때 {0,0,1,2,2,2,2}
int brute[10];


int solve(){
  int cnt = 0;
  pair<int,int> state[52][52]; // {arrival time, color}

  queue<pair<int,int>> q;
  for(int i = 0; i < candsz; i++){
    if(brute[i] == GREEN || brute[i] == RED){
      state[cand[i].X][cand[i].Y] = {0, brute[i]};
      q.push(cand[i]);
    }
  }
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    int curtime = state[cur.X][cur.Y].X;
    int curcolor = state[cur.X][cur.Y].Y;
    if(state[cur.X][cur.Y].Y == FLOWER) continue;
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == 0) continue;
      if(state[nx][ny].Y == EMPTY){
        state[nx][ny] = {curtime+1, curcolor};
        q.push({nx,ny});
      }
      else if(state[nx][ny].Y == RED){
        if(curcolor == GREEN && state[nx][ny].X == curtime+1){
          cnt++;
          state[nx][ny].Y = FLOWER;
        }
      }
      else if(state[nx][ny].Y == GREEN){
        if(curcolor == RED && state[nx][ny].X == curtime+1){
          cnt++;
          state[nx][ny].Y = FLOWER;
        }        
      }
    }
  }
  return cnt;
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> g >> r;  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      assert(board[i][j] >= 0 && board[i][j] <= 2);
      if(board[i][j] == 2)
        cand.push_back({i,j});
    }
  }
  candsz = cand.size();
  fill(brute+candsz-g-r, brute+candsz-r,GREEN);
  fill(brute+candsz-r, brute+candsz,RED);
  int mx = 0;
  do{
    mx = max(mx, solve());
  }while(next_permutation(brute, brute+candsz));
  cout << mx << '\n';
}