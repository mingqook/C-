#include <stdio.h>

int main() {
    int choice;

    printf("�� ���� : 1 \n");
    printf("�ҷ����� : 2 \n");
    printf("���� : 3 \n");
    printf("ũ���� : 4 \n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("�� ����.\n");
        case 2:
            printf("�ҷ�����.\n");
        case 3:
            printf("����.\n");
        case 4:
            printf("ũ����.\n");
        default:
            printf("�߸� �Է��ϼ̽��ϴ�. \n");
    }
}