#include <stdio.h>
#include <stdbool.h>
#define MAX_STR  100

bool prefix(char* str1, int len1, char* str2, int len2);
bool prefixR(char* str1, int len1, char* str2, int len2, int n);
void stampa_filtro_substr(char* str1, int len1, char* str2, int len2);
void stampa_filtro_substrR(char* str1, int len1, char* str2, int len2, int n);

int main(void) {
	char seq[MAX_STR];
	char del_seq[MAX_STR];
    int len1, len2;
	
	scanf("%s%n", seq, &len1);
	scanf("%s%n", del_seq, &len2);
	stampa_filtro_substr(seq, len1, del_seq, len2);
}

bool prefix(char* str1, int len1, char* str2, int len2) {
    return prefixR(str1, len1, str2, len2, 0);
}

bool prefixR(char* str1, int len1, char* str2, int len2, int n) {
    if (n = len2-1) {
        return true;
    } else {
        if (!prefixR(str1, len1, str2, len2, n+1)) {
            return false;
        }
        if (str1[n+1] != str2[n+1]) {
            return false;
        }
    }
    
    return true;
}

void stampa_filtro_substr(char* str1, int len1, char* str2, int len2) {
    stampa_filtro_substrR(str1, len1, str2, len2, 0);
}

void stampa_filtro_substrR(char* str1, int len1, char* str2, int len2, int n) {
    printf("%s\n", prefix(str1, len1, str2, len2) ? "true" : "false");
    /* if (n < len1) {
        if (prefix(str1, len1, str2, len2)) {
            printf("-");
            stampa_filtro_substrR(str1, len1, str2, len2, n+1);
        } else {
            printf("%c", str1[n+1]); 
            stampa_filtro_substrR(str1, len1, str2, len2, n+1);
        }
    } */
}