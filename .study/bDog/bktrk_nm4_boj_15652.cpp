#include <iostream>
using namespace std;

int N, M;

void solution(int* numbers, int count) {
    if (count == M) {
        for (int i = 0; i <  M; i++) {
            cout << numbers[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = (count == 0) ? 1 : numbers[count-1]; i <= N; i++) {
        numbers[count] = i;
        solution(numbers, count+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;

    int numbers[N+1] = {};

    solution(numbers, 0);
    return 0;
}