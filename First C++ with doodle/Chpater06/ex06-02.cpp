#include <stdio.h>

int itemCnt = 0;
int money = 100;

void buyIem() {
    itemCnt++;
    money -= 10;

    printf("�������� �����߽��ϴ�.\n");
    printf("    ������ ���� : %d\n", itemCnt);
    printf("    �ܾ�: %d\n", money);
}

int main() {

    buyIem();

    buyIem();


}