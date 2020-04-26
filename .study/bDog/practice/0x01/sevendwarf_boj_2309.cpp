/*
start - 01 : 16
  end - 

- target
  - have to find the sum == 100

- methods
  - exhaustive search
    - why 9 dwarfs, not 7
    - calculate the total sum
    - sum - arr[i] - arr[j] == 100
      - then print the elements, excluding indexes i and j
  - recursion
    -  choose this => failed

- save inputs to an array
- starting from the first element, pass count as 0 to recursion function
  - recursion ends when count = 7
  - exit the program when the sum is 100
  - else return;
*/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int sum;

void compute() {
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k != i && k != j) {
                        cout << arr[k] << '\n';
                    }
                }
                return;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + 9);

    compute();
    return 0;
}