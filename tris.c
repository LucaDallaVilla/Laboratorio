#include <stdio.h>
#include <stdbool.h>
#define DIM 3


void leggi_griglia(char mat[DIM][DIM]);
char verifica_vittoria(char mat[DIM][DIM]);

int main() {
    char mat[DIM][DIM];
    leggi_griglia(mat);
    char vincitore = verifica_vittoria(mat);
    printf("%c\n", vincitore);
}

void leggi_griglia(char mat[DIM][DIM]) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            scanf(" %c", &mat[i][j]);
            // printf("%c \n", mat[i][j]);
        }
    }
}

char verifica_vittoria(char mat[DIM][DIM]) {
    char vincitore = '-';
    bool verticale = true;
    bool orizzontale = true;
    bool diagonale1 = true;
    bool diagonale2 = true;

    // check ORIZZONTALE
    bool seek = true;
    for (int i=0; i<DIM && seek; i++) {
        for (int j=1; j<DIM; j++) {
            if (mat[i][j] != mat[i][0]) {
                orizzontale = false;
            }
        }
        if (orizzontale) {
            vincitore = mat[i][0];
            seek = false;
        } else {
            orizzontale = true;
        }
    }

    // check VERTICALE
    seek = true;
    for (int i=0; i<DIM && seek; i++) {
        for (int j=1; j<DIM; j++) {
            if (mat[j][i] != mat[0][i]) {
                verticale = false;
            }
        }
        if (verticale) {
            vincitore = mat[0][i];
            seek = false;
        } else {
            verticale = true;
        }
    }

    // check DIAGONALE
    for (int i=1; i<DIM; i++) {
        if (mat[i][i] != mat[0][0]) {
            diagonale1 = false;
        }
        if (mat[DIM-i-1][i] != mat[2][0]) {
            diagonale2 = false;
        }
    }
    if (diagonale1 || diagonale2) {
        vincitore = mat[1][1];
    }

    return vincitore;
}