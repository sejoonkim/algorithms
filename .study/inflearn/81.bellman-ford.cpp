/*
1. adjlist vector
2. traverse over all edges
3. do once more, check negative cycle
4. else do operation in dist variable;
*/

#include <iostream>
#include <vector>
using namespace std;

int dist[101];

struct Edge {
    int v1;
    int v2;
    int cost;
    Edge (int a, int b, int c) {
        v1 = a; v2 = b; cost = c;
    }
};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m, a, b, c, i, j, s, e;
    cin >> n >> m;

    vector<Edge> map;

    for (i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        map.push_back(Edge(a, b, c));
    }

    for (i = 1; i <= n; i++) {
        dist[i] = 2147000000;
    }

    cin >> s >> e;
    dist[s] = 0;

    for (i = 1; i < n; i++) {
        for (j = 0; j < map.size(); j++) {
            int v1 = map[j].v1;
            int v2 = map[j].v2;
            int cost = map[j].cost;
            if (dist[v1] != 2147000000 && dist[v1] + cost < dist[v2]) {
                dist[v2] = dist[v1] + cost;
            }
        }
    }

    for (j = 0; j < map.size(); j++) {
            int v1 = map[j].v1;
            int v2 = map[j].v2;
            int cost = map[j].cost;
            if (dist[v1] != 2147000000 && dist[v1] + cost < dist[v2]) {
                cout << -1;
                exit(0);
            }
        }

    cout << dist[e];


    return 0;
}