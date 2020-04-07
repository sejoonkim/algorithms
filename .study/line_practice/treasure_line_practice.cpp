/*
DP
1. 보물의 위치 x, y의 합은 거니를 잡는데 걸리는 시간
2. 보물을 찾는 방법은 pascal's triangle을 이용해 경우의 수 계산
*/
#include <iostream>
using namespace std;

int pascalTri[100][100];
int printCnt;
int m, n;
int minDistance;
int startX, startY;
int di[4][2] = {{-1, 0}, {1,0}, {0,-1}, {0,1}};

void pascal(){
    for (int i = 0; i < 50; i++) {
        pascalTri[i][0] = 1;
        pascalTri[0][i] = 1;

    }
    for (int i = 1; i < 50; i++) {
        for (int j = 1; j < 50; j++) {
            pascalTri[i][j] = pascalTri[i-1][j]+pascalTri[i][j-1];
        }
    }

}

int main(void) {    
    cin >> m >> n;
    cin >> startX >> startY;

    if (startY == 0 && startX == 0){
        cout << "fail";
        return 0;
    }

    if (startY < 0 || startY >= n || startX < 0 || startX >= m){
        cout << "fail";
        return 0;
    }

    minDistance = startY + startX;
    pascal();
    cout << minDistance << '\n' << pascalTri[startY][startX];

    return 0;
}