#include <stdio.h>

struct ProductInfo
{
    int num;
    char name[100];
    int cost;
};


int main() {

    ProductInfo myProduct = {4797283, "���� �Ѷ��", 19900};

    printf("��ǰ ��ȣ : %d\n", myProduct.num);
    printf("��ǰ �̸� : %s\n", myProduct.name);
    printf("��ǰ ���� : %d��\n", myProduct.cost);

}