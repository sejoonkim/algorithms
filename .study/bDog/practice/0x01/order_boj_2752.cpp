#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    
    // vector<int> v;
    // for (int i = 0; i < 3; i++) {
    //     int num;
    //     cin >> num;
    //     v.push_back(num);
    // }

    // sort(v.begin(), v.end());

    // for (int i = 0; i < 3; i++) {
    //     cout << v[i] << " ";
    // }

    int a[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
