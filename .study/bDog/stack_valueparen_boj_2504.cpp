/*
start - 10: 31 
end - 

1. push to stack if '('
    - temp = 1;
    - ( * 2, { * 3
    - 내욜물 있을 때와 업을 때를 구분할 필요가 없다
2. if impossible break the loop, and end of the loop break
3. ) or } pop stack
    - if prev same pair, add to result
    - 괄호 쌍 내에 내용물이 있냐 없냐는 중요하지 않았다!
    - ) /2, } / 3
4. cout 0 or the value


*/

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> S;

    long long result = 0;
    int temp = 1;
    bool impossible = false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            temp *= 2;
            S.push('(');
        }
        else if (s[i] == '[') {
            temp *= 3;
            S.push('[');
        }
        // impossible
        else if (s[i] == ')' && (S.empty() || S.top() != '(')) {
            impossible = true;
            break;
        }
        else if (s[i] == ']' && (S.empty() || S.top() != '[')) {
            impossible = true;
            break;
        }
        else if (s[i] == ')') {
            if (s[i-1] == '(')
                result += temp;
            S.pop();
            temp /= 2;
        }
        else if (s[i] == ']') {
            if (s[i-1] == '[')
                result += temp;
            S.pop();
            temp /= 3;
        }
    }

    if (impossible || !S.empty()) cout << 0 << '\n';
    else cout << result << '\n';
    return 0;
}