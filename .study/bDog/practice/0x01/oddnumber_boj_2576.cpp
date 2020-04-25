/*
start - 11 : 49
  end - 

- state variables: min, oddSum
- loop over 7 numbers
  - if odd number, add to oddSum
    - if smaller than min, then make it min
  
*/

#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int i, num, oddSum = 0, min = 101;

    for (i = 0; i < 7; i++) {
        cin >> num;
        if (num & 1) {
            oddSum += num;
          if (min > num) {
              min = num;
          }
        }
    }

    if (!oddSum) {
      cout << -1;
    } else {
      cout << oddSum << '\n' << min;
    }
    
    return 0;
}