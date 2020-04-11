#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    // 6개의 수에서 순서를 무시하고 4개씩 뽑고 싶은 상황
    int a[6] = {6, 21, 34, 37, 51, 57};
    // int select[6] = { 0, 0, 1, 1, 1, 1};
    // do {
    //     for (int i = 0; i < 6; i++) {
    //         if(select[i]) cout << a[i] << ' ';
    //     }
    //     cout << '\n';
    // } while (next_permutation(select, select + 6));

    // 6개의 수에서 순서를 고려해 3개씩 뽑고싶은 상황
    int select1[6] = { 0, 0, 0, 1, 2, 3};

    do {
        int seq[3] = {};
        for (int i = 0; i < 6; i++) {
            if(select1[i]) seq[select1[i] - 1] = a[i];
        }
        cout << seq[0] << ' ' << seq[1] << ' ' << seq[2] << '\n';
    } while (next_permutation(select1, select1+6));

    // int a[4] = { 1, 2, 3, 4 };
    // do {
    //     for (int i = 0; i < 4; i++) {
    //         cout << a[i] << ' ';
    //     }
    //     cout << '\n';
    // } while (next_permutation(a, a + 4));

    // vector<int> b = {1, 2, 3, 4};
    // do {
    //     for (int i = 0; i < 4; i++) {
    //         cout << b[i] << ' ';
    //     }
    //     cout << '\n';
    // } while (next_permutation(b.begin(), b.end()));
    
    return 0;
}

