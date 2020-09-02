#include <iostream>
using namespace std;

int adj[21][21], ch[21], n, m, cnt = 0;

void DFS (int v) {
    if (v == n) {
        cnt++;
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (adj[v][i] == 1 && ch[i] == 0) {
                ch[i] = 1;
                DFS(i);
                ch[i] = 0;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int i, a, b;

    cin >> n >> m;

    // construct the adj matrix
    for (i = 1; i <= m; i++) {
            cin >> a >> b;
            adj[a][b] = 1;
    }
    ch[1] = 1;
    DFS(1);

    cout << cnt;    
    return 0;
}