#include <stdio.h>
#include <string.h>
#define MAXCHAR 1000

void reverse_str(char givstr[]);

int main(){
    char text[MAXCHAR];
    int c;
    int i;

    i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        text[i] = c;
        ++i;
    }
    text[i] = '\0';
    
    reverse_str(text);
    printf("%s", text);

    return 0;

}

void reverse_str(char givstr[]){
    int i;
    int j;
    int c;

    for (j = strlen(givstr) - 1, i = 0; i < j; i++, j--)
    {
        c = givstr[i];
        givstr[i] = givstr[j];
        givstr[j] = c;
    }
    
}