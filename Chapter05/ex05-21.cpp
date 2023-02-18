#include <stdio.h>

int main() {
    int a=10;
    int b=20;
    int *ptr = &a;
    printf("ptr가 가리키는 변수의 값 =  %d\n", *ptr);
    
    ptr = &b;
    printf("ptr가 가리키는 변수의 값 =  %d\n", *ptr);
}