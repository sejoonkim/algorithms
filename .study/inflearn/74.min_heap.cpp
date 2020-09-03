#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int a;

    priority_queue<int> pQ;

    while(1) {
        cin >> a;
        if (a == -1) {
            break;
        }
        if (a == 0) {
            if (pQ.empty()) {
                cout << -1;
            }
            else {
                cout << -pQ.top();
                pQ.pop();
            }
        }
        else {
            pQ.push(-a);
        }
    }
    return 0;
}