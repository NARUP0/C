#include <stdio.h>

encryption(char *str)
{
    while (*str != '\0')
    {
        *str = *str - 1;
        str++;
    }
}

int main()
{
    char c[100];
    printf("Enter the massege you want to code : ");
    gets(c);
    encryption(c);
    printf("The Encrypted massage is : %s", c);
    return 0;
}
