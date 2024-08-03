#include <stdio.h>

void printarray(int * arr , int n)                      //function for printing array
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void merge(int * a, int low, int mid, int high)            //merge internal subarrays in sorted way.
{
    int i, j, k, b[100] ;
    i = low;
    j = mid+1;
    k = low ;

    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }

    while (i<=mid || j<=high)
    {
        if(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else if(j<=high)
        {
            b[k]=a[j];
            j++;
            k++;
        }   
    }

    for (int i = low; i <= high; i++)                             //temperearly b array for storing data is copying to a.
    {
        a[i]=b[i];
    }
        
}

void mergesort(int * a, int low, int high)                //recusive function for dividing arrays and calls merge. 
{
    int mid ;
    if(low<high)
    {
        mid = (low + high)/2;
        mergesort(a, low, mid);
        mergesort(a,mid+1, high);
        merge(a, low, mid, high);
    }
}

int main()
{                   
    
    int a[]={9, 1, 4, 14, 4, 15, 1};                                   

                                    
                                                            
    printarray(a, 7);                                          
    mergesort(a, 0, 6);
    printarray(a, 7);                                        




    
    return 0;
}
