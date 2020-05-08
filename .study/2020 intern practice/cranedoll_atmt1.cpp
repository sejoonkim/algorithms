/*
start - 11 : 13
  end - 11 : 29

- for loop with moves.size() repetitions
    - by selecting the moves[i]
    - traverse in this order
        - board[0][moves[i]] -> board[1][moves[i]] -> board[2][moves[i]] -> 
        - stop when not zero
        - push the value to stack
            if stack(!empty())
                if (check with stacktop() == value)
        - change the value to zero

*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for (int i = 0; i < moves.size(); i++) {
        int col = moves[i] - 1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][col] != 0) {
                int num = board[j][col];
                board[j][col] = 0;
                
                if (!s.empty() && num == s.top()) {
                    answer += 2;
                    s.pop();
                }
                else {
                    s.push(num);
                }
                break;
            }
        }
    }

    return answer;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    vector< vector<int> > board{
        {0,0,0,0,0},
        {0,0,1,0,3},
        {0,2,5,0,1},
        {4,2,4,4,2},
        {3,5,1,3,1}
    };

    vector<int> moves{1,5,3,5,1,2,1,4};

    int answer = solution(board, moves);

    cout << answer;
    return 0;
}