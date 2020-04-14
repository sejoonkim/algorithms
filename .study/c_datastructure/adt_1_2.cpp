#include <iostream>
using namespace std;

bool is_greater(int x, int y) {
    return x > y;
}

int main(void) {
    int x = 1, y = 2;
    int final_result;

    bool result = is_greater(x, y);
    
    cout << boolalpha << result;
    
    return 0;
}