#include <stdio.h>

int main() {
    int n;

    printf("자연수 입력 : ");
    scanf("%d", &n);

    for (; n>=1; n--){
        printf("%d ", n);
    }

}