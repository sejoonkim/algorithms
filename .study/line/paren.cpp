#include <bits/stdc++.h>
using namespace std;

stack<int> Stack;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  getline(cin, s);

  int count = 0;

  for (int i = 0; i < s.size(); i++) {
    
    if (s[i]=='(' || s[i]=='{' || s[i] == '[' || s[i] == '<') Stack.push(s[i]); 

    else { 
        if(s[i] == ')') {
            if(Stack.top() == '(') {
                Stack.pop();
                count++;
            } 
        }
        else if (s[i] == '}') {
            if(Stack.top() == '{') {
                Stack.pop();
                count++;
            }
        }
        else if (s[i] == ']') {
            if(Stack.top() == '[') {
                Stack.pop();
                count++;
            } 
        }
        else if (s[i] == '>') {
            if(Stack.top() == '<') {
                Stack.pop();
                count++;
            } 
        }
    }
  }

  if (!Stack.empty()) cout << "-1";
  else cout << count;

}


#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> Stack;

int solution(string inputString) {
  int answer = -1;

  int count = 0;

  for (int i = 0; i < inputString.length(); i++) {
    
    if (inputString[i]=='(' || inputString[i]=='{' || inputString[i] == '[' || inputString[i] == '<') Stack.push(inputString[i]); 

    else { 
        if(inputString[i] == ')') {
            if(!Stack.empty() && Stack.top() == '(') {
                Stack.pop();
                count++;
            } else {
                Stack.push(inputString[i]);            
            }
        }
        else if (inputString[i] == '}') {
            if(!Stack.empty() && Stack.top() == '{') {
                Stack.pop();
                count++;
            } else {
                Stack.push(inputString[i]);            
            }
        }
        else if (inputString[i] == ']') {
            if(!Stack.empty() && Stack.top() == '[') {
                Stack.pop();
                count++;
            } else {
                Stack.push(inputString[i]);            
            }
        }
        else if (inputString[i] == '>') {
            if(!Stack.empty() && Stack.top() == '<') {
                Stack.pop();
                count++;
            } else {
                Stack.push(inputString[i]);            
            }
        }
    }
  }

  if (!Stack.empty()) answer = -1;
  else answer = count;
    
    return answer;
}