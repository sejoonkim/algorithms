/*
start - 12 : 07
  end - 

- How to find number of ways to D[n]?
    - think as 2-D array

1. get n inputs
2. get stair points to array
3. create 2-d array for DP
    1. get the inputs for d[1] and d[2]
    2. fromd[3] loop to n
4. cout the result max
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int point[302];
int d[302][4];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> point[i];
    }

    // initialize
    d[1][1] = point[1]; d[1][2] = 0;
    d[2][1] = point[2]; d[2][2] = point[1] + point[2];

    // loop from 3
    for (int i = 3; i <= n; i++) {
        d[i][1] = max(d[i-2][1], d[i-2][2]) + point[i];
        d[i][2] = d[i-1][1] + point[i];
    }

    cout << max(d[n][1], d[n][2]);
    
    return 0;
}