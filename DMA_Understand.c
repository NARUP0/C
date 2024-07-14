#include <stdio.h>
#include <stdlib.h> //using this for DMA function

int main()
{
    char *ptr;
    int *ptr2;

    ptr = (char *)malloc(10 * sizeof(char)); // use of malloc function
    for (int i = 0; i < 10; i++)
    {
        printf("Enter the value of %dth character : ", i + 1);
        scanf("%c%*c", &ptr[i]); //%*c is used to skip enters
    }

    for (int i = 0; i < 10; i++)
    {
        printf("The value of %dth character : %c\n", i + 1, ptr[i]);
    }

    free(ptr);

    printf("\n.........................................................\n\n");

    ptr2 = (int *)calloc(10, sizeof(int)); // use of calloc function

    for (int i = 0; i < 10; i++)
    {
        printf("The value of %dth character : %d\n", i + 1, ptr[i]); // calloc gives 0
    }

    printf("\n.........................................................\n\n");

    free(ptr2);

    return 0;
}
