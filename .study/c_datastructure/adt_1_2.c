#include <stdio.h>
#include <stdbool.h>

bool is_greater(int x, int y) {
    return x > y;
}

int main(void) {
    int x = 1, y = 2;
    int final_result;

    bool result = is_greater(x, y);
    
    printf("%s", result ? "true" : "false");
    
    return 0;
}