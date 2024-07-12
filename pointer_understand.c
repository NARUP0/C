#include <stdio.h>

int main()
{
    int i = 07;
    int *r; // can also be written as : int *r=&i;
    r = &i;
    printf("The value of i is %d\n", i);
    printf("The value of i is %d\n", *r);
    printf("The value of r is %d\n", r);
    printf("The value of r is %d\n", *(&r));
    printf("The address of i is %u\n", &i);
    printf("The address of i is %u\n", r);
    printf("The address of r is %u\n", &r);
    
    return 0;
}
