// returning -1 means dequeue is not performed. 
//in circular queue using array we can store (size-1) elements at a time if queue is full, because we have to make diif bw frontInd and backInd.

#include <stdio.h>
#include <stdlib.h>

struct circularqueue 
{
    int size ;
    int frontInd ;                                       //creating structure for circularqueue.
    int backInd ;
    int * arr ;
}; 

int isfull(struct circularqueue * q)
{
    if((q->backInd +1 )%q->size==(q->frontInd))
    {
        return 1 ;                                         //determine if circularqueue is full or not.
    }
    else
    {
        return 0 ;
    }
}

int isempty(struct circularqueue * q)
{
    if(q->backInd==q->frontInd)
    {
        return 1 ;                                              //determine if circularqueue is empty or not.
    }
    else
    {
        return 0 ;
    }
}

void enqueue(struct circularqueue * q , int value)
{
    if(isfull(q))
    {
        printf("Queue overflow\n");
    }                                                            //function to add element in circularqueue in fifo disciplne.
    else
    {
        q->backInd = (q->backInd +1)%q->size;
        q->arr[q->backInd]=value;
        printf("the enqueud element is : %d \n",value);

    }
}

int dequeue(struct circularqueue * q )
{
    if(isempty(q))
    {
        printf("Queue underflow\n");                                      //function to remove element in circularqueue in fifo disciplne.
        return -1 ;
    }
    else
    {
        q->frontInd = (q->frontInd +1)%q->size;
        int a = q->arr[q->frontInd];
        return a ;
    }
}

int main()
{
    struct circularqueue * q = (struct circularqueue *)malloc(sizeof(struct circularqueue));             //creating stuct circularqueue variable'
    q->size=4;
    q->frontInd=0;                                                     // here we have to take frontInd and backInd 0 instead of -1 for the logic of isempty and isfull.
    q->backInd=0;
    q->arr=(int *)malloc(q->size*sizeof(int));                               //generating addres of circularqueue.
    
    enqueue(q,8);
    enqueue(q,2);
    enqueue(q,7);
    enqueue(q,4);                                                   

    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));                                 

    free(q->arr);                                                     //freeing the dma memory.
    free(q);

    return 0 ;
}
