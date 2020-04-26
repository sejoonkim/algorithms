/*
start - 10 : 25
  end - 11 : 20

- Q analysis
    - the paper rotates
    - 
1. get inputs for the notebook and the number of stickers
2. loop over k
    1. get the sticker input
    2. for the 4 rotations
        1. paste_flag = false
        2. loop over x, and loop over y
        3. check if pastable()
3. add all elements in note
3. pastable
    1. get input coordinates x and y
    2. return false if not pastable
    3. fill the note with sticker
    4. return true

4. rotate
    1. declare 2-D array temp
    2. copy paper to tmp
    3. swap r and c
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int note[42][42];
int r, c;
int sticker[12][12];

void rotate() {
    int temp[12][12];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            temp[i][j] = sticker[i][j];
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            sticker[i][j] = temp[r-1-j][i];
        }
    }

    swap(r, c);
}

bool pastable(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (note[x+i][y+j] == 1 && sticker[i][j] == 1){
                return false;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            note[x+i][y+j] = sticker[i][j];
        }
    }
    return true;
}



int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> k;

    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> sticker[i][j];
            }
        }
        for (int rot = 0; rot < 4; rot++) {
            bool paste_flag = false;
            for (int x = 0; x <= n-r; x++) {
                if (paste_flag) break;
                for (int y = 0; y <= m-c; y++) {
                    if (pastable(x, y)) {
                        paste_flag = true;
                        break;
                    }
                }
            }
            if (paste_flag) break;
            rotate();
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += note[i][j];
        }
    }

    cout << sum << '\n';
    return 0;
}