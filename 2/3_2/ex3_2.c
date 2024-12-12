#include<stdio.h>

void escape(char txt[], char conv_str[]);

int main(){    
    int i,c;
    char s[1000];
    char t[1000];    
    i =0;
    while((c =getchar()) != EOF && c != 'z'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    escape(s, t);
    printf("%s", t);
    
    return 0;
}

void escape(char txt[], char conv_str[]){
    int i,j;
    
    i = 0;
    j = 0;
    while(txt[i] != '\0'){
         switch (txt[i]){
             case '\n':
                 conv_str[j++] = '\\';
                 conv_str[j++] = 'n';
                 break;
            case '\t':
                 conv_str[j++] = '\\';
                 conv_str[j++] = 't';
                 break;
             default:
                 conv_str[j++] = txt[i];
                 break;
         }
         ++i;
         
     }
     conv_str[i+j] = '\0';
    

}