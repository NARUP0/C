// here the no. of vertices > the value of the vertices in graph.

#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the adjacency list and the queue

struct Node {
    int data;                                                                                     // Store the data of the node
    struct Node* next;                                                                            // Pointer to the next node in the list
};

// Define the structure for the graph

struct Graph {
    int numvertices;                                                                              // Number of vertices in the graph
    int* visitarray;                                                                                // Array to keep track of visited vertices
    struct Node** adjlist;                                                                          // Array of pointers to adjacency lists
};

// Define the structure for the queue used in BFS

struct Queue {
    int maxsize;                                                                                      // Maximum size of the queue
    int size;                                                                                           // Current size of the queue
    struct Node* f;                                                                                  // Pointer to the front of the queue
    struct Node* r;                                                                                            // Pointer to the rear of the queue
};

// Function to create a new node

struct Node* createnode(int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

// Function to check if the queue is empty

int isEmpty(struct Queue* q) {
    if (q->f == NULL) {
        return 1;                                                                                // Return 1 (true) if the queue is empty
    }
    return 0;                                                                                  // Return 0 (false) if the queue is not empty
}

// Function to check if memory is full (not related to queue size, but to memory availability)

int isFull() {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    if (n == NULL) {                                                                           // If memory allocation fails
        free(n);                                                                              // Free the allocated memory
        return 1;                                                                            // Return 1 (true) indicating memory is full
    }
    free(n);                                                                                // Free the allocated memory if successful
    return 0;                                                                               // Return 0 (false) indicating memory is not full
}

// Function to add an element to the queue

void enqueue(struct Queue* q, int data) {
    if (isFull()) {   // Check if memory is full
        printf("Queue Overflow\n");
    } else {
        struct Node* n = createnode(data);                                                    // Create a new node with the given data
        if (isEmpty(q)) {                                                                     // If the queue is empty
            q->f = q->r = n;                                                                // Set both front and rear to the new node
        } else {
            q->r->next = n;                                                                // Add the new node at the end of the queue
            q->r = n;                                                                 // Update the rear pointer to the new node
        }
        q->size++;                                                                        // Increment the size of the queue
    }
}

// Function to remove an element from the queue

int dequeue(struct Queue* q) {
    if (!isEmpty(q)) {                                                                         // Check if the queue is not empty
        struct Node* ptr = q->f;                                                               // Pointer to the front node
        q->f = q->f->next;                                                                     // Move the front pointer to the next node
        int val = ptr->data;                                                                  // Store the data of the front node
        free(ptr);                                                                           // Free the memory of the removed node
        q->size--;                                                                              // Decrement the size of the queue
        return val;                                                                          // Return the data of the removed node
    } else {
        printf("Queue Underflow\n");
        return -1;                                                                        // Return -1 if the queue is empty
    }
}

// Function to create a graph with the given number of vertices

struct Graph* creategraph(int num) {
    struct Graph* ptr = (struct Graph*)malloc(sizeof(struct Graph));
    ptr->numvertices = num;
    ptr->visitarray = (int*)malloc(num * sizeof(int));                                                     // Allocate memory for the visit array
    ptr->adjlist = (struct Node**)malloc(num * sizeof(struct Node*));                                     // Allocate memory for the adjacency list array

    for (int i = 0; i < num; i++) {
        ptr->visitarray[i] = 0;                                                                          // Initialize all vertices as not visited
        ptr->adjlist[i] = NULL;                                                                          // Initialize all adjacency lists as empty
    }
    
    return ptr;
}

// Function to add an edge to the graph

void addedge(struct Graph* ptr, int source, int destination) {

    // Add an edge from source to destination

    struct Node* newnode = createnode(destination);
    newnode->next = ptr->adjlist[source];
    ptr->adjlist[source] = newnode;

    // Add an edge from destination to source (since it's an undirected graph)

    newnode = createnode(source);
    newnode->next = ptr->adjlist[destination];
    ptr->adjlist[destination] = newnode;
}

// Function to perform Breadth-First Search (BFS) on the graph

void BFS(struct Graph* graph, int startvertex) {
    struct Queue* ptr = (struct Queue*)malloc(sizeof(struct Queue));
    ptr->maxsize = graph->numvertices;
    ptr->size = 0;
    ptr->f = ptr->r = NULL;

    enqueue(ptr, startvertex);                                                                    // Enqueue the start vertex
    graph->visitarray[startvertex] = 1;                                                            // Mark the start vertex as visited
    int vertex;

    while (!isEmpty(ptr)) {
        vertex = dequeue(ptr);                                                                   // Dequeue a vertex from the queue
        printf("%d ", vertex);                                                                    // Print the dequeued vertex

        struct Node* n = graph->adjlist[vertex];                                                   // Get the adjacency list of the dequeued vertex

        // Traverse all adjacent vertices

        while (n != NULL) {
            if (graph->visitarray[n->data] == 0) {                                               // If the adjacent vertex has not been visited
                graph->visitarray[n->data] = 1;                                                 // Mark it as visited
                enqueue(ptr, n->data);                                                         // Enqueue the adjacent vertex
            }
            n = n->next;                                                                       // Move to the next adjacent vertex
        }
    }
    free(ptr) ;
} 

// Function to free the memory allocated for the graph

void freeGraph(struct Graph * graph)
{
    // Loop through each vertex in the graph

    for (int i = 0; i < graph->numvertices ; i++)
    {
        struct Node * temp = graph->adjlist[i] ;                                      // Get the head of the adjacency list for vertex i

        // Traverse the adjacency list for this vertex

        while (temp != NULL)                                                         
        {
            struct Node * next = temp->next  ;                                           // Store the next node in the list
            free(temp) ;                                                                 // Free the current node
            temp = next ;                                                               // Move to the next node
        }
        
    }

    // Free the memory allocated for the adjacency list array
    free(graph->adjlist) ;

    // Free the memory allocated for the visit array
    free(graph->visitarray) ;

     // Free the memory allocated for the graph structure itself
    free(graph) ;
}

int main() {

    // Create a graph with 11 vertices (0 to 10)

    struct Graph* graph = creategraph(11);
    
    // Add edges to the graph

    addedge(graph, 0, 10);
    addedge(graph, 0, 7);
    addedge(graph, 0, 5);
    addedge(graph, 7, 5);
    addedge(graph, 7, 2);
    addedge(graph, 10, 5);
    addedge(graph, 2, 5);
    addedge(graph, 5, 1);
    addedge(graph, 1, 4);

    // Perform BFS starting from vertex 0

    BFS(graph, 0);

    return 0;
}
