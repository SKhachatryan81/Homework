#include <stdio.h>
#include <string.h>


void changePos(char *c1, char *c2)
{
    char cup;
    cup = *c1;
    *c1 = *c2;
    *c2 = cup;
}


void charPermu(char *c, int start, int end)
{
    int i;
    if (start == end)
        printf("%s  ", c);
    else
    {
        for (i = start; i <= end; i++)
        {
            changePos((c + start), (c + i)); 
            charPermu(c, start + 1, end);
            changePos((c + start), (c + i));
        }
    }
}

int main()
{
    char str[] = "abcd";
    int n = strlen(str);

    charPermu(str, 0, n - 1);

    return 0;
}