/*
start - 12 : 56
  end - 01 : 14

- target
  - calculate average
  - calculate median

- get 5 inputs to array
- sort the array ascending
- state sum variable
- arr[2] is the median
*/


#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = *a;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int arr[5];
    int sum = 0;


    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    //sort(arr, arr + 5);
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
    }

    // cout << sum / 5 << '\n' << arr[2];
    
    return 0;
}