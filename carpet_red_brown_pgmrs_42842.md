## Problem

- 프로그래머스 > 완전탐색 > 카펫
- https://programmers.co.kr/learn/courses/30/lessons/42842

<br/>

## Approach

1. from the test cases, find out how many red blocks in a given width and length

2. width and length are found by finding divisor of the sum of brown and red blocks

3. calculate red blocks of each width, length pair, and compare with red to find match

<br/>

## Code

```c++
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    
    int sum = brown + red;
    
    vector< pair<int, int> > divisor;
    
    for (int i = 1; i <= sqrt(sum); i++) {
        if (sum % i == 0) {
            int quotient;
            quotient = sum / i;
            divisor.push_back({ quotient, i });
        }
    }
    
    reverse(divisor.begin(), divisor.end());
    
    // check red number match
    for (int i = 0; i < divisor.size(); i++) {
        int num_of_red;
        num_of_red = (divisor[i].first - 2) * (divisor[i].second - 2);
        if (red == num_of_red) {
            answer.push_back(divisor[i].first);
            answer.push_back(divisor[i].second);
            break;
        }
    }
    
    return answer;
}

int main(void) {
    solution(10, 2);
}
```

<br/>

## Other Methods

- > 1. Since border is brown and red has to be at the center area, min_height is 3
  > 2. divide brown + add with a certain height to find width
  > 3. find match 

  - ```c++
    #include <vector>
    
    using namespace std;
    
    vector<int> solution(int brown, int red) {
        vector<int> answer;
        
        int sum = brown + red;
        int height = 3;
        
        while (1) {
            if (sum % height == 0) {
                int width = sum / height;
                if ((height - 2) * (width - 2) == red) {
                    answer.push_back(width);
                    answer.push_back(height);
                    break;
                }
            }
            height++;
        }
        
        return answer;
    }
    
    int main(void) {
        solution(10, 2);
    }
    ```

<br/>

## Takeaways

- there always would be a simpler method
- focus on the concept of the theme of the algorithm to use
  - if exhaustive search -> start from a min value, end at max value 
    - -> find and calculate answers at each stages of search

