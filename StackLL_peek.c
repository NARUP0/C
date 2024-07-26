#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
    int data ;
    struct stackNode * next ;                                     //creating structure of stack using linkedlist
};

int isEmpty(struct stackNode * n)
{
    if(n==NULL)
    {
        return 1 ;
    }
    else                                                     //checks if stack is empty or not
    {
        return 0 ;
    }
}

int isFull(struct stackNode * n)
{
    if(n==NULL)
    {
        return 1 ;                                      //checks if stack is full or not
    }
    else
    {
        return 0 ;
    }
}

struct stackNode * push(struct stackNode * high , int value)
{
    struct stackNode * ptr=(struct stackNode *)malloc(sizeof(struct stackNode));
    if(isFull(ptr))
    {
        printf("stack overflow !!!!");
        return high;
    }                                                              //push elements from header side in lifo discipline
    else
    {
        ptr->data=value;
        ptr->next=high ;
        high = ptr ;
        return high ;
    }
}


int peek(struct stackNode * high, int pos)
{
    for(int i=0; i<pos-1 && high!=NULL ; i++)
    {
        high=high->next;
    }
    if(high!=NULL)
    {                                                        //peek at given position starting at 1.
        return high->data ;
    }
    else
    {
        printf("\ninvalide input !!!!");
        
    }
}

int stacktop(struct stackNode * high)
{
    if(isEmpty(high))
    {
        printf("stack is empty");                                       //give top data
    }
    else
    {
        return high->data;
    }
}

int stackbottom(struct stackNode * high)
{
    if(isEmpty(high))
    {
        printf("stack is empty");                                       
    }
    else
    {
        while(high->next!=NULL)
        {                                                     //give bottom data
            high=high->next;
        }
        return high->data;
    }
}

void StackTraversal(struct stackNode * high)
{
    if(isEmpty(high))
    {
        printf("stack is empty");                                         //printing stack
    }
    else
    {
    while(high->next!=NULL)
    {
        printf("%d\n", high->data );
        high=high->next;
    }
    printf("%d", high->data );
    }
}

void fre(struct stackNode * high)
{
    if(isEmpty(high)==0)
    {
                struct stackNode * temp ;                                         //freeing the stack
        while(high->next!=NULL)
        {
            temp=high;
            high=high->next;
            free(temp);
        }
        free(high);
    }                                        
  

}

int main()
{
    struct stackNode * top = NULL ;
    top = push(top, 2);
    top = push(top, 6);
    top = push(top, 5);
    top = push(top, 3);                                  //pushed 4 elements

    StackTraversal(top);

    printf("\n\n%d\n\n",peek(top, 6));                      //peeked at position 1.

    printf("\n\n%d\n\n",stacktop(top));                      //stacktop

    printf("\n\n%d\n\n",stackbottom(top));                    //stackbottom

    fre(top);

    return 0 ;
}