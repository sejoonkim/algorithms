# Data Structures with C

Table of Contents

1. Data Structures and Algorithms
2. Recursion
3. Array, Struct, Pointer

<br/>

## Data Structures and Algorithms

### 1.2 Abstract Datatypes

- Quiz

  - is_greater(x, y)

    - ```c++
      /*
      boolalpha is a function which is a manipulator.
        - Designed to use alone with no arguments
        - used between << and >>
        - values are represented either "true" or "false"
      */
      cout << boolalpha << result;
      ```

    - http://www.cplusplus.com/reference/ios/boolalpha/

  - better way of printf bool

    - ```c
      printf("%s", result ? "true" : "false");
      ```

    - using ternary operator

  - simple return in bool function

    - ```c
      bool is_greater(int x, int y) {
          return x > y;
      }
      ```

    - there would be a better way than if-elseing

  - `#include "stdbool.h"`

    - 4 macros for a boolean data type
      1. bool : expands to \_Bool
      2. true: expands to 1
      3. false: expands to 0
      4. \_\_bool_true_false_are_defined: expands to 1

<br/>

### 1.3 Calculating Time Complexity

- calculating duration of an algorithm

  - ```c
    #include <time.h>
    start = clock();
    ...
    end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    ```

  - ```c
    #include <time.h>
    start = time(NULL);
    ...
    end = time(NULL);
    double duration = (double) difftime(end, start);
    ```

- for loop has

  - 1 - `int i = 0`
  - n + 1 - `i < n`
  - n - `i++`

<br/>

<br/>

## Recursion

### 2.1 Recursion and System Stack

- Structure of memory

  - from `lower memory address`
  - CODE
    - instructions
    - CPU takes them one by one and executes
  - DATA
    - global and static variables
  - HEAP
    - size set at runtime
    - **user** should manage well
    - :arrow_down:
  - STACK
    - :arrow_up:
    - size set at compile time
    - deals with function calls by creating `stack frame` = `activation record`
      - `return address` is saved
      - `local variables` & `function parameters` are saved
    - too much recursive function call would increase overhead in memory
  - to `higher memory address`

- structure of recursive algorithm

  1. stopping condition
  2. making recursive calls

- basics of recursion

  - state part of solution

  - THEN do recursion on the **rest** of the problem

    - ```c
      factorial(int n) {
          if (n <= 1) return 1;
          else return n * factorial(n-1); // n = part of solution
      }

      ```

<br/>

### 2.2 Power

- IMPORTANT = the SIZE of problem n

- = # of searching iteration n

- ```c
  double power(double x, int n) {
      if (!n) return 1.0;
      else if (n & 1) return x * power(x * x, (n - 1) / 2);
      else return power(x * x, n / 2);
  }
  ```

- O(logn)

<br/>

### 2.3 Fibonacci

- loop > recursion

- ```c
  int fib(int n) {
  	if (n == 0) return 0;
  	if (n == 1) return 1;
  	return fib(n-1) + fib(n-2);
  }
  ```

- ```c
  int fib_loop(int n) {
  	if (n == 0) return 0;
      if (n == 1) return 1;

      int pp = 0;
      int p = 1;
      int result;

      for (int i = 2; i <= n; i++) {
          result = p + pp;
          pp = p;
          p = result;
      }

      return result;
  }
  ```

<br/>

### 2.4 Hanoi

- number of moves = 2^n - 1

- ```c
  void hanoi(int n, char from, char tmp, char to) {
      if (n == 1) {
  		printf("move 1 from %c to %c", from, to);
      }
      else {
          hanoi(n-1, from, to, tmp);
          printf("move %d from %c to %c", n, from, to);
          hanoi(n-1, tmp, from, to);
      }
  }
  ```

<br/>

<br/>

## Array, Struct, Pointer

### 3.1 Array

- Array ADT

  - > Object: <index, value> pair
    >
    > Operation:
    >
    > - create(size) ::= create array with size size
    > - get(A, i) ::= returns ith element in array A
    > - set(A, i, n) ::= sets ith element in array A to n

- Array Address

  - `base` + `i * sizeof(int)`

<br/>

### 3.2 Struct

- Array = continuous memory allocation for same datatypes

- Struct = continuous memory allocation for different datatypes

- '.' = membership operator

- ```c
  typedef StudentTag {
      char name[10];
      int age;
      double gpa;
  } student;

  student a = {"kim", 20, 4.3}; // easy initialization
  ```

<br/>

### 3.3 Array: Polynomials

- Which datastructure to use considering comfort and lower memory usage
- 2 ways of arithmetic on two polynomials
  1.  save coefs into array
      1. create struct that contains int and float array
      2. create a function that returns the finished array
  2.  create global struct array
      1. declare struct with a pair { coef, expon }
      2. declare global struct array
      3. create a function that compares the expons and do operations

<br/>

### 3.4 Array: Sparse Matrix

- 2 ways to calculate the sparse matrix
  1. classic 2-d array
  2. using 2 structs to function like 2-d array

<br/>

### 3.5 Pointer

- basics

  - a variable that contains other variable's address

  - & operator

    - ```c
      int a = 100;
      int *p;
      p = &a;
      ```

  - \* operator

    - ```c
      *p = 200;
      ```

  - check if NULL pointer before using it

<br/>

### 3.6 Dynamic Allocation of Memory

- classic code

  - ```c
    int *p;
    p = (int *)malloc(sizeof(int));
    *p = 1000;
    free(p);
    ```

  - cast the malloced pointer since `void *` gets returned from malloc()

  - check if p is NULL

- pointers and struct

  - `(*ps).i` < `ps->i`

<br/>

<br/>

## Stack

### 4.1 What is Stack

- System Stack

  - Activation Record created per function call
    1. return address
    2. program counter
    3. function parameters
    4. local variables in the function

- Stack ADT

  - ```reStructuredText
    Object: finite linear list containing at least 1 element
    Operations:
    	create(size) ::= create stack with size size
    	is_full(s) ::=
    		if (stack_elem == SIZE) return TRUE;
    		else return FALSE;
    	is_empty(s) ::=
    		if (stack_elem == 0) return TRUE;
    		else return FALSE;
    	push(s, item) :==
    		if (is_full(s)) return ERROR_STACKFULL;
    		else add item to the top of the stack.
    	pop(s) :==
    		if (is_empty(s)) return ERROR_STACKEMPTY;
    		else delete stack top and return it.
    	peek(s) :==
    		if (is_empty(s)) return ERROR_STACKEMPTY;
    		else return stack top.
    ```

<br/>

### 4.2 Stack Implementation

- ```c
  typedef int element;
  typedef struct {
      element data[MAX_SIZE];
      int top;
  } StackType;

  void init_stack(StackType *s) {
      s->top = -1;
  }
  ```

- create code for

  - is_empty
  - is_full
  - push
  - pop
  - peek

- ```c
  int main(void) {
      // Dynamic memory allocation
      StackType *s = (StackType*)malloc(sizeof(StackType));

      // Static memory allocation
      StackType t;

      free(s);
      return 0;
  }
  ```

<br/>
