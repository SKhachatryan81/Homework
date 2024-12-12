#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

int main() {
    FILE *text1, *text2;
    char line1[BUF_SIZE], line2[BUF_SIZE];

    text1 = fopen("text1", "r");
    text2 = fopen("text2", "r");

    if (text1 == NULL) {
        printf("Error opening file1.\n");
        return 1;
    }
    if (text2 == NULL) {
        printf("Error opening file2.\n");
        return 1;
    }

    int lineNum = 1;

    while (fgets(line1, sizeof(line1), text1) != NULL && fgets(line2, sizeof(line2), text2) != NULL) {
        if (strcmp(line1, line2) != 0) {
            printf("Files differ at line %d:\n", lineNum);
            printf("File 1: %s", line1);
            printf("File 2: %s", line2);
            break;
        }
        lineNum++;
    }

    fclose(text1);
    fclose(text2);

    return 0;
}