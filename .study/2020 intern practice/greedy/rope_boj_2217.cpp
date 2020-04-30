/*
start - 10 : 29
  end - 

- if weight = 500 and there are 10 ropes
- 50 to each rope
- which means the min handle weight for rope is 50

- DO NOT HAVE TO CHOOSE ALL ROPE
- 100 50 1 -. highest is 1 if use all 3
- 100 if used 2
- the biggest, the smallest. the smallest has to be bigger than 
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int n;
// vector<int> v;

// int main(void) {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);

//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         int num;
//         cin >> num;
//         v.push_back(num);
//     }

//     sort(v.begin(), v.end());

//     int num_rope = n;
//     int max = -1;
//     for (int i = 0; i < n; i++) {
//         int mul = v[i] * num_rope;
//         if (max < mul)
//             max = mul;
//         num_rope--;
//     }
//     cout << max << '\n';
//     return 0;
// }

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[100003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, arr[n-i] * i);
    }
    cout << res;
    return 0;
}