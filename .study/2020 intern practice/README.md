## Greedy Algorithm

### Basic Concept

- compared with `Dynamic Programming` does not guarantee optimal solution
- along with `Dynamic Programming`
  - the problem requires `Optimal Sub-Structure`
- Process of Greedy Algorithm
  1. Find Solution
     - find optimal solution for the sub-problem
     - add it to the solution set
  2. Check Applicable
     - check if the new solution set is executable
  3. Match with Target
     - check if the new solution set is the solution to the problem
     - if not, loop from 1.

<br/>

### Q1: Change

1. Find Solution
   - choose the biggest value coin
2. Check Applicable
   - check if the biggest value coin exceeds actual change
   - if true, choose the next biggest value coin
3. Match with Target
   - if not, loop from 1

<br/>

### 그리디의 함정

1. 0/1 knapsack problem

   - 부피 대비 가치 선택
     - 반례: 부피 - 10, 물건 - (6,7), (5,5), (5,3)
     - 정해: O(NK) DP or O(2^N) 전수조사

2. [휴게소](https://icpc.me/1477)
   - 휴개소 0개 일 때, 새로운 휴게소 2개를 세우는 과정
   - 정해: O(Nlg1000) 이분탐색
