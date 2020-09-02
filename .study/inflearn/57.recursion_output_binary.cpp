#include <iostream>
using namespace std;

void D(int x) {
    if (x == 0) return;
    else {
        D(x / 2);
        cout << x % 2;
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    D(n);
    return 0;
}