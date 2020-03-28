## Code

```c++
const int INF = 987654321;

// determine everyone can eat
bool canEverybodyEat(const vector<int>& menu);

// number of menus can cook
int M;

// decide whether to cook food-th menu
int selectMenu(vector<int>& menu, int food) {
    // end case: finished deciding on every menu
    if (food == M) {
        if (canEverybodyEat(menu)) return menu.size();
        
        // return if someone cannot eat
        return INF;
    }
    
    // not cooking this food
    int ret = selectMenu(menu, food+1);
    
    // cooking this food, select lower value
    menu.push_back(food);
    ret = min(ret, selectMenu(menu, food+1));
    
    menu.pop_back();
    return ret;
}
```

<br/>

## Links

- [꾸준함](https://jaimemin.tistory.com/414)
- [꾸준함-최적화](https://jaimemin.tistory.com/415)

- [int-num-bitmask-pruning](https://int-num.tistory.com/28)