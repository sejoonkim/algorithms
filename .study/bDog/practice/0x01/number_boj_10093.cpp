/*
start - 09 : 32
  end - 10 : 06

- long long int 
- abs(a-b) - 1;
- for i = a + 1 i < b
  - cout i
*/
#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    long long int a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    if (a != b) {
        cout << b - a - 1 << '\n';
        for (long long int i = a + 1; i < b; i++) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    else {
        cout << 0 << '\n';
    }
    
    return 0;
}