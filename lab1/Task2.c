#include <stdio.h>

int PalCheck(unsigned long long int num)
{
    int n = num;
    int rnum = 0;
    while (n>0)
    {
        rnum =rnum*10 + n % 10;
        n/=10;
    }    
    if (num != rnum) return 0;
    else return 1;
}
int main()
{
    unsigned long long int xmax, i, v;
    v = 1800000000000000000;
    printf ("\nEnter Max: ") && scanf("%llu", &xmax);
    if (xmax * xmax >= v)
    {
        printf ("Too high value");
        return 0;
    }
    for(i=1; i<=xmax; i++)
    {
        unsigned long long int i2 = i * i;
        if (PalCheck(i2) == 1) 
        {
            printf("%llu: %llu\n", i, i2);
        }
    }
}