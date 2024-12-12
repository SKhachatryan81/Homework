#include <stdio.h>

int main(){
    char c = 'A';
    char *p = &c;
    int i;

    for (i = 0; i < 26; i++)
    {
        printf("%c ", (*p+i));
    }
    return 0;
}