#include <stdio.h>

int swap(int *x1, int *x2) {
    int temp = *x1;
    *x1 = *x2;
    *x2 = temp;
    return 0;
}


int main(void) {
    // Leggi i dati dallo standard input usando scanf
    int x1, x2, x3, x4;
    scanf("%d%d%d%d", &x1, &x2, &x3, &x4);
    
   for (int i=0; i<3; i++) {
        if (x1 >= x2) {
            swap(&x1, &x2);
        }
        if (x2 >= x3) {
            swap(&x2, &x3);
        }
        if (x3 >= x4) {
            swap(&x3, &x4);
        }
    }
    
    printf("%d %d %d %d\n", x1, x2, x3, x4);
    return 0;
}