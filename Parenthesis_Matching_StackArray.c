//parenthesis checking with stack array , but it can also done by using stack linked list.

//this programe checks parenthesis matching not expression is true or not like 5/%6**&9+8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size ;
    int top ;           // creating stack structure
    char * arr ;
};

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

void push(struct stack * ptr,char value)
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

char pop(struct stack * ptr)
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

int parenthesisMatch(char * exp)
{
    struct stack * sp =  (struct stack *)malloc(sizeof(struct stack));            //created stack structure variable
    sp->top=-1;
    sp->size=strlen(exp);
    sp->arr=(char *)malloc(sp->size*sizeof(char));                                   //created dynamical array

    for (int i = 0; exp[i]!= '\0'; i++)
    {
        if(exp[i]=='(')
        {
            push(sp,'(' );
        }
        else if(exp[i]==')')
        {
            if(isEmpty(sp))                                                   //putting condition of parenthesesis matching and freeing memory
            {
                free(sp->arr);
                free(sp);
                return 0 ;
            }
            else
            {
                pop(sp);
            }
        }
    }

    if(isEmpty(sp))
    {
        free(sp->arr);
        free(sp);
        return 1 ;
    }
    else
    {
        free(sp->arr);
        free(sp);
        return 0 ;
    }


      
}



int main()
{
    char exp[100]="(9+11(0)";                                             // put your expression here
    if(parenthesisMatch(exp))
    {
        printf("parenthesis matched");
    }
    else
    {
        printf("parenthesis not matched");
    }



return 0;
}