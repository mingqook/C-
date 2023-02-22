#include <stdio.h>
#include <string.h>

int main() {

    char sa[10];
    int a;

    printf("정수 입력 : ");
    scanf("%d", &a);

    sprintf(sa, "%d", &a);

    int len = strlen(sa);
    printf("%d은(는) %d 자리 수입니다.", a, len);
    
}