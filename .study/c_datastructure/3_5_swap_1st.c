#include <stdio.h>

void swap(int *a, int * b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int a = 3, b = 4;
    int *p1, *p2;
    p1 = &a; p2 = &b;
    swap(p1, p2);
    printf("%d %d", a, b);
    return 0;
}