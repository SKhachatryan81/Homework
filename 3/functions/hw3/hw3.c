#include <stdio.h>


void printPyramid(int n);

int main() {
    int rows;

    printf("Input number of rows: ");
    scanf("%d", &rows);

    printPyramid(rows);

    return 0;
}

void printPyramid(int n) {
    int j;
    for (int i = 1; i <= n; i++) {

        for (j = 0; j < n-i; j++)
            printf(" ");
        for (j = 0; j < i; j++)
            printf("* ");
        printf("\n");
    }
    
}