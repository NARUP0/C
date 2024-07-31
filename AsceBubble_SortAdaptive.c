//time complexity adaptive bubble sort is O(n) if array in input is already sorted. otherwise O(n^2).
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
    int temp ,issort ;
    for (int i = 0; i < n-1; i++)
    {   
        issort = 1;

        printf("completing %d pass\n",i+1);            //printing the no. of passes.

        for (int j = 0; j < n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp ;
                issort = 0;                       // if the value of issort remains 1 it means the entire pass is not been compare 
            }                                     //and it means the array has been sorted.
        }
        if(issort)
        {
            return ;
        }
        
    }
    
}

int main()
{                   
    // int arr[]={1, 25, 36, 47, 27, 50};
    int arr[]={1, 2, 3, 4, 5, 6};                                     //creating integer array.
    int n = 6 ;                                                             //setting size.
    printarray(arr, n);
    bubblesort(arr, n);
    printarray(arr, n);

    
    return 0;
}
