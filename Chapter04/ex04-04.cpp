#include <stdio.h>

int main() {
    int n;

    printf("숫자 입력 : ");
    scanf("%d", &n);

    if (n > 0) {
        printf("n은 양수입니다.\n");
    }
    else if (n == 0){
        printf("n은 0입니다.\n");
    }
    else {
        printf("n은 음수입니다.\n");
    }
}