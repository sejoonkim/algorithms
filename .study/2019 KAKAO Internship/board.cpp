#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

stack<int> s;

void rotate(vector<vector<int>>& board) {
    reverse(board.begin(), board.end());
    int size = board.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            swap(board[i][j], board[j][i]);
        }
    }
}

void pop_zeros(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = board.size() - 1; j >= 0; j--) {
            if (board[i][j] == 0) {
                board[i].pop_back();
            }
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    rotate(board);
    pop_zeros(board);
    
    for (int i = 0; i < moves.size(); i++) {
        if (!board[moves[i] - 1].empty()) {
            int last_elem = 0;
            last_elem = board[moves[i] - 1].back();
            board[moves[i] - 1].pop_back();
            
            if (!s.empty()) {
                if (last_elem == s.top()) {
                    s.pop();
                    answer += 2;
                }
                else {
                    s.push(last_elem);
                }
            }
            else {
                s.push(last_elem);
            }
        }
    }
    
    return answer;
}

int main(void) {
    vector<vector<int>> board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};
    int num = solution(board, moves);
    cout << num;
    return 0;
}