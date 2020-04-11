/*
start - 11:24
end - 

- create map and track the number of coupons per person
- check if the number of coupons exceeds k
- add all the second element in map and put it in answer

1. loop on each character in id_list[i] string
    - stop loop if met with ' '
    - decide to add in map
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> m;

int solution(vector<string> id_list, int k) {
    int answer = 0;

    for (int i = 0; i < id_list.size(); i++) {
        string::iterator it = id_list[i].begin();
        int count = 0;
        int string_size = id_list[i].size();
        while (1) {
            string s = "";
            while (*it != ' ') {
                if (it != id_list[i].end()) {
                    s.push_back(*it);
                    count++;
                    it++;
                }
                else break;
                
            }
            if (*it == ' ') {
                count++;
                it++;
            }

            if (m[s] < k && m[s] < i + 1) {
                m[s]++;
            }

            if (count == string_size) break;
        }
    }

    for(auto idx : m) {
        answer += idx.second;
    }

    return answer;
}

int main(void) {
    int k = 2;
    vector<string> id_list = {
        "A B C D",
        "A D",
        "A B D",
        "B D"
    };

    cout << solution(id_list, k);
    return 0;
}