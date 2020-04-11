/*
- choose number of ski and * 2 = m
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int total;

void recursion(int num_arr[], int count, int n, int m, int k) {
    if (count == m/4) {
        int sum = 0;
        for (int i = 0; i < count; i++) {
            sum += num_arr[i];
        }
        if (sum == m/2) {
            total++;
            return;
        }
        else return;
    }

    for (int i = 1; i <= k-1; i++) {
        num_arr[count] = i;
        recursion(num_arr, count+1, n, m, k);
    }
}

int solution(int n, int m, int k) {
    int answer = -1;
    int num_arr[n+1];
    fill(num_arr, num_arr + n + 1, 0);

    if (n > m || n*k < m) {
        answer = total;
    }
    else {
        recursion(num_arr, 0, n, m, k);
        answer = total * 2;
    }
    return answer;
}

int main(void) {
    cout << solution(10, 6, 5);
    return 0;
}