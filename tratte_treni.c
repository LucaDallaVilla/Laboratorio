#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

/*
Ci sono rows città connesse da delle tratte ferroviarie. Una matrice irregolare mat rappresenta tali connessioni: la citta i è connessa da una tratta ferroviaria con la città j se il valore j compare nella riga i-esima di mat. Nella matrice è garantito che, se i è connessa con j, allora anche j è connessa con i.

Scrivere un programma che legge in input una matrice irregolare, seguita da un numero q di richieste. Per ogni richiesta, viene letta una coppia (from, to) che rappresentano il numero della città di partenza e della città di destinazione. Il programma deve rispondere ad ogni richiesta stampando una stringa:

"DIRETTO" se esiste una connessione diretta tra from e to;
"1 CAMBIO" se non esiste una connessione diretta tra from e to, ma esiste una città intermedia di indice middle tale che sia from che to sono connesse a middle;
"NO" se non esiste né una connessione diretta, né una connessione con un cambio.
INPUT: la matrice irregolare è fornita indicando le dimensioni rows e cols, seguite, per ogni riga, dal numero di elementi inizializzati di tale riga e successivamente dagli elementi stessi della riga.
L'elenco delle richieste è fornito indicando il numero totale q di richieste, seguito dalle coppie from to.
OUTPUT: una stringa per riga, per ciascuna delle q richieste.

For example:
Input	    Result
5 3         
2  1 2      
3  0 2 4    
2  0 1
1  4        
2  1 3

3
0 1         1 CAMBIO
2 4         DIRETTO
0 3         NO
*/

void leggi_matrice_irregolare(const size_t rows, const size_t cols,
                            int mat[rows][cols], size_t rags[rows]);

int trova_percorso(const size_t rows, const size_t cols, const int mat[rows][cols],
                    const size_t from, const size_t to, const size_t rags[rows]);


int main(void) {
    size_t rows, cols;
    scanf("%zu %zu", &rows, &cols);
    int mat[rows][cols];
    size_t rags[rows];
    leggi_matrice_irregolare(rows, cols, mat, rags);

    size_t q, from, to;
    scanf("%zu", &q);
    
    for (int i=0; i<q; i++) {
        scanf("%zu", &from);
        scanf("%zu", &to);
        int result = trova_percorso(rows, cols, mat, from, to, rags);

        if (result == -1) {
            printf("NO\n");
        } else if (result == 0) {
            printf("DIRETTO\n");
        } else if (result == 1) {
            printf("1 CAMBIO\n");
        } else {
            printf("ERRORE\n");
        }
    }    
}


void leggi_matrice_irregolare(const size_t rows, const size_t cols,
                            int mat[rows][cols], size_t rags[rows]) 
{
    for (size_t r=0; r<rows; r++) {
        scanf("%zu", &rags[r]);
        for (size_t c=0; c<rags[r]; c++) {
            scanf("%d", &mat[r][c]);
        }
    }
}

int trova_percorso(const size_t rows, const size_t cols, const int mat[rows][cols],
                    const size_t from, const size_t to, const size_t rags[rows]) {
    int result = -1;
    bool esegui = true;

    // cerca percorso diretto
    for (int i=0; i<rags[from] && esegui; i++) {
        if (mat[from][i] == to) {
            result = 0;
            esegui = false;
        }
    }

    // cerca percorso con un cambio
    // per ciascuna città collegata alla partenza...
    for (int i=0; i<rags[from] && esegui; i++) {
        // ...controlla il collegamento con la città dove fare il cambio
        // cambio rappresenta la città dove prendere la coincidenza
        int cambio = mat[from][i];
        for (int j=0; j<rags[cambio]; j++) {
            if (mat[cambio][j] == to) {
                result = 1;
                esegui = false;
            }
        }
    }

    return result;
}