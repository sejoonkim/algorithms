# Data Structures with C

Table of Contents

1. Data Structures and Algorithms
2. Recursion
3. Array, Struct, Pointer
4. Stack
5. Queue

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

### 4.3 Dynamic Array Stack

- create StackType statically

- the actual stack array works dynamically

- ```c
  void init_stack(StackType *s) {
      s->top = -1;
      s->capacity = 1;
      s->data = (element *)malloc(s->capacity * sizeof(element));
      if (s->data == NULL){
          fprintf(stderr, "No more memory");
          exit(1);
      }
  }

  void push(StackType *s, element item) {
      if (is_full(s)) {
          s->capacity *= 2;
          s->data = (element *)realloc(s->data, s->capacity * sizeof(element));
          if (s->data == NULL) {
              fprintf(stderr, "No more memory");
              exit(1);
          }
      }
      s->data[++(s->top)] = item;
  }
  ```

- the size of the stack array is being reallocated doubly

<br/>

### 4.4 Q: Check Parenthesis

- ```c
  for (i = 0; i < n; i++) {
          ch = in[i];
          switch (ch) {
              case '(': case '[': case '{':
                  push(&s, ch);
                  break;
              case ')': case ']': case '}':
                  open_ch = pop(&s);
                  if (open_ch == '(' && ch != ')' || open_ch == '[' && ch != ']' || open_ch == '{' && ch != '}')
                      return 0; // failed
                  break;
          }
      }
      if (!is_empty(&s)) return 0; // remain in stack: failure
      return 1;
  ```

- failure condition

  1. char pairs do not match
  2. stack is not empty

<br/>

### 4.5 Pre, In, Post fix Operation

- why computer prefer postfix?

  - no need for parentheses
  - no need to manipulate Order of Operations
    - already in the order
  - fast computation time
    - compute while reading the sentence
      - since no parentheses

- saving int type to char type array

  - ```c
    #include <stdio.h>
    #include <stdlib.h>

    void toCharArray(char arr[], char integer, int index) {
        arr[index] = integer;
    }

    int main(void) {
        char arr[4] = "1900";
        int number_one = arr[0] - '0';
        printf("%c\n", arr[0]);
        printf("%d\n", arr[0]);
        toCharArray(arr, number_one, 0);
        printf("%c\n", arr[0]);
        printf("%d\n", arr[0]);

        printf("-------------\n");

        int number_nine = arr[1] - '0';
        printf("%c\n", arr[1]);
        printf("%d\n", arr[1]);
        toCharArray(arr, number_nine, 1);
        printf("%c\n", arr[1]);
        printf("%d\n", arr[1]);

        printf("-------------\n");

        int number_ten = 10;
        printf("%c\n", arr[2]);
        printf("%d\n", arr[2]);
        toCharArray(arr, number_ten, 2);
        printf("%c\n", arr[2]);
        printf("%d\n", arr[2]);

        printf("-------------\n");

        int large_num = 130;
        printf("%c\n", arr[3]);
        printf("%d\n", arr[3]);
        toCharArray(arr, large_num, 3);
        printf("%c\n", arr[3]);
        printf("%d\n", arr[3]);
        return 0;
    }
    /*
    1
    49
    ?
    1
    -------------
    9
    57

    9
    -------------
    0
    48


    10
    -------------
    0
    48
    ?
    -126
    */
    ```

  - if the numbers that are dealt with is in range 0 ~ 9

    - and trying to output with %d
      - it is possible to do arithmetic operations with int variables and save the result to char array
      - -128 ~ 127 = char array range

- Multi-Digit infix, postfix calculator

  - the magic of `int` and `char`, feat. **casting**
  - placed `whitespaces` when infix -> postfix for multi digit support

<br/>

### 4.6 Maze

1. Initialize the stack, exit location, start location
2. if the location is not yet visited, visit
3. up, down, left, right check availability
4. check if empty stack = no where available to move => failure
5. if not empty stack -> change here -> continue move

<br/>

<br/>

## 5. Queue

### 5.2 Linear Queue

<br/>

### 5.3 Circular Queue

- update `front` and `rear` values to 0 when at the end of the queue
  - initialize them to `0` not `-1`
  - increment `rear` and insert value
  - increment `front` and insert value
  - to distinguish **full** and **empty**
    - if `front` == `rear` -> empty
- without `count` the max number of elements = `MAX NUM - 1`

<br/>

### 5.4 Application: Buffer

- `srand(x)`

  - set the starting value **(seed)** used by function `rand()`

  - `srand(time(NULL));`

    - using computer's internal clock to control the choice of the seed

    ```c
    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        if (rand() % 5 == 0)
            enqueue(&queue, rand() % 100);
        print_queue(&queue);
    }
    ```

<br/>

### 5.5 Deque

- double-ended queue

- compared to Circular Queue

  - `delete_rear()`
  - `add_front()`
  - `get_rear()`

- when `front`, `rear` become **negative**

  - > front <- (front-1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    >
    > rear <- (rear-1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;

  - add `MAX_QUEUE_SIZE` when **negative**

<br/>

### 5.6 Simulation

- Pseudo Code
  1. increment `clock`
  2. create random number [0:10], if num < 3, consider new customer
  3. check if `service_time` = 0
  4. after 60 minutes, `printf` waited times

<br/>

<br/>

## Linked List 1

### 6.1 List ADT

- Object: datatype `element`, consisted of `n` number of elements that have order
- Operations
  - insert
    - at position
    - first
    - last
  - delete
    - at position
  - clear
  - get_entry
  - get_length
  - empty
  - full
  - print

<br/>

### 6.2 LL with Array

- sequential representation

- insert element to `pos`

  ```c
  for (int i = (L->size - 1); i >= pos; i--) {
      L->array[i + 1] = L->array[i];
  }
  // L->array[L->size] always points to the next element in array, which is empty
  ```

- Time Complexity

  - access arbitrary index
    - O(1)
  - insert or delete
    - Worst: 0(N)
    - Best: O(1)

<br/>

### 6.3 LL

- linked representation
- vs LL with Array
  - difficult to implement
  - takes more memory space
  - slow retrieval time
- singly linked list
  - last node ->next == NULL
- circular linked list
- doubly linked list

<br/>

### 6.4 Singly Linked List

- Node

  - self-referential structure

- Head pointer is Crucial

  - if head pointer points to `NULL` , then it is an empty list

- Using pointers to access struct members
  1. `(\*p).member
     - order of operation `* < .`
  2. p->member
     - `->` operator goes to the address saved in p, access struct's member

<br/>

### 6.5 Implement SLL

- `head pointer` points to the first element in list

- methods

  - `insert_first`
  - `insert`
  - `delete_first`
  - `delete`
  - `print_list`

- loop until the end of list

  ```c
  for(ListNode *p = head; p != NULL; p = p->link)
  ```

  - very similar to `list<int>::iterator iter`

#### LL with char datatype

- implement with struct containing char array

  ```c
  typedef struct {
  	char name[100];
  } element;
  ```

#### LL implement search_list

- loop using `for` or `while`

#### LL implement concat_list

```c
while (p->link != NULL) vs while (p != NULL)
```

- the **former** stops at the last node
- the **latter** stops **after** the last node

#### LL implement reverse

- use 3 `pointers`, always know the next element

  ```c
  ListNode* reverse(ListNode *head) {
      ListNode *p, *q, *r;

      p = head;
      q = NULL;
      while (p != NULL) {
          r = q; // r follows q,
          q = p; // q follows p
          p = p->link; // p will end up becoming NULL
          q->link = r; // connecting the link
      }
      return q;
  }
  ```

<br/>

### 6.6 Application: Polynomials

- addition
  - concept: use 2 `pointers`, traverse each polynomials
  - 3 cases
    - p.expon == q.expon
    - p.expon > q.expon
    - p.expon < q.expon
- using `header` node
  - size
  - pointer front
  - pointer back

<br/>

<br/>

## Linked List 2

### 7.1 Circular Linked List

- Basic Concept

  - last node points first node
  - **traverse** the whole list, starting from any node
  - **insert/delete** always needs `*prev`

- `head` points to the last element
- `head->link` points to the first element

- insert_first
- insert_last

<br/>

### 7.2 Applications for Circular LL

1. Queuing processes for CPU
2. Multiplayer Game
3. Making Circular Queue
   1. needs 2 pointers `front` & `rear`

<br/>

### 7.3 Doubly Linked List

- Basic Concept

  - 1 node had `prev` `next` links
  - takes up more space
  - DLL + CLL
  - `head node`
    - When empty
    - p = p->llink->rlink = p->rlink->llink

- insert

  1. link new node
  2. link prev
  3. link next

- delete

- no need for head pointers
  - important = init()

<br/>

### 7.4 Mp3 Player

- `header node` = node with no data, just links

<br/>

### 7.5 LL Stack

- linked stack
- insert at the top
- delete at the top

<br/>

### 7.6 LL Queue

- linked queue
- SLL + 2 pointers `front` `back`
- insert_back
- delete_front

<br/>

<br/>

## Tree

### 8.1 What is Tree?

- Used when data has `hierarchical structure`
- structure

  - root
    - subtree
  - all composed of nodes and `edges`
  - parent node
    - children node
  - node's perspective
    - ancestor node
    - descendent node
  - terminal node / nonterminal node
  - `degree`
    - '#' of children nodes
    - terminal nodes have degree of `0`
  - `level`
    - root = `level 1`
    - level++
  - `height`
    - highest `level`

- binary tree
  - if more than 2 degrees in a node
    - more complexity

<br/>

### 8.2 Binary Tree

- `Definition`
  1. empty tree
  2. root
     - left subtree(binary tree)
     - right subtree(binary tree)
- compared with normal tree

  1. every node's degree <= 2
  2. empty node ok
  3. each subtree is distinguished

- `Properties`

  1. n node binary tree

     - has `n-1` edges
     - why? every node has `1` parent node, 1 `edge` in between

  2. height `h` binary tree
     - at least `h` nodes
     - at largest `2^h - 1` nodes
     - at least `1`node in a `level`
  3. `n` node binary tree
     - at least upper(`log2(n+1)`) high
     - at largest `n` high

- `Categories`
  1. full binary tree
     - max nodes at each `level`
     - height `k` tree has `2^k - 1` nodes
     - numbering
       - from the left node
  2. complete binary tree
     - from `level` 1 ~ k-1 = full nodes
     - at `level k` nodes filled from the `left`
       - no `empty` nodes in the middle
  3. other trees

<br/>

### 8.3 Handling Binary Tree

- Array
  - index 0 is `not` used
  - size gets increased per 2^(k-1)
  - index of node `i`
    - `i / 2` = parent index of node `i`
    - `2i` = left child node index
    - `2i + 1` = right child node index
- Linked Lists
  - struct
    - left, right `pointer`
    - data

<br/>

### 8.4 Traversing Binary Tree

- preorder, inorder, postorder traversal
- When visit Root?
  - VLR, LVR, LRV
- algorithm = `recursion`
  - why? = same substructure, size of problem decrease
- `preorder`
  - process
    1. visit root
    2. go left subtree
    3. go right subtree
- `inorder`
  - process
    1. go left subtree
    2. visit root
    3. go right subtree
- `postorder`
  - process
    1. go to left subtree
    2. go to right subtree
    3. visit root

<br/>

### 8.5 Traverse with Loop

- require `stack`

- left child nodes get added to`stack` until `NULL`
- gets deleted after meeting `NULL`
- then check `right` child node
- add left child nodes to `stack`

<br/>

### 8.6 Level Order Traversal

- queue
- process

  1. dequeue and visit
  2. enqueue child nodes
  3. loop until queue empty
     1. pop
     2. print
     3. push
     4. push

- which traversal method to choose?
  - order to operate
    - child nodes first? `postorder`
    - parent nodes first? `preorder`

<br/>

### 8.7 Application: Expression Tree

- preorder, inorder, postorder traversal

  - prefix, infix, postfix expressions

- considering expression tree

  - operator

    - operand
    - operand

  - traverse child nodes first and visit root = `postorder` traversal

<br/>

### 8.8 Application: Directory Size

- postorder traversal
  - recursion algorithm returns size

<br/>

### 8.9 Methods in Binary Tree

1. `get_node_count(x)`
   - if root is not NULL, return 1 + get_noed_count(x.left) + get_node_count(x.right)
2. `get_leaf_count(x)`

   - if root is not NULL, if root->left and root->right are NULL return 1
   - else return get_leaf_count(x.left) + get_leaf_count(x.right)

3. `get_height(x)`
   - get max from left and right subtree + 1(for self)

<br/>

### 8.10 Threaded Binary Tree

- Motivation
  - recursion creates function overhead in stack
  - implement traversing in BT w/o stack and recursion
- Using `NULL` links
  - `n - 1` links point other nodes
  - `n + 1` links are NULL
  - total `2n` links are present
- Definition

  - While `inorder`traversing, inside `NULL` links, inorder predecessor and inorder successor are set

- Implementation

  1. require `tag` to distinguish terminal or nonterminal nodes

  2. `find_successor()`check for successor

<br/>

### 8.11 Binary Search Tree

- search

  - table
    - records(key)
      - many fields

- `Definition`

  - `primary key` for any record
  - root > left subtree
  - root < right subtree

- `search(root, key)`

  - check `key` value with root
    - if same: found
    - if smaller: search(root->left, key)
    - if larger: search(root->right, key)
  - `recursion`
    - return NULL when after reaching the terminal node
  - `loop`
    - return NULL when search is failed

- `insert()`

  - `search()`
    - failed location is the place to insert
  - return modified root pointer

- `delete()`

  - `search()`

  1. if node == terminal node
     1. delete the terminal node
        - parent's link to `NULL`
        - free(terminal)
  2. if node has 1 child
     1. delete self
     2. move the child up
  3. if node has 2 children = which node `to bring up to` delete node's location
     1. get the next minimum value
     2. save it to the root node
     3. delete the minimum node

- analysis

  - `O(h)`
    - search, insert, delete
  - so n nodes -> `O(log2h)`
  - if not balanced -> O(n) like linear DS
    - keep BT balanced -> AVL trees etc

<br/>

### 8.12 Application: Eng Dictionary

- operations

  - insert
  - delete
  - search
  - print
  - quit

- `compare`
  - `strcmp`
    - return -1 when 1 < 2
    - return 0 when 1 == 2
    - return 1 when 1 > 2

<br/>

<br/>

## Priority Queue

### 9.1 Priority Queue ADT

- use `heap` to implement priority queue
- ADT
  - grouping of `n` number of `element` datatyped prioritized elements
  - operations: create, init, is_empty, is_full, insert, delete, find

<br/>

### 9.2 Implementation

- sorting or not sorting
- `heap` = `log(n)` for insertion and deletion
- heap is a complete binary tree

<br/>

### 9.3 Heap

- Definition
  - parent's key value >= children's key value
- cf) binary tree
  - allows `repetitive` values in `heap tree`, not allowed in `binary tree`
- different kinds
  1. `max heap`
  2. `min heap`
- implementation
  - array
    - not use `index 0`
    - 2n, 2n + 1

<br/>

### 9.4 Implementing Heap

1. definition

   - define `element`
   - define `tree`

2. insertion

   - insert at the `last` index
   - compare `key` with parent, switch if bigger
   - process
     - drag down the parent node
     - update the `index`
     - at `index` insert `item`

3. deletion
   1. remove the first element
   2. put last element to first element
   3. swap with the largest children

- analysis
  - `log(n)` = insertion, deletion = the number of height

<br/>

### 9.5 Heap Sort

- analysis
  - `height` = `logN` (complete binary tree)
  - inserting or deleting a single element requires `logN`
  - better than insertion sort = O(n^2)
  - useful when
    - needing several `Max` elements

<br/>

### 9.6 Machine Scheduling

- Target
  - run machine full capacity
  - finish `at least` time
- `LPT` (Longest Processing Time first)

  - ending task time is important

- Purpose
  - need to get the available machines , maintaining the array

<br/>

### 9.7 Huffman Coding

- Definition
  - frequency tree of letters
- Introduction
  - acquiring the least length encoding bitfields
  - compressing data -> `DO NOT` use ASCII
  - dynamic length code, assign high frequency with lesser bit length, low frequency with bigger bit length
- Problem to Solve when `text is given`
  1. How to dynamically generate bitcodes
  2. how to decompress the text and restore
- Concept
  - to decompress,
    - any code must not be **the first part** of other codes
  - `Huffman codes` hold the above concept
- Process of making `Huffman codes`
  1. list ascending, pick two of the smallest to create as terminal nodes to create binary tree
  2. root = child + child
  3. add the added root to the list, pick two smallest to create as terminal nodes
  4. add the added root to the list, pick two smallest to create as terminal nodes...finish making tree
  5. left edge = 1, right edge = 0
  6. reading the label to each node = Huffman code
- `pick two smallest` = `Min Heap tree` is used

<br/>

<br/>

## Graph I

### 10.1 What is graph?

- Definition

  - DS that represents relation between nodes

  - logical tool ex) map(cities), subway(stations), circuit(resistance)

  - Graph

    - Tree, a special kind of graph

  - Eulerian tour

    - while visiting all edges, returning to the start node

    - possible only when all nodes have `even` number of edges

<br/>

### 10.2 Graph Syntax

- Definition
  - finite set of vertices and edges
  - G = (V, E)
- Categories

  - undirected graph
    - (0, 1)
    - total degrees = 2 \* edges
    - connected graph
      - there exists path to visit all nodes
    - unconnected graph
    - complete graph
      - all nodes are connected with edge
      - edges = nodes \* (nodes - 1) / 2
  - directed graph
    - <0, 1>
  - network = weighted graph
    - edges having `weights`
  - subgraph
  - path
    - cycle, repeating edges
    - simple path

- Graph ADT
  - create_graph, init
  - insert_vertex, insert_edge
  - delete_vertex, delete_edge
  - is_empty
  - adjacent
  - destroy_graph

<br/>

### 10.3 Representing Graph

1. adjacency matrix

   - 2-D array

   - if undirected graph = `symmetric`
   - excels at `dense` graph, poor at `sparse` graph = size-wise
   - TC
     - O(1) - edges exist
     - O(n) - degree of node
     - O(n^2) - total edges

2. adjacency list

   - excels at `sparse` graph
   - O(n + e) = total edges

<br/>

### 10.4 Traverse Graph

### 10.5 DFS

- Implementation
  - recursion, adjacency matrix
  - recursion, adjacency list
  - stack
- Analysis
  - O(n + e) = adj list
  - O(n^2) = adj matrix

<br/>

### 10.6 BFS

- Implementation
  - queue
  - d-> d + 1 -> ...
  - adjacency matrix, queue
  - adjacency list, queue
- analysis
  - O(n + e) = adj list
  - O(n^2) = adj matrix

<br/>

<br/>

## Graph II

### 11.1 Minimum Cost Spanning Tree

- Definition
  - included all vertices of Graph G
  - total number of edges = `n - 1`
  - no cycle
  - cost = `minimum` cost of adding edges

<br/>

### 11.2 Kruskal MST

- use `greedy` algorithm
  - combine locally optimized solutions
  - need to `validate` if globally optimized
- check `cycle`
- process
  1. order by ascending
  2. choose minimum cost
  3. check `cycle`, if not -> add to set
- Checking `cycle` -> `Union-find`

  - Introduction
    - `Union(x,y)`: join x, y sets
    - `Find(x)`: returns the set that x is located in
  - Process
    1. get single element sets
    2. union(a, b): combining sets a, b
  - Implementation
    - `tree`
    - parent pointer expression
      - use 1-D array, for each single set elements, set parent `index`
      - if no parent -> `-1`
      - root node = `-1`

- analysis
  - eloge
