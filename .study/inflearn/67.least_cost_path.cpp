#include <iostream>
#include <vector>
using namespace std;

int ch[30], minVal = 2147000000, n;
vector< pair<int, int> > map[30];

void DFS(int v, int sum) {
    int i;
    if (v == n) {
        if  (sum < minVal) {
            minVal = sum;
            cout << minVal << '\n';
        }
    }
    else {
        for (i = 0; i < map[v].size(); i++) {
            if (ch[map[v][i].first] == 0) {
                ch[map[v][i].first] = 1;
                DFS(map[v][i].first, sum + map[v][i].second);
                ch[map[v][i].first] = 0;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int m, i, a, b, c;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        map[a].push_back({b, c});
    }

    ch[1] = 1;
    DFS(1, 0);
    cout << minVal;

    return 0;
}

// // sensei
// int map[30][30], ch[30], n, cost = 2147000000;

// void DFS(int v, int sum) {
//     int i;
//     if (v == n) {
//         if (sum < cost) {
//             cost = sum;
//             cout << cost << '\n';
//         }
//     }
//     else {
//         for (i = 1; i <= n; i++) {
//             if (map[v][i] > 0 && ch[i] == 0) {
//                 ch[i] = 1;
//                 DFS(i, sum + map[v][i]);
//                 ch[i] = 0;
//             }
//         }
//     }
// }

// int main() {
//     int m, i, a, b, c;
//     cin >> n >> m;
//     for (i = 1; i <= m; i++) {
//         cin >> a >> b >> c;
//         map[a][b] = c;
//     }
//     ch[1] = 1;
//     DFS(1, 0);
// }