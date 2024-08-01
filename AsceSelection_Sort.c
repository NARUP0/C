//time complexity O(n^2)

#include <stdio.h>

void printarray(int *arr, int n) // function for printing array
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionsort(int *arr, int n)
{
    int indexMIN, temp;
    for (int i = 0; i < n - 1; i++)                    //loop for passes
    {
        indexMIN = i;
        for (int j = i + 1; j < n; j++)                //loop for comparision
        {
            if (arr[j] <arr[indexMIN])
            {
                indexMIN = j;
            }
        }
        temp = arr[i];                                 //swapping values
        arr[i] = arr[indexMIN];
        arr[indexMIN] = temp;
    }
}

int main()
{
    int arr[] = {3, 5, 2, 13, 12}; // creating integer array.

    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13


    int n = 5;                          // setting size.
    printarray(arr, n);
    selectionsort(arr, n);
    printarray(arr, n);

    return 0;
}