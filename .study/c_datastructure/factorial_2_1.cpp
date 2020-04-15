#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

int main(void){
    int n = 5;
    int result = 1;
    // result = factorial(n);
    for (int i = 1; i <= 5; i++){
        result *= i;
    }

    
    cout << result << '\n';
    return 0;
}