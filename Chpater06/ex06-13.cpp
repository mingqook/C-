#include <stdio.h>

void walk(int distance) {
    printf("%dcm ������ �����߽��ϴ�.\n", distance);
}

void rotate(int angle) {
    printf("%d�� ȸ���߽��ϴ�.\n", angle);
}

void walkSquare() {
    for (int i = 1; i <=4; i++) {
        walk(10);
        rotate(90);
    }
}

int main() {
    walkSquare();
}