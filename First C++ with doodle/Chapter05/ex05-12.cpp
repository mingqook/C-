#include <stdio.h>
#include <string.h>

int main() {
    char s[1000] = "hello";
    int len = strlen(s);

    printf("�迭�� ĭ�� : %d\n", sizeof(s) / sizeof(s[0]));
    printf("���ڿ��� ���� : %d\n", len);

}