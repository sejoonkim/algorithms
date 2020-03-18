## Problem

- 프로그래머스 > 완전탐색 > 소수 찾기
- https://programmers.co.kr/learn/courses/30/lessons/42839

<br/>

## Approach

1. Sort to make the largest number
2. From 2 to the largest number, check the number that is prime and can be composed with digits from the largest number

<br/>

## Code

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool elementOfNumbers(int num_to_check, string numbers) {
    //int size_of_numbers = numbers.size();
    int visited[8] = { 0, };

    int isAllChecked = 0;

    string str_num_to_check = to_string(num_to_check);

    for (int i = 0; i < str_num_to_check.size(); i++){
        for (int j = 0; j < numbers.size(); j++){
            if (!visited[j]) {
                if (str_num_to_check[i] == numbers[j]) {
                    visited[j] = 1;
                    isAllChecked++;
                    break;
                }
            }
        }
    }

    if (isAllChecked == str_num_to_check.size()) return true;
    else return false;
}

int solution(string numbers) {
	int answer = 0;

    sort(numbers.begin(), numbers.end(), greater<int>());

    int max_num = stoi(numbers);

    vector<int> check_prime_numbers(max_num + 1, 1);

    // check only prime numbers as true using sieve of Eratosthenes
    for (int i = 2; i <= max_num; i++) {
        if (check_prime_numbers[i]) {
            if (elementOfNumbers(i, numbers)) {
                answer++;
            }

            for (int j = i * 2; j <= max_num; j += i) {
                check_prime_numbers[j] = 0;
            }
        }
    }

	return answer;
}

int main(void) {
    string numbers = "17";
    int answer = solution(numbers);
    cout << answer;
    return 0;
}
```

<br/>

## Other Methods

- > 1. Sort to find the largest number
  > 2. if isPrime is true, checkNumber runs
  > 3. if checkNumber is true, increment answer

  - ```c++
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    //#include <cmath>

    using namespace std;

    vector<int> v;

    bool checkNumber(int num_to_check, string numbers) {
        // stringify num_to_check
        string str_num_to_check = to_string(num_to_check);

        // initialize visited with size of v
        vector<int> visited(v.size());

        // loop for each digits in num_to_check
        for (int i = 0; i < str_num_to_check.size(); i++) {
            // find(A) returns the index of the first occurrence of substring A
            int index = numbers.find(str_num_to_check.substr(i, 1));

            // When comparing signed with unsigned,
            // the compiler converts the signed value to unsigned.
            // The index is signed, numbers.size() is unsigned.
            // When index equals -1, it becomes the largest vlaue of unsigned

            // when num_to_check is not found
            if (index >= numbers.size()) {
                return false;
            }
            // when num_to_check matches, delete the number at numbers
            else {
                numbers = numbers.substr(0, index) + numbers.substr(index + 1);
            }
        }
        return true;
    }

    int solution(string numbers) {
        int answer = 0;

        //// Not using sort on numbers
        // for (int i = 0; i < numbers.size(); i++) {
        //     v.push_back(stoi(numbers.substr(i,1)));
        // }

        // sort(v.begin(), v.end(), greater<int>());

        // for (int i = 0; i < v.size(); i++) {
        //     max = max + (v[i] * pow(10, v.size()- 1 - i));
        // }

        // Using sort on numbers
        sort(numbers.begin(), numbers.end(), greater<int>());
        int max = stoi(numbers);

        // set isPrime vector to true initially
        vector<int> isPrime(max + 1, 1);

        // loop for all numbers from 2 to max
        for (int i = 2; i <= max; i++) {
            // if i is prime number
            if (isPrime[i]) {
                // check number in numbers
                if (checkNumber(i, numbers)) {
                    answer++;
                }

                //// set i's multiples starting from times 2 to not prime number
            	// for (int j = 2; i * j <= max; j++) {
            	//     isPrime[i * j] = 0;
            	// }

            	// j sets the initial multiple value, keeps adding i to find i's multiples
            	for (int j = i; j <= max; j += i) {
            	    isPrime[j] = 0;
            	}
            }
        }
        return answer;
    }

    int main(void) {
        string s = "17";
        int answer = solution(s);
        cout << answer << '\n';

        return 0;
    }
    ```

  - ```c++
    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>

    using namespace std;

    bool isElement(int num_to_check, string numbers) {
        // declare flag if number on a certain digit in i matched a certain element in numbers
        bool isMatch = false;

        // keep track of visited number in numbers
        vector<int> visited(numbers.length());

        // repeat while num_to_check is not 0
        while (num_to_check != 0) {
            // set isMatch to false
            isMatch = false;

            // get the number on the rightmost digit of num_to_check
            int num_on_digit = num_to_check % 10;

            // loop for each number in numbers
            for (int i = 0; i <= numbers.length(); i++) {
                // check if num_on_digit matches numbers[i] and visited[i] is 0
                if (num_on_digit == numbers[i] - '0' && !visited[i]) {
                    // say it is a match
                    isMatch = true;
                    // set visited[i] to 1
                    visited[i] = 1;
                    break;
                }
            }

            // check if there is no match
            if (isMatch == false)
                return false;

            // discard the rightmost digit
            num_to_check /= 10;
        }
        return true;
    }

    int solution(string numbers) {
        int answer = 0;

        // sort the numbers in descending order
        sort(numbers.begin(), numbers.end(), greater<int>());

        // initialize vector with size stoi(numbers) + 1
        vector<int> check_not_prime_not_element_of(stoi(numbers) + 1);

        int stoi_numbers = stoi(numbers);

        // loop for all numbers from 2 to numbers
        for (int i = 2; i <= stoi_numbers; i++) {
            // if i has not been checked and i is an element of numbers, increment answer
            if (!check_not_prime_not_element_of[i] && isElement(i, numbers))
                answer++;

            // if i has not been checked and i is not an element of numbers,
            //check all i's multiples not prime
            if (!check_not_prime_not_element_of[i]) {
                for (int j = i; j <= stoi_numbers; j += i) {
                    check_not_prime_not_element_of[j] = 1;
                }
            }
        }
        return answer;
    }

    int main(void) {
        string s = "17";
        int answer = solution(s);
        cout << answer << '\n';

        return 0;
    }
    ```

<br/>

## Algorithms for finding Prime Numbers

- What is a prime number?

  - A prime number is a natural number greater than 1 that cannot be formed by multiplying two smaller natural numbers. [wikipedia](https://en.wikipedia.org/wiki/Prime_number)

- **Method 1:** Given N, Search from 2 to N - 1

  - ```c++
    #include <iostream>
    using namespace std;

    int main(void) {
        int number;
        cin >> number;

        bool isPrime = true;

        for (int i = 2; i < number; i++) {
            if (number % i == 0){
                isPrime = false;
                break;
            }
        }

        if (isPrime) cout << "It is a Prime Number." << '\n';
        else cout << "It is not a Prime Number." << '\n';
        return 0;
    }
    ```

- **Method 2:** Eratosthenes's approach, sqrt(N)

  - ```c++
    #include <iostream>
    using namespace std;

    int main(void) {
        int number;
        cin >> number;

        bool isPrime = true;

        for (int i = 2; i < number; i++) {
            if (number % i == 0){
                isPrime = false;
                break;
            }
        }

        if (isPrime) cout << "It is a Prime Number." << '\n';
        else cout << "It is not a Prime Number." << '\n';
        return 0;
    }
    ```

- **Method 3:** Sieve of Eratosthenes [link](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)

  - ```c++
    #include <iostream>
    #include <cstring>
    using namespace std;

    int main(void) {
        int number;
        cin >> number;

        bool isPrime[number + 1];
        memset(isPrime, 1, sizeof(isPrime));

        for (int i = 2; i < number; i++) {
            if (isPrime[i] == true){
                // start from the second multiple of i
                for (int j = i * 2; j <= number; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        cout << isPrime[0] << isPrime[14] << isPrime[23];

        return 0;
    }
    ```
