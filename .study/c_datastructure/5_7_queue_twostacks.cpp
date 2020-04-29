#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enQueue(int x) {
        // move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        // push everything back to s1;
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue() {
        if (s1.empty()) {
            cout << "Q is empty" << '\n';
            exit(0);
        }

        int x = s1.top();
        s1.pop();
        return x;
    }
};
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    cout << q.deQueue() << '\n';
    return 0;
}