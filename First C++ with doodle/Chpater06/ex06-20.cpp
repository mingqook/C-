#include <stdio.h>

void printArr(int parr[4]) {
    printf("parr�� �� : %d\n", parr);
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    printf("arr�� �� : %d\n", arr);
    printArr(arr);

}