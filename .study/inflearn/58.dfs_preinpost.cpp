#include <iostream>
using namespace std;

void D(int v) {
    if (v > 7) return;
    else {
        
        D(v*2);
        
        D(v*2+1);
        cout << v << ' ';
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    D(1);
    return 0;
}