// time complexity is O(n^2) but best case time complexity is O(n*logn)

#include <stdio.h>

void printarray(int * arr , int n)                      //function for printing array
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int partition(int * arr,int low, int high)                  //return partition index and place partition element at its correct position.
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp ;

    while(i<=j)                                         
    {
    while(arr[i]<=pivot  &&  i<=high)
    {
        i++;
    }

    while(arr[j]>pivot  &&  j>=low)
    {
        j--;
    }

    if(i<j)                                             
    {
        temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp; 
    }
    }

    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;    

    return j ;
}

void quicksort(int* arr,int low, int high)                           //recursive function
{
    if(low<high)                                                    //condition that stop recursive function.
    {
    int partitionind = partition(arr, low, high);
    quicksort(arr, low, partitionind-1);
    quicksort(arr, partitionind+1, high);
    }
}

int main()
{                   
    int arr[]={9, 4, 4, 8, 7, 5, 6, 10, 0, 2};                    //creating integer array.
    int n = 10 ;                                                  //setting size.
    printarray(arr, n);
    quicksort(arr, 0, n-1);
    printarray(arr, n);

    
    return 0;
}
