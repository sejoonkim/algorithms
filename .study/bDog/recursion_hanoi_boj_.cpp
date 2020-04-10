#include <iostream>
using namespace std;

void hanoi(int a, int b, int n){
    if(n==1){ //a에 있는 원판 1개를 b로 옮기기만 하면 된다.
        cout << a << ' ' << b << '\n';
        return;
    }
    int c = 6-a-b;
    hanoi(a, c, n-1); //a에 있던 1 to n-1번째 원판을 a에서 c로 이동한다.
    cout << a << ' ' << b << '\n'; //a에 남아있던 n번째 원판을 b로 이동한다.
    hanoi(c, b, n-1); // c에 있던 1to n-1번째 원판을 c에서 b로 이동한다.

}

int main(void) {
    int n;
    cin >> n;
    cout << (1<<n) - 1 << '\n';
    hanoi(1, 3, n);
    return 0;
}