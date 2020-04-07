#include <bits/stdc++.h>

using namespace std;

vector< pair<string, int> > pair_v(100010);

bool compare(pair<string, int>& elem1, pair<string, int>& elem2) {
    if (elem1.second == elem2.second) return elem1.first < elem2.first;
    return elem1.second > elem2.second;
}

vector<string> solution(vector<vector<string>> dataSource, vector<string> tags) {
    vector<string> answer;

    int num = 1;
    for (vector<pair<string,int>>::iterator it = pair_v.begin() ; it != pair_v.end(); it++) {
        it->first = "doc" + to_string(num);
        num++;
    }

    for (int i = 0; i < dataSource.size(); i++) {
        for (int j = 1; j < dataSource[i].size(); j++) {
            for (int k = 0; k < tags.size(); k++) {
                if (dataSource[i][j].compare(tags[k]) == 0) {
                    pair_v[i].second++;
                }
            }
        }
    }

    sort(pair_v.begin(), pair_v.end(), compare);

    for (int i = 0; i < 10; i++) {
        if (pair_v[i].second != 0) {
            answer.push_back(pair_v[i].first);
        }
    }

    return answer;
}