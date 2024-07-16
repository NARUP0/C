#include <stdio.h>

int linearsearch(int arr[], int element, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element) // here we check value one bye one
        {
            return i;
        }
    }
    return -1;
}

main()
{
    int arr[100], n, element, index; // initialization

    printf("Enter the no. of input : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) // taking array from user
    {
        printf("Enter the %dth element : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("the array looks like : { ");
    for (int i = 0; i < n; i++) // printing array
    {
        printf(" %d", arr[i]);
    }
    printf(" }\n");

    printf("Enter the element you want find in array : "); // taking info about element which have to be found
    scanf("%d", &element);

    index = linearsearch(arr, element, n); // calling function

    if (index != (-1))
    {
        printf("your element is at index no. : %d", index);
    }
    else // printing index based on output of function
    {
        printf("your element is not present in the array.");
    }
}