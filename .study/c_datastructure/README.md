# Data Structures with C

Table of Contents

1. Data Structures and Algorithms

<br/>

## Data Structures and Algorithms

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
