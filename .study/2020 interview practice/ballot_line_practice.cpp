/*
1. cin N
2. declare booth[1001][2]
3. declare start, end && cin start, end
4. check if start >= booth[i][0] in a for loop
5. then booth[i][0] = end && break
6. booth[i] = end;
7. cout count of active booths, booth[i] != 0
*/

#include <bits/stdc++.h>
using namespace std;

int booth[1001];

int main(void) {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;

        for (int j = 0; j < 1001; j++) {
            if (start >= booth[j]) {
                booth[j] = end;
                break;
            }
            else if (booth[j] == 0){
                booth[j] = end;
                break;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 1001; i++) {
        if (booth[i])
        {
            count++;
        }
    }
    cout << count;
    return 0;
}
// int arr[160];

// int main(void) {
//     int N;
//     int start, end;
//     int max = -1;
//     cin >> N;

//     for (int i = 0; i < N; i++) {
//         cin >> start >> end;
//         for (int j = start; j < end; j++) {
//             arr[j]++;
//             if (max < arr[j]) max = arr[j];
//         }
//     }

//     cout << max;

//     return 0;
// }