#include <iostream>
#include <queue>
using namespace std;

// int ch[10001];
// int dis[10001];

// int main(void) {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);

//     int s, e, x, i;
//     cin >> s >> e;

//     queue<int> Q;

//     Q.push(s);
//     ch[s] = 1;
//     while (!Q.empty()) {
//         x = Q.front();
//         Q.pop();
//         if (x == e) {
//             cout << dis[e];
//             break;
//         }
//         for (i = 0; i < 3; i++) {
//             Q.push(x-1);
//             if (dis[x-1] == 0) dis[x-1] = dis[x] + 1;
//             Q.push(x+1);
//             if (dis[x+1] == 0) dis[x+1] = dis[x] + 1;
//             Q.push(x+5);
//             if (dis[x+5] == 0) dis[x+5] = dis[x] + 1;
//         }
//     }
//     return 0;
// }


int ch[10001], d[3] = {1, -1, 5};
int main() {
    int s, e, x, pos, i;
    queue<int> Q;
    cin >> s >> e;
    Q.push(s);
    ch[s] = 1;
    while (!Q.empty()) {
        x = Q.front();
        Q.pop();
        for (i = 0; i < 3; i++) {
            pos = x + d[i];
            if (pos <= 0 || pos > 10000) continue;
            if (pos == e) {
                cout << ch[x];
                exit(0);
            }
            if (ch[pos] == 0) {
                Q.push(pos);
                ch[pos] = ch[x] + 1;
            }
        }
    }
    return 0;
}

























// // sensei

// int ch[10001], d[3] = {1, -1, 5};
// int main() {
//     int s, e, x, pos, i;
//     queue<int> Q;
//     cin >> s >> e;
//     ch[s] = 1;
//     Q.push(s);
//     while (!Q.empty()) {
//         x = Q.front();
//         Q.pop();
//         for (i = 0; i < 3; i++) {
//             pos = x + d[i];
//             if (pos <= 0 || pos > 10000) continue;
//             if (pos == e) {
//                 cout << ch[x];
//                 exit(0);
//             }
//             if (ch[pos] == 0) {
//                 ch[pos] = ch[x] + 1;
//                 Q.push(pos);
//             }
//         }
//     }
//     return 0;
// }
