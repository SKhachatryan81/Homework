#include <stdio.h>

void expand(char s1[], char s2[]);

int main() {
    
    int i;
    int c;
    char s1[1000];
    char s2[1000];

    i = 0;
    while ((c = getchar()) != EOF && c != '\n')
    {
        s1[i++] = c;
    }
    s1[i] = '\0';

    expand(s1,s2);
    printf("%s", s2);

    return 0;
}

void expand(char s1[], char s2[]){
    int i;
    int j;
    char c;

    i = j = 0;
    while ((c = s1[i++]) != '\0')
    {
        if (c <= s1[i+1] && s1[i] == '-')
        {
            i++;
            while (c < s1[i])
            {
                s2[j++] = c++;
            }
            
        }
        else if (c == '-')
        {
            continue;
        }
        
        else
            s2[j++] = c;
        
        
        
        
        
    }
    s2[j] = '\0';
    
}