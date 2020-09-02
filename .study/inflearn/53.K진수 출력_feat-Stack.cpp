#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// int s[1001];
// int i = 0;


// // state the methods
// // push
// void push(int num) {
//     if (i > 1000) {
//         cout << "Stack FULL!" << '\n';
//         return;
//     }
//     s[i] = num;
//     i++;
//     return;
// }

// int pop() {
//     if (i == 0) {
//         cout << "Empty Stack!" << '\n';
//         return -1;
//     }
//     int tmp = s[--i];

//     if (tmp == 10) tmp = 'A';
//     else if (tmp == 11) tmp = 'B';
//     else if (tmp == 12) tmp = 'C';
//     else if (tmp == 13) tmp = 'D';
//     else if (tmp == 14) tmp = 'E';
//     else if (tmp = 15) tmp = 'F';
//     return tmp;
// }

// int top() {
//     return s[i];
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, k, size;
//     cin >> n >> k;


//     while (n > 0) {
//         cout << n << ' ' << n % k << '\n';
//         push(n % k);
//         n /= k;
//     }
    
//     size = i;
//     for (int j = 0; j < size; j++) {
//         cout << pop();
//     }

//     return 0;
// }

// ----------sensei------------
int stack[100], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int n, k;
    char str[20] = "0123456789ABCDEF";
    cin >> n >> k;
    while (n > 0) {
        push(n%k);
        n /= k;
    }
    while (top != -1) {
        cout << str[pop()];
    }
    return 0;
}

// ---------------sensei with stack STL------------
#include <stack>
int main() {
    int n, k;
    stack<int> s;
    while (n > 0) {
        s.push(n%k);
        n /= k;
    }
    while (!s.empty()) {
        cout << str[s.top()]; // returns the top element
        s.pop(); // no return value
    }
}



/*
Goal
- find the nth ugly number

1. 3 pointer
2. update the array with a[i] * 2, a[i] * 3, a[i] * 5
*/