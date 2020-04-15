#include <iostream>

using namespace std;

double power(double x, int n) {
    if (!n) return 1.0;
    else if (n & 1) return x * power(x * x, (n-1)/2);
    else return power(x * x, n/2);
}

int main(void) {
    double x = 1.2;
    int n = 5;
    cout << power(1.2, 5) << '\n';    
    return 0;
}