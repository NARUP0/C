#include <stdio.h>

int enter(int arr[])
{
    int n;
    printf("Enter the no. of input : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth element : ", i + 1);
        scanf("%d",&arr[i]);
    }
    return n;
}

void display(int arr[], int n)
{
    printf("{ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}


int indinsertion(int arr[], int element, int size, int capacity, int index)
{
    if (size == capacity)
    {
        printf("Capacity is full");
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        size++;
    }
    return size;
}

int main()
{
    int arr[100], element , index;
    int size = enter(arr); 
    display(arr, size);
    printf("Enter the element you want include : ");
    scanf("%d",&element);
    printf("Enter the index no. of your element you want include : ");
    scanf("%d",&index);
    size = indinsertion(arr, element, size, 100, index);
    display(arr, size);
    return 0;
}
