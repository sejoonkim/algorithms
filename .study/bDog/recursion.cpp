#include <iostream>
using namespace std;

void func(int n) {
    cout << n << ' ';
    if (n == 1) return; // base condition
    func(n-1);
}

int main(void) {
    func(5);
    return 0;
}