#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

/*
{7, 3, 3},
{6, 6, 4, 8}};
*/

/* bool e1(const size_t rows, const size_t cols, const int mat[rows][cols],
        const size_t rags[], int* pMinSumProd) {
    int prodotto = 1;
    int somma = 0;
    int somma_min = INT_MAX;
    int conta_selex = 0;
    
    for (int i=0; i<rows; i++) {
        somma = 0;
        for (int j=0; j<rags[i]; j++) {
            if (mat[i][j] % 3 == 0) {
                prodotto = 1;
                for (int k=0; k<rows; k++) {
                    if (rags[k] > j) {
                        // printf("%d; ", mat[k][j]);
                        prodotto *= mat[k][j];
                    }
                }
                // puts("");
                somma += prodotto;
            }
        }
        if (somma > 0) {
            // printf("SOMMA: %d\n", somma);
            if (somma < somma_min) {
                somma_min = somma;
            }
            if (somma % 10 == 0) {
                conta_selex++;
            }
        }
    }
    
    if (conta_selex >= 2) {
        *pMinSumProd = somma_min;
    }
    
    return conta_selex >= 2;
} */

int prodotto_colonna(const size_t rows, const size_t cols,
    const int mat[rows][cols], const int c) {
    int prodotto = 1;

    for (int i=0; i<rows; i++) {
        prodotto *= mat[i][c];
    }

    printf("Prodotto della colonna indice %d: %d\n", c, prodotto);
    return prodotto;
}

bool e1(const size_t rows, const size_t cols, const int mat[rows][cols],
        const size_t rags[], int* pMinSumProd) {
    int selex = 0;

    for (int r=0; r<rows; r++) {
        int somma = 0;
        for (int c=0; c<rags[r]; c++) {
            if (mat[r][c] % 3 == 0) {
                somma += prodotto_colonna(rows, cols, mat, c);
            }
        }
        if (somma % 10 == 0) {
            selex++;
        }
    }   

    if (selex >= 2) {
        *pMinSumProd = selex;
    }

    return selex >= 2;
}