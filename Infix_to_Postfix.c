
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

int stacktop(struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        return -1 ;            //function that returns top most element
    }   
    else
    {
        return ptr->arr[ptr->top];
    }
}

int isoperater(char infix)
{
    if( infix=='+' || infix=='-' || infix=='*' || infix=='/' || infix=='%')
    {
        return 1 ;
    }
    else                                          //chexks if given value is operater or not
    {
        return 0 ;
    }
}

int precedence(char x)
{
    if( x=='+' || x=='-')
    {
        return 1 ;
    }
    else if (x=='*' || x=='/' || x=='%')                        //return the precedence no. of operater
    {
        return 2 ;
    }
    return 0 ;
    
}


char InfixtoPostfix(char * infix)
{
    struct stack * sp = (struct stack *) malloc (sizeof(struct stack));          //creating struct stack variable
    sp->size=strlen(infix);
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));                              
    char * postfix = (char *)malloc((strlen(infix)+1)*sizeof(char));                     //creating dynamically string for storing postfix.
    int i = 0 ;
    int j = 0 ;

    while(infix[i]!='\0')
    {
        if(!isoperater(infix[i]))
        {
            postfix[j]=infix[i];                                           
            i++;                                         // adding in postfix
            j++;
        }                                     
        else
        {
            if(precedence(infix[i])>precedence(stacktop(sp)))
            {                                                                     
                push(sp, infix[i]);
                i++;
            }                                             //adding in post fix based on condition
            else
            {
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp))
    {
        postfix[j]=pop(sp);                                        //adding leftover operater in postfix
        j++;
    }
    postfix[j]='\0';                                               //adding null character at last in string

    printf("the postfix is %s", postfix);                          //printing postfix.

    free(sp->arr);
    free(sp);
    free(postfix);                                                 //freeing memory

    return j ;

}    




int main()
{
    char infix[]="a+b";                                             // put your expression here
    printf("the infix is %s\n", infix);
    InfixtoPostfix(infix);


return 0;
}