#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    for (int i = 0; i < banned_id.size() - 1; i++) {
        for (int j = i+1; j < banned_id.size(); j++) {
            if(banned_id[i].size() && banned_id[j].size() && banned_id[i].compare(banned_id[j]) == 0) {
                banned_id[i].clear();
                banned_id[j].clear();
            }
        }
    }

    for (int i = 0; i < user_id.size(); i++) {
        for (int j = 0; j < banned_id.size(); j++) {
            if (!banned_id.empty()){
                for (int k = 0; k < banned_id[j].size(); k++) {
                    
                }
            }
        }
    }
    return answer;
}

int main(void) {
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"fr*d*", "abc1**"};
    int num = solution(user_id, banned_id);
    cout << num;
    return 0;
}