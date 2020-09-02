#include <iostream>
#include <string>
#include <vector>

using namespace std;
int ans = 0;

void dfs(vector<int> numbers, int target, int sum, int idx) {
    if (idx >= numbers.size()) {
        if (sum == target) ans++;
        return;
    }

    dfs(numbers, target, sum + numbers[idx], idx+1);
    dfs(numbers, target, sum - numbers[idx], idx+1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    vector<int> numbers = {1,1,1,1,1};
    int target = 3;
    solution(numbers, target);
    cout << ans;
    return 0;
}