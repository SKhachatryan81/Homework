#include <stdio.h>

int main(){
    int i,j;
    int arr[100];
    int n;
    int cup;
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
        for (j = 0; j < n; j++)
        {
            if (*(arr+j) > *(arr +i))
            {
                cup = *(arr+j);
                *(arr+j) = *(arr+i);
                *(arr+i) = cup;

            }
            
        }
        
    }
    for (i = 0; i < n; i++)
    {
        printf("element %d is %d\n", i, *(arr+i));
    }
    

    return 0;
}