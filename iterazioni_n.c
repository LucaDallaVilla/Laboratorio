#include <stdio.h>

int main() {
    int n;
    printf("Fino a che numero? ");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        printf("%d\n", i);
    }

    printf("\n");

    for (int i=n-1; i>0; i--) {
        printf("%d\n", i);
    }

    printf("\n");

    for (int i=1; i<n; i++) {
        if (i % 2 == 0) continue;
        printf("%d\n", i);
    }
}