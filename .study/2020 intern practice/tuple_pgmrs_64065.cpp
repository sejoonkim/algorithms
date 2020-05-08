/*
start - 11 : 30
  end - 

- breakdown to arrays
    - get numbers before ,
        - push to vector as soon as numbers have been discovered
- order by array size ascending
- get elements by finding new element in K array comparing with past element vector
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer, v;
    vector< vector<int> > dv;
    for (int i = 1; i < s.size()-1; i++) {
        int sum = 0;
        if (s[i] == '{') {
            int idx = i + 1;
            vector<int> temp;
            for (int j = i+1; j < s.size(); j++) {
                if (s[j] == ',') {
                    temp.push_back(stoi(s.substr(idx, j-idx)));
                    sum += (stoi(s.substr(idx, j-idx)));
                    idx = j + 1;
                }
                if (s[j] == '}') {
                    temp.push_back(stoi(s.substr(idx, j-idx)));
                    sum += (stoi(s.substr(idx, j - idx)));
                    idx = j + 1;
                    dv.push_back(temp);
                    break;
                }
            }
            v.push_back(sum);
        }
    }
    sort(v.begin(), v.end());
    answer.push_back(v[0]);
    for (int i = 1; i < v.size(); i++) {
        answer.push_back(v[i] - v[i-1]);
    }
    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s = "{{20,111},{111}}";

    vector<int> ans = solution(s);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}