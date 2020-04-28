/*
start - 10 : 20
  end - 11 : 00

- use stack
- rotate the input 2-D array
- clean_zero
- stack check top
- stack check empty

-----QUESTIONS-----
1. How to do array traversal?
2. How to get sizes of 2-d array?

-----LESSONS-----
1. Think harder before solving problems
    - do not jump to creating a function for modifying an array
    - maybe a better traversal method for the problem
        1. determine how the array should be traversed
        2. set i, j variables OR create your own variable for traversal
            1. ex) which index should be fixed, which index should change

2. no redundant if elses
    - if A
        - if B
        else SAME
    -else SAME
    --------------------
    - if A && B
    - else SAME

3. Write Pseudo Code considering a block of operations
    - In each operation(algorithm)
        - from START to END
        - organize the subOperations from START to END
        - while brainstorming, structure of subOperation would be the first to come.
    - EX)
        - Choose what kind of DS to use -> Stack
        - get element from 2-D array
            - in which order?
                - like this: (0,0) (1,0) (2,0) (3,0) (4,0)
                    - i increases, while j is fixed
                - moves[] traverse
                    - traverse from top to bottom in 2-D array
        - make the element zero, 
            - should do this after operating on stack
            - for the sake of saving space
        - stack operation, 
            - check if empty
                - if not empty, check with top and pop if match
                - else push to stack

4. Array Traversal can be different from Loop Operations
    - Loop: i, j != board[i][j];
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define LEN(arr) ((int) (sizeof(arr) / sizeof(arr)[0]))

int count;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    for (int i = 0; i < moves.size(); i++) {
        int col = moves[i] - 1;
        for (int j = 0; j < board.size(); j++) {
            if (board[j][col] != 0) {
                if (!s.empty() && board[j][col] == s.top()) {
                    answer += 2;
                    s.pop();
                }
                else {
                    s.push(board[j][col]);
                }
                board[j][col] = 0;
                break;
            }
        }
    }
    return answer;
}

void rotate90_arr(int board[]){

}

void rotate90_vec(vector< vector<int> >& board){
    vector< vector<int> > temp = board;
    int r = board.size();
    int c = board[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            board[i][j] = temp[r-1-j][i];
        }
    }
}

void clean_zero(vector< vector<int> >& board){
    int n = board.size();
    for (int i = 0; i < n; i++) {
        while(1) {
            if (board[i].back() == 0){
                board[i].pop_back();
            }
            else {
                break;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    // int board[31][31] = {
    //     {0,0,0,0,0},
    //     {0,0,1,0,3},
    //     {0,2,5,0,1},
    //     {4,2,4,4,2},
    //     {3,5,1,3,1}
    // };

    // int row = sizeof(board) / sizeof(board[0]);
    // int col = sizeof(board[0]);

    vector< vector<int> > board{
        {0,0,0,0,0},
        {0,0,1,0,3},
        {0,2,5,0,1},
        {4,2,4,4,2},
        {3,5,1,3,1}
    };

    vector<int> moves{1,5,3,5,1,2,1,4};

    // int row = board.size();
    // int col = board[0].size();

    // rotate90_vec(board);
    // clean_zero(board);

    // stack<int> s;
    // for (int i = 0; i < moves.size(); i++) {
    //     if (!board[moves[i]-1].empty()) {
    //         int num = board[moves[i]-1].back();
    //         board[moves[i]-1].pop_back();
            
    //         if (!s.empty()) {
    //             if (num == s.top()) {
    //                 count++;
    //                 s.pop();
    //             }
    //             else {
    //                 s.push(num);
    //             }
    //         }
    //         else {
    //             s.push(num);
    //         }
    //     }
    // }               
    return 0;
}