#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 8

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

void stampa_matrice(const int mat[ROWS][COLS]);

bool matrici_uguali(const int matA[ROWS][COLS], 
                    const int matB[ROWS][COLS]);

void init_alternate(int mat[ROWS][COLS], 
                    const int* pPari, const int* pDispari);

void imposta_riga(int mat[ROWS][COLS], const size_t r, const int val);

void imposta_colonna(int mat[ROWS][COLS], const size_t c, const int val);

bool elem_div_riga(const int pRiga[COLS], const size_t c);

bool elem_div_mat(const int mat[ROWS][COLS]);

//------------------------------------------------------------------

int main(void)
{
    // Inizializzazione da valori letterali
    const int matA[ROWS][COLS] = {
        {  4, -2,  -6,  -1,   8,   5,   5,   2 },
        {  8,  9,  -7,  -1,  -6,   4,  -4,   6 },
        { -4,  8,  -1,  -4,  -4,   3,  -8,   0 },
        {  9,  0,   8,  -7,   4,   1,   0,   6 },
        {  3,  8,   2,  -4,   9,   4,  -4,  -3 },
    };
    stampa_matrice(matA);
    puts("");

    const int rPari[COLS]    = { 0, 5, 0, 5, 0, 5, 0, 5 };
    const int rDispari[COLS] = { 8, 0, 8, 0, 8, 0, 8, 0 };
    int matB[ROWS][COLS];
    init_alternate(matB, rPari, rDispari);
    stampa_matrice(matB);

    const int risB[ROWS][COLS] = {
        { 0, 5, 0, 5, 0, 5, 0, 5 },
        { 8, 0, 8, 0, 8, 0, 8, 0 },
        { 0, 5, 0, 5, 0, 5, 0, 5 },
        { 8, 0, 8, 0, 8, 0, 8, 0 },
        { 0, 5, 0, 5, 0, 5, 0, 5 },
    };
    printf("%s\n\n", matrici_uguali(matB, risB) ? "Ok." : "NO.");

    imposta_riga(matB, 0, 4);
    imposta_riga(matB, 3, 2);
    imposta_riga(matB, 5, 100);
    imposta_riga(matB, 500, 200);
    imposta_colonna(matB, 2, -1);
    imposta_colonna(matB, 7, 5);
    imposta_colonna(matB, 8, 100);
    imposta_colonna(matB, 25, 100);
    stampa_matrice(matB);

    const int risB2[ROWS][COLS] = {
        { 4,  4, -1,  4,  4,  4,  4,  5 },
        { 8,  0, -1,  0,  8,  0,  8,  5 },
        { 0,  5, -1,  5,  0,  5,  0,  5 },
        { 2,  2, -1,  2,  2,  2,  2,  5 },
        { 0,  5, -1,  5,  0,  5,  0,  5 },
    };
    printf("%s\n\n", matrici_uguali(matB, risB2) ? "Ok." : "NO.");

    const int rD0[COLS] = { 3, 5,  7, 11, 13, 17, 19, 23 };
    const int rD1[COLS] = { 4, 8, 12, 16, 20, 24, 28, 32 };
    int matC[ROWS][COLS];
    init_alternate(matC, rD0, rD1);
    printf("%s\n\n", !elem_div_mat(matC) ? "Ok." : "NO.");

    init_alternate(matC, rD0, rD0);
    printf("%s\n\n", !elem_div_mat(matC) ? "Ok." : "NO.");

    init_alternate(matC, rD1, rD1);
    printf("%s\n\n", elem_div_mat(matC) ? "Ok." : "NO.");
}

//------------------------------------------------------------------

void stampa_matrice(const int mat[ROWS][COLS]) {
    for (size_t r=0; r<ROWS; r++) {
        for (size_t c=0; c<COLS; c++) {
            printf("%3d", mat[r][c]);
        }
        puts("");
    }
}

//------------------------------------------------------------------

bool matrici_uguali(const int matA[ROWS][COLS], 
                    const int matB[ROWS][COLS])
{
    bool run = true;
    for (int* i=(int*)matA; i<(int*)matA+ROWS*COLS && run; i++) {
        for (int* j=(int*)matB; j<(int*)matB+ROWS*COLS && run; j++) {
            if (*i != *j) {
                run = false;
            }
        }
    }
    return run;
}

//------------------------------------------------------------------

// Inizializza le righe della matrice mat copiando dagli
// array pPari e pDispari i valori rispettivamente per le righe
// pari e dispari.
void init_alternate(int mat[ROWS][COLS], 
                    const int* pPari, const int* pDispari)
{
    /* int counter = 0;
    for (int* i=pPari; i<pPari+sizeof(pPari)/sizeof(pPari[0]); i++) {
        mat[counter][3] = 3; // ??
    } */
}

//------------------------------------------------------------------

// Imposta tutti i valori per la riga r della matrice mat con il
// valore val passato come argomento. Se l'indice r passato come argomento
// non e' un indice di riga valido, allora la funzione non esegue operazioni.
void imposta_riga(int mat[ROWS][COLS], const size_t r, const int val)
{
    if (r < ROWS) {
        for (int i=0; i<sizeof(mat[r])/sizeof(mat[r][0]); i++) {
            mat[r][i] = val;
        }
    }
}

//------------------------------------------------------------------

// Imposta tutti i valori per la colonna c della matrice mat con il
// valore val passato come argomento. Se l'indice c passato come argomento
// non e' un indiice di colonna valido, allora la funzione non esegue operazioni.
void imposta_colonna(int mat[ROWS][COLS], const size_t c, const int val)
{
    if (c < COLS) {
        for (int i=0; i<COLS; i++) {
            mat[i][c] = val;
        }
    }
}

//------------------------------------------------------------------

// Una riga ha un elemento divisivo in posizione j se
// tutti gli elementi della riga sono divisibili per tale elemento
// Ritorna true se la riga in ingresso ha un elemento divisivo 
// in posizione j
bool elem_div_riga(const int pRiga[COLS], const size_t j)
{
    bool divisivo = true;

    for (int i=0; i<COLS && divisivo; i++) {
        if (pRiga[i] % pRiga[j] != 0) {
            divisivo = false;
        }
    }

    return divisivo;
}

//------------------------------------------------------------------

// una matrice e' divisiva se tutte le righe hanno almeno 
// una posizione divisiva. 
// Ritorna true se la matrice in ingresso e' divisiva.
bool elem_div_mat(const int mat[ROWS][COLS])
{
    bool divisiva = true;
    int counter = 0;

    for (int i=0; i<ROWS && divisiva; i++) {
        for (int j=0; j<COLS; j++) {
            if (!elem_div_riga(mat[i], j)) {
                counter += 1;
            }
        }
        if (counter == COLS) {
            divisiva = false;
        }
    }

    return divisiva;
}

//------------------------------------------------------------------