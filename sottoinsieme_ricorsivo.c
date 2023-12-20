/*
Scrivere le seguenti funzioni ricorsive su array:

leggi_arrayR: funzione ricorsiva che legge n valori da standard input con scanf e li memorizza nell'array a[]
somma_arrayR: funzione ricorsiva che calcola la somma dei valori dell'array a[]
esiste_val_in_arrayR: funzione ricorsiva che riceve in ingresso un array (aLen,a[]) ed un valore val
e restituisce true se val compare tra gli elementi di a[].
sottoinsiemeR: funzione ricorsiva che riceve in ingresso un array (aLen,a[]) ed un array (bLen,b[])
e restituisce true se ogni elemento di a[] compare nell'array b[]
Per ciascuna funzione ricorsiva scrivere la corrispondente funzione involucro.

Il programma deve leggere da standard input due array a[] e b[], stampare su di una sola riga la somma dei valori degli array a[] e b[]
ed infine stampare su di una seconda linea un valore booleano (0 o 1) se A è sottoinsieme di B, e se B è sottoinsieme di A.

INPUT: per ciascun array compare prima il numero di elementi len, seguito dai len valori interi dell'array.
NOTA: non potete scrivere cicli for/while.

For example:

Input	Result
2       4 6
1 3     1 0
3
1 2 3
*/

#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

void leggi_array(const size_t aLen, int a[]);
int somma_array(const size_t aLen, int a[]);
int somma_arrayR(const size_t aLen, int a[], int n);
bool esiste_val_in_array(const size_t aLen, const int a[], int val);
bool esiste_val_in_arrayR(const size_t aLen, const int a[], int val, int n);
bool sottoinsieme(const size_t aLen, const int a[], 
			    const size_t bLen, const int b[]);
bool sottoinsiemeR(const size_t aLen, const int a[],
                const size_t bLen, const int b[], int n);

//------------------------------------------------------------------

void stampa_arrayR(const int* array, const int len, int n) {
    if (n < len) {
        printf("%d ", array[n]);
        stampa_arrayR(array, len, n+1);
    } else {
        puts("");
    }
}

void stampa_array(const int* array, const int len) {
    stampa_arrayR(array, len, 0);
}


int main(void) {
	size_t aLen, bLen;

	scanf("%zu", &aLen);
	int a[aLen];
	leggi_array(aLen, a);

	scanf("%zu", &bLen);
	int b[bLen];
	leggi_array(bLen, b);

	printf("%d %d\n", somma_array(aLen, a), somma_array(bLen, b));

	printf("%d %d\n", 
		   sottoinsieme(aLen, a, bLen, b),
		   sottoinsieme(bLen, b, aLen, a));
}

//------------------------------------------------------------------


// leggi_arrayR: funzione ricorsiva che legge n valori da standard input con scanf
// e li memorizza nell'array a[]
void leggi_arrayR(const size_t aLen, int a[], size_t i) {
    if (i < aLen) {
        scanf("%d", &a[i]);
        leggi_arrayR(aLen, a, i+1);
    }
}

void leggi_array(const size_t aLen, int a[]) { 
	leggi_arrayR(aLen, a, 0);
}

// somma_arrayR: funzione ricorsiva che calcola la somma dei valori dell'array a[]
int somma_array(const size_t aLen, int a[]) {
    return somma_arrayR(aLen, a, 0);
}

int somma_arrayR(const size_t aLen, int a[], int n) {
    int ret = 0;

    if (n < aLen) {
        ret = a[n] + somma_arrayR(aLen, a, n+1);
        // printf("Somma: %d\n", ret);
    }

    return ret;
}

bool esiste_val_in_array(const size_t aLen, const int a[], int val) {
    return esiste_val_in_arrayR(aLen, a, val, 0);
}

// esiste_val_in_arrayR: funzione ricorsiva che riceve in ingresso un array (aLen,a[])
// ed un valore val, e restituisce true se val compare tra gli elementi di a[].
bool esiste_val_in_arrayR(const size_t aLen, const int a[], int val, int n) {
    bool ret = false;

    // printf("VAL: %d\n", val);
    if (n < aLen) {
        ret = esiste_val_in_arrayR(aLen, a, val, n+1);
        if (!ret) {
            if (val == a[n]) {
                ret = true;
            }
        }
    }

    return ret;
}

bool sottoinsieme(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
    return sottoinsiemeR(aLen, a, bLen, b, 0);
}

// sottoinsiemeR:   funzione ricorsiva che riceve in ingresso un array (aLen,a[]) ed un array (bLen,b[])
//                  restituisce true se ogni elemento di a[] compare nell'array b[]
bool sottoinsiemeR(const size_t aLen, const int a[], const size_t bLen, const int b[], int n) {
    bool ret = true;

    if (n < aLen) {
        // printf("Ret 1: %d elemento: %d in posizione %d\n", ret, a[n], n);
        ret = sottoinsiemeR(aLen, a, bLen, b, n+1);
        if (ret) {
            ret = esiste_val_in_array(bLen, b, a[n]);
            // printf("Ret 2: %d elemento: %d in posizione %d\n", ret, a[n], n);
        }
    }

    return ret;
}