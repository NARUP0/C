#include <stdio.h>
#include <stdlib.h>

// Define the structure for the queue
struct queue 
{
    int size;                                               // Maximum size of the queue
    int frontInd;                                          // Index of the front element
    int backInd;                                          // Index of the back element
    int *arr;                                            // Pointer to dynamically allocated array to store queue elements
}; 

// Function to check if the queue is full
int isfull(struct queue *q)
{
    if(q->backInd == (q->size) - 1)
    {
        return 1;                                                           // Return 1 if the queue is full
    }
    else
    {
        return 0;                                                           // Return 0 if the queue is not full
    }
}

// Function to check if the queue is empty
int isempty(struct queue *q)
{
    if(q->backInd == q->frontInd)
    {
        return 1;                                                            // Return 1 if the queue is empty
    }
    else
    {
        return 0;                                                           // Return 0 if the queue is not empty
    }
}

// Function to add an element to the queue (enqueue)
void enqueue(struct queue *q, int value)
{
    if(isfull(q))
    {
        printf("Queue overflow\n");                                  // Print an error message if the queue is full
    }
    else
    {
        q->backInd++;                                               // Move backInd to the next position
        q->arr[q->backInd] = value;                                // Insert the value at the back of the queue
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue(struct queue *q)
{
    if(isempty(q))
    {
        printf("Queue underflow\n");                                // Print an error message if the queue is empty
        return -1;                                                // Return -1 to indicate that dequeue is not performed
    }
    else
    {
        q->frontInd++;                                              // Move frontInd to the next position
        int a = q->arr[q->frontInd];                                // Retrieve the value at the front of the queue
        return a;                                                     // Return the dequeued value
    }
}

int main()
{
    // Create a queue and allocate memory for its elements
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->frontInd = -1;                                                   // Initialize frontInd to -1 (indicating the queue is empty)
    q->backInd = -1;                                                   // Initialize backInd to -1 (indicating the queue is empty)
    q->arr = (int *)malloc(q->size * sizeof(int));                      // Allocate memory for the queue elements
    
//     this is what this graph looks like

//                   0 --------- 1
//                   | \        /|
//                   |   \    /  |
//                   |     \/    |
//                   |    /   \  |
//                   |  /       \|
//                   2 --------- 3
//                    \         / 
//                     \       /
//                      \     / 
//                       \   /
//                         4  
//                        / \         
//                       /   \       
//                      /     \     
//                     /       \   
//                    5         6
                

    int initial = 4;                                                   // Starting node for BFS traversal
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};                            // Array to keep track of visited nodes
    
    // Adjacency matrix representation of the graph
    int adjmatrixofgraph[7][7] = 
    {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 1, 0, 0}
    };

    // Print the initial node and mark it as visited
    printf("%d ", initial);
    enqueue(q, initial);                                                // Enqueue the initial node
    visited[initial] = 1;                                                // Mark the initial node as visited

    // Perform BFS traversal
    while (!isempty(q))
    {
        int i = dequeue(q);                                            // Dequeue a node
        for (int j = 0; j < 7; j++)                                   // Check all adjacent nodes
        {
            if (adjmatrixofgraph[i][j] == 1 && visited[j] == 0)       // If an adjacent node is found and it hasn't been visited
            {
                visited[j] = 1;                                      // Mark the node as visited
                printf("%d ", j);                                   // Print the node
                enqueue(q, j);                                      // Enqueue the node
            }
        }
    }
    
    // Free the dynamically allocated memory for the queue
    free(q->arr); 
    free(q);

    return 0;
}
