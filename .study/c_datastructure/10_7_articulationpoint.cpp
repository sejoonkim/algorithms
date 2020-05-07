#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int V, E, df;
vector<int> adj[MAX + 2];

int dfsn[MAX + 2];

set<int> ans;

int DFS(int curr, bool isRoot) {
    dfsn[curr] = df;
    df++;
    int ret = dfsn[curr];
    int CT = 0;
    for (auto child: adj[curr]) {
        if (dfsn[child] != 0)
            ret = min(ret, dfsn[child]);
        else {
            CT++;
            int Ctree = DFS(child, false);
            if (Ctree >= dfsn[curr] && !isRoot)
                ans.insert(curr);
            ret = min(ret, Ctree);
        }
    }
    if (isRoot && CT >= 2)
        ans.insert(curr);
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    df = 1;
    for (int i = 1; i <= V; i++) {
        if (dfsn[i] == 0) DFS(i, true);
    }
    cout << ans.size() << '\n';
    for (auto ss: ans)
        cout << ss << ' ';
    return 0;
}