#include <stdio.h>
#define SIZE 6

void get_integers(int arr[]) {
    printf(" 6 inputs: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
}

int cal_sum(int arr[]) {
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += *(arr + i);
    }
    return sum;
}

int main(void) {
    int list[SIZE];
    get_integers(list);
    printf("Total = %d \n", cal_sum(list));
    return 0;
}