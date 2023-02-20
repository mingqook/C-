#include <stdio.h>

struct ProductInfo
{
    int num;
    char name[101];
    int cost;
};

void productSwap(ProductInfo *a, ProductInfo *b) {
    ProductInfo tmp = *a;
    *a = *b;
    *b = tmp;

}

int main() {

    ProductInfo myProduct = {4797283, "���� �Ѷ��", 19900};
    ProductInfo yourProduct = {4797284, "���� ������", 1000};
    productSwap(&myProduct, &yourProduct);

    printf("��ǰ ��ȣ : %d\n", myProduct.num);
    printf("��ǰ �̸� : %s\n", myProduct.name);
    printf("��ǰ ���� : %d��\n", myProduct.cost);

}