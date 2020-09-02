/*
start - 09 : 40
  end - 10 : 03

- using map to insert with key and value
1. get three inputs
2. multiply them
3. transform as string
4. insert values to map<char, int>
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<char, int> m;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    long long mult = a * b * c;

    string m_str = to_string(mult);

    for (int i = 0; i < m_str.size(); i++) {
        m[m_str[i]]++;
    }

    for (int i = 0; i <= 9; i++) {
        char idx = i + '0';
        if (m[idx]) cout << m[idx] << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}