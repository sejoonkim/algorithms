/*
Kruskal
1. 간선 가중치 값 기준 오름차순 정렬
2. union-find하여 cycle이면 노드 선택하지 않는다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int unf[101];

struct Edge{
    int v1;
    int v2;
    int cost;
    Edge(int a, int b, int c) {
        v1 = a;
        v2 = b;
        cost = c;
    }
    bool operator<(Edge &b) {
        return cost < b.cost;
    }
};

int Find(int v) {
    if (v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) unf[a] = b;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    vector<Edge> Ed;
    int i, n, m, a, b, c, res = 0;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        unf[i] = i;
    }
    for (i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        Ed.push_back(Edge(a, b, c));
    }
    sort(Ed.begin(), Ed.end());
    for (i = 0; i < m; i++) {
        int fa = Find(Ed[i].v1);
        int fb = Find(Ed[i].v2);
        if (fa != fb) {
            res += Ed[i].cost;
            Union(Ed[i].v1, Ed[i].v2);
        }
    }
    cout << res;
    return 0;
}
