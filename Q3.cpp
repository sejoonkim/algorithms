#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int i = 0;
    int arr[30];

    for (i = 0; i < n; i++) arr[i] = 1;
    for (i = 0; i < lost.size(); i++) arr[lost[i] - 1]--;
    for (i = 0; i < reserve.size(); i++) arr[reserve[i] + 1]++;

    for (i = 0; i < n; i++) {
        if (arr[i] == 2 && i > 0 && arr[i-1] == 0) {
            arr[i]--;
            arr[i-1]++;
        }
        if (arr[i] == 2 && i < n && arr[i+1] == 0) {
            arr[i]--;
            arr[i+1]++;
        }
    }

    for (i = 0; i < n; i++) if (arr[i] > 0) answer++;

    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n = 5;
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};
    cout << solution(n, lost, reserve);
    
    return 0;
}