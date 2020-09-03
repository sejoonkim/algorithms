#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// int Q[21], front = -1, back = -1;
// int ch[21];
// vector<int> map[21];
// int visit[21];

// int main(void) {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);

//     int n, m, a, b, i, x;
//     cin >> n >> m;

//     for (i = 1; i <= m; i++) {
//         cin >> a >> b;
//         map[a].push_back(b);
//     }

//     ch[1] = 1;
//     Q[++back] = 1;

//     while (front < back) {
//         x = Q[++front];
//         for (i = 0; i < map[x].size(); i++) {
//             if (ch[map[x][i]] == 0) {
//                 ch[map[x][i]] == 1;
//                 Q[++back] = map[x][i];
//                 if (visit[map[x][i]] == 0) {
//                     visit[map[x][i]] = visit[x] + 1;
//                 }
//                 else
//                     visit[map[x][i]] = min(visit[map[x][i]], visit[x] + 1);
                
                    
//             }
//         }
//     }

//     for (i = 2; i <= n; i++) {
//         cout << i << " : " << visit[i] << '\n';
//     }
//     return 0;
// }

// sensei
int ch[30], dis[30];
int main() {
    int n, m, a, b, x, i;
    vector<int> map[30];
    queue<int> Q;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b;
        map[a].push_back(b);
    }
    Q.push(1);
    ch[1] = 1;
    while (!Q.empty()) {
        x = Q.front();
        Q.pop();
        for (i = 0; i < map[x].size(); i++) {
            if (ch[map[x][i]] == 0) {
                ch[map[x][i]] = 1;
                Q.push(map[x][i]);
                dis[map[x][i]] = dis[x] + 1;
            }
        }
    }
    for (i = 2; i <= n; i++) {
        cout << i << " : " << dis[i] << '\n';
    }
}