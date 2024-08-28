#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_COUNT 26

int main() {
    char str[100];
    int freq[ALPHABET_COUNT] = {0};

    // Input string from the user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Count occurrences of each alphabet (case insensitive)
    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        // Convert to uppercase if it's an alphabet
        if (isalpha(ch)) {
            ch = toupper(ch);
            freq[ch - 'A']++;  // Increment the frequency for the letter
        }
    }

    // Display the occurrences of each alphabet
    printf("Output:\n");
    for (int i = 0; i < ALPHABET_COUNT; i++) {
        if (freq[i] > 0) {
            printf("%c : %d\n", 'A' + i, freq[i]);
        }
    }

    return 0;
}
