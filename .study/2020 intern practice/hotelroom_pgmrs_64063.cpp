#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// struct UNION_FIND {
//     int n;
// public:
//     vector<int> parent, height;
//     vector<long long> right;
//     UNION_FIND(int len) {
//         n = len + 1;
//         parent.resize(n, 0), height.resize(n, 0), right.resize(n,0);
//         for (int i = 0; i < n; i++) {
//             parent[i] = i;
//         }
//     }

//     void init(int idx, long long r) {
//         right[idx] = r;
//     }

//     int find(int u) {
//         if (u == parent[u]) return u;
//         return find(parent[u]);
//     }

//     void merge(int u, int v) {
//         u = find(u), v = find(v);
//         if (u == v) return;
//         if (height[u] > height[v]) swap(u,v);
//         parent[u] = v;
//         right[v] = max(right[u], right[v]);
//         if (height[u] == height[v]) height[v]++;
//     }
//     long long getRight(int idx) {
//         return right[find(idx)];
//     }
// };

// vector<long long> solution(long long k, vector<long long> room_number) {
//     vector<long long> answer;
//     map<long long, int> cache;
//     UNION_FIND uf(room_number.size());
//     int cnt = 0;
//     for (auto i : room_number) {
//         if (cache.find(i) != cache.end())
//             i = uf.getRight(cache[i]) + 1;

//         answer.push_back(i);
//         cache.insert({i, cnt++});
//         uf.init(cache[i], i);

//         if (cache.find(i-1) != cache.end()) {
//             uf.merge(cache[i-1], cache[i]);
//         }
//         if (cache.find(i + 1) != cache.end()) {
//             uf.merge(cache[i], cache[i+1]);
//         }
//     }
//     return answer;
// }

map<long long, long long> p;

long long find(long long x) {
    if (p[x] == 0) return x;
    else {
        p[x] = find(p[x]);
        return p[x];
    }
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for (long long x : room_number) {
        long long y = find(x);
        answer.push_back(y);
        p[y] = y + 1;
    }
    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<long long> sol = solution(10, {1,3,4,1,3,1,});
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << ' ';
    }
    return 0;
}