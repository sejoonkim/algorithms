# Data Structures with C

Table of Contents

1. Data Structures and Algorithms

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
