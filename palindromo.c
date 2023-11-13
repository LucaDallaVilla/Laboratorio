#include <stdio.h>
#define MAX_CHAR 50

int isPalindroma(char* string, int length);
void capovolgi(char*, int len_dst, char*);

int main() {
    int length1;
    char array1[MAX_CHAR];
    char array2[MAX_CHAR];

    scanf("%s%n", array1, &length1);
    capovolgi(array1, length1, array2);
    int palindroma = isPalindroma(array1, length1);
    if (palindroma) {
        printf("PALINDROMA");
    } else {
        printf("%s %s", array1, array2);
    }

    return 0;
}


int isPalindroma(char* string1, int length) {
    char string2[length];
    int result = 1;

    capovolgi(string1, length, string2);
    for (int i=0; i<length; i++) {
        if (string1[i] != string2[i]) {
            result = 0;
            i = length;
        }
    }

    return result;
}


void capovolgi(char* dst, int len_dst, char* src) {
    for (int i=len_dst-1; i>=0; i--) {
        src[len_dst-i-1] = dst[i];
    }
}