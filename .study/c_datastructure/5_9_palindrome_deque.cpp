#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    bool isPalin = true;

    deque<char> dq;
    string str = "RadAr.";
    string str_conv = str;

    //transform(str.begin(), str.end(), str_conv.begin(), ::tolower);

    if (str.size() == 1) {
        isPalin = false;
        exit(0);
    }

// check for only characters
    for (int i = 0; i < str_conv.size(); i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            dq.push_back(str[i]);
        }
        else if ('A' <= str[i] && str[i] <= 'Z') {
            dq.push_back(str[i] - 'A' + 'a');
        }
    }

    while(!dq.empty()) {
        if (dq.front() == dq.back()) {
            if (dq.size() == 1) {
                dq.pop_back();
                continue;
            }
            dq.pop_back();
            dq.pop_front();
        }
        else {
            isPalin = false;
            break;
        }
    }

    if (isPalin) {
        cout << "Yes Palin" << '\n';
    }
    else {
        cout << "No Palin" << '\n';
    }
    return 0;
}


/*
How to determin palindrome
1. in deque do all operation
    1. check if there is only 1 input then flaf notp = true
    1. check if front and rear match
    2. if match, pop front and pop back
    3. else notp = true, break;
2. determination
    1. if 1 element or no element in queue and notp false
        1. 
*/