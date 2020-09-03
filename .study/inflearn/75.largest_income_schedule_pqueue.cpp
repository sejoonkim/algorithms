#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// bool compare(const pair<int, int> &a, const pair<int, int> &b) {

//     if (a.second != b.second) {
//         return a.second > b.second;
//     }
//     return a.first > b.first;
// }

// int main(void) {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);

//     priority_queue<int> pQ;
//     int n, a, b, i, sum = 0, time = 0, maxVal = 0;
//     pair<int, int> x;
//     cin >> n;

//     // declare vector, sort with .second first and .first later
//     vector< pair<int, int> > v;

//     for (i = 1; i <= n; i++) {
//         cin >> a >> b;
//         v.push_back({a, b});
//         maxVal = max(b, maxVal);
//     }

//     sort(v.begin(), v.end(), compare);
    
//     // get the max price for each day limit
//     for (i = maxVal; i >= 1; i--) {
//         for (int j = 0; j < n; j++) {
//             if (v[j].second == i) {
//                 pQ.push(v[j].first);
//             }
//         }
//         sum += pQ.top();
//         pQ.pop();
//     }
    
//     cout << sum;
//     return 0;
// }

// sensei
// struct Data {
//     int money;
//     int when;
    
//     // constructor
//     Data (int a, int b) {
//         money = a;
//         when = b;
//     }

//     bool operator<(Data &b) {
//         return when > b.when;
//     } // 날짜에 의해서 내림차순 정렬
// };

// int main() {
//     int n, i, j, a, b, res = 0, max = -2147000000;

//     // vector of Data structs
//     vector<Data> T;

//     // save only money data
//     priority_queue<int> pQ;
//     cin >> n;

//     // get money and when
//     // call constructor
//     for (i = 1; i <= n; i++) {
//         cin >> a >> b;
//         T.push_back(Data(a, b));
//         if (b > max) {
//             max = b;
//         }
//     }
//     sort(T.begin(), T.end());
//     j = 0;
//     // date limits from 3, 2, 1
//     for (i = max; i >= 1; i--) {
//         for ( ; j < n; j++) {
//             // when date limit is smaller than i break;
//             if (T[j].when < i) break;
//             pQ.push(T[j].money);
//         }
//         if (!pQ.empty()) {
//             res += pQ.top();
//             pQ.pop();
//         }
//     }

//     cout << res;
//     return 0;
// }

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Data {
    int money;
    int when;
    Data (int a, int b) {
        money = a;
        when = b;
    }
    bool operator<(Data &b) {
        return when > b.when;
    }
};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, i, j, a, b, maxVal = -2147000000, sum = 0;
    cin >> n;

    vector<Data> T;
    priority_queue<int> pQ;

    for (i = 0; i < n; i++) {
        cin >> a >> b;
        T.push_back(Data(a, b));
        if (b > maxVal) {
            maxVal = b;
        }
    }

    sort(T.begin(), T.end());

    for (i = 0; i < n; i++) {
        cout << T[i].money << " : " << T[i].when << '\n';
    }

    j = 0;
    for (i = maxVal; i >= 1; i--) {
        for (; j < n; j++) {
            if (T[j].when < i) break; 
                pQ.push(T[j].money);
            
        }
        if (!pQ.empty()) {
            sum += pQ.top();
            pQ.pop();
        }
        
    }

    cout << sum;

    return 0;
}