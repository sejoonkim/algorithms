[바킹독](https://blog.encrypted.gg/category/강좌/실전 알고리즘)

# Contents

1. [코드 작성 요령 1](#기초-코드-작성-요령-1)
2. [코드 작성 요령 2](#기초-코드-작성-요령-2)
3. [배열](#배열)
4. [연결리스트](#연결리스트)
5. [스택](#스택)
6. [큐](#큐)
7. [덱](#덱)
8. [스택활용(수식의 괄호쌍)](#스택활용(수식의-괄호쌍))
9. [Flood Fill](#Flood-Fill)
10. [BFS](#BFS)
11. [DFS](#DFS)
12. [재귀](#재귀)
13. 백트래킹
14. 시뮬레이션
15. 정렬1
16. 정렬2
17. 다이나믹 프로그래밍
18. 그리디

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

  - char*로 입력 받고, string 형 변환 휴 c_str()로 출력한다.

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

       

- cin/cout만 쓸 경우 속도 빠르게 하자.

  ```c++
  ios::sync_with_stdio(0);
  cin.tie(0);
  ```

- endl 절대 쓰지 않기.

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

<br/>

<br/>

## 연결리스트

목차

1. 정의와 성질
2. 기능과 구현
3. STL list
4. 연습 문제

<br/>

### 1. 정의와 성질

- 연결 리스트의 성질

  1. k번째 원소를 확인/변경하기 위해 O(k)가 필요하다.
  2. 임의의 위치에 원소를 추가/임의 위치의 원소 제거는 O(1)
  3. 원소들이 메모리 상에 연속해있지 않아 Cache hit rate가 낮지만 할당이 다소 쉽다.

- 연결 리스트의 종류

  - 단일 연결 리스트 - singly linked list
  - 이중 연결 리스트 - doubly linked list
  - 원형 연결 리스트 - circular linked list

- 배열 vs 연결 리스트

  - |               항목               | 배열 | 연결 리스트 |
    | :------------------------------: | :--: | :---------: |
    |        k번째 원소의 접근         | O(1) |    O(k)     |
    |    임의 위치에 원소 추가/제거    | O(N) |    O(1)     |
    |         메모리 상의 배치         | 연속 |   불연속    |
    | 추가적으로 필요한 공간(overhead) |  -   |    O(N)     |

<br/>

### 연결 리스트의 구현

- ```c++
  struct NODE {
  	struct NODE *prev, *next;
      int data;
  }
  ```

- 야매 연결 리스트

  - ```c++
    const int MAX = 10000005;
    int data[MAX], pre[MAX], nxt[MAX]; // 이전과 다음 원소를 배열 상 인덱스 저장하는 방식으로 구현했다.
    int unused = 1;
    
    fill(pre, pre+MAX, -1); // -1: 이전/다음 원소가 존재하지 않는다.
    fill(nxt, nxt+MAX, -1);
    
    // traverse()
    void traverse(){
        int cur = nxt[0];
        while(cur != -1){
            cout << dat[cur] << ' ';
            cur = nxt[cur];
        }
        cout << "\n\n";
    }
    ```

- 제일 마지막 원소 O(1)에 확인하는 방법? 

  - Circular linked list?

<br/>

### STL list

- C++11 이상일 때 auto t = L.begin()

- ```c++
  int main(void){
      list<int> L = {1, 2};
      list<int>::iterator t = L.begin(); // t is at 1
      L.push_front(10); // 10 1 2
      cout << *t << '\n'; // 1
      L.push_back(5); // 10 1 2 5
      L.insert(t, 6); // at the front of t insert 6, 10 6 1 2 5
      t++; // t is at 2
      t = L.erase(t); // t is at 5
      cout << *t << '\n' // 5
          for (auto i : L) cout << i << ' ';
      cout << '\n';
      for (list<int>::iterator it = :.begin(); it != L.end(); it++)
          cout << *it << ' ';
  }
  ```

<br/>

### 4. 연습문제

- 풀어보기 - https://blog.encrypted.gg/932?category=773649

<br/>

<br/>

## 스택

목차

1. 정의와 성질
2. 기능과 구현
3. STL stack
4. 연습문제

<br/>

### 1. 정의와 성질

- 스택의 성질
  1. 원소의 추가가 O(1)
  2. 원소의 제거가 O(1)
  3. 제일 상단의 원소 확인이 O(1)
  4. 제일 상단이 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능
     - 단, 배열로 구현하면 가능

<br/>

### 2. 기능과 구현

- 배열 구현

  - ```c++
    const int MAX = 1000005;
    int dat[MAX];
    int pos = 0;
    ```

- push 함수

  - ```c++
    void push(int x) {
        dat[pos++] = x;
    }
    ```

- pop 함수

  - ```c++
    void pop() {
    	pos--;
    }
    ```

- top 함수

  - ```c++
    int top() {
        return dat[pos-1];
    }
    ```

<br/>

### 3. STL stack

- stack이 비어있는데 s.top(), s.pop()하면 runtime 에러가 발생한다.

<br/>

### 4. 연습문제

- 핵심유형
  1. 수식의 괄호 쌍
  2. 전위/중위/후위 표기법
  3. DFS
  4. Flood Fill

<br/>

<br/>

## 큐

목차

1. 정의와 성질
2. 기능과 구현
3. STL queue
4. 연습문제

<br/>

### 1. 정의와 성질

- 큐의 성질
  1. 원소의 추가가 O(1)
  2. 원소의 제거가 O(1)
  3. 제일 앞/뒤의 원소 확인이 O(1)
  4. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능
- **중요**
  - STL queue에는 인덱스로 내부 원소를 접근하는 기능이 없다.

<br/>

### 2. 기능과 구현

- 배열 구현

  - ```c++
    const int MAX = 1000005;
    int dat[MAX];
    int head = 0, tail = 0;
    ```

- push 함수

  - ```c++
    void push(int num) {
    	dat[tail] = num;
        tail++;
        // dat[tail++] = num;
    }
    ```

  - 

- pop 함수

  - ```c++
    void pop() {
        head++;
    }
    ```

- front/back 함수

  - ```c++
    int front() {
    	return dat[head];
    }
    
    int back() {
    	return dat[tail-1];
    }
    ```

<br/>

### 3. STL queue

- 큐가 비어 있는데 front나 back, pop을 호출하면 runtime 에러가 발생한다.
- 핵심유형
  1. BFS
  2. Flood Fill

<br/>

### 4. 연습문제

​	1. https://www.acmicpc.net/problem/10845

<br/>

<br/>

## 덱

목차

1. 정의와 성질
2. 기능과 구현
3. STL deque
4. 연습문제

<br/>

### 1. 정의와 성질

- Double Ended Queue

- 양쪽 끝에서 삽입과 삭제가 전부 가능하다.

- 덱의 성질

  1. 원소의 추가가 O(1)
  2. 원소의 제거가 O(1)
  3. 제일 앞/뒤의 원소 확인이 O(1)
  4. 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가능

- > 인덱스로 원소에 접근할 수 있다. @STL deque
  >
  > VS. @STL stack, @STL queue는 불가하다.

<br/>

### 2. 기능과 구현

- 배열 구현

  - ```c++
    const int MAX = 1000005;
    int dat[2*MAX + 1];
    int head = MAX, tail = MAX;
    ```

- push_front 함수, push_back 함수

  - ```c++
    void push_front(int num) {
    	if (head >= 0) {
            dat[--head] = num;
        }
    }
    
    void push_back(int num) {
        if (tail <= 2*MAX) {
            dat[tail++] = num;
        }
    }
    ```

- pop_front 함수, pop_back 함수

  - ```c++
    void pop_front() {
        if (head <= tail) {
            head++;
        }
    }
    
    void pop_back() {
        if (head <= tail) {
            tail--;
    	}
    }
    ```

- front 함수, back 함수

  - ```c++
    int front() {
        return dat[head];
    }
    
    int back() {
    	return dat[tail-1];
    }
    ```

<br/>

### 3. STL deque

- similar to vector
- BUT the elements are not stored in contiguous storage locations in deque.

```c++
#include <deque>
using namespace std;

deque<int> DQ;

int main(void) {
	DQ.push_front(10); // 10
    DQ.push_back(50); // 10 50
    DQ.push_front(24); // 24 10 50
    cout << DQ.size() << '\n'; // 3
    if (DQ.empty()) cout << "DQ is empty\n";
    DQ.pop_front(); // 10 50
    DQ.pop_back(); // 10
    cout << DQ.back() << '\n'; // 10
    DQ.push_back(72); // 10 72
    cout << DQ.front() << '\n'; // 10
    DQ.push_back(12); // 10 72 12
    DQ[2] = 17; // 10 72 17
    DQ.insert(DQ.begin() + 1, 33); // 10 33 72 17
    DQ.insert(DQ.begin() + 4, 60); // 10 33 72 17 60
    DQ.erase(DQ.begin() + 3); // 10 33 72 60
    cout << DQ[3] << '\n'; // 60
    DQ.clear();
    return 0;
}
```

<br/>

### 4. 연습문제

- https://www.acmicpc.net/problem/10866

<br/>

<br/>

## 스택활용(수식의 괄호쌍)

목차

1. 수식의 괄호 쌍이란?
2. 문제 해결을 위한 관찰
3. 문제 해결 방법
4. 연습문제

<br/>

### 1. 수식의 괄호 쌍이란?

- > (())()() - O
  >
  > ))(() - X
  >
  > ())())(()) - O

<br/>

### 2. 문제 해결을 위한 관찰

- 괄호의 종류가 여러 개인 경우
- 문자열을 앞에서부터 읽어나갈 때, 닫는 괄호는 남아있는 괄호 중에서 가장 최근에 들어온 여는 괄호와 짝을 지어 없애버리는 명령이라고 생각한다.

<br/>

### 3. 문제 해결 방법

1. 여는 괄호가 나오면 스택에 추가한다.
2. 닫는 괄호가 나왔을 경우,
   1. 스택이 비어있으면, 올바르지 않은 괄호 쌍
   2. 스택의 top이 짝이 맞지 않는 괄호일 경우 올바르지 않은 괄호 쌍
   3. 스택의 top이 짝이 맞는 괄호일 경우 pop
3. 모든 과정을 끝낸 후 스택에 괄호가 남아있으면 올바르지 않은 괄호 쌍, 남아있지 않으면 올바른 괄호 쌍

<br/>

### 4. 연습문제

1. https://www.acmicpc.net/problem/4949

   - use short-circuit evaluation
   - 스택을 전역으로 설정 했을 때 주의!
     - input 단위로 스택이 필요하기 때문에, input할 때마다 stack을 생성하자.

2. https://www.acmicpc.net/problem/10799

   - 닫힌 괄호가 레이저를 의미하는지, 쇠막대기를 의미하는지?

3. https://www.acmicpc.net/problem/2504

   1. 왼쪽 괄호가 나올 때마다 스택에 넣는다.

      1. 핵심: temp = 1로 선언하여, '('일 때는 * 2, '['일 때는 * 3 한다.
      2. 내용물이 있을 때와 없을 때를 구분하면 코드 길어지고 시간 많이 걸린다.

   2. 시간 단축을 위해 불가능한 조합이 나올 경우 미리 반복문에서 탈출한다.

      1. > (()()()

         - 정의한 불가능한 경우를 빠져나간다.
         - 반복문을 다 돌고도 스택이 비지 않았을 경우, 불가능하다고 판단해야 한다.

   3. 오른쪽 괄호가 나올 때마다 스택에서 제거한다.

      1. 바로 전 인덱스에서 있던 괄호가 맞는 쌍일 경우에만 결과에 더한다.
         1. 결국 괄호쌍 내에 내용물이 있냐 없냐는 중요하지 않았다.
      2. 소괄호일 경우 temp / 2, 중괄호일 경우 temp / 3

   4. impossible 혹은 스택이 비지 않았을 경우 무조건 0 출력, 아닐 경우에는 결과를 출력한다.

<br/>

<br/>

## Flood Fill

### 문제 개요

- 다차원 배열에서 어떤 칸과 연결된 영역을 찾는 알고리즘
- 마치 그림판에서 색 채우기 명령으로 동일한 색을 전부 바꾸는 것이다.

<br/>

<br/>

## BFS

### 개요

- 다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘이다.

<br/>

### 설명

1. 시작하는 칸을 큐에 넣고 방문했다는 표시를 남긴다.
2. 큐에서 원소를 꺼내어 그 칸에 상/하/좌/우로 인접한 4개의 칸에 대해 3번 행동을 한다.
3. 해당 칸을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 넣는다.
4. 큐의 모든 원소가 빌 때 까지 2를 반복한다.

<br/>

### 특징

- 모든 칸이 큐에 1번 씩만 들어감이 보장되므로 시간복잡도는 칸이 N개일 때 O(N)이다.

<br/>

### 예시

- https://blog.encrypted.gg/729?category=773649
- 예시 코드
  - https://0bin.net/paste/RcSjQF1D3wU6wHIs#C1aLSA1Wbaxy5JeMsLoHcRisFEofH0-Evx4d2YVtMrZ

```c++
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용한다.

int board[502][502] = {
    {1,1,1,0,1,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
}; // 1 is Blue, 0 is Red

bool visited[502][502]; // save visited
int n = 7, m = 10; // n = number of rows, m = number of columns
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // the four directions

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> Q;
    visited[0][0] = 1; // check already visited (0, 0)
    Q.push({0, 0}); // push to Q the starting point
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int dir = 0; dir < 4; dir++) { // will check for all 4-directions
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어간다.
            if (nx < 0 or nx >= n   or ny < 0 or ny >= m) continue; // 범위 밖일 경우 넘어간다.
            if (visited[nx][ny] or board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우 넘어간다.
            visited[nx][ny] = 1; // (nx, ny)를 방문했다고 명시한다.
            Q.push({nx, ny});
        }
    }
}
```

<br/>

### 응용

- https://www.acmicpc.net/problem/1926
- https://www.acmicpc.net/problem/2178

<br/>

### 자주 실수하는 요소

1. 시작 점에 방문했다는 표시를 남기지 않는다.
2. 큐에 넣을 때 방문했다는 표시를 하지 않고, 큐에서 빼낼 때 방문했다는 표시를 남긴다.
3. 문자열로 지도를 입력 받았을 때 '1'과 비교를 해야 하는데 1과 비교를 한다.
4. 이웃한 원소가 범위를 벗어났는지에 대한 체크를 잘못했다.
5. 배열로 큐를 구현한 경우 ,큐의 크기를 충분하게 주지 않았다.
6. 가로와 세로를 헷갈렸다.
7. 여러 테스트 케이스를 처리해야 하는 경우, 변수를 제대로 초기화하지 않았다.

<br/>

<br/>

## DFS

### 개요

- 다차원 배열에서 각 칸을 방문할 때 깊이를 우선으로 방문하는 알고리즘이다.

<br/>

### 설명

1. 시작하는 칸을 스택에 넣고 방문했다는 표시를 남긴다.
2. 스택에서 원소를 꺼내 그 칸에 상/하/좌/우로 인접한 4개의 칸에 대해 3번 행동을 한다.
3. 해당 칸을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 넣는다.
4. 스택의 모든 원소가 빌 때 까지 2를 반복한다.

<br/>

### 특징

- 모든 칸이 스택에 1번씩 들어감이 보장되므로 시간복잡도는 칸이 N개일 때 O(N)입니다.
- 큐에서 원소를 넣었다가 꺼내는지, 스택에서 원소를 넣었다가 꺼내는지

<br/>

### 예시

- https://blog.encrypted.gg/729?category=773649
- 예시 코드
  - https://0bin.net/paste/fd4--ZSocw-8wCdN#d0dC6SHLTDS7wy7200cwBYIiyPrZechYUVGD81G9Kuz

```c++
#include <iostream>
#include <stack>

using namespace std;

#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,1,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

bool visited[502][502];
int n = 7, m = 10;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack< pair<int, int> > s;

    visited[0][0] = 1;
    s.push({0, 0});

    while(!s.empty()) {
        auto cur = s.top(); s.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!board[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            s.push({nx, ny});
        }
        
    }
    return 0;
}
```

<br/>

### 주의사항

1. 거리가 정확하지 않다.
   - 시작점으로부터의 거리를 잴 때는 DFS 대신 BFS를 사용해야 한다.

<br/>

<br/>

## 재귀

목차

1. 재귀란?
2. 예시 문제 1: 거듭제곱
3. 예시 문제 2: 하노이 탑
4. 문제 소개

<br/>

### 1. 재귀란

- 하나의 함수에서 자기 자신을 다시 호출해 작업을 수행하는 방식이다.

- 자기 자신을 다시 호출할 때에는 현재 함수에서의 입력값보다 더 작은 값을 인자로 넘겨주어야 합니다.

- Base condition으로 호출 중단해야 한다.

- 예시 1

  ```c++
  #include <iostream>
  using namespace std;
  
  void func(int n) {
      cout << n << ' ';
      if (n == 1) return; // base condition
      func(n-1);
  }
  
  int main(void) {
      func(5);
      return 0;
  }
  ```

- 예시 2

  ```c++
  #include <iostream>
  using namespace std;
  
  void func(int n) {
  		if (n == 1) return 1; // base condition
    	return n * func(n-1);
  }
  
  int main(void) {
  		cout << func(5);
  }
  ```

- **TIP**

  1. 함수가 입력에 대해 어디까지 연산을 수행하고, 어떤 입력값을 자기 자신에게 다시 넘겨주어야 할지 잘 정해야 한다. 

  2. 모든 재귀 함수는 재귀 구조 없이 반복문만으로 동일한 동작을 하는 함수를 구현할 수 있다. (역도 성립한다.) 재귀를 사용할 경우 반복문으로 구현을 했을 때에 비해 코드를 간결하고 이해하기 쉽게 만들 수 있다는 장점이 있지만, 메모리/시간에서는 손해를 본다.

  3. 경험적으로 재귀를 사용할 때를 알자!

  4. 피보나치 수열 - 재귀로 해결하면 안 된다!

     - 이미 계산한 값을 다시 계산한다. -> BAD, 지수함수 시간복잡도이다.

     - k번째 항을 구하는 것이 목표이다.
     - DP로 보통 해결한다.
     - https://blog.encrypted.gg/731?category=773649 참고하자

  5. 재귀함수 호출은 스택 메모리에 계속 누적된다.

     - 문제 전체의 메모리 제한만 있고 스택 메모리에 다른 제한이 없다면, 시간 초과가 먼저 발생하게 되어 스택 메모리를 신결쓸 필요가 없다.재귀로 스택 메모리를 다 채우고 싶어도 할 수 없다.