#include <iostream>
using namespace std;



int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int sally_marcus[n + 1][n + 1] = {0, };

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        sally_marcus[a][b] = c;
    }

    for (int i = 1; i <= n; i++) {
        for ( int j = 1; j <= n; j++) {
            cout << sally_marcus[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}