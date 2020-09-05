/*
kruskal = koogan minimum sort
union find on each sorted edges
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int unf[101];

// struct Edge {
//     int v1;
//     int v2;
//     int cost;
//     Edge (int a, int b, int c) {
//         v1 = a; v2 = b; cost = c;
//     }
//     bool operator<(const Edge &b) const{
//         return cost < b.cost;
//     }
// };

// int Find(int v) {
//     if (v == unf[v]) return v;
//     else return unf[v] = Find(unf[v]);
// }

// void Union(int x, int y) {
//     x = Find(x);
//     y = Find(y);
//     if (x != y) unf[x] = y;
// }

// int main(void) {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);

//     int v, e, a, b, c, i, sum = 0;
//     cin >> v >> e;
//     vector<Edge> map;

//     for (i = 1; i <= v; i++) {
//         unf[i] = i;
//     }
//     for (i = 1; i <= e; i++) {
//         cin >> a >> b >> c;
//         map.push_back(Edge(a, b, c));
//     }
//     sort(map.begin(), map.end());

//     for (i = 0; i < map.size(); i++) {
//         int fa = Find(map[i].v1);
//         int fb = Find(map[i].v2);
//         if (fa != fb) {
//              Union(map[i].v1, map[i].v2);
//              sum += map[i].cost;
//         }
        
//     }

//     cout << sum;
//     return 0;
// }

/*
Prim
1. pri queue - min heap
2. adj list
3. ch
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ch[101];

struct Edge {
    int v;
    int cost;
    Edge (int a, int b) {
        v = a; cost = b;
    }
    bool operator<(const Edge &b) const{
        return cost > b.cost;
    }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, a, b, c, i, sum = 0;
    cin >> v >> e;
    priority_queue<Edge> pQ;
    // vector<Edge> map[101];
    vector< pair<int, int> > map[101];
    for (i = 1; i <= e; i++) {
        cin >> a >> b >> c;
        // map[a].push_back(Edge(b, c));
        // map[b].push_back(Edge(a, c));
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }

    pQ.push(Edge(1, 0));

    while (!pQ.empty()) {
        int v = pQ.top().v;
        int cost = pQ.top().cost;
        ch[pQ.top().v] == 1;
        pQ.pop();

        if (ch[v] == 0) {
            sum += cost;
            ch[v] = 1; // tree의 집합으로 선택한다.
            for (i = 0; i < map[v].size(); i++) {
                pQ.push(Edge(map[v][i].first, map[v][i].second));
            }
        }
    }
    cout << sum;
    return 0;
}