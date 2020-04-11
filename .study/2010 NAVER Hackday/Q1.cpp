/*
- check for the delievered
- check isRemain = true on each items
- 

1. will sort the delivery 2-d vector regarding column 3, descending order
2. create array initialized to -1
    - -1 = don't know
    - 0 = no remaining
    - 1 = yes remaining
3. loop from the first element in delivery
4. else when delivery[i][2] == 0, check value from remain and process


*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool descending_col_3(vector<int>& elem1, vector<int>& elem2) {
    return elem1[2] > elem2[2];
}

string solution(int n, vector<vector<int>> delivery) {
    string answer = "";
    int remain[n+1];
    fill(remain, remain + n + 1, -1);
    sort(delivery.begin(), delivery.end(), descending_col_3);
    
    for (int i = 0; i < delivery.size(); i++) {
        if (delivery[i][2]) {
            remain[delivery[i][0]] = 1;
            remain[delivery[i][1]] = 1;
        }
        else { // not delivered
            if (remain[delivery[i][0]]) { // if first item has remain
                remain[delivery[i][1]] = 0;
            }
            else if (remain[delivery[i][1]]) { // if second item has remain
                remain[delivery[i][0]] = 0;
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        if (remain[i] == 1){
            answer.push_back('O');
        }
        else if (!remain[i]) {
            answer.push_back('X');
        }
        else {
            answer.push_back('?');
        }
        
    }
    return answer;
}

int main(void) {
    int n = 6;
    vector<vector<int>> delivery = {
        {1, 3, 1},
        {3, 5, 0},
        {5, 4, 0},
        {2, 5, 0}
    };

    cout << solution(n, delivery);
    return 0;
}