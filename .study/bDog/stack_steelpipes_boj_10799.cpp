/* start - 9: 54 end - 10:13
1. get the inputs
2. if c == '(' push and if s.top() == '(' and c == ')' do pop
3. check the size of the stack
4. add the size to the count
 

- if laser 1 time, 2 pieces
- if laser 2 times, 3 pieces
- so keep track of count of lasers? 
- if ')' and then '(' reset all variables
- if '(' increase a variable value 
*/
#include <bits/stdc++.h>
using namespace std;

stack<char> s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    int count = 0;
    char prev;
    for (auto c : str) {
        if (c == '(') s.push(c);
        else {
            s.pop();
            // if lase
            if (prev == '(')
                count += s.size();
            else //end of bar
                count++;
        }
        prev = c;
    }

    cout << count;
    return 0;
}