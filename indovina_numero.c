#include <stdio.h>

int tentativo(int t) {
    int n = 99;
    if (t < n) {
        return 0;
    }
    else if (t > n) {
        return 1;
    }
    else {
        printf("Hai vinto\n");
        return 100;
    }
}

int main(void) {
    // Fai un tentativo con un numero t
    int t = 50;
    int delta = t/2;
    
    for (int i=0; i<7; i++) {
        if (tentativo(t)) { // t é > del numero da indovinare
            t -= delta;
        }
        else { // t é < del numero da indovinare
            t += delta;
        }
        delta = (delta + 1) / 2;
        printf("Test: %d\n", t);
        printf("Delta: %d\n", delta);
    }
    return 0;
}