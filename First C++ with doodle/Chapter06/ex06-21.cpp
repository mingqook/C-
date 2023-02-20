#include <stdio.h>

void printArr(int parr[4]) {
    for (int i=0; i<4; i++) {
        parr[i]++;
    }
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    printArr(arr);
    for (int i =0; i<4; i++) {
        printf("%d ", arr[i]);
    }

}