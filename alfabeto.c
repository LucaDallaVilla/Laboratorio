#include <stdio.h>

int main() {
    char alphabet[28];

    for (int i=65; i<=90; i++) {
        alphabet[i-65] = i;
    }

    alphabet[28] = 0;

    for (int i=0; i<28; i++) {
        printf("%c ", alphabet[i]);
    }

    puts("");
}