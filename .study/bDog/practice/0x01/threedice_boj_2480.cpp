// #include <iostream>
// #include <algorithm>
// using namespace std;

// int max(int one, int two, int three) {
//     int arr[3];
//     arr[0] = one; arr[1] = two; arr[2] = three;
//     return *max_element(arr, arr + 3);
// }

// int same(int one, int two, int three) {
//     if (one == two) return one;
//     else if (two == three) return two;
//     else return three;
// }

// int main(void) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(nullptr);
   
//    int one, two, three;
//    cin >> one >> two >> three;

//    if (one == two && two == three) cout << 10000 + one * 1000;
//    else if (one != two && two != three && one != three) cout << max(one, two, three) * 100;
//    else cout << 1000 + same(one, two, three) * 100;
//    return 0;
// }

#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int arr[7] = {};
    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        arr[num]++;
    }

    int result = 0;
    int maxNum = -1;
    for (int i = 1; i <= 6; i++) {
        if (arr[i] == 3) {
            result = 10000 + i * 1000;
            break;
        }
        else if (arr[i] == 2) {
            result = 1000 + i * 100;
            break;
        }
        else if (arr[i] == 1) {
            maxNum = max(maxNum, i);
        }

    }

    if (result) cout << result;
    else cout << maxNum * 100;



    
    return 0;
}