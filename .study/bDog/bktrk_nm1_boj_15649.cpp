#include <iostream>
using namespace std;

int N, M;
int number[9];
bool visited[9];

void solution(int count) {
    if (count == M) {
        for (int i = 0; i < M; i++) {
            cout << number[i] << ' ';   
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            number[count] = i;
            solution(count + 1);
            visited[i] = false;   
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> N >> M;

    solution(0);
    return 0;
}