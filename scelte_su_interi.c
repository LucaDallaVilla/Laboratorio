#include <stdio.h>

int main(void) {
    int m, n;
    
    //printf("Inserire m: ");
    //scanf("%d", &m);
    //printf("Inserire n: ");
    //scanf("%d", &n);
    scanf("%d %d", &n, &m);
    
    if ((n % 2) == 0 && n > m) {
        printf("C1\n");
    } else if ((n % 2) == 0 && n <= m) {
        printf("C2\n");
    } else if ((n % 2) == 1) {
        if (m % 2 == 1) {
            printf("C3\n");
        } else if (m > 2*n) {
            printf("C4\n");
        } else {
            printf("ALTRO\n");
        }
    }
}