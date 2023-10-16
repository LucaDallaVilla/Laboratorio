#include <stdio.h>

int main() {
    int n;
    int count = 1;

    printf("Fino a che numero? ");
    scanf("%d", &n);
    
    for (int i=1; i<=n; i++) {
        for (int j=0; j<i; j++) {
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }

    return 0;
}