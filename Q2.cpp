#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& computers, int n) {
    // already traversed, then return
    if (!computers[n][n]) return false;

    //change to traversed
    computers[n][n] = 0;

    // loop on the number of nodes
    for (int i = 0; i < computers.size(); i++) {
        // if there are connected nodes, recursion
        if (computers[n][i]) dfs(computers, i);
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (computers[i][i] && dfs(computers, i)) answer++;
    }
    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n = 3;
    vector< vector<int> > computers = { {1,1,0}, {1,1,1}, {0,1,1} };
    cout << solution(n, computers);
    return 0;
}