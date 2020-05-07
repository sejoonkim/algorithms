#include <iostream>
#include <utility>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 100000;

int V, E, dfsn[MAX + 1];
vector<int> adj[MAX+1];

set<pii> ans;
int cnt = 1;
int DFS(int curr, int justbefore) {
    dfsn[curr] = cnt;
    cnt++;
    int ret = dfsn[curr];
    for (auto child: adj[curr]) {
        if (child == justbefore) continue;
        if (dfsn[child]) {
            ret = min(ret, dfsn[child]);
            continue;
        }
        int prev = DFS(child, curr);
        if (prev > dfsn[curr]) {
            int a = min(curr, child);
            int b = max(curr, child);
            if (!ans.count(pii(a, b)))
                ans.insert(pii(a,b));
        }
        ret = min(ret, prev);
    }
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

    for (int i = 1; i <= V; i++) {
        if (dfsn[i] == 0) DFS(i, 0);
    }

    cout << ans.size() << '\n';
    for (auto x: ans)
        cout << x.first << ' ' << x.second << '\n';

    
    return 0;
}