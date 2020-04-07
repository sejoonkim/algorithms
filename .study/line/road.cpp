#include <string>
#include <vector>

using namespace std;

int solution(string road, int n) {
    int answer = -1;

    int count = 0;
    int result = 0;

    for (int i = 0; i < road.size(); i++) {
        if (road[i] == 0)
            count = 0;
        else {
            count++;
            road[i] = 0;
            result = max(result, count);
        }
    }

    for (int i = 0; i < road.size(); i++) {
        if (road[i] == 1)
            answer += i;
    }
    
    return answer;
}

/*
How to fill in roads? given road and number n to fill in zeros
111001111101111011111100011111

*/
