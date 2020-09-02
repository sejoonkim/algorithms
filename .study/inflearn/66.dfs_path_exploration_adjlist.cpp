#include <iostream>
#include <vector>
using namespace std;

int ch[30], cnt = 0, n;
vector<int> map[30];

void DFS(int v) {
    int i;
    if (v == 5) {
        cnt++;
    }
    else {
        for (i = 0; i < map[v].size(); i++) {
            if (ch[map[v][i]] == 0) {
                ch[map[v][i]] = 1;
                DFS(map[v][i]);
                ch[map[v][i]] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, a, b, i;

    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b;
        map[a].push_back(b);
    }
    ch[1] = 1;
    DFS(1);
    cout << cnt;
}


// // sensei

// int ch[30], cnt = 0, n;
// vector<int> map[30]; // 30개 vector가 생성된다.

// void DFS(int v) {
//     int i;
//     if (v == n) {
//         cnt++;
//     }
//     else {
//         for (i = 0; i < map[v].size(); i++) {
//             if(ch[map[v][i]] == 0) {
//                 ch[map[v][i]] = 1;
//                 DFS(map[v][i]);
//                 ch[map[v][i]] = 0;
//             }
//         }
//     }
// }

// int main() {
//     int m, i, a, b;
//     cin >> n >> m;
//     for (i = 1; i <= m; i++) {
//         cin >> a >> b;
//         map[a].push_back(b);
//     }
//     ch[1] = 1;
//     DFS(1);
//     cout << cnt;
// }
