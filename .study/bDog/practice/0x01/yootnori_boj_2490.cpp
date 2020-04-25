/*
start - 09 : 43
end   - 10 : 00

- add the elements in array
- if 1 A, if 2 B, if 3 C, if 4 D, if 0 E
*/

#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    //int arr[4] = {};
    //int sum, i, loop;

    int sum, a, i, loop;

    for (loop = 0; loop < 3; loop++) {
        sum = 0;
        for (i = 0; i < 4; i++) {
            cin >> a;
            sum += a;
        }

        switch (sum) {
            case 0:
                cout << 'D' << '\n';
                break;
            case 1:
                cout << 'C' << '\n';
                break;
            case 2:
                cout << 'B' << '\n';
                break;
            case 3:
                cout << 'A' << '\n';
                break;
            case 4:
                cout << 'E' << '\n';
                break;
        }
    }
    
    return 0;
}