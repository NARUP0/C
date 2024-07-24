#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size; // creating stack
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    } // check if stack is empty or not
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // //check if stack is empty or not
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack)); // creating pointer of stack to manupilate data

    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    if (s->arr == NULL)
    {
        free(s);
        printf("Memory allocation for array failed\n");
        return 1;
    }

    // s->arr[0]=1;
    // ++(s->top);
    // s->arr[1]=1;
    // ++(s->top);                                                 //ex of data
    // s->arr[2]=1;
    // ++(s->top);
    // s->arr[3]=1;
    // ++(s->top);
    // s->arr[4]=1;
    // ++(s->top);
    // s->arr[5]=1;
    // ++(s->top);

    if (isEmpty(s) == 1)
    {
        printf("empty");
    } // calling function

    if (isFull(s) == 1)
    {
        printf("full");
    }

    free(s->arr);
    s->arr = NULL; // freeing the allocate memory
    free(s);
    s = NULL;

    return 0;
}