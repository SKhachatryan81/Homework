#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int i;
    char *p;
    int cup;

    scanf("%s", str);
    p = &str[0];


    for (i = 0; i <strlen(str)/2; i++)
    {
        int n = strlen(str) - 1-i;
        cup = str[n];
        str[n] = *(p + i);
        *(p+i) = cup;
    }
    
    for (i = 0; i < strlen(str); i++)
    {
        printf("%c",*(p+i));
    }




    return 0;
}