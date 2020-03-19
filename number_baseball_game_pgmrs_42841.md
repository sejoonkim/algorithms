## Problem

- 프로그래머스 > 완전탐색 > 숫자 야구
- https://programmers.co.kr/learn/courses/30/lessons/42841

<br/>

## Approach

1. Make string vector for 3-digit numbers
2. triple for loop starting from 123 to 789
3. next_permutation on each number sequence
4. calculate the sequence's strike and ball and check with the original vector
5. return false if there is no match

<br/>

## Code

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<string, int>> str_vec;

bool successful(vector<int>& num, vector<vector<int>>& baseball) {
    bool flag = true;
    for (int i = 0; i < str_vec.size(); i++) {
        int s = 0, b = 0;
        for (int j = 0; j < num.size(); j++) {
            for (int k = 0; k < 3; k++) {
                if (num[j] == (str_vec[i].first[k] - '0')) {
                    if (j == k) s++;
                    else b++;
                    break;
                }
            }
        }
        if ((s != baseball[i][1]) || (b != baseball[i][2])) {
            flag = false;
            break;
        }
    }
    return flag;
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    for (int i = 0; i < baseball.size(); i++) {
        int num = baseball[i][0];
        string str_num = to_string(num);
        str_vec.push_back({str_num, i});
    }

    for (int i = 1; i <= 9; i++) {
        vector<int> temp_vec;
        temp_vec.push_back(i);
        for (int j = i + 1; j <= 9; j++) {
            temp_vec.push_back(j);
            for (int k = j + 1; k <= 9; k++) {
                temp_vec.push_back(k);
                do {
                    if (successful(temp_vec, baseball))
                        answer++;
                } while (next_permutation(temp_vec.begin(), temp_vec.end()));
                temp_vec.pop_back();
            }
            temp_vec.pop_back();
        }
        temp_vec.pop_back();
    }
    return answer;
}

int main(void) {
    vector<vector<int>> baseball {
				{ 123, 1, 1 },
				{ 356, 1, 0 },
				{ 327, 2, 0 },
                { 489, 0, 1}
			};
    int answer = solution(baseball);
    cout << answer;
    return 0;
}
```

<br/>

## Other Methods

- > 1. acknowledge the max and min of number sequences to check(123, 987)
  > 2. for loop from 123 to 987, incrementing by 1
  > 3. continue for sequences that have same numbers and zero included
  > 4. check for strike and ball for each number sequence
  > 5. return false if none match

  - ```c++
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int solution(vector<vector<int>> baseball) {
        int answer = 0;

        for (int i = 123; i < 987; i++) {
            string num_to_check = to_string(i);
            bool flag = true;

            if (num_to_check[0] == num_to_check[1] || num_to_check[1] == num_to_check[2] || num_to_check[2] == num_to_check[0]) continue;
            if (num_to_check[0] == 0 || num_to_check[1] == 0 || num_to_check[2] == 0) continue;

            for (int j = 0; j < baseball.size(); j++) {
                int strike = 0, ball = 0;

                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        string original = to_string(baseball[j][0]);
                        if (num_to_check[k] == original[l]){
                            if (k == l) {
                                strike++;
                            }
                            else ball++;
                        }
                    }
                }

                if (strike != baseball[j][1] || ball != baseball[j][2]) {
                    flag = false;
                    break;
                }
            }
            if (flag) answer++;
        }
        return answer;
    }

    int main(void) {
        vector<vector<int>> baseball {
    				{ 123, 1, 1 },
    				{ 356, 1, 0 },
    				{ 327, 2, 0 },
                    { 489, 0, 1}
    			};
        int answer = solution(baseball);
        cout << answer;
        return 0;
    }
    ```

<br/>

## Takeaways

- find out the range of numbers to execute search
- \*start analyzing on how to match the test cases, do not try to focus too much on the test cases which would make the solution narrower
