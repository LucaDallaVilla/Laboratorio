#include <stdio.h>
#include <ctype.h>

int main() {
    char pwd[21];
    int length;

    int P1 = 0;
    int P2 = 0;
    int P3 = 0;
    int P4 = 0;
    int P5 = 0;

    // printf("Inserire la password: ");
    scanf("%s%n", pwd, &length);
    printf("LENGTH: %d\n", length);
    
    for (int i=0; i<length; i++) {
        char c = pwd[i];

        // P1:  esiste almeno un carattere che è una cifra;
        P1 += isdigit(c) ? 1 : 0;
        // P2:  tutti i caratteri sono lettere;
        P2 += isalpha(c) ? 1 : 0;
        // P3:  ci sono almeno due lettere maiuscole;
        P3 += isupper(c) ? 1 : 0;

        // P4:  ci sono almeno due cifre consecutive;
        if (i != 0) {
            if (isdigit(pwd[i]) && isdigit(pwd[i-1])) {
                P4++;
            }
        }
    }

    // P5: gli ultimi due caratteri sono segni di punteggiatura.
    if (ispunct(pwd[length-1]) && ispunct(pwd[length-2])) {
        P5++;
    }
    
    // puts("");
    // printf("VARIABLES: %d %d %d %d %d\n", P1, P2, P3, P4, P5);
    printf("'%s' %d %d %d %d %d\n", pwd, P1>0, P2==length, P3>=2, P4>0, P5>=1);
}