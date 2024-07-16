#include <stdio.h>

int binarysearch(int arr[], int element, int size)
{
    int high, low, mid;
    low = 0;
    high = size - 1; // my own version of binary search

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] > element)
        {
            if (arr[low] == element) // only line 25 in else if for original version
            {
                return low;
            }
            else
            {
                low++;
                high = mid - 1;
            }
        }
        else if (arr[mid] < element)
        {
            if (arr[high] == element)
            {
                return high;
            }
            else // only line 37 in else if for original version
            {
                high--;
                low = mid + 1;
            }
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
        printf("Enter the %dth element (must be sorted in ascending order) : ", i + 1);
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

    index = binarysearch(arr, element, n); // calling function

    if (index != (-1))
    {
        printf("your element is at index no. : %d", index);
    }
    else // printing index based on output of function
    {
        printf("your element is not present in the array.");
    }
}