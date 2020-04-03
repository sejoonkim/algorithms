[바킹독](https://blog.encrypted.gg/category/강좌/실전 알고리즘)

# Contents

1. [코드 작성 요령 1](#기초-코드-작성-요령-1)
2. [코드 작성 요령 2](#기초-코드-작성-요령-2)
3. [배열](#배열)
4. [연결리스트](#연결리스트)
5. 스택
6. 큐
7. 덱
8. 스택활용(수식의 괄호쌍)
9. BFS
10. DFS
11. 재귀
12. 백트래킹
13. 시뮬레이션
14. 정렬1
15. 정렬2
16. 다이나믹 프로그래밍
17. 그리디

<br/>

<br/>

## 기초 코드 작성 요령 1

목차

1. 시간, 공간 복잡도
2. 정수 자료형
3. 실수 자료형

<br/>

### 1. 시간, 공간 복잡도

- 시간

  - 1초 = 3 ~ 5억 개 연산

    - 300,000,000 ~ 500,000,000 개 연산

  - 연산 복잡도

    - 단순 연산
      - 비트연산, AND, OR, 비교연산, 덧셈연산
    - 복잡 연산
      - 나눗셈, 곱셈, 대입연산, 함수호출

  - > 내가 알고리즘의 시간 복잡도를 고려했는지 생각해보자!

- 공간

  - 512MB = 1.2 억 개 int형 변수 저장이 가능하다.

<br/>

### 2. 정수 자료형

- Integer Overflow
  - 컴퓨터는 무식하게 시킨 계산만 수행한다.
  - int or long long
  - unsigned int or unsigned long long

<br/>

### 3. 실수 자료형

- [실수의 표현, 고정, 부동 소수점 방식](http://tcpschool.com/c/c_refer_floatingPointNumber)
- [부동소수점 변수 포맷 (IEEE 754-1985)](https://gammabeta.tistory.com/319)

1. 실수 연산, 저장할 때 **오차** 발생한다.

   - float: 유효숫자 6자리

   - double: 유효숫자 15자리

   - **double** > float

   - > 문제에서 "절대/상대 오차가 허용됩니다."
     >
     > -> 실수 자료형이 필요한 것이다.

2. long long 범위에 담을 수 있는 정수는 double에 담지 말자.

   - long long 19자리 > double 15자리
   - int는 double에 담을 수 있다.

3. 실수 비교는 **등호**를 사용하지 말자.

   - ```c++
     if(abs(a - b) < 1e-12) // 차이가 1e-12보다 작으면 동일하다고 판단하자!
     ```

<br/>

<br/>

## 기초 코드 작성 요령 2

목차

1. STL과 함수 인자
2. 표준 입출력
3. 코드 작성 팁

<br/>

### 1. STL과 함수 인자

- 함수 인자 - C++ 참조자(reference) vs C 포인터

  - C++ 참조자

    - ```C++
      void swap(int& a, int& b){
          int tmp = a;
          a = b;
          b = tmp;
      }

      void swap(int* a, int* b){
          int tmp = a;
          a = b;
          b = tmp;
      }
      ```

    - C 포인터와 비슷, 그러나 Null pointer에 값 넣거나, type이 다른 것을 마음대로 casting 문제 줄였다.

- STL과 함수 인자

  - vector reference

    - ```c++
      bool cmp(vector<int>& v1, vector<int>& v2, int idx){
          return v1[idx] > v2[idx];
      }
      ```

<br/>

### 2. 표준 입출력

- scanf/printf에서 C++ string 처리할 수 **없다.**

  - char\*로 입력 받고, string 형 변환 휴 c_str()로 출력한다.

    - ```c++
      int main(void){
          char str[10];
          printf("input : ");
          scanf("%s", str);
          string s(str); // string s = str;
          printf("str is %s\n", str);
          printf("s is %s\n", s.c_str());
      }
      // str is something
      // s is something
      ```

- 공백이 포함된 문자열을 받는 경우 주의하자.

  - scanf/cin을 그대로 쓰면 망한다.

  1. scanf를 쓰는 경우

     - ```c++
       char str[1];
       scanf("%[^\n]", str); // 줄바꿈 전까지 입력 받겠다.
       ```

  2. cin을 쓰는 경우 - feat. getline

     - ```c++
       string s;
       getline(cin, s);
       cout << s;
       ```

     - cin.ignore()

       ```c++
       // 이전 cin 입력과정으로 버퍼에 개행문자가 남아 있는 경우
       cin.ignore(); // 버퍼 비우기
       getline(cin, string); // 정상 작동
       ```

* cin/cout만 쓸 경우 속도 빠르게 하자.

  ```c++
  ios::sync_with_stdio(0);
  cin.tie(0);
  ```

* endl 절대 쓰지 않기.

  - '\n' 쓰기

<br/>

### 3. 코드 작성 팁

- 작동하게만 짜라.

- 출력 맨 마지막에 공백, 줄바꿈 있어도 상관 없다.
- 디버거는 사용하지 말라, cout을 사용하자.

<br/>

<br/>

## 배열

목차

1. 정의와 성질
2. 기능과 구현
3. STL vector
4. 연습 문제

<br/>

### 1. 정의와 성질

- 배열의 성질
  1. O(1)에 k번째 원소를 확인/변경 가능하다.
  2. 추가적으로 소모되는 메모리의 양(=overhead)가 거의 없다.
  3. Cache hit rate가 높다. [Cache hit rate 설명](https://blog.naver.com/sungeuns/50098123735)
  4. 메모리 상에 연속한 구간을 잡아야 해서 할당에 제약이 걸린다.

<br/>

### 2. 기능과 구현

- 임의의 위치에 원소를 추가 또는 제거

  - O(N) 시간 소요

- 사용 팁

  - 배열 전체를 특정 값으로 초기화할 때

    - memset 비추

    - for문 이나 **algorithm의 fill 강추**

      - ```c++
        fill(v.begin(), v.end(), 0) // 0으로 초기화
        ```

<br/>

### 3. STL vector

- insert, erase 기능

  - ```c++
    v.insert(v.begin() + 1, 3); // {0, 0} -> {0, 3, 0}
    v.erase(v.begin() + 2); // {0, 3}
    ```

- range-based for loop

  - ```c++
    vector<int> v(5, 0);
    for (int i : v)
        cout << i << ' '; // 0 0 0 0 0

    for (int& i: v) {
        i = 1;
        cout << i << ' '; // 1 1 1 1 1
    }
    ```

- v.size() -1

  - ```c++
    for (int i = 0; i <= v.size()-1; i++){
        // error: if v is an empty vector, v.size() is unsigned int 0
        // unsigned int overflow
    }
    ```

<br/>

### 4. 연습문제

- 복습하고 확인하기
- 배열 - https://blog.encrypted.gg/927?category=773649
