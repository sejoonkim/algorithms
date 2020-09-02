#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     stack<int> s;
//     vector<int> v;
//     int n, i, tmp;
//     cin >> n;

//     cin >> tmp;
//     s.push(tmp);
//     cout << 'P';

//     for (i = 1; i <= n; i++) {
//         v.push_back(i);
//     }
//     // v = {1, 2, ... n}

//     for (i = 1; i < n; i++) {
//         cin >> tmp;
//         if (tmp < s.top()) {
//             s.push(tmp);
//             cout << 'P';
//         }
//         else {
//             while (!s.empty() && tmp > s.top()) {
//                 s.pop();
//                 cout << 'O';
//             }
//             s.push(tmp);
//             cout << 'P';
//             if (i == n-1) {
//                 s.pop();
//                 cout << 'O';
//             }
//         }
        
//     }

//     if (!s.empty()) {
//         cout << "Stack Not Empty!";
//     }
    
//     return 0;
// }

//sensei
int main() {
    stack<int> s;
    int i, j = 1, n, m;
    cin >> n;
    //vector<int> a(n+1);

    // 도착 순서 정하기 [1, 2, 3, 4...]
    // for (i = 1; i <= n; i++) {
    //     a[i] = i;
    // }
    vector<char> str;
    for (i = 1; i <= n; i++) {
        cin >> m;
        s.push(m);
        str.push_back('P');
        while(1) {
            if (s.empty()) break;
            if (j == s.top()) {
                s.pop();
                str.push_back('O');
                j++;
            }
            else {
                break;
            }
        }
    }

    if (!s.empty()) {
        cout << "impossible" << '\n';
    }
    else {
        for (i = 0; i < str.size(); i++) {
            cout << str[i];
        }
    }
    return 0;
}

/*
Goal

*/