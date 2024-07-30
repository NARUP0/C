#include <stdio.h>
#include <stdlib.h>

struct queuenode * front = NULL;
struct queuenode * back = NULL;                   //initialising front and back as global variable (so we can access this from anywhere) to null.

struct queuenode 
{                                                 //creating struct queue using linked list
    int data ;
    struct queuenode * next ;
};

void enqueue (int value)                          //adding elements in queue in fifo discipline using linked list.
{
    struct queuenode * n = (struct queuenode *)malloc(sizeof(struct queuenode));
    if(n==NULL)
    {
        printf("queue overflow");
    }
    else
    {
        n->data=value;
        n->next=NULL;
        if(front==NULL)                            //condition if we are adding the first element in queue.
        {
            front=back=n;
        }
        else                                      //condition if we are not adding the first element in queue.
        {
            back->next=n;
            back=n;
        }
    }
}

int dequeue()                            //removing elements in queue in fifo discipline using linked list.
{
    int value ;
    if(front==NULL)
    {
        printf("queue underflow");
        return -1;
    }
    else
    {
       struct queuenode * temp = front ;
       value = front->data;
       front=front->next;
       free(temp);
       return value ; 
    }
}

void fre()                                   //freeing dma memory.
{
    struct queuenode * temp ;
    while (front!=NULL)
    {
        temp=front;
        front=front->next;
        free(temp);
    }
    
}

int main()
{
    enqueue(5);
    enqueue(4);
    enqueue(8);
    enqueue(12);
    enqueue(74);                         //pushed 5 elments
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());             //poped 5 elements
    printf("%d\n",dequeue());
    fre();

    return 0 ;

}