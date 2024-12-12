#include <stdio.h>

#define MAXCHAR 1000

int getline(char line[], int lim);

int main() {
    char longline[MAXCHAR];
    int len;
    
    while ((len = getline(longline, MAXCHAR)) > 0)
    {
        if (len > 80)
        {
        printf("%s", longline);
        }
    }


    return 0;
}


int getline(char line[], int lim){
    int i;
    int c;

    i = 0;

    while ((c = getchar()) != EOF && c != '\n')
    {
        line[i] = c;
        ++i;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
    
}