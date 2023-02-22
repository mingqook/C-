#include <stdio.h>
#include <stdlib.h>

int getSum() {
    int sum=0;

        for (int i =1; i<=5; i++) {
            int n;
            scanf("%d", &n);
            if (n < 0) {
                printf("INPUT ERROR\n");
                exit(0);
            }
            sum += n;
        }
}

int main() {

    printf("гу : %d\n", getSum());
    
}