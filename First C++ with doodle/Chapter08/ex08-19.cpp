#include <stdio.h>


int main() {

    char sa[] = "123";
    int a;

    sscanf(sa, "%d", &a);
    printf("%d", a);
    
}