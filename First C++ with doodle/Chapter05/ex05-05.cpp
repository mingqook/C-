#include <stdio.h>

int main() {
    int n;
    int arr[1000];

    printf("�Է��� ������ ���� : ");
    scanf("%d", &n);
    printf("���� %d���� �Է��ϼ��� : ", n);
    for (int i=0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max=arr[0];
    for (int i =1 ; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    printf("�ִ밪 : %d", max);
}