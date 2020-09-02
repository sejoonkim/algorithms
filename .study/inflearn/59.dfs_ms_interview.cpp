/*
원인
맨 마지막 호출 D(4)가 2번씩 호출된다.
순서가 맞지 않는다.

선생님의 경우 check를 따로 변수로 빼지 않고,
하나의 Root에서 시작되어 자식 2개씩 증가하는 상황으로 DFS의 원칙에 맞게 구현하였다.
미리 배열도 생성하여 전역으로 접근 가능하게 하였다.

LEVEL이라는 개념. LEVEL마다 처리할 것이다.
*/

#include <iostream>
#include <vector>
using namespace std;

int n, ch[11];

void DFS(int L) {
    int i;
    if (L == n + 1) {
        for (i = 1; i <= n; i++) {
            if (ch[i] == 1) {
                cout << i << ' ';
            }
        }
        cout << '\n';
        return;
    }
    else {
        ch[L] = 1;
        DFS(L+1);
        ch[L] = 0;
        DFS(L+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    DFS(1);
    return 0;
}






// int n, N, ch[11];

// void printVec(vector<int> &vec) {
//     for (int i = 1; i <= N; i++) {
//         if (vec[i] == 1) {
//             cout << i << ' ';
//         }
//     }
//     cout << '\n';
// }

// void D(int v, int check, vector<int> &vec) {
//     if (v == N+1) {
//         printVec(vec);
//         return;
//     }
//     else {
//         vec[v] = check;
//         if (v + 1 > N) {
//             D(v+1, 1, vec);
//         }
//         else {
//             D(v+1, 1, vec);
//             D(v+1, 0, vec);
//         }
//     }
// }

// int main(void) {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);

//     int i;
//     cin >> N;

//     vector<int> v(N+1);

//     D(1, 1, v);
//     D(1, 0, v);
    
//     return 0;
// }

// sensei
// void DFS(int L) {
//     int i;
//     if (L == n + 1) {
//         for (i = 1; i <= n; i++) {
//             if (ch[i] == 1) cout << i << ' ';
//         }
//         cout << '\n';
//     }
//     else {
//         ch[L] = 1;
//         DFS(L + 1);
//         ch[L] = 0;
//         DFS(L + 1);
//     }
// }

// int main() {
//     cin >> n;
//     DFS(1);
//     return 0;
// }