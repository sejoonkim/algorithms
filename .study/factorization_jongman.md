## Code

```c++
// return int vector for result of N's factorization
vector<int> factor(int n) {
	if (n == 1) return vector<int>(1, 1); // exception: when n = 1
    vector<int> ret;
    for (int div = 2; n > 1; div++) 
        while (n % div == 0) {
            n /= div;
            ret.push_back(div);
        }
    return ret;
}
```

<br/>

## Time complexity

- when N is a prime number, takes longest time
- **Question:** Whether inputs can be scaled?
  - binarySearch, movingAverage - scaled
  - factorization - cannot be scaled, rather exponential growth