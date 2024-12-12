#include <stdio.h>

int main(){
    int i;
    int arr[100];
    int n;
    printf("How many numbers do you want to store?: ");
    scanf("%d", &n);

    printf("write %d elements\n", n);

    for (i = 0; i < n; i++)
    {
        printf("element %d: ", i);
        scanf("%d", arr+i);
    }
    
    for (i = 0; i < n; i++)
    {
        printf("element %d is %d\n", i, *(arr+i));
    }
    

    return 0;
}