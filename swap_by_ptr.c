#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
main()
{
    int n = 5, m = 7;
    printf("The value of n=%d and m=%d before swap.\n ", n, m);
    swap(&n, &m);
    printf("The value of n=%d and m=%d after swap. ", n, m);
}
