/*
1. initial queue with first elem 0 second elem 1
2. compute fibo num
    1. int x = q.front();
    2. q.pop()
    3. int x2 = q.front();
    4. q.push(x + x2);
    5. print q.rear() for the fibo
*/

#include <iostream>
#include <queue>
using namespace std;

void initial(queue<int>& q) {
    q.push(0);
    q.push(1);
}

int compute_fibo(queue<int>& q) {
    int x1 = q.front();
    q.pop();
    int x2 = q.front();
    q.push(x1+x2);
    return q.back();
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    queue<int> q;

    initial(q);

    cout << compute_fibo(q) << '\n';
    cout << compute_fibo(q) << '\n';
    cout << compute_fibo(q) << '\n';
    cout << compute_fibo(q) << '\n';
    cout << compute_fibo(q) << '\n';
    cout << compute_fibo(q) << '\n';
    

    
    return 0;
}