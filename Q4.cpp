#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();

    int tmp = 0, turn = n-1;

    for (int i = 0; i < n; i++) {
        int startto = name[i] = 'A';
        int endto = 'Z' - name[i] + 1;

        if (startto > endto) tmp += endto;
        else tmp += startto;

        int next = i + 1;
        while (next < n && name[next] == 'A') next++;
        turn = min(turn, i + n - next + min(i, n=next));
    }
    
    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    
    return 0;
}