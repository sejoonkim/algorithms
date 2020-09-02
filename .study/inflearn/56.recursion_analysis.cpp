#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recur(int x) {
    if (x == 0) return; // 종료지점을 명시하자
    else {
        recur(x-1);
            cout << x << '\n';
    }
}

int main() {
    int n;
    cin >> n;
    recur(n);
    return 0;
}


/*
Stack frame
1. main 함수 호출. stack frame에 호출 정보(매개변수, 지역변수, 복귀주소)가 기록된다.
2. recur(n)이 호출된다. 매개변수 (x), 지역변수, 복귀주소가 설정된다.
3. 

*/