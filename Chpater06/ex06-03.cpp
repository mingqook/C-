#include <stdio.h>

int itemCnt = 0;
int money = 100;

void buyIem(int cost) {
    itemCnt++;
    money -= cost;

    printf("아이템을 구매했습니다.\n");
    printf("    아이템 개수 : %d\n", itemCnt);
    printf("    잔액: %d\n", money);
}

int main() {

    buyIem(30);

    buyIem(40);


}