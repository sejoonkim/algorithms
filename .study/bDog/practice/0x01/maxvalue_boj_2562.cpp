/*
start - 10 : 07
  end - 11 : 06

- use array
- create two variables max and index
- keep updating max and index
*/

#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int max = 0, index = 0, num;

    for (int i = 1; i <= 9; i++) {
        cin >> num;
        if (max < num) {
            max = num;
            index = i;
        }
    }

    cout << max << '\n' << index;


    return 0;
}