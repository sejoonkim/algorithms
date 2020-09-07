#include <iostream>
using namespace std;

int N, R;
int ch[16], arr[16], cnt = 0, res[20];

void DFS(int L) {
    int i;
    if (L == R) {
        for (i = 0; i < L; i++) {
            cout << res[i] << ' ';

        }
        cout << '\n';
        cnt++;
    }
    else {
        for (i = 1; i <= N; i++) {
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
    cin >> N >> R;

    for (i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    DFS(0);
    cout << cnt;
    return 0;
}