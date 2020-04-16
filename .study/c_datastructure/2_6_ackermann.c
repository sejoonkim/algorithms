#include "stdio.h"

int ack(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return ack(m-1, 1);
    return ack(m-1, ack(m, n-1));
}

int ack_loop(int m, int n) {
    
}

int main(void) {
    printf("%d\n", ack(2, 3));
    printf("%d\n", ack_loop(2, 3));
    return 0;
}