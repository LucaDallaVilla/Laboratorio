/* Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, un intero k, ed un puntatore ad interi pMaxSum
e1 restituisce true se in tutte le righe di lunghezza non zero la somma degli elementi della riga è multiplo di k.
Se almeno una riga con tale proprietà sulla somma esiste, il massimo di tutte le somme (sulle righe che rispettano tale proprietà) deve essere scritto nell'intero puntato da pMaxSum.
In ogni altro caso e1 restituisce false. */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols,
        const int mat[rows][cols], const size_t rags[rows],
        const int k, int *pMaxSum)
{
    *pMaxSum = INT_MIN;
    int somma = 0;
    bool ret = true;

    for (int r = 0; r < rows; r++)
    {
        somma = 0;
        // calcola somma della riga r
        for (int c = 0; c < rags[r]; c++)
        {
            somma += mat[r][c];
        }

        printf("Somma: %d\n", somma);

        if (somma != 0)
        {
            if (somma % k != 0)
            {
                ret = false;
            }
            else if (somma > *pMaxSum)
            {
                *pMaxSum = somma;
            }
        }
    }

    return ret;
}

int main(void)
{
    const size_t rows = 2, cols = 5;
    int mat[2][5] = {
        {4, 7, 4, 2, 1},
        {1, 3}};
    size_t rags[2] = {5, 2};
    int maxSum;
    bool ret = e1(rows, cols, mat, rags, 4, &maxSum);
    if (ret)
    {
        printf("T %d\n", maxSum);
    }
    else
    {
        printf("F %d\n", maxSum);
    }
}