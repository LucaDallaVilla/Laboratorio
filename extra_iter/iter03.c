/* Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, ed un array di interi (aLen, a)
definiamo come prodotto riga-array tra la riga i e l'array a[] la somma dei prodotti elemento per elemento tra la riga i della matrice e l'array, fino al limite della sequenza più piccola.
e1 determina se esistono righe per le quali il prodotto riga-array è sia maggiore di 0 che multiplo di 5: in quel caso, e1 restituisce true, e la somma di tutti i prodotti riga-array viene scritta nella variabile pSum.
In ogni altro caso, e1 restituisce false. */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int prodotto_riga_array(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen], const int r) {
    int somma = 0;

    for (int c=0; c<rags[r] && c<aLen; c++) {
        somma += mat[r][c] * a[c];
    }

    return somma;
}

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) 
{
    bool ret = false;
    int somma_min = INT_MAX;

    for (int r=0; r<rows; r++) {
        int prodotto = prodotto_riga_array(rows, cols, mat, rags, aLen, a, r);
        
        if (prodotto > 0 && prodotto % 5 == 0) {
            ret = true;
            if (prodotto < somma_min) {
                somma_min = prodotto;
            }
        }
    }

    if (ret) {
        *pSum = somma_min;
    }

    return ret;
}