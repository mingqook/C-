#include <stdio.h>

int main() {
    int a = 30;
    int b = 50;

    bool p = a > b;
    bool q = a < b;
    bool r = a == b;

    printf("%d는 %d보다 크다 : %d\n", a, b, p);
    printf("%d는 %d보다 작다 : %d\n", a, b, q);
    printf("%d는 %d과 같다 : %d\n", a, b, r);
}