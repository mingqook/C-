#include <stdio.h>

int main() {
    int a = 5;
    int b;

    b = ++a;
    printf("=== ��ġ ���� ���� === \n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    b = a++;
    printf("=== ��ġ ���� ���� === \n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}