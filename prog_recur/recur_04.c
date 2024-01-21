#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void copia_stringa(char* string1, char* string2, size_t n) {
    if (string1[n] == '\0') {
        string2[n] = '\0';
    } else {
        string2[n] = string1[n];
        copia_stringa(string1, string2, n+1);
    }
}

bool esiste_carattereR(const char* string, char c, size_t n) {
    bool found = false;

    if (string[n] != '\0') {
        if (string[n] != c) {
            found = esiste_carattereR(string, c, n+1);
        } else {
            found = true;
        }
    }

    return found;
}

void e2R(char* pStr, const char* pStr2, size_t n, size_t c) {
    // caso base. Ho finito tutti i controlli.
    // Posso quindi aggiungere il terminatore a pStr
    if (pStr2[n] == '\0') {
        pStr[c] = '\0';
    } else {
        // chiamo la funzione con n+1 perché voglio controllare l'esistenza
        // di caratteri uguali a partire dal carattere successivo
        // e.g.= se voglio controllare a in amaca, devo controllare a partire da m
        if (!esiste_carattereR(pStr2, pStr2[n], n+1)) {
            // se non esiste il carattere lo aggiungo a pStr
            pStr[c] = pStr2[n];
            e2R(pStr, pStr2, n+1, c+1);
        } else {
            // altrimenti passo al controllo della prossima lettera 
            e2R(pStr, pStr2, n+1, c);
        }
    }
}

void e2(char* pStr) {
    // ottengo la lunghezza di pStr
    size_t len = sizeof(*pStr) / sizeof(pStr[0]);
    // creo una copia di pStr con la stessa lunghezza
    char pStr2[len];
    copia_stringa(pStr, pStr2, 0);

    /* chiamo la funzione ricorsiva con:
        - n = contatore ricorsivo
        - c = contatore delle lettere filtrate  
    */
    e2R(pStr, pStr2, 0, 0);
}