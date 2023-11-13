#include <stdio.h>
#include <stdbool.h>
#define NMAX 50

int leggi_sequenza(int* seq);
bool trova_sottosequenza(const int* seq, const int length, const int* subseq, const int sub_length, const int max_err, int* range, int* err);

int main() {
    int subseq[NMAX];
    int sub_length = leggi_sequenza(subseq);
    int length = sub_length;
    int max_err;
    int errori = 0;
    scanf("%d", &max_err);

    bool run = true;
    while (run) {
        int seq[NMAX];
        int range[2];
        length = leggi_sequenza(seq);
        if (length == 0) {
            run = false;
        } else {
            if (trova_sottosequenza(seq, length, subseq, sub_length, max_err, range, &errori)) {
                printf("[%d, %d) errori=%d\n", range[0], range[1], errori);
            }
            else {
                printf("NO\n");
            }
        }
    }

    return 0;
}


int leggi_sequenza(int* seq) {
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        scanf("%d", &seq[i]);
    }

    return n;
}


bool trova_sottosequenza(const int* seq, const int length, const int* subseq, const int sub_length, const int max_err, int* range, int* err) {
    bool found = false;
    // fino a length-sub_length+1 perché è l'ultimo elemento
    // dalla quale la sottosequenza non esce più dai limiti della sequenza
    for (int i=0; i<length-sub_length+1 && !found; i++) {
        range[0] = i;
        for (int j=0; j<sub_length; j++) {
            if (subseq[j] != seq[i+j]) {
                *err += 1;
            }
        }
        // trovata una sequenza con un numero ristretto di errori
        if (*err <= max_err) {
            range[1] = i + sub_length;
            found = true;
        }
        else {
            *err = 0;
        }
    }

    return found;
}