#include <stdio.h>

void slice(char *st, int m, int n)
{
    int i = 0;
    while (m+i-1 < n)
    {
        st[i] = st[m + i];
        i++;
    }
    st[i] = '\0';
}

int main()
{
    int m, n;
    char string [100];
    printf("Enter a string : ");
    gets(string);
    printf("Enter the index no. you want to start slicinng (included)  : ");
    scanf("%d", &m);
    printf("Enter the index no. you want to stop slicinng (included)  : ");
    scanf("%d", &n);
    slice(string, m, n);
    printf("The sliced string is %s", string);

    return 0;
}
