#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    while (true) {
        int MIN = 987654321;
        int flag = 0;
        // find the minimum element in vector
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] < MIN && stones[i] != 0) {
                MIN = stones[i];
            }
        }

        // change values in stones
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] > 0) {
                stones[i] = stones[i] - MIN;
            }
        }
            

        // increment by MIN
        answer += MIN;

        // check
        for (int i = 0; i < stones.size() - k; i++) {
            int isZero = 1;
            int count = 0;

            // if not all zero, then continue
            for (int j = i; j < i + k; j++) {
                if (stones[j] != 0) {
                    isZero = 0;
                    break;
                }
            }

            // if all is zero
            if (isZero == 1) {
                flag = 1;
                break;
            }
        }
        // if cannot walk anymore
        if (flag) break;
        
    }
    

    return answer;
}

int main(void) {
    vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
    int k = 4;
    int num = solution(stones, k);
    cout << num;
    return 0;
}