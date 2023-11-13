#include <stdio.h>
#include <stdbool.h>
#define MAX_CHAR 50


// ritorna true se il carattere ch è una vocale
bool is_vowel(char ch) {
#   define NUM_VOWELS 10
    const char vowels[NUM_VOWELS] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    bool is_v = false;
    for (size_t i=0; i<NUM_VOWELS && !is_v; i++) {
        if (ch == vowels[i])
            is_v = true;
    }
    return is_v;
}

void elimina_vocali(char *stringa, int length) {
    int counter = 0;
    char copia[length];

    for (int i=0; i<length; i++) {
        copia[i] = stringa[i];
        stringa[i] = '\0';
    }

    for (int i=0; i<length; i++) {
        if (!is_vowel(copia[i])){
            stringa[counter] = copia[i];
            counter++;
        }
    }
}


int main(void) {
    char input[MAX_CHAR];
    int input_length;

    scanf("%s%n", input, &input_length);
    elimina_vocali(input, input_length);

    printf("%s", input);
}
