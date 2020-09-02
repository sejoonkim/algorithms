#include <iostream>
#include <cstdlib>
using namespace std;

// int n, arr[11], ch[11];
// int sum1, sum0;

// void DFS(int L) {
//     int i;
//     if (L == n + 1) {
//         for (i = 1; i <= n; i++) {
//             if (ch[i] == 1) {
//                 sum1 += arr[i];
//             }
//             else {
//                 sum0 += arr[i];
//             }
//         }
//         if (sum1 == sum0) {
//             cout << "YES";
//             exit(0);
//         }
//         else {
//             sum1 = sum0 = 0;
//         }
//     }
//     else {
//         ch[L] = 1;
//         DFS(L+1);
//         ch[L] = 0;
//         DFS(L+1);
//     }
// }

// int main(void) {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);

//     cin >> n;
    
//     int i;
//     for (i = 1; i <= n; i++) {
//         cin >> arr[i];
//     }

//     DFS(1);
//     cout << "NO" << '\n';    
//     return 0;
// }

// sensei
int n, a[11], total = 0;
bool flag = false;

void DFS(int L, int sum) {
    if (sum > total / 2) return;
    if (flag == true) return;
    if (L == n + 1) {
        if (sum == (total - sum)) {
            flag = true;
        }
    }
    else {
        DFS(L + 1, sum + a[L]);
        DFS(L + 1, sum);
    }
}
int main() {
    int i;
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        total += a[i];
    }
    DFS(1, 0);

    if (flag) cout << "YES";
    else cout << "NO";
    return 0;
}