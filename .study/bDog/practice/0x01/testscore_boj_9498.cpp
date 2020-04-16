#include <iostream>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    cout << a+b << '\n' << a-b << '\n' << a*b << '\n' << a/b << '\n' << a%b;
    return 0;
}