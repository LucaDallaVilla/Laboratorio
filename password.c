#include <stdio.h>
#include <ctype.h>

int main() {
    char password[20];
    int P1 = 0;
    int P1_prec = 0;
    int P2 = 1;
    int P3 = 0;
    int P4 = 0;
    int P5 = 0;
    // printf("Inserire la password: ");
    scanf("%s", password);
    
    for (int i=0; i<20; i++) {
        if (isdigit(password[i])) {
            P1++;
            P1_prec = 1;
        } else {
            P1_prec = 0;
        }
        if (!isalpha(password[i])) {
            P2 = 0;
        } 
        if (password[i] == toupper(password[i])) {
            P3++;
        }
        if (P1_prec && isdigit(password[i])) {
            P4++;
        }
    }
    if (ispunct(password[19]) && ispunct(password[20])) {
        P5 = 1;
    }
    
    printf("%s %d %d %d %d %d", password, P1>0, P2, P3>=2, P4>0, P5);
}