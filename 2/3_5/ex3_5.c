#include <stdio.h>

void itob(int num, char s[], int base);

int main(){
    int givn;
    int base;
    char s[1000];

    printf("Enter your number: ");
    scanf("%d", &givn);
    printf("Enter converting base(2-32): ");
    scanf("%d", &base);

    itob(givn, s, base);
    printf("%s", s);

    return 0;
}

void itob(int num, char s[], int base){
    int k;
    int i;
    int j;
    int neg = 0;
    char cup;
    
    i = 0;
    if (num == 0){
        s[i++] = '0';
        s[i] = '\0';
        return;
    }
    else if(num < 0){
        neg = 1;
        num = -num;
    }

    while (num > 0)
    {
        k = num % base;
        if (k < 10) {
            s[i++] = k + '0';
        } else {
            s[i++] = k - 10 + 'A';
        }
        num = num / base;
    }
    if (neg) {
        s[i++] = '-';
    }

    s[i] = '\0';

    for (j = 0; j < i / 2; j++) {
        cup = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = cup;
    }
    
}