#include <iostream>
using namespace std;

void hanoi(int n, char from, char tmp, char to) {
    if (n == 1) {
        cout << "move 1 from " << from << " to " << to << '\n';
    }
    else {
        hanoi(n-1, from, to, tmp);
        cout << "move " << n << " from " << from << " to " << to << '\n';
        hanoi(n-1, tmp, from, to);
    }
}

int main(void) {
    hanoi(5, 'A', 'B', 'C');
    return 0;
}