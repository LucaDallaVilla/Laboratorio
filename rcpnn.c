#include <stdio.h>
#include <stdbool.h>

/*
Scrivere un programma che legge dall'input una matrice rettangolare, e stampa in output tutte le coppie di indici r,c
tali per cui tutti i numeri sulla riga r e sulla colonna c risultano non-negativi e pari.

INPUT: le dimensioni rows e cols, seguite da rows*cols interi che rappresentano le righe della matrice

OUTPUT: le coppie di indici che soddisfano i criteri indicati (una coppia per riga)
*/

int trova_rcpnn(int rows, int cols, const int mat[rows][cols], int result[rows][2]);
void leggi_matrice(const size_t rows, const size_t cols, int mat[rows][cols]);

int main(void) {
	// leggi le dimensioni della matrice rettangolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);

	// riserva la memoria per la matrice di dimensione rows * cols
	int mat[rows][cols];
    int result[rows][2];
	
	// leggi i dati
	leggi_matrice(rows, cols, mat);
    int occurencies = trova_rcpnn(rows, cols, mat, result);

	for (int i=0; i<occurencies; i++) {
		printf("%d %d", result[i][0], result[i][1]);
		printf("\n");
	}
}

void leggi_matrice(const size_t rows, const size_t cols, int mat[rows][cols]) {
	for (size_t r=0; r<rows; r++) {
		for (size_t c=0; c<cols; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

int trova_rcpnn(int rows, int cols, const int mat[rows][cols], int result[rows][2]) {
	int counter = 0;

	for (int n=0; n<rows*cols; n++) {
		int raw_index = n / cols;
		int col_index = n % cols;

		bool run_row = true;
		for (int r=0; r<rows && run_row; r++) {
			int element = mat[r][col_index];
			if (element % 2 != 0 || element < 0) {
				run_row = false;
			}
		}

		bool run_cols = true;
		for (int c=0; c<cols && run_cols; c++) {
			int element = mat[raw_index][c];
			if (element % 2 != 0 || element < 0) {
				run_cols = false;
			}
		}

		if (run_cols && run_row) {
			result[counter][0] = raw_index;
			result[counter][1] = col_index;
			counter++;
		}
	}

	return counter;
}