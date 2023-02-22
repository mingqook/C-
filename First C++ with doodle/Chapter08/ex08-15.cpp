#include <stdio.h>


int main() {

    FILE *in;
    in = fopen("intput.txt", "r");

    char ch;
    while (fscanf(in, "%c", &ch) != EOF) {
        printf("%c", ch);
    }
    

}