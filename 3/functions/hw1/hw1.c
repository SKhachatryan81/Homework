#include <stdio.h>

int isprime(int n);

void arePrimePairs(int num);

int main(){
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    arePrimePairs(num);

    return 0;
}

int isprime(int n){
    if (n <= 1) 
        return 0;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void arePrimePairs(int num){
    int found = 0;

    for (int i = 2; i <= num / 2; i++){
        if (isprime(i) && isprime(num - i))
        {
            printf("%d = %d + %d\n", num, i, num - i);
            found = 1;
        }
    }
    if (!found){
        printf("%d can't be expressed as a sum of two prime numbers.\n", num);
    }

}