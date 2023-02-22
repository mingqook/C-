#include <stdio.h>


int main() {

    int sum=0;

    for (int i =1; i<=5; i++) {
        int n;
        scanf("%d", &n);
        if (n < 0) {
            printf("INPUT ERROR\n");
            return 0;
        }
        sum += n;
    }

    printf("гу : %d\n", sum);
    
}