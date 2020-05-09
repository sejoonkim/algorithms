/*
start - 10 : 11
  end - 

- 
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

bool check[8];
int blen, ulen;
set<string> s;

void solve(int index, string res, vector<string> user_id, vector<string>banned_id) {
    if (index == blen) {
        s.insert(res);
        return;
    }
    string bid = banned_id[index];
    int bidlen = bid.size();

    for (int i = 0; i < ulen; i++) {
        string uid = user_id[i];
        if (uid.size() != bidlen) continue;
        if (check[i]) continue;

        bool flag = true;

        for (int j = 0; j < bidlen; j++) {
            if (bid[j] == '*') continue;

            if (uid[j] != bid[j]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            check[i] = true;
            solve(index + 1, res + to_string(i), user_id, banned_id);
            check[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    ulen = user_id.size();
    blen = banned_id.size();

    solve(0, "", user_id, banned_id);
    answer = s.size();

    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"fr*d*", "abc1**"};
    solution(user_id, banned_id);
    return 0;
}