#include <stdio.h>

void swap(int *px, int *py) {
    int tmp = *px;
    *px = *py;
    *py = tmp;
}

int main() {
    int a, b;

    scanf("%d%d", &a, &b);

    swap(&a, &b);

    printf("a=%d, b=%d\n", a, b);
}