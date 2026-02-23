#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    // Edge case: if only one row or string length <= numRows
    if (numRows == 1 || len <= numRows) {
        char* result = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result, s);
        return result;
    }

    // Allocate memory for result
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int index = 0;

    int cycleLen = 2 * numRows - 2;

    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += cycleLen) {
            
            // Vertical element
            result[index++] = s[j];

            // Diagonal element (only for middle rows)
            if (i != 0 && i != numRows - 1) {
                int diagonal = j + cycleLen - 2 * i;
                if (diagonal < len) {
                    result[index++] = s[diagonal];
                }
            }
        }
    }

    result[index] = '\0';
    return result;
}