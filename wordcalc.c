#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    char *filename;

    if (argc >= 2) {
        filename = argv[1];
    } else {
        printf("Enter filename: ");
        filename = malloc(256);
        scanf("%255s", filename);
    }

    FILE *filePointer = fopen(filename, "r");

    if (filePointer == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    char buffer[LINE_LENGTH];
    int lines = 0, words = 0;
    char lastChar = ' ';

    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        lines++;

        for (size_t i = 0; buffer[i] != '\0'; i++) {
            const char current = buffer[i];

            if ((current != ' ' && current != '\n' && current != '\t') &&
                (lastChar == ' ' || lastChar == '\n' || lastChar == '\t')) {
                words++;
            }

            lastChar = current;
        }
    }

    fclose(filePointer);

    printf("File:  %s\n", filename);
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);

    return 0;
}