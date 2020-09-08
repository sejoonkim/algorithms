#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr, oper;
int minV = 2147000000, maxV = -2147000000;

void DFS(int L, int res) {
    if (L == n) {
        if (res > maxV) {
            maxV = res;
        }
        if (res < minV) {
            minV = res;
        }
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (oper[i] > 0) {
                if (i == 0) {
                    oper[i]--;
                    DFS(L+1, res + arr[L]);
                    oper[i]++;
                }
                else if (i == 1) {
                    oper[i]--;
                    DFS(L+1, res - arr[L]);
                    oper[i]++;
                }
                else if (i == 2) {
                    oper[i]--;
                    DFS(L+1, res * arr[L]);
                    oper[i]++;
                }
                else if (i == 3) {
                    oper[i]--;
                    DFS(L+1, res / arr[L]);
                    oper[i]++;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int i, a;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    for (i = 0; i < 4; i++) {
        cin >> a;
        oper.push_back(a);
    }
    DFS(1, arr[0]);
    cout << maxV << '\n' << minV;
    return 0;
}

// sensei
// void DFS(int L, int res) {
//     if (L == n) {
//         if (res > maxi) maxi = res;
//         if (res < mini) mini = res;
//     }
//     else {
//         if (op[0] > 0) {
//             op[0]--;
//             DFS(L+1, res + a[L]);
//             op[0]++;
//         }
//         if (op[1] > 0) {
//             op[1]--;
//             DFS(L+1, res + a[L]);
//             op[1]++;
//         }
//         if (op[2] > 0) {
//             op[2]--;
//             DFS(L+1, res + a[L]);
//             op[2]++;
//         }
//         if (op[3] > 0) {
//             op[3]--;
//             DFS(L+1, res + a[L]);
//             op[3]++;
//         }
//     }
// }