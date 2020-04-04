#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool great_to_less(pair<int, int>& elem1, pair<int, int>& elem2) {
    return elem1.second > elem2.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector< pair<int, int> > vec_freq;
    map< int, int > m;
    string temp_num;

    for (int i = 0; i < s.length(); i++) {
        // if (s[i] == '{' || s[i] == '}' || s[i] == ',') continue;
        if (s[i] == '{') {
            continue;
        }
        else if ((s[i] == ',' || s[i] == '}') && !temp_num.empty()) {
            int num = stoi(temp_num);
            m[num]++;
            temp_num.clear();
        }
        else if (s[i] == ',' || s[i] == '}') {
            continue;
        }        
        else {
            temp_num.push_back(s[i]);
        }
    }

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        vec_freq.push_back({iter->first, iter->second});
    }

    sort(vec_freq.begin(), vec_freq.end(), great_to_less);

    for (auto iter = vec_freq.begin(); iter != vec_freq.end(); iter++) {
        if (iter->second > 0) {
            int num = iter->first;
            answer.push_back(num);
        }
    }
    
    return answer;
}

int main(void) {
    string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
    vector<int> v = solution(s);

    return 0;
}