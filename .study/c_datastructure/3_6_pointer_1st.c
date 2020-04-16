#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define SIZE 10
int main(void) {
    int *p;
    p = (int*)malloc(sizeof(int) * 10);
    if (p == NULL) {
        fprintf(stderr, "no mem space\n");
        exit(1);
    }
    for (int i = 0; i < SIZE; i++) {
        p[i] = i;
    }
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", p[i]);
    }
    printf("%p", p);
    free(p);
    return 0;
}