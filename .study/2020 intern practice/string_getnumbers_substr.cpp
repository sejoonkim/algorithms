#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s1 = "6 2 3 5 8";
    string s2 = "123,52,6,321";

    vector<int> v1;
    vector<int> v2;

    int idx1 = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == ' ') {
            v1.push_back(stoi(s1.substr(idx1, i - idx1)));
            idx1 = i + 1;
        }
    }
    v1.push_back(stoi(s1.substr(idx1)));

    int idx2 = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s2[i] == ',') {
            v2.push_back(stoi(s2.substr(idx2, i - idx2)));
            idx2 = i + 1;
        }
    }
    v2.push_back(stoi(s2.substr(idx2)));
    return 0;
}