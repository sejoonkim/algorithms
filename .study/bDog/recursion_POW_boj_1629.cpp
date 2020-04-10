#include <iostream>
using namespace std;

typedef long long ll;

ll POW(ll a, ll b, ll m) {
    if (b == 0) return 1;
    ll val = POW(a, b/2, m);
    val = val * val % m;
    if (!(b & 1)) return val;
    else return val * a % m;
}

int main(void) {
    ll a, b, m;
    cin >> a >> b >> m;
    cout << POW(a, b, m);    
    return 0;
}