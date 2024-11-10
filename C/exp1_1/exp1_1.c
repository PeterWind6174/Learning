#include <stdio.h>

int main() 
{
    int a,b,sum,diference,product;
    //int quotient;
    double quotient,ave;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    sum = a + b;
    diference = a - b;
    product = a * b;
    //quotient = a / b;
    quotient = a * 1.0 / b;
    //ave = (a + b) / 2;
    ave = (a + b) / 2.0;
    printf("Sum = %d\n", sum);
    printf("Diference = %d\n", diference);
    printf("Product = %d\n", product);
    //printf("Quotient = %d\n", quotient);
    printf("Quotient = %.2f\n", quotient);
    //printf("Average = %d\n", ave);
    printf("Average = %.2f\n", ave);
    return 0;
}