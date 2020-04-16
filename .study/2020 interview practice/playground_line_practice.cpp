/*
설계한 것과 문제를 비교해가면서 확인하자.

1. declare N, K && get inputs && get numbers to store in group[1010]
2. write a function that returns the smallest ticketOffice index
3. call the 2. function and update ticketOffice[index]
4. update maxVisitor when value is added to ticketOffice[index]
5. loop for N groups and cout maxVisitor 
*/
#include <bits/stdc++.h>
using namespace std;
int N, K;
int group[1010], ticketOffice[20];

int minTicketOffice(){
    int min = ticketOffice[0];
    int index = 0;

    for (int i = 1; i < K; i++) {
        if (min > ticketOffice[i]){
            index = i;
        }
    }
    return index;
}

int main(void) {
    int maxVisitor = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> group[i];
    }

    for (int i = 0; i < N; i++) {
        int tempIndex = minTicketOffice();
        ticketOffice[tempIndex] += group[i];
        if (ticketOffice[tempIndex] > maxVisitor) {
            maxVisitor = ticketOffice[tempIndex];
        }
    }
    cout << maxVisitor;
    return 0;
}