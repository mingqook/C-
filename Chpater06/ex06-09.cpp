#include <stdio.h>

int itemCnt = 0;
int money = 100;

int buyIem(int cost) {

    if (money < cost) {
        return -1;
    }

    itemCnt++;
    money -= cost;

    printf("�������� �����߽��ϴ�.\n");
    printf("    ������ ���� : %d\n", itemCnt);
    printf("    �ܾ�: %d\n", money);
    return 0;
}

int main() {

    buyIem(50);
    int result = buyIem(70);

    if (result == -1) {
        printf("�ܾ��� �����մϴ�! \n");
        printf("    ������ ���� : %d\n", itemCnt);
        printf("    �ܾ�: %d\n", money);
    }

}