#include <stdio.h>

int itemCnt = 0;
int money = 100;

void buyIem(int cost) {
    itemCnt++;
    money -= cost;

    printf("�������� �����߽��ϴ�.\n");
    printf("    ������ ���� : %d\n", itemCnt);
    printf("    �ܾ�: %d\n", money);
}

int main() {

    buyIem(50);

    buyIem(70);


}