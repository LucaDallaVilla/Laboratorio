#include <stdio.h>
#define MAX_N 20

int leggi_array(int[]);
int conta_univoci(int array[], int length);
void stampa_elementi_ripetuti(int array1[], int array2[], int length1, int length2);


int main() {
    int array1[20];
    int array2[20];

    int length1 = leggi_array(array1);
    int length2 = leggi_array(array2);

    int univoci1 = conta_univoci(array1, length1);
    int univoci2 = conta_univoci(array2, length2);

    printf("%d %d\n", univoci1, univoci2);
    stampa_elementi_ripetuti(array1, array2, length1, length2);

    return 0;
}

int leggi_array(int array[]) {
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        scanf("%d", &array[i]);
    }

    return N;
}

int conta_univoci(int array[], int length) {
    int counter = 0;
    int univoco = 1;

    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++) {
            if (array[i] == array[j] && i != j) {
                univoco = 0;
            }
        }
        if (univoco == 1) {
            counter++;
        }
        univoco = 1;
    }

    return counter;
}

void stampa_elementi_ripetuti(int array1[], int array2[], int length1, int length2) {
    for (int i=0; i<length1; i++) {
        for (int j=0; j<length2; j++) {
            if (array1[i] == array2[j]) {
                printf("%d ", array1[i]);
                // una volta trovato l'elemento nell'array2
                // si deve uscire dal secondo ciclo
                j = length2;
            }
        }
    }
    puts("");
}