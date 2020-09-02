#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i;
    string s;
    cin >> s;

    stack<char> st;

    for (i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(s[i]);
        else {
            if (st.empty()) {
                st.push(s[i]);
                break;
            }
            if (st.top() == '(') {
                st.pop();
            }
            

        }
    }

    if (st.empty()) {
        cout << "YES";
    }
    else cout << "NO";
    
    return 0;
}

// sensei
int main() {
    stack<char> s;
    char a[50];
    int i, flag = 1;
    cin >> a;
    for (i = 0; i != '\0'; i++) {
        if (a[i] == '(') s.push(a[i]);
        else {
            if (s.empty()) {
                cout << "NO";
                flag = 0;
                return 0;
            }
            else s.pop();
        }
    }
    if (s.empty()) cout << "YES";
    else cout << "NO";    
}

/*
Goal

*/