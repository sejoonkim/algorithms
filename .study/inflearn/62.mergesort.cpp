#include <iostream>
using namespace std;
int dataArr[10], tmp[10];

void divide(int lt, int rt) {
    int mid;
    int p1, p2, p3;
    if (lt < rt) {
        mid = (lt + rt) / 2;
        divide(lt, mid);
        divide(mid + 1, rt);
        
        // merge after children finished!
        p1 = lt;
        p2 = mid;
        p3 = lt;
        while (p1 <= mid && p2 <= rt) {
            if (dataArr[p1] < dataArr[p2]) tmp[p3++] = dataArr[p1++];
            else tmp[p3++] = dataArr[p2++];
        }

        // if remaining values exist, fill them to tmp arr
        while (p1 <= mid) tmp[p3++] = dataArr[p1++];
        while (p2 <= rt) tmp[p3++] = dataArr[p2++];

        // copy tmp to dataArr
        for (int i = lt; i <= rt; i++) {
            dataArr[i] = tmp[i];
        }

    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, i;
    for (i = 1; i <= n; i++) {
        cin >> dataArr[i];
    }
    divide(1, n);
    for (i = 1; i <= n; i++) {
        cout << dataArr[i];
    }
    return 0;
}