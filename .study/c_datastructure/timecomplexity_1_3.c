#include <stdio.h>
#include <time.h>
#define SIZE 5

int iarray[SIZE];

void store(int i, int item) {
    iarray[i] = item;
}

int retrieve(int i) {
    return iarray[i];
}

int main(void) {
    clock_t start, stop;
    double duration;
    int sum = 0;
    start = clock();
    
    // sum = 3 * 3;

    // for (int i = 0; i < 3; i++)
    // {
    //     sum += 3;
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         sum++;
    //     }
    // }

    for (int i = 0; i < SIZE; i++)
    {
        store(i, i+1);
    }
    for (int i = 0; i < SIZE; i++)
    {
        sum += retrieve(i);
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", iarray[i]);
    }

    printf("%d\n", sum);
    
    
    stop = clock();

    duration = (double)(stop-start) / CLOCKS_PER_SEC;
    printf("%f seconds", duration);

    return 0;
}