#include <iostream>
#include <ctime>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;

}

int main(void) {
    clock_t start, end;
    double duration;
    int sum = 0;

    start = clock();
    // start = time(NULL);

    // sum = 3 * 3;

    // for (int i = 0; i < 3; i++) {
    //     sum += 3;
    // }

    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         sum++;
    //     }
    // }

    // selection sort
    int arr[5] = { 30, 1, 59, 33, 19};
    
    for (int i = 0; i < (sizeof(arr)/ sizeof(int)) - 1; i++) {
        int smallest = arr[i];
        int smallest_index = i;
        for (int j = i + 1; j < sizeof(arr) / sizeof(int); j++) {
            if (arr[j] < smallest) {
                smallest = arr[j];
                smallest_index = j;
            }
        }
        swap(arr[i], arr[smallest_index]);
    }

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    end = clock();
    // end = time(NULL);

    duration = (double)(end - start) / CLOCKS_PER_SEC;
    // duration = (double) difftime(end, start);
    cout << duration << " seconds" << '\n';
    return 0;
}