#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    int ret = 1;
    if (n <= 1) {
        ret = -1;
    } else {
        for (int i=2; i<sqrt(n); i++) {
            if (n%i == 0) {
                ret = 0;
            }
        }
    }

    return ret;
}

int main() {
    for (int n=0; n<=100; n++) {
        if (isPrime(n) == 1) {
            printf("%d\n", n);
        }
    }
    return 0;
}