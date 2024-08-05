// time complexity is O(n+m), where the n is no. of element and m is highest value element.


#include <stdio.h>
#include <stdlib.h>                                       // for using calloc

void printarray(int * arr , int n)                      //function for printing array
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int maxelement(int * arr, int n)                   //function returns  maximum value element of array
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }

    return max ;
    
}

void countsort(int * arr , int n)
{
        int max=maxelement(arr, n);                                //storing the max element

        int * count =(int *)calloc(max+1,sizeof(int));            //dma the count array using calloc so we get pre-written data of element equal to 0.

        for (int i = 0; i < n; i++)                               //counting the no. of occurence of element of input array in count array.
        {
            count[arr[i]]= count[arr[i]]+1;
        }

        int i = 0;                                    
        int j = 0;

        while (i<=max)                                            //storing element in sorted way.
        {
            if(count[i]!=0)
            {
                arr[j]=i;
                j++;
                count[i]--;
            }
            else
            {
                i++;
            }
        }

        free(count);
        
        
}

int main()
{                   
    int arr[]={1, 9, 6, 3, 2, 8, 5, 8};                                      //creating integer array.

    int n = 8 ;                                                             //setting size.
    printarray(arr, n);
    countsort(arr, n);
    printarray(arr, n);

    
    return 0;
}