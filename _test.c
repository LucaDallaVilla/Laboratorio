#include <stdio.h>
#include <string.h>

int main() {
    char stringa[3][10] = {"test", "ciao", "dioporco"};
    printf("%ld", strlen(stringa[0]));
}