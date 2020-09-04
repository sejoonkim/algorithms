#include <iostream>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;

// array to check if visited
int ch[101];

struct Edge {
    int v;
    int cost;
    Edge(int a, int b) {
        v = a;
        cost = b;
    }
    bool operator<(const Edge &b) const{
        return cost > b.cost; // for min heap, for max heap is cost < b.cost
    }
};

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    priority_queue<Edge> pQ;
    vector<pair<int, int> > map[101];
    int i, n, m, a, b, c, res = 0;
    cin >> n >> m;
    for (i = 1; i <= m; i++) {
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }  
    pQ.push(Edge(1, 0));
    while (!pQ.empty()) {
        Edge tmp = pQ.top();
        pQ.pop();
        int v = tmp.v;
        int cost = tmp.cost;
        if (ch[v] == 0) {
            res += cost;
            ch[v] = 1;
            for (i = 0; i < map[v].size(); i++) {
                pQ.push(Edge(map[v][i].x, map[v][i].y));
            }
        }
    }
    cout << res;
    return 0;
}