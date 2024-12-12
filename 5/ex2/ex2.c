#include <stdio.h>

struct Complex
{
    float real;
    float imag;
};

struct Complex multiply(float rl1, float img1, float rl2, float img2){
    struct Complex n1;
    struct Complex n2;

    n1.real = rl1;
    n1.imag = img1;
    n2.real = rl2;
    n2.imag = img2;

    float rl = (n1.real*n2.real)-(n1.imag*n2.imag);
    float img = (n1.real*n2.imag)+(n1.imag*n2.real);

    struct Complex result;
    result.real = rl;
    result.imag = img;
    
    return result;
};

int main(){

    struct Complex num1;
    struct Complex num2;

    printf("write the real part of the num1: "); scanf("%f",&num1.real);
    printf("write the imaginary part of the num1: "); scanf("%f",&num1.imag);

    // if (num1.imag >= 0)
    //     printf("your complex num1 is %.1f+%.1fi\n\n",num1.real,num1.imag);
    // else if (num1.imag < 0)
    printf("your complex num1 is %.1f %.1fi\n\n",num1.real,num1.imag);


    printf("write the real part of the num2: "); scanf("%f",&num2.real);
    printf("write the imaginary part of the num2: "); scanf("%f",&num2.imag);

    
    printf("your complex num2 is %.1f %.1fi\n\n",num2.real,num2.imag);

    struct Complex result = multiply(num1.real,num1.imag,num2.real,num2.imag);

    printf("the result of num1*num2 is %.2f %.2fi\n",result.real,result.imag);
    printf("(if between real and imaginary number is nothing, then we suppose the '+' between exists :))\n");
    
    
}