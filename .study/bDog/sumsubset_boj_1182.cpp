#include <bits/stdc++.h>
using namespace std;
int n, s;
int cnt = 0;
int a[24];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < (1<<n); i++) {
        int tmp = i;
        int total = 0;
        for (int j = 0; j < n; j++) {
            if (tmp & 1) total += a[j];
            tmp /= 2;
        }
        if (total == s) cnt++;
    }
    cout << cnt;
    return 0;
}