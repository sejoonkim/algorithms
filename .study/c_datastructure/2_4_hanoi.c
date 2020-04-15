#include "stdio.h"

void hanoi(int n, char from, char tmp, char to) {
    if (n == 1) {
        printf("move 1 from %c to %c\n", from, to);
    }
    else {
        hanoi(n-1, from, to, tmp);
        printf("move %d from %c to %c\n", n, from, to);
        hanoi(n-1, tmp, from, to);
    }
}

int main(void) {
    hanoi(5, 'A', 'B', 'C');
    return 0;
}