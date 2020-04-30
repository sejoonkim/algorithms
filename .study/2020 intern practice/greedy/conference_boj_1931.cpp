/*
start - 
  end - 

- think real life
- if now is time t, start time >= t, choose the conference that finishes early

1. get the n input
2. get the time inputs with STL pair
3. sort with the pair that ascending 2nd value, if same 2nd, then earlist 1st value
4. int time = 0, count = 0;
5. for loop 
    1. if i->second >= time
        time += i->second
        count++;
6. cout << count;
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector< pair<int, int> > p;

bool compare(pair<int, int>& elem1, pair<int, int>& elem2) {
    if (elem1.second == elem2.second) return elem1.first < elem2.first;
    return elem1.second < elem2.second;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }
    
    sort(p.begin(), p.end(), compare);

    int time = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].first >= time) {
            time = p[i].second;
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}