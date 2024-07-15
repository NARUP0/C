#include <stdio.h>

int enter(int arr[]) // for entering details of array
{
    int n;
    printf("Enter the no. of input : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth element : ", i + 1);
        scanf("%d", &arr[i]);
    }
    return n;
}

void display(int arr[], int n) // for displaying array
{
    printf("{ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}

int inddeletion(int arr[], int size, int index) // for inserting int element in array
{
    
        for (int i = index; i<=size-1; i++)
        {
            arr[i] = arr[i+1];
        }
        size--;
    
    return size;
}

int main()
{
    int arr[100], element, index;
    int size = enter(arr);
    display(arr, size);
    printf("Enter the index no. of your element you want delete : ");
    scanf("%d", &index);
    size = inddeletion(arr, size,index);
    display(arr, size);
    return 0;
}
