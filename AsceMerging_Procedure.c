#include <stdio.h>

void printarray(int * arr , int n)                      //function for printing array
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int* a, int* b, int* c, int m, int n)                  //function for merging two sorted array in third array in sorted way.
{
    int i,j,k ;
    i=j=k=0;

    while(i<m && j<n)                                             //loop will run till one of the indices of array will reach end.
    {
        if(a[i]<b[j])
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }

    while(i<m || j<n)                                     //all the left over elements will push into third array
    {
        if(i<m)
        {
            c[k]=a[i];
            i++;
            k++;
        }
        else if(j<m)
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
}

int main()
{                   
    
    int a[]={7, 9, 18, 19, 22};                               //taking two sorted array.
    int b[]={1, 6, 9, 11};
    int c[9];
                                    
                                                            
    printarray(a, 5);                                            //printing two sorted array
    printarray(b, 4);
    merge(a, b, c, 5, 4);
    printarray(c, 9);                                          //printing third merged sorted array




    
    return 0;
}
