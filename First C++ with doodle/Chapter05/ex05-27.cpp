#include <stdio.h>

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *ptr = &arr[0];

    printf("&arr[3]�� �� : %d \n", &arr[3]);
    printf("arr+3�� �� : %d \n", arr+3);
    printf("ptr+3�� �� : %d \n", ptr+3);
    printf("&ptr[3]�� �� : %d \n", &ptr[3]);

    printf("arr[3]�� �� : %d \n", arr[3]);
    printf("*(arr+3)�� �� : %d \n", *(arr+3));
    printf("*(ptr+3)�� �� : %d \n", *(ptr+3));
    printf("ptr[3]�� �� : %d \n", ptr[3]);
}