/*
start - 
  end - 

- think in real life
- use from the biggest value of coin
- condition: A(i) is a multiple of A(i-1)
    - if not, greedy algorithm will not suit

1. get the inputs n, k
2. save the coin values to an array, size of 10
3. for loop
    1. state temp = k / a[i] // t is the number of coins used
    2. num += t
    3. k -= t*a[i];
4. cout num
*/

#include <iostream>
using namespace std;

int n, k;
int a[10];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int num = 0;
    for (int i = n - 1; i >= 0; i--) {
        int temp = k / a[i];
        num += temp;
        k -= temp * a[i];
    }

    cout << num << '\n';
    return 0;
}
