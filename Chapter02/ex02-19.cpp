#include <stdio.h>

int main() {
    int a = 3;

    bool p = a >=1 && a <=10;
    bool q = a==3 || a==7;
    bool r = !q;

    printf("%d\n", p);
    printf("%d\n", q);
    printf("%d\n", r);
}