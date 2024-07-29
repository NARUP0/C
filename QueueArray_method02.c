// returning -1 means dequeue is not performed. 

#include <stdio.h>
#include <stdlib.h>

struct queue 
{
    int size ;
    int frontInd ;                                       //creating structure for queue.
    int backInd ;
    int * arr ;
}; 

int isfull(struct queue * q)
{
    if(q->backInd==(q->size)-1)
    {
        return 1 ;                                         //determine if queue is full or not.
    }
    else
    {
        return 0 ;
    }
}

int isempty(struct queue * q)
{
    if(q->backInd==q->frontInd)
    {
        return 1 ;                                              //determine if queue is empty or not.
    }
    else
    {
        return 0 ;
    }
}

void enqueue(struct queue * q , int value)
{
    if(isfull(q))
    {
        printf("Queue overflow\n");
    }                                                            //function to add element in queue in fifo disciplne.
    else
    {
        q->backInd++;
        q->arr[q->backInd]=value;

    }
}

int dequeue(struct queue * q )
{
    if(isempty(q))
    {
        printf("Queue underflow\n");                                      //function to remove element in queue in fifo disciplne.
        return -1 ;
    }
    else
    {
        q->frontInd++;
        int a = q->arr[q->frontInd];
        return a ;
    }
}

int main()
{
    struct queue * q = (struct queue *)malloc(sizeof(struct queue));             //creating stuct queue variable'
    q->size=10;
    q->frontInd=-1;
    q->backInd=-1;
    q->arr=(int *)malloc(q->size*sizeof(int));                               //generating addres of queue.
    
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
