#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    for (int i=1; i <=5; i++)
        printf("%d\n", rand() % 10 + 1);
    
}