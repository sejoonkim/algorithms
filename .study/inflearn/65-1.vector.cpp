#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

  

    // vector<int> a(5);
    // a[1] = 5;
    // cout << a[1];
    // a.push_back(6);
    // a.push_back(8);
    // a.push_back(11);
    // cout << a.size() << '\n';
    // cout << a[1] << '\n';

    // vector<int> c[3]; // vector가 3개 생성된다.
    // c[0].push_back(1);
    // c[0].push_back(2);
    // c[0].push_back(3);
    // c[1].push_back(4);
    // c[1].push_back(5);
    // c[1].push_back(6);
    // c[2].push_back(7);
    // c[2].push_back(8);
    // c[2].push_back(9);


    // cout << c[1][1] << '\n';
    // cout << c[2][0] << '\n';


    vector<pair<int, int> > g[3];
    g[1].push_back({3, 5});
    g[1].push_back({4, 7});
    g[1].push_back({5, 9});
    g[2].push_back(make_pair(7, 7));
    cout << g[2][0].first << ' ' << g[2][0].second << '\n';
    
    return 0;
}