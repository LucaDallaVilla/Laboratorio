#include <stdio.h>
#include <stdbool.h>

/*
Una riga rA di lunghezza lenA è prefisso di una riga rB di lunghezza lenB se lenA ≤ lenB e, per ogni elemento i ∈ [0, lenA), rA[i]==rB[i].
Scrivere un programma che, date due matrici irregolari matA e matB, determina se esistono righe di matA che sono prefissi di righe di matB.

INPUT: le matrici irregolari matA e matB. Ciascuna matrice irregolare è fornita indicando le dimensioni rows e cols, seguite, per ogni riga,
dal numero di elementi inizializzati di tale riga e successivamente dagli elementi stessi della riga.

OUTPUT: le coppie di indici iA iB tali che la riga iA di matA è prefisso della riga iB di matB (una coppia di indici per linea dell'output).

For example:
Input				Result
2 3					1 0
3    9 -5 7
1    2
2 3
3    2 -5  9
3    9 -5 -2
*/

void leggi_matrice_irregolare(const size_t rows, const size_t cols, int mat[rows][cols], size_t rags[rows]);
int trova_prefisso(int* row, size_t row_len, size_t rowsB, size_t colsB, int mat[rowsB][colsB], int* result);


int main(void) {
	// leggi la matrice irregolare A
	size_t rowsA, colsA;
	scanf("%zu %zu", &rowsA, &colsA);
	int matA[rowsA][colsA];
	size_t ragsA[rowsA];
	leggi_matrice_irregolare(rowsA, colsA, matA, ragsA);

	// leggi la matrice irregolare B
	size_t rowsB, colsB;
	scanf("%zu %zu", &rowsB, &colsB);
	int matB[rowsB][colsB];
	size_t ragsB[rowsB];
	leggi_matrice_irregolare(rowsB, colsB, matB, ragsB);

	int result[rowsB];
	for (int r1=0; r1<rowsA; r1++) {
		int occorrenze = trova_prefisso(matA[r1], ragsA[r1], rowsB, colsB, matB, result);
		for (int i=0; i<occorrenze; i++) {
			printf("%d %d\n", r1, result[i]);
		}
	}
}

void leggi_matrice_irregolare(const size_t rows, const size_t cols, int mat[rows][cols], size_t rags[rows]) 
{
	for (size_t r=0; r<rows; r++) {
	    scanf("%zu", &rags[r]);
		for (size_t c=0; c<rags[r]; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

int trova_prefisso(int* row, size_t row_len, size_t rowsB, size_t colsB, int mat[rowsB][colsB], int* result) {
	bool run = true;
	int counter = 0;

	for (int j=0; j<rowsB; j++) {
		run = true;
		for (int i=0; i<row_len && run; i++) {
			if (mat[j][i] != row[i]) {
				run = false;
			}
		}
		if (run) {
			result[counter] = j;
			counter++;
		}
	}

	return counter;
}