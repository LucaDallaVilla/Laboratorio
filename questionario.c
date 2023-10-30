#include <stdio.h>
#define MARKS 3
#define STARS 5

int main() {
    int rate[STARS];

    // lettura delle [MARKS] valutazioni
    for (int i=0; i<MARKS; i++) {
        int input;
        printf("Inserire votazioni: ");
        scanf("%d", &input);

        if (input >= 0 && input <= STARS) {
            rate[input]++;
        }
    }

    // calcolo delle frequenze
    int max = 1;
    for (int i=1; i<= STARS; i++) {
        if (rate[i] > rate[max]) {
            max = i;
        }
    }

    // rappresentazione frequenze
    printf("Stelle\tFrequenza\tLivello\n");
    for (int i=1; i<= STARS; i++) {
        printf("%d\t%d\t\t%0*d\n", i, rate[i], rate[i], i);
    }
    
    return 0;
}