#include "stdio.h"

int fibo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibo(n-1) + fibo(n-2);
}

int fib_iter(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int pp = 0;
    int p = 1;
    int result = 0;

    for (int i = 2; i <= n; i++) {
        result = p + pp;
        pp = p;
        p = result;
    }

    return result;
}

int fib(int n) {
    printf("fib(%d) is called", n);
    if(n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main(void) {
    int n = 5;
    // printf("%d", fibo(10));
    fib(5);
    return 0;
}