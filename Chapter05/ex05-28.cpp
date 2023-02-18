#include <stdio.h>

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    
    for (int *ptr = arr; ptr < arr + 10; ptr++) {
        printf("%d\n", *ptr);
    }
}