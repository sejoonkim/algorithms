/*
상황을 세 가지로 나눈다.
1. 양쪽에 사람이 있는 경우
(0의 개수가 가장 많이 연속으로 있는 곳 / 2)
2. 왼쪽에 사람이 없는 경우
(원쪽부터 0의 개수)
3. 오른쪽에 사람이 없는 경우
(오른쪽부터 0의 개수)

1, 2, 3 중 제일 큰 값 출력하기
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> v;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max;
    int N, cnt = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    int i = 0;
    for (int i = 0; i < N; i++) {
        if(v[i] == 1){
            break;
        }
    }
    for (i = i + 1; i < N; i++) {
        if (v[i] == 0){
            cnt++;
        }
        else {
            int temp = cnt % 2 ? cnt/2 + 1 : cnt/2;
            if (max < temp) max = temp;
            cnt = 0;
        }
    }

    cnt = 0;
    for (i = 0; i < N; i++) {
        if(!v[i]) cnt++;
        else break;
    }

    if (max < cnt) max = cnt;
    cnt = 0;
    for ( i = N - 1; i >= 0; i--) {
        if (!v[i]) cnt++;
        else break;
    }
    if (max < cnt) max = cnt;

    cout << max;

    return 0;
}