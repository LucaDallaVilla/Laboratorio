#include <stdio.h>
#include <stdbool.h>

bool prefix(char* str1, int len1, char* str2, int len2);
bool prefixR(char* str1, int len1, char* str2, int len2, int n);

int main(void) {
    printf("%s\n", prefix("ciao", 4, "ci", 2) ? "true" : "false");
}

bool prefix(char* str1, int len1, char* str2, int len2) {
    return prefixR(str1, len1, str2, len2, len2);
}

bool prefixR(char* str1, int len1, char* str2, int len2, int n) {
    if (n == 0) {
        return str1[n] == str2[n];
    } else {
        if (prefixR(str1, len1, str2, len2, n-1)) {
            return str1[n] == str2[n];
        } else {
            return false;
        }
    }
}