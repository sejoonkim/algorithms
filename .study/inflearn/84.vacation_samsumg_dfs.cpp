#include <iostream>
#include <vector>
using namespace std;

// int maxVal = -2147000000, n;
// vector< pair<int, int> > v;
// int res[16];

// void DFS(int L, int sum) {
//     int i;
//     if (L == 7) {
//         if (sum > maxVal) {
//             maxVal = sum;
//         }
//     }
//     else {
//         for (i = L; i <= n; i++) {
//             DFS(L+v[L].first, sum + v[L].second);
//         }
//     }
// }

// int main(void) {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);
//     int i, a, b;
//     cin >> n;
//     for (i = 1; i <= n; i++) {
//         cin >> a >> b;
//         v.push_back({a, b});
//     }

//     DFS(0, 0);
//     cout << maxVal;
//     return 0;
// }

// sensei
int n, res = -2147000000;
vector<int> T, P;
void DFS(int L, int sum) {
    if (L > n) {
        if (sum > res) res = sum;
    }
    else {
        if (L + T[L] <= n + 1) DFS(L + T[L], sum + P[L]);
        DFS(L + 1, sum);
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    int a, b;
    cin >> n;
    T.push_back(0); // 0번 인덱스 사용 안할 것이다.
    P.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        T.push_back(a);
        P.push_back(b);
    }
    DFS(1, 0);
    cout << res;
    return 0;
}