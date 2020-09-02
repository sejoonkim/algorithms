#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[1501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, i, p2 = 1, p3 = 1, p5 = 1, min;
    cin >> n;

    a[1] = 1;

    for (i = 2; i <= n; i++) {
        min = 2147000000;
        if (a[p2] * 2 < min) {
            min = a[p2] * 2;
        }
        if (a[p3] * 3 < min) {
            min = a[p3] * 3;
        }
        if (a[p5] * 5 < min) {
            min = a[p5] * 5;
        }

        a[i] = min;

        if (a[p2] * 2 == min) {
            p2++;
        }
        if (a[p3] * 3 == min) {
            p3++;
        }
        if (a[p5] * 5 == min) {
            p5++;
        }
    }

    cout << a[n];

    return 0;
}

// sensei
int main() {
    int n, i, p2, p3, p5, min=2147000000;
    cin >> n;
    a[1] = 1;
    p2=p3=p5=1;
    for(i = 1; i <= n; i++) {
        // find the min
        if (a[p2]*2 < a[p2]*3) min = a[p2]*2;
        else min=a[p3]*3;
        if (a[p5]*5<min) min = a[p5]*5;

        // update each pointers
        if (a[p2] * 2 == min) p2++;
        if (a[p3]*3 == min) p3++;
        if (a[p5]*5 == min) p5++;
        a[i] = min;
    }
}

/*
Goal
- find the nth ugly number

1. 3 pointer
2. update the array with a[i] * 2, a[i] * 3, a[i] * 5
*/