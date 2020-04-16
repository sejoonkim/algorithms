#include "stdio.h"

int bc(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    }
    return bc(n-1, k-1) + bc(n-1, k);
}

int bc_loop(int n, int k) {
    int t1 = 1, t2 = 1, t3 = 1;
    for (int i = 1; i <= n; i++) {
        t1 *= i;
    }
    for (int i = 1; i <= k; i++) {
        t2 *= i;
    }
    for (int i = 1; i <= n-k; i++) {
        t3 *= i;
    }
    return t1/(t2*t3);
}
int main(void) {
    printf("%d", bc_loop(5, 2));
    return 0;
}