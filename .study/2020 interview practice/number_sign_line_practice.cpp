/*
처리해야할 정보
1. 출력 방향
    행(row)단위로 출력이 된다. NOT 열 방향

2. 숫자 특징 5개 패턴이 존재한다.
3. 정렬 처리

*/
#include <iostream>
#include <string>
using namespace std;

int n, cols[105], align, maxRow;
char numbers[105][15];

void input() {
    char alignString[10];
    scanf("%d %s\n", &n, alignString);

    if (alignString[0] == 'T') align = 0;
    else if (alignString[0] == 'M') align = 1;
    else align = 2;

    int max = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d %s\n", &cols[i], numbers[i]);
        if(max < cols[i]){
            max = cols[i];
        }   
    }
    maxRow = max * 2 - 1;
}

int numberPad[10][5] = {
    { 0, 3, 3, 3, 0 },
    { 1, 1, 1, 1, 1 },
    { 0, 1, 0, 2, 0 },
    { 0, 1, 0, 1, 0 },
    { 3, 3, 0, 1, 1 },
    { 0, 2, 0, 1, 0 },
    { 2, 2, 0, 3, 0 },
    { 0, 1, 1, 1, 1 },
    { 0, 3, 0, 3, 0 },
    { 0, 3, 0, 1, 1 },
};

void printShape(int type, int col){
    for (int i = 0; i < col; i++) {
        if(i == 0) {
            if(type == 1 || type == 4) printf(".");
            else printf("#");
        }
        else if (i == col - 1){
            if(type == 2 || type == 4) printf(".");
            else printf("#");
        }
        else {
            if(type != 0) printf(".");
            else printf("#");
        }
    }
}

int getAreaType(int row, int curRow){
    int gap = maxRow - row, margin;

    if(align == 0) margin = 0;
    else if (align == 1) margin = gap/2;
    else margin = gap;

    int top = 0 + margin;
    int middle = row/2 + margin;
    int bottom = row - 1 + margin;

    if(curRow==top){
        return 0;
    }
    else if(top < curRow && curRow < middle){
        return 1;
    }
    else if(curRow == middle){
        return 2;
    }
    else if(middle < curRow && curRow < bottom){
        return 3;
    }
    else if(curRow == bottom){
        return 4;
    }
    else{
        return -1;
    }
}

void printNumber(int number, int row, int col, int curRow){
    int areaType = getAreaType(row, curRow);
    int shapeType = areaType < 0 ? 4 : numberPad[number][areaType];
    printShape(shapeType, col);
}

void print(){
    for (int row = 0; row < maxRow; row++) {
        for (int i = 0; i < n; i++) {
            for (int numberIdx = 0; numbers[i][numberIdx] != '\0'; numberIdx++) {
                int r = cols[i]*2 - 1;
                int c = cols[i];
                printNumber(numbers[i][numberIdx]-'0', r, c, row);
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    input();
    print();
    return 0;
}