#include <string>
#include <vector>

using namespace std;

int count_suspicious = 0;
int count_continuous = 0;
int sum = 0;
int max_length = 0;
int max_suspicious = 0;

int solution(string answer_sheet, vector<string> sheets) {
    int answer = -1;

    for (int i = 0; i < sheets.size() - 1; i++) {
        for (int j = i + 1; j < sheets.size(); j++) {
            for (int k = 0; k < answer_sheet.size(); k++) {
                if (sheets[i][k] == sheets[j][k] && sheets[i][k] != answer_sheet[k]) {
                    count_suspicious++;
                    count_continuous++;
                    if (max_length < count_continuous) {
                        max_length = count_continuous;
                    }
                } else {
                    count_continuous = 0;
                }
            }
            sum = count_suspicious + max_length * max_length;
            if (max_suspicious < sum) {
                max_suspicious = sum;
            }
            count_suspicious = 0;
            count_continuous = 0;
            sum = 0;
            max_length = 0;
        }
    }
    answer = max_suspicious;
    return answer;
}