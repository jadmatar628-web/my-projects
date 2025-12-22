#include <stdio.h>
#include <ctype.h>  // for toupper

int main() {
    FILE *inputFile = fopen("my_first_file.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int ch; // store each character as an int
    while ( /* condition to read until end of file */ ) {
        // read a character from inputFile

        // check if it's lowercase

        // convert to uppercase if needed

        // write the character to outputFile
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion complete. Check output.txt\n");
    return 0;
}
