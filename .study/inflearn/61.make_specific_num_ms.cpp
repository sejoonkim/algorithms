#include <iostream>
using namespace std;

int n, m, a[11], count = 0, path[11];

void DFS(int L, int sum) {
    
    if (L == n + 1) {
        if (sum == m) {
            count++;
            for (int i = 1; i < L; i++) {
                cout << path[i];
            }
            cout << '\n';
        }
    }
    else {
        path[L] = a[L];
        DFS(L + 1, sum + a[L]);
        path[L] = -a[L];
        DFS(L + 1, sum - a[L]);
        path[L] = 0;
        DFS(L + 1, sum);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int i;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    DFS(1, 0);

    if (count == 0) {
        cout << -1;
    }
    else {
        cout << count;
    }
    return 0;
}

// sensei

// int a[11], n, m, cnt = 0;

// void DFS(int L, int val) {
//     if (L == n + 1) {
//         if (val == m) {
//             cnt++;
//         }
//     }
//     else {
//         DFS(L + 1, val + a[L]);
//         DFS(L + 1, val - a[L]);
//         DFS(L + 1, val);
//     }
// }

// int main() {
//     int i;
//     cin >> n >> m;
//     for (i = 1; i <= n; i++) {

//         cin >> a[i];
//     }

//     if (cnt == 0) cout << -1;
//     else cout << cnt;
//     DFS(1, 0);
// }