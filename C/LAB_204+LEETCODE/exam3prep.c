#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void reverse(char *word, int l, int r) {
    while (l < r) {
        char tmp = word[l];
        word[l] = word[r];
        word[r] = tmp;
        l++;
        r--;
    }
}

int main()
{
    printf("Enter a string: ");
    char *word = malloc(100 * sizeof(char));
    fgets(word, 100, stdin);
    word[strcspn(word, "\n")] = '\0';

    int len = strlen(word);

    // Step 1: reverse entire string
    reverse(word, 0, len - 1);
    int start = 0;
    for (int i = 0; i <= len; i++) {
        if (word[i] == '.' || word[i] == '\0') {
            reverse(word, start, i - 1);
            start = i + 1;
        }
    }

    printf("Reversed words: %s\n", word);
    free(word);
    return 0;
}
