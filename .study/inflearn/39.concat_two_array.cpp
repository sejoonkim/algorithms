#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int a[101], b[101], c[202], n, m, i, p1, p2, p3;
    p1 = p2 = p3 = 1;

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (i = 1; i <= m; i++) {
        cin >> b[i];
    }

    while (p1 <= n && p2 <= m) {
        if (a[p1] > b[p2]) {
            c[p3++] = b[p2++];
        }
        else {
            c[p3++] = a[p1++];
        }
    }

    if (p1 > n) {
        while (p2 <= m) {
            c[p3++] = b[p2++];
        }
    }
    else {
        while (p1 <= n) {
            c[p3++] = a[p1++];
        }
    }

    for (i = 1; i < p3; i++) {
        cout << c[i] << ' ';
    }

    return 0;
}