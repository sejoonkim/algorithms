/*
1. state Edge struct
2. ch[] - to check if visited
3. map[] to make adj list
4. dist[] - to keep update the distance from 1 cost + map[v][i].dist
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int v;
    int cost;
    Edge (int a, int b) {
        v = a;
        cost = b;
    }
    bool operator<(const Edge &b) const{
        return cost > b.cost; // for min heap
    }
};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int i, n, m, a, b, c;
    cin >> n >> m;
    priority_queue<Edge> pQ;
    // vector<Edge> map[21];
    vector< pair<int, int> > map[21];
    vector<int> dist(n+1, 2147000000);

    for (i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }

    pQ.push(Edge(1, 0));
    dist[1] = 0;
    while (!pQ.empty()) {
        int now = pQ.top().v;
        int cost = pQ.top().cost;
        pQ.pop();
        if (cost > dist[now]) {cout << cost << ' ' << dist[now] << '\n'; continue;}
        for (i = 0; i < map[now].size(); i++) {
            int next = map[now][i].first;
            int nextDis = cost + map[now][i].second;
            if (nextDis < dist[next]) {
                dist[next] = nextDis;
                pQ.push(Edge(next, nextDis));
            }
        }
    }
    
    for (i = 2; i <= n; i++) {
        if (dist[i] != 2147000000) cout << i << " : " << dist[i] << '\n';
        else cout << i << " : impossible" << '\n';
    }
    return 0;
}