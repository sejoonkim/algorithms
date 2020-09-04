// factorial with recursion
#include <iostream>
using namespace std;

int dy[21][21];

int factorial(int n) {
    if (n == 1) return 1;
    else return n * factorial(n - 1);
}

int bi_co(int n, int r) {
    // memoization
    if (dy[n][r] > 0) return dy[n][r];
    if (n == r || r == 0) {
        return 1;
    }
    else {
        return dy[n][r] = bi_co(n-1, r) + bi_co(n-1, r-1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cout << bi_co(9, 3);
    return 0;
}