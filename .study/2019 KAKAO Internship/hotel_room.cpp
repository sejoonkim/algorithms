// #include <string>
// #include <vector>
// #include <iostream>

// using namespace std;

// vector<long long> solution(long long k, vector<long long> room_number) {
//     vector<long long> answer;
    
//     for (int i = 0; i < room_number.size(); i++) {
//         if (!arr[room_number[i]]){
//             arr[room_number[i]] = true;
//             answer.push_back(room_number[i]);
//         }
//         else {
//             for (int j = room_number[i] + 1; j < k; j++) {
//                 if (!arr[room_number[j]]){
//                     arr[room_number[j]] = true;
//                     answer.push_back(room_number[j]);     
//                     break;
//                 }
//             }
//         }
        
//     }
//     return answer;
// }

// int main(void) {
//     long long k = 10;
//     vector<long long> room_number = {1, 3, 4, 1, 3, 1};

//     vector<long long> v = solution(k, room_number);

//     return 0;
// }