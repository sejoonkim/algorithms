#include <iostream>
using namespace std;

const int MAX = 100010;
long long int table[MAX];
int n;

int main() {

cin>>n;

table[1] = 1;
table[2] = 2;
table[3] = 4;

for(int i=4; i<=n; i++){
  for(int j=i-3; j<=i-1; j++){
    table[i] += table[j];
    table[i] %= 1000007;
  }
}
cout<<table[n];
  return 0;
}