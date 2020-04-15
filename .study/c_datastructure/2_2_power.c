#include "stdio.h"

double slow_power(double x, int n) {
    int i;
    double result = 1.0;

    for (i = 0; i < n; i++) {
        result = result * x;
    }
    return result;
}

double fast_power(double x, int n) {
    if (!n) return 1.0;
    else if (n & 1) {// n이 홀수 일때
        return x * fast_power(x * x, (n-1)/2);
    }
    else return fast_power(x * x, n/2);
}

int main(void) {
    double x = 1.2;
    int n = 3;
    printf("%f", slow_power(1.2, 3));
    return 0;
}