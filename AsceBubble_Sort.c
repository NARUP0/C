//time complexity normal bubble sort is O(n^2)

#include <stdio.h>

void printarray(int * arr , int n)                      //function for printing array
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubblesort(int * arr , int n)                     //function for sorting array with bubble sort but this code is not adaptive.
{
    int temp ;
    
    for (int i = 0; i < n-1; i++)
    {
        printf("completing %d pass\n",i+1);              //printing no. of passes.

        for (int j = 0; j < n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp ;
            }
        }
        
    }
    
}

int main()
{                   
    int arr[]={6, 2, 9, 5, 3};                    //creating integer array.
    int n = 5 ;                                   //setting size.
    printarray(arr, n);
    bubblesort(arr, n);
    printarray(arr, n);

    
    return 0;
}
