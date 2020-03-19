//Variant 3

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float x, y, z, a, b;
    printf("Input(x):");
    scanf("%f", &x);
    printf("Input(y):");
    scanf("%f", &y);
    printf("Input(z):");
    scanf("%f", &z);
    if ((x != -2 && x != 2 && pow(z, (-x-2)) != -1/(pow(x, 2) - 4)) && (pow(x, 4) + cos(2*z)!= 1))
    {
        a = (1+y)*(x+y/(pow(x, 2)+4))/(pow(z, (-x-2)) + 1/(pow(x, 2)-4));
        b = (1 + pow(cos(a-2), y))/(pow(x, 4)/2-pow(sin(z), 2));
        printf("\nx: %.3f,\ny: %.3f,\nz: %.3f,\na: %.3f,\nb: %.3f\n\n", x, y, z, a, b);
    }
    else
    {
       printf("\nERROR\n\n");
    }
}