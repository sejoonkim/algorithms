/*
start - 11 : 32
  end - 

- three operations
    1. if X % 3 == 0 X/3
    2. if X % 2 == 0 X/2
    3. X = X - 1

1. get the input n
2. run compute(int num, int count)
    1. if num = 1 if (total > count) total = count
    1. if num % 3 == 0 compute(X/3, count+1)
    2. if num % 2 == 0 compute(X/2, count+1)
    3. else compute(X-1, count+1)
3. print total

-----QUESTION-----
1. How to avoid time out error?
    - Was trying to do recursion in all operations

-----HINT-----
1. starting from the answer, and coming backwards
2. D[i] = min number of operations to make i to 1
3. D[1] = 0, D[2] = 1, D[3] = 1, D[4] = 2, D[5] = 3, D[6] = 2, D[7] = 3, D[8] = 3, D[9] = 2, D[10] = 3, D[11] = 4
4. D[12] = min(D[4] + 1, D[6] + 1, D[11] + 1);
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[1000005];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    d[1] = 0;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i-1] + 1;
        if (i % 2 == 0) d[i] = min(d[i], d[i/2] + 1);
        if (i % 3 == 0) d[i] = min(d[i], d[i/3] + 1);
    }
    cout << d[n];
    return 0;
}