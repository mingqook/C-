#include <stdio.h>

void rec() {
    printf("rec() ȣ��� \n");
    rec();
}

int main() {
    rec();
}