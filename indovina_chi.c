#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUM_PERS 24

int stringCommon(char string1[], int length1, char string2[], size_t length2, char result[]);


int main() {
    char input[NUM_PERS];
    int input_length;
    const char* nomi[NUM_PERS] = {
        "Claire","Eric",   "Maria", "George","Bernard","Sam",    "Tom",    "Paul",
        "Joe",   "Frans",  "Anne",  "Max",   "Alex",   "Philip", "Bill",   "Anita",  
        "David", "Charles","Herman","Peter", "Susan",  "Robert", "Richard","Alfred" };
    // Gli attributi dei soggetti fermati, codificati come stringa
    const char* attributi[NUM_PERS] = {
        "drco", "bc",   "dtc", "wc",   "tcg",  "wpo",  "npzo", "wo",  
        "bo",   "r",    "dn",  "nfsg", "nfs",  "nal",  "rpal", "dblz", 
        "ba",   "bfs",  "rpg", "wszg", "dwls", "tlzg", "tpfa", "rfz" };

    scanf("%s%n", input, &input_length);
    char input_m[input_length];
    char input_M[input_length];
    int counter_M = 0;
    int counter_m = 0;

    for (int i=0; i<input_length; i++) {
        if (isupper(input[i])) {
            input_M[counter_M] = input[i];
            counter_M++;
        }
        else {
            input_m[counter_m] = input[i];
            counter_m++;
        }
    }

    // keeps track of the maximum number of attributes in common with each character
    int maxCommonAttributes = 0;
    int indexes[NUM_PERS] = {-1};
    int counter = 0;
    char result[5];

    for (int i=0; i<NUM_PERS; i++) {
        int commonAttributes = stringCommon(input_m, input_length, (char *)attributi[i], strlen(attributi[i]), result);
        if (commonAttributes == maxCommonAttributes) {
            indexes[counter] = i;
            counter++;
        } else if (commonAttributes > maxCommonAttributes) {
            for (int j=0; j<NUM_PERS; j++) {
                indexes[i] = -1;
                counter = 0;
            }

            maxCommonAttributes = commonAttributes;
            indexes[counter] = i;
            counter++;
        }
    }

    int suspectsIndexes[NUM_PERS] = {-1};
    for (int i=0; i<NUM_PERS; i++) {
        suspectsIndexes[i] = -1;
    }
    int k=0;
    for (int i=0; i<counter; i++) {
        // avoids all null indexes
        if (indexes[i] != -1) {
            for (int j=0; j<input_length; j++) {
                if (strchr(nomi[indexes[i]], tolower(input_M[j])) == NULL) {
                    suspectsIndexes[k] = indexes[i];
                    k++;
                }
            }
        }
    }

    for (int i=0; i<NUM_PERS; i++) {
        if (suspectsIndexes[i] != -1) {
            printf("%s\n", nomi[suspectsIndexes[i]]);
        }
    }

    puts("");
    printf("%d\n", counter);
    
    return 0;
}



int stringCommon(char string1[], int length1, char string2[], size_t length2, char result[]) {
    // elimino tutti gli elementi dell'array
    for (int i=0; i<5; i++) {
        result[i] = '\0';
    }
    
    int c = 0;
    for (int i=0; i<length1; i++) {
        for (size_t j=0; j<length2; j++) {
            if (string1[i] == string2[j]) {
                result[c] = string1[i];
                c++;
            }
        }
    }

    return c;
}