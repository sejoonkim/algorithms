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
