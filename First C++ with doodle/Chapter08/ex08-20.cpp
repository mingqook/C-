#include <stdio.h>
#include <string.h>

int main() {

    char sa[10];
    int a;

    printf("���� �Է� : ");
    scanf("%d", &a);

    sprintf(sa, "%d", &a);

    int len = strlen(sa);
    printf("%d��(��) %d �ڸ� ���Դϴ�.", a, len);
    
}