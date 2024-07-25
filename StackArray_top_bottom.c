#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size ;
    int top ;           // creating stack structure
    int * arr ;
};

int isFull(struct stack * ptr)
{
    if(ptr->top==ptr->size - 1)
    {
        return 1 ;
    }                            // //check if stack is full or not
    else
    {
        return 0;
    }
}

int isEmpty(struct stack * ptr)
{
    if(ptr->top==-1)
    {
        return 1 ;
    }                                            // check if stack is empty or not
    else
    {
        return 0;
    }
}

void push(struct stack * ptr,int value)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow !!\n");                  //pushing value
    }
    else
    {
        ptr->top ++;
        ptr->arr[ptr->top]= value ;
    }
}

int pop(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underflow !!\n");
    }                                                      //poping value
    else
    {
        int val = ptr->arr[ptr->top];
        (ptr->top)--;
        return val;
    }
}

int stacktop(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underflow !!\n");            //function that returns top most element
    }   
    else
    {
        return ptr->arr[ptr->top];
    }
}

int stackbottom(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack underflow !!\n");                  //function that returns bottom most element
    }   
    else
    {
        return ptr->arr[0];
    }
}

int main(){

struct stack * s = (struct stack *)malloc(sizeof(struct stack));            // creating pointer of stack to manupilate data
s->size=6;
s->top=-1;
s->arr=(int *)malloc(s->size * sizeof(int));

push(s, 1);
push(s, 2);
push(s, 3);
push(s, 4);
push(s, 5);
push(s, 6);             //pushed 6 values

printf("%d\n",stacktop(s));               //printing top most element
printf("%d\n",stackbottom(s));            //printing bottom most element

free(s->arr);               // freeing the allocate memory
free(s); 

return 0;
}