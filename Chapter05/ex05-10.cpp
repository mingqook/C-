#include <stdio.h>

int main() {
    char s[] = "mingukkim";

    printf("%c\n", s[0]);
    s[0] = 'M';
    s[3] = 'N';
    printf("%s\n", s);
}