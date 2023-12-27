#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool esiste_carattereR(char* string, char c, int n) {
    bool found = false;

    if (string[n] != '\0') {
        if (string[n] == c) {
            found = true;
        }
        if (!found) {
            esiste_carattereR(string, c, n+1);
        }
    }

    return found;
}

bool esiste_carattere(char* string, char c) {
    return esiste_carattereR(string, c, 0);
}

void e2R(char* pStr, int n) {
    int pStrLen = sizeof(pStr) / sizeof(pStr[0]);
    char pStrC[pStrLen];
    strcpy(pStrC, pStr);
    if (pStr[n] != '\0') {
        e2R(pStr, n+1);
        printf("%c in %s? %s\n", pStr[n], pStr, esiste_carattere(pStrC, pStrC[n]) ? "Si" : "No");
        if (esiste_carattere(pStrC, pStrC[n])) {
            pStr[n] = '0';
        }
    }
}

void e2(char* pStr) {
    e2R(pStr, 0);
}