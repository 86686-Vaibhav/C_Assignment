#include <stdio.h>
#include <string.h>

#define SIZE 10

int main() {
    // Initialize the array with hard-coded strings
    char *arr[SIZE] = {
        "aaa", "bbb", "ooo", "aaa", 
        "ggg", "bbb", "ppp", "kkk", 
        "ggg", "mmm"
    };

    int i, j;
    int isDuplicate[SIZE] = {0};  // To keep track of duplicates

    printf("Duplicate Strings in the Array:\n");

    // Check for duplicates
    for (i = 0; i < SIZE - 1; i++) {
        if (isDuplicate[i] == 1) {
            continue;  // Skip already found duplicates
        }
        for (j = i + 1; j < SIZE; j++) {
            if (strcmp(arr[i], arr[j]) == 0) {
                // Mark duplicates
                if (isDuplicate[i] == 0) {
                    printf("%s\n", arr[i]);  // Print only once
                    isDuplicate[i] = 1;
                }
                isDuplicate[j] = 1;
            }
        }
    }

    return 0;
}
