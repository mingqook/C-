#include <stdio.h>

int main() {
    int itemCnt = 0;
    int money = 100;

    itemCnt++;
    money -= 10;

    printf("�������� �����߽��ϴ�.\n");
    printf("    ������ ���� : %d\n", itemCnt);
    printf("    �ܾ�: %d\n", money);

    itemCnt++;
    money -= 10;

    printf("�������� �����߽��ϴ�.\n");
    printf("    ������ ���� : %d\n", itemCnt);
    printf("    �ܾ�: %d\n", money);


}