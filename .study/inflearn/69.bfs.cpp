#include <iostream>
#include <vector>
using namespace std;

// declare Q
int Q[100], front = -1, back = -1;
// declare check array
int ch[10];
// declare adj list
vector<int> map[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int i, a , b, x;
    for (i = 1; i <= 6; i++) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    ch[1] = 1;
    Q[++back] = 1;
    while (front < back) {
        x = Q[++front];
        cout << x << ' ';
        for (i = 0; i < map[x].size(); i++) {
            if (ch[map[x][i]] == 0) {
                ch[map[x][i]] = 1;
                Q[++back] = map[x][i];
            }
        }
    }
    return 0;
}




















































// // declare Q with front and back index
// int Q[100], front = -1, back = -1;
// // declare check array
// int ch[10];
// // declare adj list
// vector<int> map[10];

// int main(void) {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);

//     int i, a, b, x;
//     // num of edges is n-1
//     for (i = 1; i <= 6; i++) {
//         cin >> a >> b;
//         map[a].push_back(b);
//         map[b].push_back(a);
//     }

//     // work with Q
//     // Q process
//     // 1. insert vertex to Q using back index
//     // 2. access first element in Q using front index
//     // 3. if there are edges from the front index value, add to Q using back
//     // 4. stop the process when front < back is not true
//     Q[++back] = 1;
//     ch[1] = 1;
//     while (front < back) {
//         // access Q.front and pop
//         x = Q[++front];
//         cout << x;
//         // add edges from Q front index value
//         for (i = 0; i < map[x].size(); i++) {
//             if (ch[map[x][i]] == 0) {
//                 ch[map[x][i]] = 1;
//                 Q[++back] = map[x][i];
//             }
//         }
//     }

//     return 0;
// }