#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> primes;
vector<bool> check;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    //에라토스테네스의 체
    check.resize(n + 1, true);
    for (int i = 2; i*i <= n; i++)
    {
        if (!check[i]) continue;
        for (int j = i * i; j <= n; j += i)
        {
            check[j] = false;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (check[i]) primes.push_back(i);
    }

    //투포인터를 이용
    //1. lo와 hi 사이의 구간합을 구한다.
    //2. 구간합이 n보다 크거나 같으면 가장 왼쪽의 수를 뺀다.
    //3. 구간합이 n보다 작으면 가장 오른쪽의 수를 더한다.
    int result = 0, sum = 0, lo = 0, hi = 0;
    while (1) {
        if (sum >= n) {
            sum -= primes[lo++];
        } else if (hi == primes.size()) {
            break;
        } else {
            sum += primes[hi++];
        }

        if (sum == n) result++;
    }

    cout << result;

    return 0;
}