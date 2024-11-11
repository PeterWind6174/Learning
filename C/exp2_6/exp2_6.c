#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, tmp;
    printf("Enter three numbers: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (a > c)
    {
        tmp = a;
        a = c;
        c = tmp;
    }
    if (b > c)
    {
        tmp = b;
        b = c;
        c = tmp;
    }
    if(a + b <= c)
    {
        printf("Not a triangle\n");
        return 0;
    }
    if (a == b && b == c && a == c)
        printf("Equilateral triangle\n");
    else if (fabs(a * a + b * b - c * c) < 1e-3)
    {
        if (a == b || b == c || a == c)
            printf("Isosceles right triangle\n");
        else
            printf("Right-angled triangle\n");
    }
    else if (a == b || b == c || a == c)
        printf("Isosceles triangle\n");
    else
        printf("Scalene triangle\n");
}