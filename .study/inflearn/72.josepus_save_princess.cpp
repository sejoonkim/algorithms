/*
1. 로직 순서대로 연산하여 추가적인 조치가 필요없다.
2. Q.push(Q.front())
*/

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, i, cnt = 1, x;
    cin >> n >> m;
    queue<int> Q;

    for (i = 1; i <= n; i++) {
        Q.push(i);
    }

    while (Q.size() > 1) {
        if (cnt == m) {
            Q.pop();
            cnt = 1;
        }
        else {
            x = Q.front();
            Q.pop();
            Q.push(x);
            cnt++;
        }
    }

    while (!Q.empty()) {
        for (i = 1; i < m; i++) {
            Q.push(Q.front());
            Q.pop();
        }
        Q.pop();
        if (Q.size() == 1) {
            cout << Q.front();
            Q.pop();
        }
    }

    cout << Q.front();
    return 0;
}

// sensei
int main() {
    int n, k, i;
    queue<int> Q;
    cin >> n >> k;
    for (i = 1; i <= n; i++) {
        Q.push(i);
    }
    while (!Q.empty()) {
        for (i = 1; i < k; i++) {
            Q.push(Q.front());
            Q.pop();
        }
        Q.pop();
        if (Q.size() == 1) {
            cout << Q.front();
            Q.pop();
        }
    }
}