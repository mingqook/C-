#include <stdio.h>

int itemCnt = 0;
int money = 100;

void buyIem(int cost, int cnt) {
    itemCnt += cnt;
    money -= cost;

    printf("�������� �����߽��ϴ�.\n");
    printf("    ������ ���� : %d\n", itemCnt);
    printf("    �ܾ�: %d\n", money);
}

int main() {

    buyIem(30, 5);

    buyIem(50, 7);


}