#include <iostream>
using namespace std;

int arr[16], ch[16], res[16];
int n, r, cnt = 0;

void DFS(int L) {
    int i;
    if (L == r) {
        for (i = 0; i < r; i++) {
            cout << res[i] << ' ';
        }
        cout << '\n';
        cnt++;
    }
    else {
        for (i = 1; i <= n; i++) {
            if (ch[i] == 0) {
                res[L] = arr[i];
                ch[i] = 1;
                DFS(L + 1);
                ch[i] = 0;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int i;
    cin >> n >> r;
    for (i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    DFS(0);
    cout << cnt;
    return 0;
}