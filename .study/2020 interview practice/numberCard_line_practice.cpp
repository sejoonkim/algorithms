/*
1. create vector<int> && fill it in
2. sort(v.begin(), v.end());
3. for (int i = 0; i < K; i++){
    next_permutation(v.begin(), v.end());
}
4. for (auto i : v)
    cout << i << ' ';
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int K;

int main(void) {
    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    cin >> K;

    sort(v.begin(), v.end());

    for (int i = 1; i < K; i++) {
        next_permutation(v.begin(), v.end());
    }

    for (auto i : v)
        cout << i << ' ';

    return 0;
}