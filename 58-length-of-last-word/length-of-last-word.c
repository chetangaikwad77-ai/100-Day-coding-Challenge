#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int length = strlen(s);
    int count = 0;

    // Start from the end of the string
    int i = length - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
}
