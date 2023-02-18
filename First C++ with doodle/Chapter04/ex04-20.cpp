#include <stdio.h>

int main() {

    for (int i = 1; ; i++) {
        int k;
        scanf("%d", &k);
        if (k ==0) {
            break;
        }
        printf("%d번째 입력 결과 : %d\n", i, k);
    }

}