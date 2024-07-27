//parenthesis checking with stack linked list , but it can also done by using stack array.

//this programe checks parenthesis matching not expression is true or not like 5/%6**&9+8

#include <stdio.h>
#include <stdlib.h>

struct stackNode
{
    char data ;
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

struct stackNode * push(struct stackNode * high , char value)
{
    struct stackNode * ptr=(struct stackNode *)malloc(sizeof(struct stackNode));
    if(isFull(ptr))
    {
        printf("stack overflow !!!!");
        return high ;
    }                                                              //push elements from header side in lifo discipline
    else
    {
        ptr->data=value;
        ptr->next=high ;
        high = ptr ;
        return high ;
    }
}

char pop(struct stackNode **high)
{
    if(isEmpty(*high))
    {
        printf("stack underflow");
    }
    else                                                              //pop elements from header side in lifo discipline
    {
        struct stackNode * temp = *high ;
        char x = (*high)->data ;
        *high=(*high)->next;
        free(temp);
        return x ;
    }
}

void fre(struct stackNode * high)
{
    struct stackNode * temp ;                                         //freeing the stack
    while(high!=NULL)
    {
        temp=high;
        high=high->next;
        free(temp);
    }
}

int ismatch(char a, char b)
{
    if((a=='('&& b==')') || (a=='['&& b==']')|| (a=='{'&& b=='}')|| (a=='<'&& b=='>'))
    {
        return 1;                                                          //to check the poepd up element is equal to what?
    }
    else
    {
        return 0 ;
    }
}

int parenthesisMatch(char * exp)
{
    struct stackNode * sp =NULL;      

    for (int i = 0; exp[i]!= '\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{' || exp[i]=='<')
        {
            sp=push(sp,exp[i] );
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}' || exp[i]=='>')
        {
            if(isEmpty(sp))                                                   //putting condition of parenthesesis matching and freeing memory
            {
                fre(sp);
                return 0 ;
            }
            else
            {
                char x = pop(&sp);
                if(!(ismatch(x, exp[i])))
                {
                    return 0; 
                }
            }
        }
    }
    if(isEmpty(sp))
    {
        fre(sp);
        return 1 ;
    }
    else
    {
        fre(sp);
        return 0 ;
    }

}

int main()
{
    char exp[100]="((9+1)*)<>{}";                            // put your expression here
    if(parenthesisMatch(exp))
    {
        printf("parenthesis matched");
    }
    else
    {
        printf("parenthesis not matched");
    }

    return 0 ;
}