#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool my_equal(char *stringa1, char *stringa2) 
{
	bool ver1 = 1;
	bool ver2 = 1;

    for (int i=0; stringa1[i]!='\0' && ver1; i++) {
        // printf("%d == %d\n", stringa1[i], stringa2[i]);
        if (stringa1[i] == stringa2[i]) {
            ver1 = 1;
        } else {
            ver1 = 0;
        }
    }

	for (int i=0; stringa2[i]!='\0' && ver2; i++) {
        // printf("%d == %d\n", stringa1[i], stringa2[i]);
        if (stringa1[i] == stringa2[i]) {
            ver2 = 1;
        } else {
            ver2 = 0;
        }
    }

    return ver1 && ver2;
}

int main() {
    bool result = my_equal("Test", "Testosterone");
    printf("%s\n", result ? "Uguali" : "Diverse");
}





/* printf("dstStart: %s length: %ld\n", dstStart, strLen);
	printf("str1: %s str2: %s\n", str1, str2);

	size_t oldIndex = 0;
	for (int i=0; i<strLen-1; i++) {
		for (int j=0; str1[j]!='\0' && i+oldIndex<strLen; j++) {
			dstStart[i+oldIndex] = str1[j];
			// printf("dstStart: %s length: %ld\n", dstStart, strLen);
			oldIndex++;
		}
		for (int j=oldIndex; str2[j-oldIndex]!='\0' && i+oldIndex<strLen; j++) {
			dstStart[i+oldIndex] = str2[j];
			oldIndex++; 
			// printf("dstStart: %s length: %ld\n", dstStart, strLen);
		}
	}
	dstStart[strLen-1] = '\0';
*/