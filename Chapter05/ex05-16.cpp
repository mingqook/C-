#include <stdio.h>
#include <string.h>

int main() {
    char s1[] = "sample";
    char s2[] = "sample";

    if (strcmp(s1, s2) < 0) {
        printf("%s는 %s보다 사전 순으로 빠릅니다.\n", s1, s2);
    }
    else if (strcmp(s1, s2) == 0) {
        printf("%s는 %s와 일치합니다..\n", s1, s2);
    }
    else {
        printf("%s는 %s보다 사전 순으로 늦습니다.\n", s1, s2);
    }
}